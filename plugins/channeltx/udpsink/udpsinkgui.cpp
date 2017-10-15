///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2017 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include "device/devicesinkapi.h"
#include "dsp/upchannelizer.h"
#include "dsp/threadedbasebandsamplesource.h"
#include "dsp/spectrumvis.h"
#include "dsp/dspengine.h"
#include "util/simpleserializer.h"
#include "util/db.h"
#include "gui/basicchannelsettingsdialog.h"
#include "plugin/pluginapi.h"
#include "mainwindow.h"

#include "udpsinkgui.h"
#include "ui_udpsinkgui.h"

const QString UDPSinkGUI::m_channelID = "sdrangel.channeltx.udpsink";

UDPSinkGUI* UDPSinkGUI::create(PluginAPI* pluginAPI, DeviceSinkAPI *deviceAPI)
{
    UDPSinkGUI* gui = new UDPSinkGUI(pluginAPI, deviceAPI);
    return gui;
}

void UDPSinkGUI::destroy()
{
}

void UDPSinkGUI::setName(const QString& name)
{
    setObjectName(name);
}

QString UDPSinkGUI::getName() const
{
    return objectName();
}

qint64 UDPSinkGUI::getCenterFrequency() const {
    return m_channelMarker.getCenterFrequency();
}

void UDPSinkGUI::setCenterFrequency(qint64 centerFrequency)
{
    m_channelMarker.setCenterFrequency(centerFrequency);
    applySettings();
}

void UDPSinkGUI::resetToDefaults()
{
    blockApplySettings(true);

    ui->sampleFormat->setCurrentIndex(0);
    ui->sampleRate->setText("48000");
    ui->rfBandwidth->setText("32000");
    ui->fmDeviation->setText("2500");
    ui->spectrumGUI->resetToDefaults();
    ui->gainIn->setValue(10);
    ui->gainOut->setValue(10);

    blockApplySettings(false);
    applySettings();
}

QByteArray UDPSinkGUI::serialize() const
{
    SimpleSerializer s(1);
    s.writeS32(2, m_channelMarker.getCenterFrequency());
    s.writeS32(3, (int) m_settings.m_sampleFormat);
    s.writeReal(4, m_settings.m_inputSampleRate);
    s.writeReal(5, m_settings.m_rfBandwidth);
    s.writeBlob(6, m_channelMarker.serialize());
    s.writeBlob(7, ui->spectrumGUI->serialize());
    s.writeS32(10, ui->gainOut->value());
    s.writeS32(11, m_settings.m_fmDeviation);
    s.writeBool(13, ui->stereoInput->isChecked());
    s.writeS32(14, ui->squelch->value());
    s.writeS32(15, ui->squelchGate->value());
    s.writeBool(16, ui->autoRWBalance->isChecked());
    s.writeS32(17, ui->gainIn->value());
    return s.final();
}

bool UDPSinkGUI::deserialize(const QByteArray& data)
{
    SimpleDeserializer d(data);

    if (!d.isValid())
    {
        resetToDefaults();
        return false;
    }

    if (d.getVersion() == 1)
    {
        QByteArray bytetmp;
        QString strtmp;
        qint32 s32tmp;
        Real realtmp;
        bool booltmp;

        blockApplySettings(true);
        m_channelMarker.blockSignals(true);

        d.readBlob(6, &bytetmp);
        m_channelMarker.deserialize(bytetmp);

        d.readS32(2, &s32tmp, 0);
        m_channelMarker.setCenterFrequency(s32tmp);

        d.readS32(3, &s32tmp, UDPSinkSettings::FormatS16LE);
        setSampleFormat(s32tmp);
        d.readReal(4, &realtmp, 48000);
        m_settings.m_inputSampleRate = realtmp;
        d.readReal(5, &realtmp, 32000);
        m_settings.m_rfBandwidth = realtmp;
        d.readBlob(7, &bytetmp);
        ui->spectrumGUI->deserialize(bytetmp);
        d.readS32(10, &s32tmp, 10);
        ui->gainOut->setValue(s32tmp);
        ui->gainOutText->setText(tr("%1").arg(s32tmp/10.0, 0, 'f', 1));
        d.readS32(11, &s32tmp, 2500);
        m_settings.m_fmDeviation = s32tmp * 1.0;
        d.readBool(13, &booltmp, true);
        ui->stereoInput->setChecked(booltmp);
        d.readS32(14, &s32tmp, -60);
        ui->squelch->setValue(s32tmp);
        ui->squelchText->setText(tr("%1").arg(s32tmp*1.0, 0, 'f', 0));
        d.readS32(15, &s32tmp, 5);
        ui->squelchGate->setValue(s32tmp);
        ui->squelchGateText->setText(tr("%1").arg(s32tmp*10.0, 0, 'f', 0));
        d.readBool(16, &booltmp, true);
        ui->autoRWBalance->setChecked(booltmp);
        d.readS32(17, &s32tmp, 10);
        ui->gainIn->setValue(s32tmp);
        ui->gainInText->setText(tr("%1").arg(s32tmp/10.0, 0, 'f', 1));

        blockApplySettings(false);
        m_channelMarker.blockSignals(false);

        this->setWindowTitle(m_channelMarker.getTitle());
        displaySettings();
        applySettings(true);
        return true;
    }
    else
    {
        resetToDefaults();
        return false;
    }
}

