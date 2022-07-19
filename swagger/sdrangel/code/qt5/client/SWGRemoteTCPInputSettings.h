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

/*
 * SWGRemoteTCPInputSettings.h
 *
 * RemoteTCPInput
 */

#ifndef SWGRemoteTCPInputSettings_H_
#define SWGRemoteTCPInputSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGRemoteTCPInputSettings: public SWGObject {
public:
    SWGRemoteTCPInputSettings();
    SWGRemoteTCPInputSettings(QString* json);
    virtual ~SWGRemoteTCPInputSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGRemoteTCPInputSettings* fromJson(QString &jsonString) override;

    qint64 getCenterFrequency();
    void setCenterFrequency(qint64 center_frequency);

    qint32 getLoPpmCorrection();
    void setLoPpmCorrection(qint32 lo_ppm_correction);

    qint32 getDcBlock();
    void setDcBlock(qint32 dc_block);

    qint32 getIqCorrection();
    void setIqCorrection(qint32 iq_correction);

    qint32 getBiasTee();
    void setBiasTee(qint32 bias_tee);

    qint32 getDirectSampling();
    void setDirectSampling(qint32 direct_sampling);

    qint32 getDevSampleRate();
    void setDevSampleRate(qint32 dev_sample_rate);

    qint32 getLog2Decim();
    void setLog2Decim(qint32 log2_decim);

    qint32 getGain();
    void setGain(qint32 gain);

    qint32 getAgc();
    void setAgc(qint32 agc);

    qint32 getRfBw();
    void setRfBw(qint32 rf_bw);

    qint64 getInputFrequencyOffset();
    void setInputFrequencyOffset(qint64 input_frequency_offset);

    qint32 getChannelGain();
    void setChannelGain(qint32 channel_gain);

    qint32 getChannelSampleRate();
    void setChannelSampleRate(qint32 channel_sample_rate);

    qint32 getChannelDecimation();
    void setChannelDecimation(qint32 channel_decimation);

    qint32 getSampleBits();
    void setSampleBits(qint32 sample_bits);

    QString* getDataAddress();
    void setDataAddress(QString* data_address);

    qint32 getDataPort();
    void setDataPort(qint32 data_port);

    qint32 getOverrideRemoteSettings();
    void setOverrideRemoteSettings(qint32 override_remote_settings);

    qint32 getPreFill();
    void setPreFill(qint32 pre_fill);

    qint32 getUseReverseApi();
    void setUseReverseApi(qint32 use_reverse_api);

    QString* getReverseApiAddress();
    void setReverseApiAddress(QString* reverse_api_address);

    qint32 getReverseApiPort();
    void setReverseApiPort(qint32 reverse_api_port);

    qint32 getReverseApiDeviceIndex();
    void setReverseApiDeviceIndex(qint32 reverse_api_device_index);


    virtual bool isSet() override;

private:
    qint64 center_frequency;
    bool m_center_frequency_isSet;

    qint32 lo_ppm_correction;
    bool m_lo_ppm_correction_isSet;

    qint32 dc_block;
    bool m_dc_block_isSet;

    qint32 iq_correction;
    bool m_iq_correction_isSet;

    qint32 bias_tee;
    bool m_bias_tee_isSet;

    qint32 direct_sampling;
    bool m_direct_sampling_isSet;

    qint32 dev_sample_rate;
    bool m_dev_sample_rate_isSet;

    qint32 log2_decim;
    bool m_log2_decim_isSet;

    qint32 gain;
    bool m_gain_isSet;

    qint32 agc;
    bool m_agc_isSet;

    qint32 rf_bw;
    bool m_rf_bw_isSet;

    qint64 input_frequency_offset;
    bool m_input_frequency_offset_isSet;

    qint32 channel_gain;
    bool m_channel_gain_isSet;

    qint32 channel_sample_rate;
    bool m_channel_sample_rate_isSet;

    qint32 channel_decimation;
    bool m_channel_decimation_isSet;

    qint32 sample_bits;
    bool m_sample_bits_isSet;

    QString* data_address;
    bool m_data_address_isSet;

    qint32 data_port;
    bool m_data_port_isSet;

    qint32 override_remote_settings;
    bool m_override_remote_settings_isSet;

    qint32 pre_fill;
    bool m_pre_fill_isSet;

    qint32 use_reverse_api;
    bool m_use_reverse_api_isSet;

    QString* reverse_api_address;
    bool m_reverse_api_address_isSet;

    qint32 reverse_api_port;
    bool m_reverse_api_port_isSet;

    qint32 reverse_api_device_index;
    bool m_reverse_api_device_index_isSet;

};

}

#endif /* SWGRemoteTCPInputSettings_H_ */
