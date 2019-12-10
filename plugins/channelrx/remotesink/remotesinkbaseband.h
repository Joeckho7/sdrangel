///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2019 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#ifndef INCLUDE_REMOTESINKBASEBAND_H
#define INCLUDE_REMOTESINKBASEBAND_H

#include <QObject>
#include <QMutex>

#include "dsp/samplesinkfifo.h"
#include "util/message.h"
#include "util/messagequeue.h"

#include "remotesinksink.h"
#include "remotesinksettings.h"

class DownSampleChannelizer;

class RemoteSinkBaseband : public QObject
{
    Q_OBJECT
public:
    class MsgConfigureRemoteSinkBaseband : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        const RemoteSinkSettings& getSettings() const { return m_settings; }
        bool getForce() const { return m_force; }

        static MsgConfigureRemoteSinkBaseband* create(const RemoteSinkSettings& settings, bool force)
        {
            return new MsgConfigureRemoteSinkBaseband(settings, force);
        }

    private:
        RemoteSinkSettings m_settings;
        bool m_force;

        MsgConfigureRemoteSinkBaseband(const RemoteSinkSettings& settings, bool force) :
            Message(),
            m_settings(settings),
            m_force(force)
        { }
    };

    class MsgBasebandSampleRateNotification : public Message {
        MESSAGE_CLASS_DECLARATION

    public:
        static MsgBasebandSampleRateNotification* create(int sampleRate) {
            return new MsgBasebandSampleRateNotification(sampleRate);
        }

        int getBasebandSampleRate() const { return m_basebandSampleRate; }

    private:

        MsgBasebandSampleRateNotification(int sampleRate) :
            Message(),
            m_basebandSampleRate(sampleRate)
        { }

        int m_basebandSampleRate;
    };

    RemoteSinkBaseband();
    ~RemoteSinkBaseband();
    void reset();
	void feed(const SampleVector::const_iterator& begin, const SampleVector::const_iterator& end);
    MessageQueue *getInputMessageQueue() { return &m_inputMessageQueue; } //!< Get the queue for asynchronous inbound communication
    int getChannelSampleRate() const;
    void startSink() { m_sink.start(); }
    void stopSink() { m_sink.stop(); }

private:
    SampleSinkFifo m_sampleFifo;
    DownSampleChannelizer *m_channelizer;
    RemoteSinkSink m_sink;
	MessageQueue m_inputMessageQueue; //!< Queue for asynchronous inbound communication
    RemoteSinkSettings m_settings;
    DeviceSampleSource *m_localSampleSource;
    QMutex m_mutex;

    bool handleMessage(const Message& cmd);
    void applySettings(const RemoteSinkSettings& settings, bool force = false);

private slots:
    void handleInputMessages();
    void handleData(); //!< Handle data when samples have to be processed
};


#endif // INCLUDE_REMOTESINKBASEBAND_H
