import esphome.codegen as cg
from esphome.components import sensor
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_EMPTY,
    STATE_CLASS_MEASUREMENT,
    UNIT_BEATS_PER_MINUTE,
    UNIT_CENTIMETER,
    UNIT_SECOND,
    UNIT_MINUTE,
)
from . import CONF_DFROBOT_SEN0623_ID, DfrobotSen0623Component

DEPENDENCIES = ["dfrobot_sen0623"]

# Core sensors
CONF_HEART_RATE = "heart_rate"
CONF_BREATH_RATE = "breath_rate"
CONF_HUMAN_DISTANCE = "human_distance"
CONF_HUMAN_MOVE_RANGE = "human_move_range"

# Fall mode - installation
CONF_INSTALL_ANGLE_X = "install_angle_x"
CONF_INSTALL_ANGLE_Y = "install_angle_y"
CONF_INSTALL_ANGLE_Z = "install_angle_z"
CONF_INSTALL_HEIGHT = "install_height"

# Fall mode - data
CONF_FALL_STATE = "fall_state"
CONF_STATIC_RESIDENCY = "static_residency"
CONF_STATIC_RESIDENCY_TIME = "static_residency_time"
CONF_FALL_TIME = "fall_time"
CONF_FALL_SENSITIVITY = "fall_sensitivity"
CONF_FALL_BREAK_HEIGHT = "fall_break_height"
CONF_TRACK_X = "track_x"
CONF_TRACK_Y = "track_y"
CONF_UNMANNED_TIME = "unmanned_time"
CONF_ACCUMULATED_HEIGHT_DURATION = "accumulated_height_duration"
CONF_SEATED_DISTANCE = "seated_distance"
CONF_MOTION_DISTANCE = "motion_distance"

# Sleep mode - data
CONF_IN_BED = "in_bed"
CONF_SLEEP_STATE = "sleep_state"
CONF_WAKE_DURATION = "wake_duration"
CONF_LIGHT_SLEEP = "light_sleep"
CONF_DEEP_SLEEP = "deep_sleep"
CONF_SLEEP_QUALITY = "sleep_quality"
CONF_SLEEP_DISTURBANCES = "sleep_disturbances"
CONF_SLEEP_QUALITY_RATING = "sleep_quality_rating"
CONF_UNATTENDED_TIME = "unattended_time"
CONF_SLEEP_DEADLINE = "sleep_deadline"
CONF_BREATHE_STATE = "breathe_state"
CONF_BREATHE_VALUE = "breathe_value"


CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(CONF_DFROBOT_SEN0623_ID): cv.use_id(DfrobotSen0623Component),
    
    # Core sensors
    cv.Optional(CONF_HEART_RATE): sensor.sensor_schema(
        unit_of_measurement=UNIT_BEATS_PER_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_BREATH_RATE): sensor.sensor_schema(
        unit_of_measurement=UNIT_BEATS_PER_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_HUMAN_DISTANCE): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_HUMAN_MOVE_RANGE): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    
    # Fall mode - installation
    cv.Optional(CONF_INSTALL_ANGLE_X): sensor.sensor_schema(
        unit_of_measurement="°",
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_INSTALL_ANGLE_Y): sensor.sensor_schema(
        unit_of_measurement="°",
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_INSTALL_ANGLE_Z): sensor.sensor_schema(
        unit_of_measurement="°",
        accuracy_decimals=1,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_INSTALL_HEIGHT): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    
    # Fall mode - data
    cv.Optional(CONF_FALL_STATE): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_STATIC_RESIDENCY): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_STATIC_RESIDENCY_TIME): sensor.sensor_schema(
        unit_of_measurement=UNIT_SECOND,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_FALL_TIME): sensor.sensor_schema(
        unit_of_measurement=UNIT_SECOND,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_FALL_SENSITIVITY): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_FALL_BREAK_HEIGHT): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_TRACK_X): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_TRACK_Y): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_UNMANNED_TIME): sensor.sensor_schema(
        unit_of_measurement=UNIT_SECOND,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_ACCUMULATED_HEIGHT_DURATION): sensor.sensor_schema(
        unit_of_measurement=UNIT_SECOND,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SEATED_DISTANCE): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_MOTION_DISTANCE): sensor.sensor_schema(
        unit_of_measurement=UNIT_CENTIMETER,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    
    # Sleep mode - data
    cv.Optional(CONF_IN_BED): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SLEEP_STATE): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_WAKE_DURATION): sensor.sensor_schema(
        unit_of_measurement=UNIT_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_LIGHT_SLEEP): sensor.sensor_schema(
        unit_of_measurement=UNIT_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_DEEP_SLEEP): sensor.sensor_schema(
        unit_of_measurement=UNIT_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SLEEP_QUALITY): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SLEEP_DISTURBANCES): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SLEEP_QUALITY_RATING): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_UNATTENDED_TIME): sensor.sensor_schema(
        unit_of_measurement=UNIT_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_SLEEP_DEADLINE): sensor.sensor_schema(
        unit_of_measurement=UNIT_MINUTE,
        accuracy_decimals=0,
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_BREATHE_STATE): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
    cv.Optional(CONF_BREATHE_VALUE): sensor.sensor_schema(
        device_class=DEVICE_CLASS_EMPTY,
        state_class=STATE_CLASS_MEASUREMENT,
    ),
})