bool UDPSinkGUI::handleMessage(const Message& message __attribute__((unused)))
{
    qDebug() << "UDPSinkGUI::handleMessage";
    return false;
}

void UDPSinkGUI::handleSourceMessages()
{
    Message* message;

    while ((message = getInputMessageQueue()->pop()) != 0)
    {
        if (handleMessage(*message))
        {
            delete message;
        }
    }
}

UDPSinkGUI::UDPSinkGUI(PluginAPI* pluginAPI, DeviceSinkAPI *deviceAPI, QWidget* parent) :
        RollupWidget(parent),
        ui(new Ui::UDPSinkGUI),
        m_pluginAPI(pluginAPI),
        m_deviceAPI(deviceAPI),
        m_channelPowerAvg(4, 1e-10),
        m_inPowerAvg(4, 1e-10),
        m_tickCount(0),
        m_channelMarker(this),
        m_doApplySettings(true)
{
    ui->setupUi(this);
    connect(this, SIGNAL(widgetRolled(QWidget*,bool)), this, SLOT(onWidgetRolled(QWidget*,bool)));
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onMenuDialogCalled(const QPoint &)));
    setAttribute(Qt::WA_DeleteOnClose, true);

    m_spectrumVis = new SpectrumVis(ui->glSpectrum);
    m_udpSink = new UDPSink(m_pluginAPI->getMainWindowMessageQueue(), this, m_spectrumVis);
    m_udpSink->setMessageQueueToGUI(getInputMessageQueue());
    m_channelizer = new UpChannelizer(m_udpSink);
    m_threadedChannelizer = new ThreadedBasebandSampleSource(m_channelizer, this);
    m_deviceAPI->addThreadedSource(m_threadedChannelizer);

    ui->fmDeviation->setEnabled(false);
    ui->deltaFrequencyLabel->setText(QString("%1f").arg(QChar(0x94, 0x03)));
    ui->deltaFrequency->setColorMapper(ColorMapper(ColorMapper::GrayGold));
    ui->deltaFrequency->setValueRange(false, 7, -9999999, 9999999);

    ui->glSpectrum->setCenterFrequency(0);
    ui->glSpectrum->setSampleRate(ui->sampleRate->text().toInt());
    ui->glSpectrum->setDisplayWaterfall(true);
    ui->glSpectrum->setDisplayMaxHold(true);
    m_spectrumVis->configure(m_spectrumVis->getInputMessageQueue(), 64, 10, FFTWindow::BlackmanHarris);

    ui->glSpectrum->connectTimer(m_pluginAPI->getMainWindow()->getMasterTimer());
    connect(&m_pluginAPI->getMainWindow()->getMasterTimer(), SIGNAL(timeout()), this, SLOT(tick()));

    //m_channelMarker = new ChannelMarker(this);
    m_channelMarker.setBandwidth(16000);
    m_channelMarker.setCenterFrequency(0);
    m_channelMarker.setColor(Qt::green);
    m_channelMarker.setTitle("UDP Sample Sink");
    m_channelMarker.setVisible(true);

    connect(&m_channelMarker, SIGNAL(changed()), this, SLOT(channelMarkerChanged()));

    m_deviceAPI->registerChannelInstance(m_channelID, this);
    m_deviceAPI->addChannelMarker(&m_channelMarker);
    m_deviceAPI->addRollupWidget(this);

    ui->spectrumGUI->setBuddies(m_spectrumVis->getInputMessageQueue(), m_spectrumVis, ui->glSpectrum);

    displaySettings();
    applySettings(true);

    connect(getInputMessageQueue(), SIGNAL(messageEnqueued()), this, SLOT(handleSourceMessages()));
    connect(m_udpSink, SIGNAL(levelChanged(qreal, qreal, int)), ui->volumeMeter, SLOT(levelChanged(qreal, qreal, int)));
}

