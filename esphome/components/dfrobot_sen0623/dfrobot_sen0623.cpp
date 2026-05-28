#include "dfrobot_sen0623.h"
#include "esphome/core/log.h"

#include "esphome/core/helpers.h"


std::pair<uint8_t, uint8_t> OP_RST_SENSOR = {0x01, 0x02};
std::pair<uint8_t, uint8_t> OP_INIT = {0x01, 0x83};
std::pair<uint8_t, uint8_t> OP_REQ_MODE = {0x02, 0xA8};
std::pair<uint8_t, uint8_t> OP_REQ_HEART_RATE = {0x85, 0x82};
std::pair<uint8_t, uint8_t> OP_REQ_BREATH_RATE = {0x81, 0x82};
std::pair<uint8_t, uint8_t> OP_REQ_HUMAN_PRESENCE = {0x80, 0x81};
std::pair<uint8_t, uint8_t> OP_REQ_HUMAN_MOVEMENT = {0x80, 0x82};
std::pair<uint8_t, uint8_t> OP_REQ_HUMAN_MOVE_RANGE = {0x80, 0x83};
std::pair<uint8_t, uint8_t> OP_REQ_HUMAN_DISTANCE = {0x80, 0x84};
std::pair<uint8_t, uint8_t> OP_SET_MODE = {0x02, 0x08};
uint8_t MODE_SLEEP = 0x02;
uint8_t MODE_FALL = 0x01;

std::pair<uint8_t, uint8_t> OP_REQ_FALL_LED = {0x01, 0x84};

std::pair<uint8_t, uint8_t> OP_SET_INSTALL_ANGLE = {0x06, 0x01};
std::pair<uint8_t, uint8_t> OP_REQ_INSTALL_ANGLE = {0x06, 0x81};
std::pair<uint8_t, uint8_t> OP_SET_INSTALL_HEIGHT = {0x06, 0x02};
std::pair<uint8_t, uint8_t> OP_REQ_INSTALL_HEIGHT = {0x06, 0x82};
std::pair<uint8_t, uint8_t> OP_AUTO_MEASURE_HEIGHT = {0x83, 0x90};


std::pair<uint8_t, uint8_t> OP_REQ_FALL_STATE = {0x83, 0x81};
std::pair<uint8_t, uint8_t> OP_REQ_STATIC_RESIDENCY_STATE = {0x83, 0x85};
std::pair<uint8_t, uint8_t> OP_REQ_STATIC_RESIDENCY_TIME = {0x83, 0x8A};
std::pair<uint8_t, uint8_t> OP_REQ_STATIC_RESIDENCY_SWITCH = {0x83, 0x8B};
std::pair<uint8_t, uint8_t> OP_REQ_FALL_TIME = {0x83, 0x8C};
std::pair<uint8_t, uint8_t> OP_REQ_FALL_SENSITIVITY = {0x83, 0x8D};
std::pair<uint8_t, uint8_t> OP_REQ_TRACK = {0x83, 0x8E};
std::pair<uint8_t, uint8_t> OP_REQ_ACCUMULATED_HEIGHT_DURATION = {0x83, 0x8F};
std::pair<uint8_t, uint8_t> OP_REQ_FALL_BREAK_HEIGHT = {0x83, 0x91};
std::pair<uint8_t, uint8_t> OP_REQ_TRACK_FREQUENCY = {0x83, 0x93};
std::pair<uint8_t, uint8_t> OP_REQ_TRAJECTORY_SWITCH = {0x83, 0x94};
std::pair<uint8_t, uint8_t> OP_REQ_HEIGHT_RATIO_SWITCH = {0x83, 0x95};

std::pair<uint8_t, uint8_t> OP_SET_FALL_SENSITIVITY = {0x83, 0x0D};
std::pair<uint8_t, uint8_t> OP_SET_RESIDENCE_TIME = {0x83, 0x0A};
std::pair<uint8_t, uint8_t> OP_SET_RESIDENCE_SWITCH = {0x83, 0x0B};
std::pair<uint8_t, uint8_t> OP_SET_ALT_TIME = {0x83, 0x0F};
std::pair<uint8_t, uint8_t> OP_SET_FALL_TIME = {0x83, 0x0C};
std::pair<uint8_t, uint8_t> OP_SET_FALL_BREAK_HEIGHT = {0x83, 0x11};
std::pair<uint8_t, uint8_t> OP_SET_REPORT_FREQUENCY = {0x83, 0x13};
std::pair<uint8_t, uint8_t> OP_SET_REPORT_SWITCH = {0x83, 0x14};
std::pair<uint8_t, uint8_t> OP_SET_HEIGHT_RATIO_SWITCH = {0x83, 0x15};

std::pair<uint8_t, uint8_t> OP_REQ_UNMANNED_TIME = {0x80, 0x92};
std::pair<uint8_t, uint8_t> OP_SET_UNMANNED_TIME = {0x80, 0x12};

std::pair<uint8_t, uint8_t> OP_SET_SEATED_DISTANCE = {0x80, 0x0D};
std::pair<uint8_t, uint8_t> OP_SET_MOTION_DISTANCE = {0x80, 0x0E};
std::pair<uint8_t, uint8_t> OP_REQ_SEATED_DISTANCE = {0x80, 0x8D};
std::pair<uint8_t, uint8_t> OP_REQ_MOTION_DISTANCE = {0x80, 0x8E};

std::pair<uint8_t, uint8_t> OP_SET_REPORTING_MODE = {0x84, 0x0F};
std::pair<uint8_t, uint8_t> OP_SET_ABNORMAL_STRUGGLE = {0x84, 0x13};
std::pair<uint8_t, uint8_t> OP_SET_UNATTENDED_STATE = {0x84, 0x14};
std::pair<uint8_t, uint8_t> OP_SET_UNATTENDED_TIME = {0x84, 0x15};
std::pair<uint8_t, uint8_t> OP_SET_SLEEP_DEADLINE = {0x84, 0x16};