async def to_code(config):
    parent = await cg.get_variable(config[CONF_DFROBOT_SEN0623_ID])

    # Core sensors
    if conf := config.get(CONF_HEART_RATE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_heart_rate_sensor(sens))

    if conf := config.get(CONF_BREATH_RATE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_breath_rate_sensor(sens))

    if conf := config.get(CONF_HUMAN_DISTANCE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_human_distance_sensor(sens))

    if conf := config.get(CONF_HUMAN_MOVE_RANGE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_human_move_range_sensor(sens))
    
    # Fall mode - installation
    if conf := config.get(CONF_INSTALL_ANGLE_X):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_install_angle_x_sensor(sens))
    if conf := config.get(CONF_INSTALL_ANGLE_Y):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_install_angle_y_sensor(sens))
    if conf := config.get(CONF_INSTALL_ANGLE_Z):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_install_angle_z_sensor(sens))
    if conf := config.get(CONF_INSTALL_HEIGHT):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_install_height_sensor(sens))
    
    # Fall mode - data
    if conf := config.get(CONF_FALL_STATE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_fall_state_sensor(sens))
    if conf := config.get(CONF_STATIC_RESIDENCY):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_static_residency_sensor(sens))
    if conf := config.get(CONF_STATIC_RESIDENCY_TIME):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_static_residency_time_sensor(sens))
    if conf := config.get(CONF_FALL_TIME):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_fall_time_sensor(sens))
    if conf := config.get(CONF_FALL_SENSITIVITY):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_fall_sensitivity_sensor(sens))
    if conf := config.get(CONF_FALL_BREAK_HEIGHT):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_fall_break_height_sensor(sens))
    if conf := config.get(CONF_TRACK_X):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_track_x_sensor(sens))
    if conf := config.get(CONF_TRACK_Y):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_track_y_sensor(sens))
    if conf := config.get(CONF_UNMANNED_TIME):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_unmanned_time_sensor(sens))
    if conf := config.get(CONF_ACCUMULATED_HEIGHT_DURATION):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_accumulated_height_duration_sensor(sens))
    if conf := config.get(CONF_SEATED_DISTANCE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_seated_distance_sensor(sens))
    if conf := config.get(CONF_MOTION_DISTANCE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_motion_distance_sensor(sens))
    
    # Sleep mode - data
    if conf := config.get(CONF_IN_BED):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_in_bed_sensor(sens))
    if conf := config.get(CONF_SLEEP_STATE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_sleep_state_sensor(sens))
    if conf := config.get(CONF_WAKE_DURATION):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_wake_duration_sensor(sens))
    if conf := config.get(CONF_LIGHT_SLEEP):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_light_sleep_sensor(sens))
    if conf := config.get(CONF_DEEP_SLEEP):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_deep_sleep_sensor(sens))
    if conf := config.get(CONF_SLEEP_QUALITY):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_sleep_quality_sensor(sens))
    if conf := config.get(CONF_SLEEP_DISTURBANCES):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_sleep_disturbances_sensor(sens))
    if conf := config.get(CONF_SLEEP_QUALITY_RATING):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_sleep_quality_rating_sensor(sens))
    if conf := config.get(CONF_UNATTENDED_TIME):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_unattended_time_sensor(sens))
    if conf := config.get(CONF_SLEEP_DEADLINE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_sleep_deadline_sensor(sens))
    if conf := config.get(CONF_BREATHE_STATE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_breathe_state_sensor(sens))
    if conf := config.get(CONF_BREATHE_VALUE):
        sens = await sensor.new_sensor(conf)
        cg.add(parent.set_breathe_value_sensor(sens))