UDPSinkGUI::~UDPSinkGUI()
{
    m_deviceAPI->removeChannelInstance(this);
    m_deviceAPI->removeThreadedSource(m_threadedChannelizer);
    delete m_threadedChannelizer;
    delete m_channelizer;
    delete m_udpSink;
    delete m_spectrumVis;
    delete ui;
}

void UDPSinkGUI::blockApplySettings(bool block)
{
    m_doApplySettings = !block;
}

void UDPSinkGUI::applySettings(bool force)
{
    if (m_doApplySettings)
    {
        setTitleColor(m_channelMarker.getColor());
        ui->deltaFrequency->setValue(m_channelMarker.getCenterFrequency());
        m_channelMarker.blockSignals(true);
        m_channelMarker.setBandwidth((int)m_settings.m_rfBandwidth);
        m_channelMarker.blockSignals(false);
        ui->glSpectrum->setSampleRate(m_settings.m_inputSampleRate);

        m_channelizer->configure(m_channelizer->getInputMessageQueue(),
                m_settings.m_inputSampleRate,
                m_channelMarker.getCenterFrequency());

        m_udpSink->configure(m_udpSink->getInputMessageQueue(),
            m_settings.m_sampleFormat,
            m_settings.m_inputSampleRate,
            m_settings.m_rfBandwidth,
            m_settings.m_fmDeviation,
            m_settings.m_amModFactor,
            m_channelMarker.getUDPAddress(),
            m_channelMarker.getUDPReceivePort(),
            ui->channelMute->isChecked(),
            ui->gainIn->value() / 10.0f,
            ui->gainOut->value() / 10.0f,
            ui->squelch->value() * 1.0f,
            ui->squelchGate->value() * 0.01f,
            ui->squelch->value() != -100,
            ui->autoRWBalance->isChecked(),
            ui->stereoInput->isChecked(),
            force);

        ui->applyBtn->setEnabled(false);
        ui->applyBtn->setStyleSheet("QPushButton { background:rgb(79,79,79); }");
    }
}

void UDPSinkGUI::displaySettings()
{
    ui->sampleRate->setText(QString("%1").arg(roundf(m_settings.m_inputSampleRate), 0));
    ui->rfBandwidth->setText(QString("%1").arg(roundf(m_settings.m_rfBandwidth), 0));
    ui->fmDeviation->setText(QString("%1").arg(m_settings.m_fmDeviation, 0));
    ui->amModPercent->setText(QString("%1").arg(roundf(m_settings.m_amModFactor), 0));

    setSampleFormatIndex(m_settings.m_sampleFormat);

    ui->gainInText->setText(tr("%1").arg(ui->gainIn->value()/10.0, 0, 'f', 1));
    ui->gainOutText->setText(tr("%1").arg(ui->gainOut->value()/10.0, 0, 'f', 1));
    ui->squelchText->setText(tr("%1").arg(ui->squelch->value()*1.0, 0, 'f', 0));
    ui->squelchGateText->setText(tr("%1").arg(ui->squelchGate->value()*10.0, 0, 'f', 0));
    ui->addressText->setText(tr("%1:%2").arg(m_channelMarker.getUDPAddress()).arg(m_channelMarker.getUDPReceivePort()));
}

void UDPSinkGUI::channelMarkerChanged()
{
    this->setWindowTitle(m_channelMarker.getTitle());
    displaySettings();
    applySettings();
}

void UDPSinkGUI::on_deltaFrequency_changed(qint64 value)
{
    m_channelMarker.setCenterFrequency(value);
}