std::pair<uint8_t, uint8_t> OP_REQ_IN_BED = {0x84, 0x81};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_STATE = {0x84, 0x82};
std::pair<uint8_t, uint8_t> OP_REQ_WAKE_DURATION = {0x84, 0x83};
std::pair<uint8_t, uint8_t> OP_REQ_LIGHT_SLEEP = {0x84, 0x84};
std::pair<uint8_t, uint8_t> OP_REQ_DEEP_SLEEP = {0x84, 0x85};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_QUALITY = {0x84, 0x86};
std::pair<uint8_t, uint8_t> OP_REQ_REPORTING_MODE = {0x84, 0x8C};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_COMPOSITE = {0x84, 0x8D};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_DISTURBANCES = {0x84, 0x8E};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_STATISTICS = {0x84, 0x8F};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_QUALITY_RATING = {0x84, 0x90};
std::pair<uint8_t, uint8_t> OP_REQ_ABNORMAL_STRUGGLE = {0x84, 0x91};
std::pair<uint8_t, uint8_t> OP_REQ_UNATTENDED_STATE = {0x84, 0x92};
std::pair<uint8_t, uint8_t> OP_REQ_ABNORMAL_STRUGGLE_SWITCH = {0x84, 0x93};
std::pair<uint8_t, uint8_t> OP_REQ_UNATTENDED_SWITCH = {0x84, 0x94};
std::pair<uint8_t, uint8_t> OP_REQ_UNATTENDED_TIME = {0x84, 0x95};
std::pair<uint8_t, uint8_t> OP_REQ_SLEEP_DEADLINE = {0x84, 0x96};

std::pair<uint8_t, uint8_t> OP_REQ_BREATHE_STATE = {0x81, 0x81};

namespace esphome
{
    namespace dfrobot_sen0623
    {

        static const char *TAG = "dfrobot_sen0623.component";

        bool _switch_request_rate = false;

        void DfrobotSen0623Component::cmd_reset()
        {
            // uint8_t payload[1] = {0x0f};
            // this->forge_packet(0x01, 0x02, payload, sizeof(payload));
            this->request(OP_RST_SENSOR);
            //delay(2000);
            //this->request(4);
        }

        void DfrobotSen0623Component::cmd_mode_fall()
        {
            uint8_t data[1];
            data[0] = {MODE_FALL};
            this->forge_packet(OP_SET_MODE.first, OP_SET_MODE.second, data, 1);
            this->request(OP_REQ_MODE);
            this->apply_install_config();
        }

        void DfrobotSen0623Component::cmd_mode_sleep()
        {
            uint8_t data[1];
            data[0] = {MODE_SLEEP};
            this->forge_packet(OP_SET_MODE.first, OP_SET_MODE.second, data, 1);
            this->request(OP_REQ_MODE);
        }

        void DfrobotSen0623Component::cmd_set_install_angle(int16_t x, int16_t y, int16_t z)
        {
            uint8_t data[6];
            data[0] = (x >> 8) & 0xff;
            data[1] = x & 0xff;
            data[2] = (y >> 8) & 0xff;
            data[3] = y & 0xff;
            data[4] = (z >> 8) & 0xff;
            data[5] = z & 0xff;
            this->forge_packet(OP_SET_INSTALL_ANGLE.first, OP_SET_INSTALL_ANGLE.second, data, 6);
            this->request_install_angle();
        }

        void DfrobotSen0623Component::cmd_set_install_height(uint16_t height)
        {
            uint8_t data[2];
            data[0] = (height >> 8) & 0xff;
            data[1] = height & 0xff;
            this->forge_packet(OP_SET_INSTALL_HEIGHT.first, OP_SET_INSTALL_HEIGHT.second, data, 2);
            this->request_install_height();
        }

        void DfrobotSen0623Component::apply_install_config()
        {
            this->drain_uart();

            if (this->install_height_ >= 0) {
                uint8_t data[2];
                data[0] = (this->install_height_ >> 8) & 0xff;
                data[1] = this->install_height_ & 0xff;
                this->forge_packet(OP_SET_INSTALL_HEIGHT.first, OP_SET_INSTALL_HEIGHT.second, data, 2);
                delay(100);
                this->drain_uart();
            }
            if (this->install_angle_x_ != 0 || this->install_angle_y_ != 0 || this->install_angle_z_ != 0) {
                uint8_t data[6];
                data[0] = (this->install_angle_x_ >> 8) & 0xff;
                data[1] = this->install_angle_x_ & 0xff;
                data[2] = (this->install_angle_y_ >> 8) & 0xff;
                data[3] = this->install_angle_y_ & 0xff;
                data[4] = (this->install_angle_z_ >> 8) & 0xff;
                data[5] = this->install_angle_z_ & 0xff;
                this->forge_packet(OP_SET_INSTALL_ANGLE.first, OP_SET_INSTALL_ANGLE.second, data, 6);
                delay(100);
                this->drain_uart();
            }
        }

