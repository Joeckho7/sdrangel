/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.5.2
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */


#include "SWGHackRFOutputSettings.h"

#include "SWGHelpers.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

namespace SWGSDRangel {

SWGHackRFOutputSettings::SWGHackRFOutputSettings(QString* json) {
    init();
    this->fromJson(*json);
}

SWGHackRFOutputSettings::SWGHackRFOutputSettings() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    bandwidth = 0;
    m_bandwidth_isSet = false;
    vga_gain = 0;
    m_vga_gain_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    bias_t = 0;
    m_bias_t_isSet = false;
    lna_ext = 0;
    m_lna_ext_isSet = false;
    use_reverse_api = 0;
    m_use_reverse_api_isSet = false;
    reverse_api_address = nullptr;
    m_reverse_api_address_isSet = false;
    reverse_api_port = 0;
    m_reverse_api_port_isSet = false;
    reverse_api_device_index = 0;
    m_reverse_api_device_index_isSet = false;
}

SWGHackRFOutputSettings::~SWGHackRFOutputSettings() {
    this->cleanup();
}

void
SWGHackRFOutputSettings::init() {
    center_frequency = 0L;
    m_center_frequency_isSet = false;
    l_oppm_tenths = 0;
    m_l_oppm_tenths_isSet = false;
    bandwidth = 0;
    m_bandwidth_isSet = false;
    vga_gain = 0;
    m_vga_gain_isSet = false;
    log2_interp = 0;
    m_log2_interp_isSet = false;
    dev_sample_rate = 0;
    m_dev_sample_rate_isSet = false;
    bias_t = 0;
    m_bias_t_isSet = false;
    lna_ext = 0;
    m_lna_ext_isSet = false;
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
SWGHackRFOutputSettings::cleanup() {









    if(reverse_api_address != nullptr) { 
        delete reverse_api_address;
    }


}

SWGHackRFOutputSettings*
SWGHackRFOutputSettings::fromJson(QString &json) {
    QByteArray array (json.toStdString().c_str());
    QJsonDocument doc = QJsonDocument::fromJson(array);
    QJsonObject jsonObject = doc.object();
    this->fromJsonObject(jsonObject);
    return this;
}

void
SWGHackRFOutputSettings::fromJsonObject(QJsonObject &pJson) {
    ::SWGSDRangel::setValue(&center_frequency, pJson["centerFrequency"], "qint64", "");
    
    ::SWGSDRangel::setValue(&l_oppm_tenths, pJson["LOppmTenths"], "qint32", "");
    
    ::SWGSDRangel::setValue(&bandwidth, pJson["bandwidth"], "qint32", "");
    
    ::SWGSDRangel::setValue(&vga_gain, pJson["vgaGain"], "qint32", "");
    
    ::SWGSDRangel::setValue(&log2_interp, pJson["log2Interp"], "qint32", "");
    
    ::SWGSDRangel::setValue(&dev_sample_rate, pJson["devSampleRate"], "qint32", "");
    
    ::SWGSDRangel::setValue(&bias_t, pJson["biasT"], "qint32", "");
    
    ::SWGSDRangel::setValue(&lna_ext, pJson["lnaExt"], "qint32", "");
    
    ::SWGSDRangel::setValue(&use_reverse_api, pJson["useReverseAPI"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_address, pJson["reverseAPIAddress"], "QString", "QString");
    
    ::SWGSDRangel::setValue(&reverse_api_port, pJson["reverseAPIPort"], "qint32", "");
    
    ::SWGSDRangel::setValue(&reverse_api_device_index, pJson["reverseAPIDeviceIndex"], "qint32", "");
    
}

QString
SWGHackRFOutputSettings::asJson ()
{
    QJsonObject* obj = this->asJsonObject();

    QJsonDocument doc(*obj);
    QByteArray bytes = doc.toJson();
    delete obj;
    return QString(bytes);
}

QJsonObject*
SWGHackRFOutputSettings::asJsonObject() {
    QJsonObject* obj = new QJsonObject();
    if(m_center_frequency_isSet){
        obj->insert("centerFrequency", QJsonValue(center_frequency));
    }
    if(m_l_oppm_tenths_isSet){
        obj->insert("LOppmTenths", QJsonValue(l_oppm_tenths));
    }
    if(m_bandwidth_isSet){
        obj->insert("bandwidth", QJsonValue(bandwidth));
    }
    if(m_vga_gain_isSet){
        obj->insert("vgaGain", QJsonValue(vga_gain));
    }
    if(m_log2_interp_isSet){
        obj->insert("log2Interp", QJsonValue(log2_interp));
    }
    if(m_dev_sample_rate_isSet){
        obj->insert("devSampleRate", QJsonValue(dev_sample_rate));
    }
    if(m_bias_t_isSet){
        obj->insert("biasT", QJsonValue(bias_t));
    }
    if(m_lna_ext_isSet){
        obj->insert("lnaExt", QJsonValue(lna_ext));
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
SWGHackRFOutputSettings::getCenterFrequency() {
    return center_frequency;
}
void
SWGHackRFOutputSettings::setCenterFrequency(qint64 center_frequency) {
    this->center_frequency = center_frequency;
    this->m_center_frequency_isSet = true;
}

qint32
SWGHackRFOutputSettings::getLOppmTenths() {
    return l_oppm_tenths;
}
void
SWGHackRFOutputSettings::setLOppmTenths(qint32 l_oppm_tenths) {
    this->l_oppm_tenths = l_oppm_tenths;
    this->m_l_oppm_tenths_isSet = true;
}

qint32
SWGHackRFOutputSettings::getBandwidth() {
    return bandwidth;
}
void
SWGHackRFOutputSettings::setBandwidth(qint32 bandwidth) {
    this->bandwidth = bandwidth;
    this->m_bandwidth_isSet = true;
}

qint32
SWGHackRFOutputSettings::getVgaGain() {
    return vga_gain;
}
void
SWGHackRFOutputSettings::setVgaGain(qint32 vga_gain) {
    this->vga_gain = vga_gain;
    this->m_vga_gain_isSet = true;
}

qint32
SWGHackRFOutputSettings::getLog2Interp() {
    return log2_interp;
}
void
SWGHackRFOutputSettings::setLog2Interp(qint32 log2_interp) {
    this->log2_interp = log2_interp;
    this->m_log2_interp_isSet = true;
}

qint32
SWGHackRFOutputSettings::getDevSampleRate() {
    return dev_sample_rate;
}
void
SWGHackRFOutputSettings::setDevSampleRate(qint32 dev_sample_rate) {
    this->dev_sample_rate = dev_sample_rate;
    this->m_dev_sample_rate_isSet = true;
}

qint32
SWGHackRFOutputSettings::getBiasT() {
    return bias_t;
}
void
SWGHackRFOutputSettings::setBiasT(qint32 bias_t) {
    this->bias_t = bias_t;
    this->m_bias_t_isSet = true;
}

qint32
SWGHackRFOutputSettings::getLnaExt() {
    return lna_ext;
}
void
SWGHackRFOutputSettings::setLnaExt(qint32 lna_ext) {
    this->lna_ext = lna_ext;
    this->m_lna_ext_isSet = true;
}

qint32
SWGHackRFOutputSettings::getUseReverseApi() {
    return use_reverse_api;
}
void
SWGHackRFOutputSettings::setUseReverseApi(qint32 use_reverse_api) {
    this->use_reverse_api = use_reverse_api;
    this->m_use_reverse_api_isSet = true;
}

QString*
SWGHackRFOutputSettings::getReverseApiAddress() {
    return reverse_api_address;
}
void
SWGHackRFOutputSettings::setReverseApiAddress(QString* reverse_api_address) {
    this->reverse_api_address = reverse_api_address;
    this->m_reverse_api_address_isSet = true;
}

qint32
SWGHackRFOutputSettings::getReverseApiPort() {
    return reverse_api_port;
}
void
SWGHackRFOutputSettings::setReverseApiPort(qint32 reverse_api_port) {
    this->reverse_api_port = reverse_api_port;
    this->m_reverse_api_port_isSet = true;
}

qint32
SWGHackRFOutputSettings::getReverseApiDeviceIndex() {
    return reverse_api_device_index;
}
void
SWGHackRFOutputSettings::setReverseApiDeviceIndex(qint32 reverse_api_device_index) {
    this->reverse_api_device_index = reverse_api_device_index;
    this->m_reverse_api_device_index_isSet = true;
}


bool
SWGHackRFOutputSettings::isSet(){
    bool isObjectUpdated = false;
    do{
        if(m_center_frequency_isSet){ isObjectUpdated = true; break;}
        if(m_l_oppm_tenths_isSet){ isObjectUpdated = true; break;}
        if(m_bandwidth_isSet){ isObjectUpdated = true; break;}
        if(m_vga_gain_isSet){ isObjectUpdated = true; break;}
        if(m_log2_interp_isSet){ isObjectUpdated = true; break;}
        if(m_dev_sample_rate_isSet){ isObjectUpdated = true; break;}
        if(m_bias_t_isSet){ isObjectUpdated = true; break;}
        if(m_lna_ext_isSet){ isObjectUpdated = true; break;}
        if(m_use_reverse_api_isSet){ isObjectUpdated = true; break;}
        if(reverse_api_address != nullptr && *reverse_api_address != QString("")){ isObjectUpdated = true; break;}
        if(m_reverse_api_port_isSet){ isObjectUpdated = true; break;}
        if(m_reverse_api_device_index_isSet){ isObjectUpdated = true; break;}
    }while(false);
    return isObjectUpdated;
}
}

