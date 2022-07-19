/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 7.0.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGSDRPlayV3Settings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGSDRPlayV3Settings::SWGSDRPlayV3Settings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGSDRPlayV3Settings::SWGSDRPlayV3Settings() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    if_frequency_index = 0;
    m_if_frequency_index_isSet = false;
    bandwidth_index = 0;
    m_bandwidth_index_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    lna_index = 0;
    m_lna_index_isSet = false;
    if_agc = 0;
    m_if_agc_isSet = false;
    if_gain = 0;
    m_if_gain_isSet = false;
    am_notch = 0;
    m_am_notch_isSet = false;
    fm_notch = 0;
    m_fm_notch_isSet = false;
    dab_notch = 0;
    m_dab_notch_isSet = false;
    ext_ref = 0;
    m_ext_ref_isSet = false;
    tuner = 0;
    m_tuner_isSet = false;
    antenna = 0;
    m_antenna_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    bias_tee = 0;
    m_bias_tee_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGSDRPlayV3Settings::~SWGSDRPlayV3Settings() {
    this->cleanup();
}

void
SWGSDRPlayV3Settings::init() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    if_frequency_index = 0;
    m_if_frequency_index_isSet = false;
    bandwidth_index = 0;
    m_bandwidth_index_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    log2_decim = 0;
    m_log2_decim_isSet = false;
    fc_pos = 0;
    m_fc_pos_isSet = false;
    dc_block = 0;
    m_dc_block_isSet = false;
    iq_correction = 0;
    m_iq_correction_isSet = false;
    lna_index = 0;
    m_lna_index_isSet = false;
    if_agc = 0;
    m_if_agc_isSet = false;
    if_gain = 0;
    m_if_gain_isSet = false;
    am_notch = 0;
    m_am_notch_isSet = false;
    fm_notch = 0;
    m_fm_notch_isSet = false;
    dab_notch = 0;
    m_dab_notch_isSet = false;
    ext_ref = 0;
    m_ext_ref_isSet = false;
    tuner = 0;
    m_tuner_isSet = false;
    antenna = 0;
    m_antenna_isSet = false;
    transverter_mode = 0;
    m_transverter_mode_isSet = false;
    transverter_delta_frequency = 0L;
    m_transverter_delta_frequency_isSet = false;
    iq_order = 0;
    m_iq_order_isSet = false;
    bias_tee = 0;
    m_bias_tee_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = new QString("");
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