        void DfrobotSen0623Component::cmd_auto_measure_height()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_AUTO_MEASURE_HEIGHT.first, OP_AUTO_MEASURE_HEIGHT.second, data, 1);
            this->request_auto_measure_height();
        }

        void DfrobotSen0623Component::request_install_angle()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_INSTALL_ANGLE.first, OP_REQ_INSTALL_ANGLE.second, data, 1);
        }

        void DfrobotSen0623Component::request_install_height()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_INSTALL_HEIGHT.first, OP_REQ_INSTALL_HEIGHT.second, data, 1);
        }

        void DfrobotSen0623Component::request_auto_measure_height()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_AUTO_MEASURE_HEIGHT.first, OP_AUTO_MEASURE_HEIGHT.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_fall_sensitivity(uint8_t sensitivity)
        {
            uint8_t data[1];
            data[0] = sensitivity;
            this->forge_packet(OP_SET_FALL_SENSITIVITY.first, OP_SET_FALL_SENSITIVITY.second, data, 1);
            this->request_fall_sensitivity();
        }

        void DfrobotSen0623Component::cmd_set_fall_break_height(uint16_t height)
        {
            uint8_t data[2];
            data[0] = (height >> 8) & 0xff;
            data[1] = height & 0xff;
            this->forge_packet(OP_SET_FALL_BREAK_HEIGHT.first, OP_SET_FALL_BREAK_HEIGHT.second, data, 2);
            this->request_fall_break_height();
        }

        void DfrobotSen0623Component::cmd_set_residence_time(uint32_t seconds)
        {
            uint8_t data[4];
            data[0] = (seconds >> 24) & 0xff;
            data[1] = (seconds >> 16) & 0xff;
            data[2] = (seconds >> 8) & 0xff;
            data[3] = seconds & 0xff;
            this->forge_packet(OP_SET_RESIDENCE_TIME.first, OP_SET_RESIDENCE_TIME.second, data, 4);
        }

        void DfrobotSen0623Component::cmd_set_residence_switch(bool enabled)
        {
            uint8_t data[1];
            data[0] = enabled ? 1 : 0;
            this->forge_packet(OP_SET_RESIDENCE_SWITCH.first, OP_SET_RESIDENCE_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_alt_time(uint32_t seconds)
        {
            uint8_t data[4];
            data[0] = (seconds >> 24) & 0xff;
            data[1] = (seconds >> 16) & 0xff;
            data[2] = (seconds >> 8) & 0xff;
            data[3] = seconds & 0xff;
            this->forge_packet(OP_SET_ALT_TIME.first, OP_SET_ALT_TIME.second, data, 4);
        }

        void DfrobotSen0623Component::cmd_set_report_frequency(uint32_t ms)
        {
            uint8_t data[4];
            data[0] = (ms >> 24) & 0xff;
            data[1] = (ms >> 16) & 0xff;
            data[2] = (ms >> 8) & 0xff;
            data[3] = ms & 0xff;
            this->forge_packet(OP_SET_REPORT_FREQUENCY.first, OP_SET_REPORT_FREQUENCY.second, data, 4);
        }

        void DfrobotSen0623Component::cmd_set_report_switch(bool enabled)
        {
            uint8_t data[1];
            data[0] = enabled ? 1 : 0;
            this->forge_packet(OP_SET_REPORT_SWITCH.first, OP_SET_REPORT_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_height_ratio_switch(bool enabled)
        {
            uint8_t data[1];
            data[0] = enabled ? 1 : 0;
            this->forge_packet(OP_SET_HEIGHT_RATIO_SWITCH.first, OP_SET_HEIGHT_RATIO_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_fall_time(uint32_t seconds)
        {
            uint8_t data[4];
            data[0] = (seconds >> 24) & 0xff;
            data[1] = (seconds >> 16) & 0xff;
            data[2] = (seconds >> 8) & 0xff;
            data[3] = seconds & 0xff;
            this->forge_packet(OP_SET_FALL_TIME.first, OP_SET_FALL_TIME.second, data, 4);
        }

        void DfrobotSen0623Component::cmd_set_unmanned_time(uint32_t seconds)
        {
            uint8_t data[4];
            data[0] = (seconds >> 24) & 0xff;
            data[1] = (seconds >> 16) & 0xff;
            data[2] = (seconds >> 8) & 0xff;
            data[3] = seconds & 0xff;
            this->forge_packet(OP_SET_UNMANNED_TIME.first, OP_SET_UNMANNED_TIME.second, data, 4);
        }

        void DfrobotSen0623Component::cmd_set_seated_distance(uint16_t distance)
        {
            uint8_t data[2];
            data[0] = (distance >> 8) & 0xff;
            data[1] = distance & 0xff;
            this->forge_packet(OP_SET_SEATED_DISTANCE.first, OP_SET_SEATED_DISTANCE.second, data, 2);
        }

        void DfrobotSen0623Component::cmd_set_motion_distance(uint16_t distance)
        {
            uint8_t data[2];
            data[0] = (distance >> 8) & 0xff;
            data[1] = distance & 0xff;
            this->forge_packet(OP_SET_MOTION_DISTANCE.first, OP_SET_MOTION_DISTANCE.second, data, 2);
        }

        void DfrobotSen0623Component::request_fall_state()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_FALL_STATE.first, OP_REQ_FALL_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::request_static_residency_state()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_STATIC_RESIDENCY_STATE.first, OP_REQ_STATIC_RESIDENCY_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::request_static_residency_time()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_STATIC_RESIDENCY_TIME.first, OP_REQ_STATIC_RESIDENCY_TIME.second, data, 1);
        }

        void DfrobotSen0623Component::request_fall_time()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_FALL_TIME.first, OP_REQ_FALL_TIME.second, data, 1);
        }

        void DfrobotSen0623Component::request_fall_sensitivity()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_FALL_SENSITIVITY.first, OP_REQ_FALL_SENSITIVITY.second, data, 1);
        }

        void DfrobotSen0623Component::request_fall_break_height()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_FALL_BREAK_HEIGHT.first, OP_REQ_FALL_BREAK_HEIGHT.second, data, 1);
        }

        void DfrobotSen0623Component::request_height_ratio_switch()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_HEIGHT_RATIO_SWITCH.first, OP_REQ_HEIGHT_RATIO_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::request_track()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_TRACK.first, OP_REQ_TRACK.second, data, 1);
        }

        void DfrobotSen0623Component::request_track_frequency()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_TRACK_FREQUENCY.first, OP_REQ_TRACK_FREQUENCY.second, data, 1);
        }

        void DfrobotSen0623Component::request_unmanned_time()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_UNMANNED_TIME.first, OP_REQ_UNMANNED_TIME.second, data, 1);
        }

        void DfrobotSen0623Component::request_accumulated_height_duration()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_ACCUMULATED_HEIGHT_DURATION.first, OP_REQ_ACCUMULATED_HEIGHT_DURATION.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_reporting_mode(uint8_t mode)
        {
            uint8_t data[1];
            data[0] = mode;
            this->forge_packet(OP_SET_REPORTING_MODE.first, OP_SET_REPORTING_MODE.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_abnormal_struggle(bool enabled)
        {
            uint8_t data[1];
            data[0] = enabled ? 1 : 0;
            this->forge_packet(OP_SET_ABNORMAL_STRUGGLE.first, OP_SET_ABNORMAL_STRUGGLE.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_unattended_state(bool enabled)
        {
            uint8_t data[1];
            data[0] = enabled ? 1 : 0;
            this->forge_packet(OP_SET_UNATTENDED_STATE.first, OP_SET_UNATTENDED_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_unattended_time(uint8_t minutes)
        {
            uint8_t data[1];
            data[0] = minutes;
            this->forge_packet(OP_SET_UNATTENDED_TIME.first, OP_SET_UNATTENDED_TIME.second, data, 1);
        }

        void DfrobotSen0623Component::cmd_set_sleep_deadline(uint8_t hours)
        {
            uint8_t data[1];
            data[0] = hours;
            this->forge_packet(OP_SET_SLEEP_DEADLINE.first, OP_SET_SLEEP_DEADLINE.second, data, 1);
        }

        void DfrobotSen0623Component::request_in_bed()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_IN_BED.first, OP_REQ_IN_BED.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_state()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_STATE.first, OP_REQ_SLEEP_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::request_wake_duration()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_WAKE_DURATION.first, OP_REQ_WAKE_DURATION.second, data, 1);
        }

        void DfrobotSen0623Component::request_light_sleep()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_LIGHT_SLEEP.first, OP_REQ_LIGHT_SLEEP.second, data, 1);
        }

        void DfrobotSen0623Component::request_deep_sleep()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_DEEP_SLEEP.first, OP_REQ_DEEP_SLEEP.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_quality()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_QUALITY.first, OP_REQ_SLEEP_QUALITY.second, data, 1);
        }

        void DfrobotSen0623Component::request_reporting_mode()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_REPORTING_MODE.first, OP_REQ_REPORTING_MODE.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_disturbances()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_DISTURBANCES.first, OP_REQ_SLEEP_DISTURBANCES.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_quality_rating()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_QUALITY_RATING.first, OP_REQ_SLEEP_QUALITY_RATING.second, data, 1);
        }

        void DfrobotSen0623Component::request_abnormal_struggle()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_ABNORMAL_STRUGGLE.first, OP_REQ_ABNORMAL_STRUGGLE.second, data, 1);
        }

        void DfrobotSen0623Component::request_unattended_state()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_UNATTENDED_STATE.first, OP_REQ_UNATTENDED_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::request_abnormal_struggle_switch()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_ABNORMAL_STRUGGLE_SWITCH.first, OP_REQ_ABNORMAL_STRUGGLE_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::request_unattended_switch()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_UNATTENDED_SWITCH.first, OP_REQ_UNATTENDED_SWITCH.second, data, 1);
        }

        void DfrobotSen0623Component::request_unattended_time()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_UNATTENDED_TIME.first, OP_REQ_UNATTENDED_TIME.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_deadline()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_DEADLINE.first, OP_REQ_SLEEP_DEADLINE.second, data, 1);
        }

        void DfrobotSen0623Component::request_breathe_state()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_BREATHE_STATE.first, OP_REQ_BREATHE_STATE.second, data, 1);
        }

        void DfrobotSen0623Component::request_breathe_value()
        {
            this->request(OP_REQ_BREATH_RATE);
        }

        void DfrobotSen0623Component::request_sleep_composite()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_COMPOSITE.first, OP_REQ_SLEEP_COMPOSITE.second, data, 1);
        }

        void DfrobotSen0623Component::request_sleep_statistics()
        {
            uint8_t data[1] = {0x0f};
            this->forge_packet(OP_REQ_SLEEP_STATISTICS.first, OP_REQ_SLEEP_STATISTICS.second, data, 1);
        }

        void DfrobotSen0623Component::request(std::pair<uint8_t, uint8_t> operation)
        {
            uint8_t data[1];
            data[0] = {0x0f};
            this->forge_packet(operation.first, operation.second, data, 1);
            // If i request something, should i wait for response?

        }

        bool _d = true;
        void DfrobotSen0623Component::forge_packet(uint8_t control, uint8_t command, uint8_t *senData, uint16_t senLen)
        {
            std::vector<uint8_t> buffer;
            buffer.push_back(0x53);
            buffer.push_back(0x59);
            buffer.push_back(control);
            buffer.push_back(command);
            buffer.push_back((senLen >> 8) & 0xff);
            buffer.push_back(senLen & 0xff);
            for (uint8_t i = 0; i < senLen; i++)
            {
                buffer.push_back(senData[i]);
            }
            // Calculate check
            uint8_t crSum = 0;
            for (uint8_t i = 0; i < buffer.size(); i++)
            {
                crSum += buffer.data()[i];
            }
            buffer.push_back(crSum & 0xff);
            buffer.push_back(0x54);
            buffer.push_back(0x43);

            // this->print_data("XX", buffer.data(), buffer.size());
            this->send_packet(buffer.data(), buffer.size());
        }

        void DfrobotSen0623Component::send_packet(uint8_t *packetData, size_t len)
        {

            if (_d)
            {
                this->print_data(">>", packetData, len);
            }
            for (uint8_t i = 0; i < len; i++)
            {
                this->write_byte(packetData[i]);
            }
        }

        uint8_t DfrobotSen0623Component::read_packet(uint8_t *packetData)
        {
            if (!this->available()) {
                return 0;
            }
            std::vector<uint8_t> buffer;
            uint8_t byte;

            // Read bytes until '\n' delimiter or no more bytes available
            while (this->available() && this->read_byte(&byte))
            {
                buffer.push_back(byte);
                if (byte == '\n')
                {
                    break;
                }
            }
            // Copy data to packetData and return the length
            size_t len = buffer.size();
            if (len > 0)
            {
                // Make sure to not overflow packetData buffer — adjust max length accordingly
                // For example, if packetData is fixed size 100 bytes:
                size_t max_len = 100; // Change as needed
                if (len > max_len)
                {
                    len = max_len;
                }
                memcpy(packetData, buffer.data(), len);
            }

            if (_d && len > 0)
            {
                this->print_data("<<", packetData, len);
            }

            return (uint8_t)len;
        }

        uint8_t DfrobotSen0623Component::wait_for_packet(std::pair<uint8_t, uint8_t> operation) {
            // Reduced timeout to prevent watchdog issues
            uint8_t ths = 32;  // Reduced from 128 to 32 (max 1.6 seconds instead of 6.4)
            uint32_t start_time = millis();
            
            while(ths > 0 && (millis() - start_time) < 2000) {  // Add 2 second timeout
                uint8_t packetData[100]; // adjust size as needed
                uint8_t len = this->read_packet(packetData);

                if(this->process_packet(packetData, len)){
                    ths--;
                    if(packetData[2] == operation.first && packetData[3] == operation.second) {
                        return packetData[6];
                    } 
                }
                delay(10);  // Small delay to prevent tight loop
            }
            ESP_LOGI(TAG, "WAIT FAILED");
            return 0xf5;
        }

        bool DfrobotSen0623Component::process_packet(uint8_t *packetData, size_t len)
        {
            // Process only valid packets
            if (len > 5)
            {
                uint8_t dataLen = ((uint16_t)packetData[4] << 8) | packetData[5];
                // Ensure we have enough data for header + payload + checksum
                if (len < 6 + dataLen) {
                    return false;
                }
                uint8_t csum = 0;
                for (uint8_t i = 0; i < 6 + dataLen; i++)
                {
                    csum += packetData[i];
                }
                csum = csum & 0xff;
                if (packetData[0] == 0x53 && packetData[1] == 0x59 && packetData[len - 2] == 0x54 && packetData[len - 1] == 0x43 && csum == packetData[len - 3])
                {
                    uint8_t data[dataLen];
                    for (uint8_t i = 0; i < dataLen; i++)
                    {
                        data[i] = packetData[6 + i];
                    }

                    std::pair<uint8_t, uint8_t> operation = {packetData[2], packetData[3]};

                    if (operation == OP_REQ_HEART_RATE) {
                        if (data[0] > 0 && this->heart_rate_sensor_ != nullptr) {
                            this->heart_rate_sensor_->publish_state(data[0]);
                        }
                    } else 
                    if (operation == OP_REQ_BREATH_RATE) {
                        if (data[0] > 0 && this->breath_rate_sensor_ != nullptr) {
                            this->breath_rate_sensor_->publish_state(data[0]);
                        }
                    } else 
                    if (operation == OP_REQ_HUMAN_PRESENCE) {
                        if (this->presence_sensor_ != nullptr) {
                            switch (data[0])
                            {
                            case 0:
                                this->presence_sensor_->publish_state(0);
                                break;
                            case 1:
                                this->presence_sensor_->publish_state(1);
                                break;
                            default:
                                ESP_LOGE(TAG, "INVALID PRESENCE: %02X", data[0]);
                                break;
                            }
                        }
                    } else 
                    if (operation == OP_REQ_HUMAN_MOVEMENT) {
                        if (this->movement_text_sensor_ != nullptr) {
                            switch (data[0])
                            {
                            case 0:
                                this->movement_text_sensor_->publish_state("none");
                                break;
                            case 1:
                                this->movement_text_sensor_->publish_state("still");
                                break;
                            case 2:
                                this->movement_text_sensor_->publish_state("active");
                                break;
                            default:
                                ESP_LOGE(TAG, "INVALID MOVEMENT: %02X", data[0]);
                                break;
                            }
                        }
                    } else 
                    if (operation == OP_REQ_HUMAN_DISTANCE) {
                        if (this->human_distance_sensor_ != nullptr) {
                            this->human_distance_sensor_->publish_state((data[0] << 8) | data[1]);
                        }
                    } else 
                    if (operation == OP_REQ_HUMAN_MOVE_RANGE) {
                        if (this->human_move_range_sensor_ != nullptr) {
                            this->human_move_range_sensor_->publish_state(data[0]);
                        }
                    } else 
                    if (operation == OP_REQ_MODE) {
                        if (this->status_text_sensor_ != nullptr)
                        {
                            switch (data[0])
                            {
                            case 1:
                                this->status_text_sensor_->publish_state("fall");
                                break;
                            case 2:
                                this->status_text_sensor_->publish_state("sleep");
                                break;
                            default:
                                this->status_text_sensor_->publish_state("error");
                                break;
                            }
                        }
                    } else
                    if (operation == OP_REQ_INSTALL_ANGLE) {
                        if (this->install_angle_x_sensor_ != nullptr) {
                            int16_t x = (int16_t)((data[0] << 8) | data[1]);
                            this->install_angle_x_sensor_->publish_state(x);
                        }
                        if (this->install_angle_y_sensor_ != nullptr) {
                            int16_t y = (int16_t)((data[2] << 8) | data[3]);
                            this->install_angle_y_sensor_->publish_state(y);
                        }
                        if (this->install_angle_z_sensor_ != nullptr) {
                            int16_t z = (int16_t)((data[4] << 8) | data[5]);
                            this->install_angle_z_sensor_->publish_state(z);
                        }
                    } else
                    if (operation == OP_REQ_INSTALL_HEIGHT || operation == OP_AUTO_MEASURE_HEIGHT) {
                        if (this->install_height_sensor_ != nullptr) {
                            uint16_t h = (uint16_t)((data[0] << 8) | data[1]);
                            this->install_height_sensor_->publish_state(h);
                        }
                    } else
                    if (operation == OP_REQ_FALL_STATE) {
                        if (this->fall_state_sensor_ != nullptr) {
                            this->fall_state_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_STATIC_RESIDENCY_STATE || operation == OP_REQ_STATIC_RESIDENCY_SWITCH) {
                        if (this->static_residency_sensor_ != nullptr) {
                            this->static_residency_sensor_->publish_state(data[0]);
                        }
                        if (this->static_residency_text_sensor_ != nullptr) {
                            switch (data[0]) {
                            case 0: this->static_residency_text_sensor_->publish_state("no_stationary_dwell"); break;
                            case 1: this->static_residency_text_sensor_->publish_state("stationary_dwell"); break;
                            default: this->static_residency_text_sensor_->publish_state("unknown"); break;
                            }
                        }
                    } else
                    if (operation == OP_REQ_STATIC_RESIDENCY_TIME || operation == OP_REQ_FALL_TIME) {
                        ESP_LOGI(TAG, "Processing STATIC_RESIDENCY_TIME or FALL_TIME, dataLen=%d", dataLen);
                        if (dataLen >= 4) {
                            uint32_t val = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
                            ESP_LOGI(TAG, "Static residency time value: %u", val);
                            if (this->static_residency_time_sensor_ != nullptr) {
                                this->static_residency_time_sensor_->publish_state(val);
                            }
                        }
                    } else
                    if (operation == OP_REQ_FALL_SENSITIVITY) {
                        if (this->fall_sensitivity_sensor_ != nullptr) {
                            this->fall_sensitivity_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_FALL_BREAK_HEIGHT) {
                        if (this->fall_break_height_sensor_ != nullptr) {
                            uint16_t h = (uint16_t)((data[0] << 8) | data[1]);
                            this->fall_break_height_sensor_->publish_state(h);
                        }
                    } else
                    if (operation == OP_REQ_TRACK) {
                        if (this->track_x_sensor_ != nullptr) {
                            uint16_t x = (uint16_t)((data[0] << 8) | data[1]);
                            this->track_x_sensor_->publish_state(x);
                        }
                        if (this->track_y_sensor_ != nullptr) {
                            uint16_t y = (uint16_t)((data[2] << 8) | data[3]);
                            this->track_y_sensor_->publish_state(y);
                        }
                    } else
                    if (operation == OP_REQ_UNMANNED_TIME) {
                        if (this->unmanned_time_sensor_ != nullptr) {
                            uint32_t val = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
                            this->unmanned_time_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_ACCUMULATED_HEIGHT_DURATION) {
                        if (this->accumulated_height_duration_sensor_ != nullptr) {
                            uint32_t val = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
                            this->accumulated_height_duration_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_SEATED_DISTANCE) {
                        if (this->seated_distance_sensor_ != nullptr) {
                            uint16_t val = (uint16_t)((data[0] << 8) | data[1]);
                            this->seated_distance_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_MOTION_DISTANCE) {
                        if (this->motion_distance_sensor_ != nullptr) {
                            uint16_t val = (uint16_t)((data[0] << 8) | data[1]);
                            this->motion_distance_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_HEIGHT_RATIO_SWITCH || operation == OP_REQ_TRAJECTORY_SWITCH) {
                        if (this->fall_status_text_sensor_ != nullptr) {
                            this->fall_status_text_sensor_->publish_state(data[0] ? "enabled" : "disabled");
                        }
                    } else
                    if (operation == OP_REQ_IN_BED) {
                        this->set_in_bed_state(data[0]);
                        if (this->in_bed_sensor_ != nullptr) {
                            this->in_bed_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_STATE) {
                        ESP_LOGI(TAG, "Processing SLEEP_STATE: %02X, sensor=%p, text_sensor=%p", data[0], sleep_state_sensor_, sleep_status_text_sensor_);
                        if (this->sleep_state_sensor_ != nullptr) {
                            this->sleep_state_sensor_->publish_state(data[0]);
                        }
                        if (this->sleep_status_text_sensor_ != nullptr) {
                            switch (data[0]) {
                            case 0: this->sleep_status_text_sensor_->publish_state("deep_sleep"); break;
                            case 1: this->sleep_status_text_sensor_->publish_state("light_sleep"); break;
                            case 2: this->sleep_status_text_sensor_->publish_state("awake"); break;
                            case 3: this->sleep_status_text_sensor_->publish_state("none"); break;
                            default: this->sleep_status_text_sensor_->publish_state("unknown"); break;
                            }
                        }
                    } else
                    if (operation == OP_REQ_WAKE_DURATION) {
                        if (this->wake_duration_sensor_ != nullptr) {
                            uint16_t val = (uint16_t)((data[0] << 8) | data[1]);
                            this->wake_duration_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_LIGHT_SLEEP) {
                        if (this->light_sleep_sensor_ != nullptr) {
                            uint16_t val = (uint16_t)((data[0] << 8) | data[1]);
                            this->light_sleep_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_DEEP_SLEEP) {
                        if (this->deep_sleep_sensor_ != nullptr) {
                            uint16_t val = (uint16_t)((data[0] << 8) | data[1]);
                            this->deep_sleep_sensor_->publish_state(val);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_QUALITY || operation == OP_REQ_REPORTING_MODE) {
                        if (this->sleep_quality_sensor_ != nullptr) {
                            this->sleep_quality_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_DISTURBANCES) {
                        if (this->sleep_disturbances_sensor_ != nullptr) {
                            this->sleep_disturbances_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_QUALITY_RATING) {
                        if (this->sleep_quality_rating_sensor_ != nullptr) {
                            this->sleep_quality_rating_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_BREATH_RATE) {
                        if (this->breathe_value_sensor_ != nullptr) {
                            this->breathe_value_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_UNATTENDED_STATE || operation == OP_REQ_ABNORMAL_STRUGGLE_SWITCH || operation == OP_REQ_UNATTENDED_SWITCH) {
                        // These are switch states, not time values - need binary sensor handlers
                        // Currently mis-assigned to unattended_time_sensor_ - bug
                    } else
                    if (operation == OP_REQ_UNATTENDED_TIME) {
                        if (this->unattended_time_sensor_ != nullptr) {
                            this->unattended_time_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_DEADLINE) {
                        if (this->sleep_deadline_sensor_ != nullptr) {
                            this->sleep_deadline_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_BREATHE_STATE) {
                        if (this->breathe_state_sensor_ != nullptr) {
                            this->breathe_state_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation == OP_REQ_SLEEP_COMPOSITE) {
                        // 8 bytes: presence, sleepState, avgRespiration, avgHeartbeat, turnover, largeMove, minorMove, apnea
                        ESP_LOGI(TAG, "Sleep composite: presence=%d, sleepState=%d, resp=%d, hr=%d, turn=%d", 
                                 data[0], data[1], data[2], data[3], data[4]);
                    } else
                    if (operation == OP_REQ_SLEEP_STATISTICS) {
                        // 12 bytes: sleepQuality, sleepTime, wakeDuration, shallow%, deep%, outOfBed, exitCount, turnOver, avgResp, avgHR, apnea
                        ESP_LOGI(TAG, "Sleep stats: quality=%d, time=%d, wake=%d, shallow=%d, deep=%d", 
                                 data[0], data[1], data[2], data[3], data[4]);
                    } else
                    if (operation == OP_REQ_STATIC_RESIDENCY_TIME) {
                        ESP_LOGI(TAG, "Static residency time: %02X %02X %02X %02X", data[0], data[1], data[2], data[3]);
                        if (dataLen >= 4) {
                            uint32_t val = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) | ((uint32_t)data[2] << 8) | data[3];
                            if (this->static_residency_time_sensor_ != nullptr) {
                                this->static_residency_time_sensor_->publish_state(val);
                            }
                        }
                    } else
                    if (operation.first == 0x01 && operation.second == 0x01) {
                    } else
                    if (operation.first == 0x07 && operation.second == 0x07) {
                    } else
                    if (operation.first == 0x80 && operation.second == 0x02) {
                        if (this->movement_text_sensor_ != nullptr) {
                            switch (data[0]) {
                            case 0: this->movement_text_sensor_->publish_state("none"); break;
                            case 1: this->movement_text_sensor_->publish_state("still"); break;
                            case 2: this->movement_text_sensor_->publish_state("active"); break;
                            default: ESP_LOGE(TAG, "INVALID MOVEMENT (unsolicited): %02X", data[0]); break;
                            }
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x03) {
                        if (this->human_move_range_sensor_ != nullptr) {
                            this->human_move_range_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x04) {
                        if (this->human_distance_sensor_ != nullptr) {
                            this->human_distance_sensor_->publish_state((data[0] << 8) | data[1]);
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x05) {
                    } else
                    if (operation.first == 0x81 && operation.second == 0x02) {
                        if (this->breath_rate_sensor_ != nullptr && data[0] > 0) {
                            this->breath_rate_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation.first == 0x85 && operation.second == 0x02) {
                        if (this->heart_rate_sensor_ != nullptr && data[0] > 0) {
                            this->heart_rate_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x03) {
                        if (this->human_move_range_sensor_ != nullptr) {
                            this->human_move_range_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x04) {
                        if (this->human_distance_sensor_ != nullptr) {
                            this->human_distance_sensor_->publish_state((data[0] << 8) | data[1]);
                        }
                    } else
                    if (operation.first == 0x80 && operation.second == 0x05) {
                    } else
                    if (operation.first == 0x81 && operation.second == 0x02) {
                        if (this->breath_rate_sensor_ != nullptr && data[0] > 0) {
                            this->breath_rate_sensor_->publish_state(data[0]);
                        }
                    } else
                    if (operation.first == 0x85 && operation.second == 0x02) {
                        if (this->heart_rate_sensor_ != nullptr && data[0] > 0) {
                            this->heart_rate_sensor_->publish_state(data[0]);
                        }
                    } else
                    {
                        ESP_LOGI(TAG, "UNHANDLED: %02X %02X (%i)", operation.first, operation.second, dataLen);
                        //ESP_LOGI(TAG, "CHECK_I: %02X", packetData[len-3]);
                        //ESP_LOGI(TAG, "CHECK_C: %c", csum);
                        //this->print_data("**", data, dataLen);
                    }
                }
                return true;
            }
            return false;
        }

        void DfrobotSen0623Component::print_data(std::string tag, const uint8_t *bytes, size_t len)
        {
            std::string out;
            char buf[5];
            for (size_t i = 0; i < len; i++)
            {
                if (i > 0)
                {
                    out += " ";
                }
                sprintf(buf, "%02X", bytes[i]);
                out += buf;
            }
            //ESP_LOGI(TAG, "%s %s", tag.c_str(), out.c_str());

            out = "";
            for (size_t i = 0; i < len; i++)
            {
                if (i > 2)
                {
                    out += " ";
                }
                if (i > 1 && i < len - 3 && i != 4 && i !=5) {
                  sprintf(buf, "%02X", bytes[i]);
                  out += buf;
                }
            }
            ESP_LOGI(TAG, "%s %s", tag.c_str(), out.c_str());
            
        }

        void DfrobotSen0623Component::setup()
        {
            ESP_LOGI(TAG, "WAITING FOR INIT");
            delay(500);  // Reduced from 1000ms

            this->request(OP_INIT);
            uint8_t result = this->wait_for_packet(OP_INIT);
            if (result != 0xf5) {
                ESP_LOGI(TAG, "WE ARE IN BUSINESS");
                if (this->status_text_sensor_ != nullptr) {
                    this->status_text_sensor_->publish_state("NA");
                }
                if (this->movement_text_sensor_ != nullptr) {
                    this->movement_text_sensor_->publish_state("NA");
                }
                
                this->request(OP_REQ_MODE);
                delay(100);
                this->wait_for_packet(OP_REQ_MODE);
                
                this->request(OP_RST_SENSOR);
                delay(100);
                this->wait_for_packet(OP_RST_SENSOR);
                delay(500);

                this->apply_install_config();
            } else {
                this->mark_failed();
            }
        }

        void DfrobotSen0623Component::sync_configuration()
        {
            ESP_LOGI(TAG, "Syncing configuration from device...");

            this->request(OP_REQ_MODE);
            uint8_t mode = this->wait_for_packet(OP_REQ_MODE);
            if (mode != 0xf5 && this->status_text_sensor_ != nullptr) {
                const char* mode_str = (mode == 1) ? "fall" : (mode == 2) ? "sleep" : "error";
                this->status_text_sensor_->publish_state(mode_str);
            }

            this->request(OP_INIT);
            uint8_t hp_led = this->wait_for_packet(OP_INIT);
            if (hp_led != 0xf5 && this->hp_led_switch_ != nullptr) {
                this->hp_led_switch_->publish_state(hp_led == 1);
            }

            this->request(OP_REQ_FALL_LED);
            uint8_t fall_led = this->wait_for_packet(OP_REQ_FALL_LED);
            if (fall_led != 0xf5) {
            }

            ESP_LOGI(TAG, "Configuration sync complete");
        }

        void DfrobotSen0623Component::drain_uart()
        {
            uint8_t packetData[100];
            while (this->available()) {
                uint8_t len = this->read_packet(packetData);
                if (len > 0) {
                    this->process_packet(packetData, len);
                } else {
                    break;
                }
            }
        }

        void DfrobotSen0623Component::update()
        {
            if (_switch_request_rate)
            {
                this->pending_update_ = true;
            }
        }

        void DfrobotSen0623Component::send_next_update_request()
        {
            switch (this->update_phase_) {
                case 0: this->request(OP_REQ_HEART_RATE); break;
                case 1: this->request(OP_REQ_BREATH_RATE); break;
                case 2: this->request_breathe_state(); break;
                case 3: this->request_breathe_value(); break;
                case 4: this->request_accumulated_height_duration(); break;
                case 5: this->request_deep_sleep(); break;
                case 6: this->request_sleep_state(); break;
                case 7: this->request_sleep_quality(); break;
                case 8: this->request_sleep_disturbances(); break;
                case 9: this->request_sleep_quality_rating(); break;
                case 10: this->request_sleep_composite(); break;
                case 11: this->request_sleep_statistics(); break;
                case 12: this->request(OP_REQ_HUMAN_PRESENCE); break;
                case 13: this->request(OP_REQ_HUMAN_MOVEMENT); break;
                case 14: this->request(OP_REQ_HUMAN_DISTANCE); break;
                case 15: this->request(OP_REQ_HUMAN_MOVE_RANGE); break;
                case 16: this->request_fall_state(); break;
                case 17: this->request_fall_time(); break;
                case 18: this->request_fall_sensitivity(); break;
                case 19: this->request_fall_break_height(); break;
                case 20: this->request_install_angle(); break;
                case 21: this->request_install_height(); break;
                case 22: this->request_in_bed(); break;
                case 23: this->request_wake_duration(); break;
                case 24: this->request_light_sleep(); break;
                case 25: this->request_unattended_state(); break;
                case 26: this->request_unattended_time(); break;
                case 27: this->request_sleep_deadline(); break;
                case 28: this->request_static_residency_state(); break;
                case 29: this->request_static_residency_time(); break;
                case 30: this->request_track(); break;
                case 31: this->request_unmanned_time(); break;
                case 32: this->request(OP_REQ_SEATED_DISTANCE); break;
                case 33: this->request(OP_REQ_MOTION_DISTANCE); break;
                default:
                    this->update_phase_ = 0;
                    this->pending_update_ = false;
                    return;
            }
            this->update_phase_++;
            this->last_request_time_ = millis();
        }

        void DfrobotSen0623Component::loop()
        {
            if (this->pending_update_ && this->update_phase_ == 0) {
                this->update_phase_ = 1;
                this->last_request_time_ = 0;  // Send first request immediately
            }

            if (this->pending_update_ && this->update_phase_ > 0) {
                uint32_t now = millis();
                if (now - this->last_request_time_ >= REQUEST_INTERVAL_MS || this->last_request_time_ == 0) {
                    this->send_next_update_request();
                }
            }

            this->drain_uart();

            if (this->auto_mode_ && (bool)this->in_bed_state_ != (bool)this->last_auto_mode_in_bed_state_) {
                if (millis() - this->in_bed_changed_at_ > 30000) {
                    this->last_auto_mode_in_bed_state_ = this->in_bed_state_;
                    ESP_LOGI(TAG, "Auto mode switching to %s mode", this->in_bed_state_ ? "sleep" : "fall");
                    if (this->in_bed_state_) {
                        this->cmd_mode_sleep();
                    } else {
                        this->cmd_mode_fall();
                    }
                }
            }
        }

        void DfrobotSen0623Component::dump_config()
        {
            ESP_LOGCONFIG(TAG, "DfrobotSen0623Component");
        }

        void DfrobotSen0623Component::set_switch_request_rate(bool val)
        {
            if (this->request_rate_switch_ != nullptr) {
                _switch_request_rate = val;
                this->request_rate_switch_->publish_state(_switch_request_rate);
            }
        }

        void DfrobotSen0623Component::set_switch_hp_led(bool val)
        {
            if (this->hp_led_switch_ != nullptr)
            {
                this->hp_led_switch_->publish_state(val);

                uint8_t data[1];
                if (val)
                {
                    data[0] = 1;
                }
                else
                {
                    data[0] = 0;
                }
                this->forge_packet(0x01, 0x03, data, sizeof(data)); // HP
            }
        }

        void DfrobotSen0623Component::set_in_bed_state(int state) {
            bool new_state = (state != 0);
            if (new_state != this->in_bed_state_) {
                this->in_bed_state_ = new_state;
                this->in_bed_changed_at_ = millis();
            }
        }

        void DfrobotSen0623Component::set_switch_auto_mode(bool val) {
            if (this->auto_mode_switch_ != nullptr) {
                this->auto_mode_ = val;
                this->auto_mode_switch_->publish_state(val);
                if (val) {
                    this->last_auto_mode_in_bed_state_ = this->in_bed_state_;
                    ESP_LOGI(TAG, "Auto mode enabled, initial switch to %s mode", this->in_bed_state_ ? "sleep" : "fall");
                    if (this->in_bed_state_) {
                        this->cmd_mode_sleep();
                    } else {
                        this->cmd_mode_fall();
                    }
                }
            }
        }

    } // namespace dfrobot_sen0623
} // namespace esphome
