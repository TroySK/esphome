#pragma once

#include "esphome/core/component.h"
#include "esphome/components/uart/uart.h"

#ifdef USE_SENSOR
#include "esphome/components/sensor/sensor.h"
#endif

#ifdef USE_TEXT_SENSOR
#include "esphome/components/text_sensor/text_sensor.h"
#endif

#ifdef USE_BINARY_SENSOR
#include "esphome/components/binary_sensor/binary_sensor.h"
#endif

#ifdef USE_SWITCH
#include "esphome/components/switch/switch.h"
#endif

#ifdef USE_BUTTON
#include "esphome/components/button/button.h"
#endif

namespace esphome {
namespace dfrobot_sen0623 {

class DfrobotSen0623Component : public uart::UARTDevice, public PollingComponent {
#ifdef USE_SWITCH
  SUB_SWITCH(request_rate)
  SUB_SWITCH(hp_led)
#endif


  public:
    void request(std::pair<uint8_t, uint8_t> operation);

    void forge_packet(uint8_t control, uint8_t command, uint8_t *senData, uint16_t senLen);

    void send_packet(uint8_t *packetData, size_t len);

    bool process_packet(uint8_t *packetData, size_t len);

    uint8_t wait_for_packet(std::pair<uint8_t, uint8_t> operation);
    uint8_t read_packet(uint8_t *packetData);

    void print_data(std::string tag, const uint8_t *bytes, size_t len);

    // sensor
    void set_heart_rate_sensor(sensor::Sensor *rate_sensor) { heart_rate_sensor_ = rate_sensor; }
    void set_breath_rate_sensor(sensor::Sensor *rate_sensor) { breath_rate_sensor_ = rate_sensor; }
    void set_human_distance_sensor(sensor::Sensor *human_distance_sensor) { human_distance_sensor_ = human_distance_sensor; }
    void set_human_move_range_sensor(sensor::Sensor *human_move_range_sensor) { human_move_range_sensor_ = human_move_range_sensor; }
    // text sensor 
    void set_status_text_sensor(text_sensor::TextSensor *status_text_sensor) { status_text_sensor_ = status_text_sensor; }
    void set_movement_text_sensor(text_sensor::TextSensor *movement_text_sensor) { movement_text_sensor_ = movement_text_sensor; }
    // binary_sensor
    void set_presence_binary_sensor(binary_sensor::BinarySensor *presence_sensor) { presence_sensor_ = presence_sensor; }
    // button
    void set_reset_button(button::Button *reset_button) { reset_button_ = reset_button; }
    void set_mode_fall_button(button::Button *mode_fall_button) { mode_fall_button_ = mode_fall_button; }
    void set_mode_sleep_button(button::Button *mode_sleep_button) { mode_sleep_button_ = mode_sleep_button; }
    // switch
    void set_switch_request_rate(bool val);
    void set_switch_hp_led(bool val);
    // actions
    void cmd_reset();
    void cmd_mode_fall();
    void cmd_mode_sleep();

    // fall mode - installation
    void cmd_set_install_angle(int16_t x, int16_t y, int16_t z);
    void cmd_set_install_height(uint16_t height);
    void cmd_auto_measure_height();
    void request_install_angle();
    void request_install_height();
    void request_auto_measure_height();

    // fall mode - configuration
    void cmd_set_fall_sensitivity(uint8_t sensitivity);
    void cmd_set_fall_break_height(uint16_t height);
    void cmd_set_residence_time(uint32_t seconds);
    void cmd_set_residence_switch(bool enabled);
    void cmd_set_alt_time(uint32_t seconds);
    void cmd_set_report_frequency(uint32_t ms);
    void cmd_set_report_switch(bool enabled);
    void cmd_set_height_ratio_switch(bool enabled);

    // fall mode - data queries
    void request_fall_state();
    void request_static_residency_state();
    void request_static_residency_time();
    void request_fall_time();
    void request_fall_sensitivity();
    void request_fall_break_height();
    void request_height_ratio_switch();
    void request_track();
    void request_track_frequency();
    void request_unmanned_time();
    void request_accumulated_height_duration();

    void setup() override;
    void loop() override;
    void update() override;
    void dump_config() override;
    void sync_configuration();
  protected:
    sensor::Sensor *heart_rate_sensor_{nullptr};
    sensor::Sensor *breath_rate_sensor_{nullptr};
    sensor::Sensor *human_distance_sensor_{nullptr};
    sensor::Sensor *human_move_range_sensor_{nullptr};
    binary_sensor::BinarySensor *presence_sensor_{nullptr};

    text_sensor::TextSensor *status_text_sensor_{nullptr};
    text_sensor::TextSensor *movement_text_sensor_{nullptr};

    button::Button *reset_button_{nullptr};
    button::Button *mode_fall_button_{nullptr};
    button::Button *mode_sleep_button_{nullptr};

    sensor::Sensor *install_angle_x_sensor_{nullptr};
    sensor::Sensor *install_angle_y_sensor_{nullptr};
    sensor::Sensor *install_angle_z_sensor_{nullptr};
    sensor::Sensor *install_height_sensor_{nullptr};

    sensor::Sensor *fall_state_sensor_{nullptr};
    sensor::Sensor *static_residency_sensor_{nullptr};
    sensor::Sensor *static_residency_time_sensor_{nullptr};
    sensor::Sensor *fall_time_sensor_{nullptr};
    sensor::Sensor *fall_sensitivity_sensor_{nullptr};
    sensor::Sensor *fall_break_height_sensor_{nullptr};
    sensor::Sensor *track_x_sensor_{nullptr};
    sensor::Sensor *track_y_sensor_{nullptr};
    sensor::Sensor *unmanned_time_sensor_{nullptr};
    sensor::Sensor *accumulated_height_duration_sensor_{nullptr};

    text_sensor::TextSensor *fall_status_text_sensor_{nullptr};

    void set_fall_state_sensor(sensor::Sensor *s) { fall_state_sensor_ = s; }
    void set_static_residency_sensor(sensor::Sensor *s) { static_residency_sensor_ = s; }
    void set_static_residency_time_sensor(sensor::Sensor *s) { static_residency_time_sensor_ = s; }
    void set_fall_time_sensor(sensor::Sensor *s) { fall_time_sensor_ = s; }
    void set_fall_sensitivity_sensor(sensor::Sensor *s) { fall_sensitivity_sensor_ = s; }
    void set_fall_break_height_sensor(sensor::Sensor *s) { fall_break_height_sensor_ = s; }
    void set_track_x_sensor(sensor::Sensor *s) { track_x_sensor_ = s; }
    void set_track_y_sensor(sensor::Sensor *s) { track_y_sensor_ = s; }
    void set_unmanned_time_sensor(sensor::Sensor *s) { unmanned_time_sensor_ = s; }
    void set_accumulated_height_duration_sensor(sensor::Sensor *s) { accumulated_height_duration_sensor_ = s; }
    void set_install_angle_x_sensor(sensor::Sensor *s) { install_angle_x_sensor_ = s; }
    void set_install_angle_y_sensor(sensor::Sensor *s) { install_angle_y_sensor_ = s; }
    void set_install_angle_z_sensor(sensor::Sensor *s) { install_angle_z_sensor_ = s; }
    void set_install_height_sensor(sensor::Sensor *s) { install_height_sensor_ = s; }
    void set_fall_status_text_sensor(text_sensor::TextSensor *s) { fall_status_text_sensor_ = s; }
};


}  // namespace dfrobot_sen0623
}  // namespace esphome