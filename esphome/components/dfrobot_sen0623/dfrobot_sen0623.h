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
  SUB_SWITCH(auto_mode)
#endif

 public:
  void request(std::pair<uint8_t, uint8_t> operation);

  void forge_packet(uint8_t control, uint8_t command, uint8_t *senData, uint16_t senLen);

  void send_packet(uint8_t *packetData, size_t len);

  bool process_packet(uint8_t *packetData, size_t len);

  uint8_t wait_for_packet(std::pair<uint8_t, uint8_t> operation);
  uint8_t read_packet(uint8_t *packetData);

  void print_data(std::string tag, const uint8_t *bytes, size_t len);

  // Core sensor setters
  void set_heart_rate_sensor(sensor::Sensor *s) { heart_rate_sensor_ = s; }
  void set_breath_rate_sensor(sensor::Sensor *s) { breath_rate_sensor_ = s; }
  void set_human_distance_sensor(sensor::Sensor *s) { human_distance_sensor_ = s; }
  void set_human_move_range_sensor(sensor::Sensor *s) { human_move_range_sensor_ = s; }

  // Text sensor setters
  void set_status_text_sensor(text_sensor::TextSensor *s) { status_text_sensor_ = s; }
  void set_movement_text_sensor(text_sensor::TextSensor *s) { movement_text_sensor_ = s; }
  void set_fall_status_text_sensor(text_sensor::TextSensor *s) { fall_status_text_sensor_ = s; }
  void set_sleep_status_text_sensor(text_sensor::TextSensor *s) { sleep_status_text_sensor_ = s; }
  void set_static_residency_text_sensor(text_sensor::TextSensor *s) { static_residency_text_sensor_ = s; }

  // Binary sensor setter
  void set_presence_binary_sensor(binary_sensor::BinarySensor *s) { presence_sensor_ = s; }

  // Button setters
  void set_reset_button(button::Button *b) { reset_button_ = b; }
  void set_mode_fall_button(button::Button *b) { mode_fall_button_ = b; }
  void set_mode_sleep_button(button::Button *b) { mode_sleep_button_ = b; }

  // Switch action setters
  void set_switch_request_rate(bool val);
  void set_switch_hp_led(bool val);
  void set_switch_auto_mode(bool val);
  void set_in_bed_state(int state);

  // Action methods
  void cmd_reset();
  void cmd_mode_fall();
  void cmd_mode_sleep();

  // Fall mode - installation
  void cmd_set_install_angle(int16_t x, int16_t y, int16_t z);
  void cmd_set_install_height(uint16_t height);
  void set_install_angle(int16_t x, int16_t y, int16_t z) {
    install_angle_x_ = x;
    install_angle_y_ = y;
    install_angle_z_ = z;
  }
  void set_install_height(uint16_t height) { install_height_ = height; }
  void cmd_auto_measure_height();
  void request_install_angle();
  void request_install_height();
  void request_auto_measure_height();

  // Fall mode - configuration
  void cmd_set_fall_sensitivity(uint8_t sensitivity);
  void cmd_set_fall_break_height(uint16_t height);
  void cmd_set_residence_time(uint32_t seconds);
  void cmd_set_residence_switch(bool enabled);
  void cmd_set_alt_time(uint32_t seconds);
  void cmd_set_report_frequency(uint32_t ms);
  void cmd_set_report_switch(bool enabled);
  void cmd_set_height_ratio_switch(bool enabled);
  void cmd_set_fall_time(uint32_t seconds);
  void cmd_set_unmanned_time(uint32_t seconds);
  void cmd_set_seated_distance(uint16_t distance);
  void cmd_set_motion_distance(uint16_t distance);

  // Fall mode - data query methods
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

  // Fall mode sensor setters
  void set_install_angle_x_sensor(sensor::Sensor *s) { install_angle_x_sensor_ = s; }
  void set_install_angle_y_sensor(sensor::Sensor *s) { install_angle_y_sensor_ = s; }
  void set_install_angle_z_sensor(sensor::Sensor *s) { install_angle_z_sensor_ = s; }
  void set_install_height_sensor(sensor::Sensor *s) { install_height_sensor_ = s; }
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
  void set_seated_distance_sensor(sensor::Sensor *s) { seated_distance_sensor_ = s; }
  void set_motion_distance_sensor(sensor::Sensor *s) { motion_distance_sensor_ = s; }

  // Sleep mode - configuration
  void cmd_set_reporting_mode(uint8_t mode);
  void cmd_set_abnormal_struggle(bool enabled);
  void cmd_set_unattended_state(bool enabled);
  void cmd_set_unattended_time(uint8_t minutes);
  void cmd_set_sleep_deadline(uint8_t hours);

  // Sleep mode - data queries
  void request_in_bed();
  void request_sleep_state();
  void request_wake_duration();
  void request_light_sleep();
  void request_deep_sleep();
  void request_sleep_quality();
  void request_reporting_mode();
  void request_sleep_disturbances();
  void request_sleep_quality_rating();
  void request_abnormal_struggle();
  void request_unattended_state();
  void request_abnormal_struggle_switch();
  void request_unattended_switch();
  void request_unattended_time();
  void request_sleep_deadline();
  void request_breathe_state();
  void request_breathe_value();
  void request_sleep_composite();
  void request_sleep_statistics();

  // Sleep mode sensor setters
  void set_in_bed_sensor(sensor::Sensor *s) { in_bed_sensor_ = s; }
  void set_sleep_state_sensor(sensor::Sensor *s) { sleep_state_sensor_ = s; }
  void set_wake_duration_sensor(sensor::Sensor *s) { wake_duration_sensor_ = s; }
  void set_light_sleep_sensor(sensor::Sensor *s) { light_sleep_sensor_ = s; }
  void set_deep_sleep_sensor(sensor::Sensor *s) { deep_sleep_sensor_ = s; }
  void set_sleep_quality_sensor(sensor::Sensor *s) { sleep_quality_sensor_ = s; }
  void set_sleep_disturbances_sensor(sensor::Sensor *s) { sleep_disturbances_sensor_ = s; }
  void set_sleep_quality_rating_sensor(sensor::Sensor *s) { sleep_quality_rating_sensor_ = s; }
  void set_unattended_time_sensor(sensor::Sensor *s) { unattended_time_sensor_ = s; }
  void set_sleep_deadline_sensor(sensor::Sensor *s) { sleep_deadline_sensor_ = s; }
  void set_breathe_state_sensor(sensor::Sensor *s) { breathe_state_sensor_ = s; }
  void set_breathe_value_sensor(sensor::Sensor *s) { breathe_value_sensor_ = s; }

  void setup() override;
  void loop() override;
  void update() override;
  void dump_config() override;
  void sync_configuration();
  void drain_uart();
  void apply_install_config();

 protected:
  sensor::Sensor *heart_rate_sensor_{nullptr};
  sensor::Sensor *breath_rate_sensor_{nullptr};
  sensor::Sensor *human_distance_sensor_{nullptr};
  sensor::Sensor *human_move_range_sensor_{nullptr};
  binary_sensor::BinarySensor *presence_sensor_{nullptr};

  text_sensor::TextSensor *status_text_sensor_{nullptr};
  text_sensor::TextSensor *movement_text_sensor_{nullptr};
  text_sensor::TextSensor *fall_status_text_sensor_{nullptr};
  text_sensor::TextSensor *sleep_status_text_sensor_{nullptr};
  text_sensor::TextSensor *static_residency_text_sensor_{nullptr};

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
  sensor::Sensor *seated_distance_sensor_{nullptr};
  sensor::Sensor *motion_distance_sensor_{nullptr};

  sensor::Sensor *in_bed_sensor_{nullptr};
  sensor::Sensor *sleep_state_sensor_{nullptr};
  sensor::Sensor *wake_duration_sensor_{nullptr};
  sensor::Sensor *light_sleep_sensor_{nullptr};
  sensor::Sensor *deep_sleep_sensor_{nullptr};
  sensor::Sensor *sleep_quality_sensor_{nullptr};
  sensor::Sensor *sleep_disturbances_sensor_{nullptr};
  sensor::Sensor *sleep_quality_rating_sensor_{nullptr};
  sensor::Sensor *unattended_time_sensor_{nullptr};
  sensor::Sensor *sleep_deadline_sensor_{nullptr};
  sensor::Sensor *breathe_state_sensor_{nullptr};
  sensor::Sensor *breathe_value_sensor_{nullptr};

  int16_t install_angle_x_{0};
  int16_t install_angle_y_{0};
  int16_t install_angle_z_{0};
  int16_t install_height_{-1};

  bool auto_mode_{false};
  bool in_bed_state_{false};
  int last_auto_mode_in_bed_state_{-1};
  uint32_t in_bed_changed_at_{0};

  // Non-blocking update state machine
  bool pending_update_{false};
  bool switch_request_rate_{false};
  bool debug_output_{true};
  int update_phase_{0};
  uint32_t last_request_time_{0};
  static const uint32_t REQUEST_INTERVAL_MS = 5;
  void send_next_update_request();
};

}  // namespace dfrobot_sen0623
}  // namespace esphome