void UDPSinkGUI::on_sampleFormat_currentIndexChanged(int index)
{
    if ((index == (int) UDPSinkSettings::FormatNFM)) {
        ui->fmDeviation->setEnabled(true);
    } else {
        ui->fmDeviation->setEnabled(false);
    }

    if (index == (int) UDPSinkSettings::FormatAM) {
        ui->amModPercent->setEnabled(true);
    } else {
        ui->amModPercent->setEnabled(false);
    }

    setSampleFormat(index);

    ui->applyBtn->setEnabled(true);
    ui->applyBtn->setStyleSheet("QPushButton { background-color : green; }");
}

void UDPSinkGUI::on_sampleRate_textEdited(const QString& arg1 __attribute__((unused)))
{
    bool ok;
    Real inputSampleRate = ui->sampleRate->text().toDouble(&ok);

    if ((!ok) || (inputSampleRate < 1000)) {
        m_settings.m_inputSampleRate = 48000;
        ui->sampleRate->setText(QString("%1").arg(m_settings.m_inputSampleRate, 0));
    } else {
        m_settings.m_inputSampleRate = inputSampleRate;
    }

    ui->applyBtn->setEnabled(true);
    ui->applyBtn->setStyleSheet("QPushButton { background-color : green; }");
}

void UDPSinkGUI::on_rfBandwidth_textEdited(const QString& arg1 __attribute__((unused)))
{
    bool ok;
    Real rfBandwidth = ui->rfBandwidth->text().toDouble(&ok);

    if ((!ok) || (rfBandwidth > m_settings.m_inputSampleRate)) {
        m_settings.m_rfBandwidth = m_settings.m_inputSampleRate;
        ui->rfBandwidth->setText(QString("%1").arg(m_settings.m_rfBandwidth, 0));
    } else {
        m_settings.m_rfBandwidth = rfBandwidth;
    }

    ui->applyBtn->setEnabled(true);
    ui->applyBtn->setStyleSheet("QPushButton { background-color : green; }");
}

void UDPSinkGUI::on_fmDeviation_textEdited(const QString& arg1 __attribute__((unused)))
{
    bool ok;
    int fmDeviation = ui->fmDeviation->text().toInt(&ok);

    if ((!ok) || (fmDeviation < 1)) {
        m_settings.m_fmDeviation = 2500;
        ui->fmDeviation->setText(QString("%1").arg(m_settings.m_fmDeviation));
    } else {
        m_settings.m_fmDeviation = fmDeviation;
    }

    ui->applyBtn->setEnabled(true);
    ui->applyBtn->setStyleSheet("QPushButton { background-color : green; }");
}

void UDPSinkGUI::on_amModPercent_textEdited(const QString& arg1 __attribute__((unused)))
{
    bool ok;
    int amModPercent = ui->amModPercent->text().toInt(&ok);

    if ((!ok) || (amModPercent < 1) || (amModPercent > 100))
    {
        m_settings.m_amModFactor = 0.95;
        ui->amModPercent->setText(QString("%1").arg(95));
    } else {
        m_settings.m_amModFactor = amModPercent / 100.0;
    }

    ui->applyBtn->setEnabled(true);
    ui->applyBtn->setStyleSheet("QPushButton { background-color : green; }");
}

void UDPSinkGUI::on_gainIn_valueChanged(int value)
{
    ui->gainInText->setText(tr("%1").arg(value/10.0, 0, 'f', 1));
    applySettings();
}

void UDPSinkGUI::on_gainOut_valueChanged(int value)
{
    ui->gainOutText->setText(tr("%1").arg(value/10.0, 0, 'f', 1));
    applySettings();
}

void UDPSinkGUI::on_squelch_valueChanged(int value)
{
    if (value == -100) // means disabled
    {
        ui->squelchText->setText("---");
    }
    else
    {
        ui->squelchText->setText(tr("%1").arg(value*1.0, 0, 'f', 0));
    }

    applySettings();
}

void UDPSinkGUI::on_squelchGate_valueChanged(int value)
{
    ui->squelchGateText->setText(tr("%1").arg(value*10.0, 0, 'f', 0));
    applySettings();
}

void UDPSinkGUI::on_channelMute_toggled(bool checked __attribute__((unused)))
{
    applySettings();
}

void UDPSinkGUI::on_applyBtn_clicked()
{
    applySettings();
}

void UDPSinkGUI::on_resetUDPReadIndex_clicked()
{
    m_udpSink->resetReadIndex(m_udpSink->getInputMessageQueue());
}