void
SWGSDRPlayV3Settings::cleanup() {























    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGSDRPlayV3Settings*
SWGSDRPlayV3Settings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGSDRPlayV3Settings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGSDRangel::setValue(&if_frequency_index, pJson["ifFrequencyIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&bandwidth_index, pJson["bandwidthIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_decim, pJson["log2Decim"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fc_pos, pJson["fcPos"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dc_block, pJson["dcBlock"], "qint32", "");
    
    ::SWGSDRangel::setValue(&iq_correction, pJson["iqCorrection"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lna_index, pJson["lnaIndex"], "qint32", "");
    
    ::SWGSDRangel::setValue(&if_agc, pJson["ifAGC"], "qint32", "");
    
    ::SWGSDRangel::setValue(&if_gain, pJson["ifGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&am_notch, pJson["amNotch"], "qint32", "");
    
    ::SWGSDRangel::setValue(&fm_notch, pJson["fmNotch"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dab_notch, pJson["dabNotch"], "qint32", "");
    
    ::SWGSDRangel::setValue(&ext_ref, pJson["extRef"], "qint32", "");
    
    ::SWGSDRangel::setValue(&tuner, pJson["tuner"], "qint32", "");
    
    ::SWGSDRangel::setValue(&antenna, pJson["antenna"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_mode, pJson["transverterMode"], "qint32", "");
    
    ::SWGSDRangel::setValue(&transverter_delta_frequency, pJson["transverterDeltaFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&iq_order, pJson["iqOrder"], "qint32", "");
    
    ::SWGSDRangel::setValue(&bias_tee, pJson["biasTee"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGSDRPlayV3Settings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGSDRPlayV3Settings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_if_frequency_index_isSet){
        obj->insert("ifFrequencyIndex", QJsonValue(if_frequency_index));
    }
    if(m_bandwidth_index_isSet){
        obj->insert("bandwidthIndex", QJsonValue(bandwidth_index));
    }
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_log2_decim_isSet){
        obj->insert("log2Decim", QJsonValue(log2_decim));
    }
    if(m_fc_pos_isSet){
        obj->insert("fcPos", QJsonValue(fc_pos));
    }
    if(m_dc_block_isSet){
        obj->insert("dcBlock", QJsonValue(dc_block));
    }
    if(m_iq_correction_isSet){
        obj->insert("iqCorrection", QJsonValue(iq_correction));
    }
    if(m_lna_index_isSet){
        obj->insert("lnaIndex", QJsonValue(lna_index));
    }
    if(m_if_agc_isSet){
        obj->insert("ifAGC", QJsonValue(if_agc));
    }
    if(m_if_gain_isSet){
        obj->insert("ifGain", QJsonValue(if_gain));
    }
    if(m_am_notch_isSet){
        obj->insert("amNotch", QJsonValue(am_notch));
    }
    if(m_fm_notch_isSet){
        obj->insert("fmNotch", QJsonValue(fm_notch));
    }
    if(m_dab_notch_isSet){
        obj->insert("dabNotch", QJsonValue(dab_notch));
    }
    if(m_ext_ref_isSet){
        obj->insert("extRef", QJsonValue(ext_ref));
    }
    if(m_tuner_isSet){
        obj->insert("tuner", QJsonValue(tuner));
    }
    if(m_antenna_isSet){
        obj->insert("antenna", QJsonValue(antenna));
    }
    if(m_transverter_mode_isSet){
        obj->insert("transverterMode", QJsonValue(transverter_mode));
    }
    if(m_transverter_delta_frequency_isSet){
        obj->insert("transverterDeltaFrequency", QJsonValue(transverter_delta_frequency));
    }
    if(m_iq_order_isSet){
        obj->insert("iqOrder", QJsonValue(iq_order));
    }
    if(m_bias_tee_isSet){
        obj->insert("biasTee", QJsonValue(bias_tee));
    }
    if(m_use_reverse_api_isSet){
        obj->insert("useReverseAPI", QJsonValue(use_reverse_api));
    }
    if(reverse_api_address != nullptr && *reverse_api_address != QString("")){
        toJsonValue(QString("reverseAPIAddress"), reverse_api_address, obj, QString("QString"));
    }
    if(m_reverse_api_port_isSet){
        obj->insert("reverseAPIPort", QJsonValue(reverse_api_port));
    }
    if(m_reverse_api_device_index_isSet){
        obj->insert("reverseAPIDeviceIndex", QJsonValue(reverse_api_device_index));
    }

    return obj;
}

qint64
SWGSDRPlayV3Settings::getCenterFrequency() {
    return center_frequency;
}
void
SWGSDRPlayV3Settings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGSDRPlayV3Settings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getIfFrequencyIndex() {
    return if_frequency_index;
}
void
SWGSDRPlayV3Settings::setIfFrequencyIndex(qint32 if_frequency_index) {
    this->if_frequency_index = if_frequency_index;
    this->m_if_frequency_index_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getBandwidthIndex() {
    return bandwidth_index;
}
void
SWGSDRPlayV3Settings::setBandwidthIndex(qint32 bandwidth_index) {
    this->bandwidth_index = bandwidth_index;
    this->m_bandwidth_index_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGSDRPlayV3Settings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getLog2Decim() {
    return log2_decim;
}
void
SWGSDRPlayV3Settings::setLog2Decim(qint32 log2_decim) {
    this->log2_decim = log2_decim;
    this->m_log2_decim_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getFcPos() {
    return fc_pos;
}
void
SWGSDRPlayV3Settings::setFcPos(qint32 fc_pos) {
    this->fc_pos = fc_pos;
    this->m_fc_pos_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getDcBlock() {
    return dc_block;
}
void
SWGSDRPlayV3Settings::setDcBlock(qint32 dc_block) {
    this->dc_block = dc_block;
    this->m_dc_block_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getIqCorrection() {
    return iq_correction;
}
void
SWGSDRPlayV3Settings::setIqCorrection(qint32 iq_correction) {
    this->iq_correction = iq_correction;
    this->m_iq_correction_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getLnaIndex() {
    return lna_index;
}
void
SWGSDRPlayV3Settings::setLnaIndex(qint32 lna_index) {
    this->lna_index = lna_index;
    this->m_lna_index_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getIfAgc() {
    return if_agc;
}
void
SWGSDRPlayV3Settings::setIfAgc(qint32 if_agc) {
    this->if_agc = if_agc;
    this->m_if_agc_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getIfGain() {
    return if_gain;
}
void
SWGSDRPlayV3Settings::setIfGain(qint32 if_gain) {
    this->if_gain = if_gain;
    this->m_if_gain_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getAmNotch() {
    return am_notch;
}
void
SWGSDRPlayV3Settings::setAmNotch(qint32 am_notch) {
    this->am_notch = am_notch;
    this->m_am_notch_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getFmNotch() {
    return fm_notch;
}
void
SWGSDRPlayV3Settings::setFmNotch(qint32 fm_notch) {
    this->fm_notch = fm_notch;
    this->m_fm_notch_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getDabNotch() {
    return dab_notch;
}
void
SWGSDRPlayV3Settings::setDabNotch(qint32 dab_notch) {
    this->dab_notch = dab_notch;
    this->m_dab_notch_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getExtRef() {
    return ext_ref;
}
void
SWGSDRPlayV3Settings::setExtRef(qint32 ext_ref) {
    this->ext_ref = ext_ref;
    this->m_ext_ref_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getTuner() {
    return tuner;
}
void
SWGSDRPlayV3Settings::setTuner(qint32 tuner) {
    this->tuner = tuner;
    this->m_tuner_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getAntenna() {
    return antenna;
}
void
SWGSDRPlayV3Settings::setAntenna(qint32 antenna) {
    this->antenna = antenna;
    this->m_antenna_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getTransverterMode() {
    return transverter_mode;
}
void
SWGSDRPlayV3Settings::setTransverterMode(qint32 transverter_mode) {
    this->transverter_mode = transverter_mode;
    this->m_transverter_mode_isSet = true;
}

qint64
SWGSDRPlayV3Settings::getTransverterDeltaFrequency() {
    return transverter_delta_frequency;
}
void
SWGSDRPlayV3Settings::setTransverterDeltaFrequency(qint64 transverter_delta_frequency) {
    this->transverter_delta_frequency = transverter_delta_frequency;
    this->m_transverter_delta_frequency_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getIqOrder() {
    return iq_order;
}
void
SWGSDRPlayV3Settings::setIqOrder(qint32 iq_order) {
    this->iq_order = iq_order;
    this->m_iq_order_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getBiasTee() {
    return bias_tee;
}
void
SWGSDRPlayV3Settings::setBiasTee(qint32 bias_tee) {
    this->bias_tee = bias_tee;
    this->m_bias_tee_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGSDRPlayV3Settings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGSDRPlayV3Settings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGSDRPlayV3Settings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGSDRPlayV3Settings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGSDRPlayV3Settings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGSDRPlayV3Settings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGSDRPlayV3Settings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_l_oppm_tenths_isSet){
            isObjectUpdated = true; break;
        }
        if(m_if_frequency_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_bandwidth_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dev_sample_rate_isSet){
            isObjectUpdated = true; break;
        }
        if(m_log2_decim_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fc_pos_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dc_block_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_correction_isSet){
            isObjectUpdated = true; break;
        }
        if(m_lna_index_isSet){
            isObjectUpdated = true; break;
        }
        if(m_if_agc_isSet){
            isObjectUpdated = true; break;
        }
        if(m_if_gain_isSet){
            isObjectUpdated = true; break;
        }
        if(m_am_notch_isSet){
            isObjectUpdated = true; break;
        }
        if(m_fm_notch_isSet){
            isObjectUpdated = true; break;
        }
        if(m_dab_notch_isSet){
            isObjectUpdated = true; break;
        }
        if(m_ext_ref_isSet){
            isObjectUpdated = true; break;
        }
        if(m_tuner_isSet){
            isObjectUpdated = true; break;
        }
        if(m_antenna_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_mode_isSet){
            isObjectUpdated = true; break;
        }
        if(m_transverter_delta_frequency_isSet){
            isObjectUpdated = true; break;
        }
        if(m_iq_order_isSet){
            isObjectUpdated = true; break;
        }
        if(m_bias_tee_isSet){
            isObjectUpdated = true; break;
        }
        if(m_use_reverse_api_isSet){
            isObjectUpdated = true; break;
        }
        if(reverse_api_address && *reverse_api_address != QString("")){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_port_isSet){
            isObjectUpdated = true; break;
        }
        if(m_reverse_api_device_index_isSet){
            isObjectUpdated = true; break;
        }
    }while(false);
    return isObjectUpdated;
}
}