void UDPSinkGUI::on_autoRWBalance_toggled(bool checked __attribute__((unused)))
{
    applySettings();
}

void UDPSinkGUI::on_stereoInput_toggled(bool checked __attribute__((unused)))
{
    applySettings();
}

void UDPSinkGUI::onWidgetRolled(QWidget* widget, bool rollDown)
{
    if ((widget == ui->spectrumBox) && (m_udpSink != 0))
    {
        m_udpSink->setSpectrum(m_udpSink->getInputMessageQueue(), rollDown);
    }
}

void UDPSinkGUI::onMenuDialogCalled(const QPoint &p)
{
    BasicChannelSettingsDialog dialog(&m_channelMarker, this);
    dialog.move(p);
    dialog.exec();
}

void UDPSinkGUI::leaveEvent(QEvent*)
{
    blockApplySettings(true);
    m_channelMarker.setHighlighted(false);
    blockApplySettings(false);
}

void UDPSinkGUI::enterEvent(QEvent*)
{
    blockApplySettings(true);
    m_channelMarker.setHighlighted(true);
    blockApplySettings(false);
}

void UDPSinkGUI::tick()
{
    m_channelPowerAvg.feed(m_udpSink->getMagSq());
    m_inPowerAvg.feed(m_udpSink->getInMagSq());

    if (m_tickCount % 4 == 0)
    {
        double powDb = CalcDb::dbPower(m_channelPowerAvg.average());
        ui->channelPower->setText(tr("%1 dB").arg(powDb, 0, 'f', 1));
        double inPowDb = CalcDb::dbPower(m_inPowerAvg.average());
        ui->inputPower->setText(tr("%1").arg(inPowDb, 0, 'f', 1));
    }

    int32_t bufferGauge = m_udpSink->getBufferGauge();
    ui->bufferGaugeNegative->setValue((bufferGauge < 0 ? -bufferGauge : 0));
    ui->bufferGaugePositive->setValue((bufferGauge < 0 ? 0 : bufferGauge));
    QString s = QString::number(bufferGauge, 'f', 0);
    ui->bufferRWBalanceText->setText(tr("%1").arg(s));

    if (m_udpSink->getSquelchOpen()) {
        ui->channelMute->setStyleSheet("QToolButton { background-color : green; }");
    } else {
        ui->channelMute->setStyleSheet("QToolButton { background:rgb(79,79,79); }");
    }

    m_tickCount++;
}

void UDPSinkGUI::setSampleFormatIndex(const UDPSinkSettings::SampleFormat& sampleFormat)
{
    switch(sampleFormat)
    {
        case UDPSinkSettings::FormatS16LE:
            ui->sampleFormat->setCurrentIndex(0);
            break;
        case UDPSinkSettings::FormatNFM:
            ui->sampleFormat->setCurrentIndex(1);
            break;
        case UDPSinkSettings::FormatLSB:
            ui->sampleFormat->setCurrentIndex(2);
            break;
        case UDPSinkSettings::FormatUSB:
            ui->sampleFormat->setCurrentIndex(3);
            break;
        case UDPSinkSettings::FormatAM:
            ui->sampleFormat->setCurrentIndex(4);
            break;
        default:
            ui->sampleFormat->setCurrentIndex(0);
            break;
    }
}

void UDPSinkGUI::setSampleFormat(int index)
{
    switch(index)
    {
    case 0:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatS16LE;
        ui->fmDeviation->setEnabled(false);
        ui->stereoInput->setChecked(true);
        ui->stereoInput->setEnabled(false);
        break;
    case 1:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatNFM;
        ui->fmDeviation->setEnabled(true);
        ui->stereoInput->setEnabled(true);
        break;
    case 2:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatLSB;
        ui->fmDeviation->setEnabled(false);
        ui->stereoInput->setEnabled(true);
        break;
    case 3:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatUSB;
        ui->fmDeviation->setEnabled(false);
        ui->stereoInput->setEnabled(true);
        break;
    case 4:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatAM;
        ui->fmDeviation->setEnabled(false);
        ui->stereoInput->setEnabled(true);
        break;
    default:
        m_settings.m_sampleFormat = UDPSinkSettings::FormatS16LE;
        ui->fmDeviation->setEnabled(false);
        ui->stereoInput->setChecked(true);
        ui->stereoInput->setEnabled(false);
        break;
    }
}


