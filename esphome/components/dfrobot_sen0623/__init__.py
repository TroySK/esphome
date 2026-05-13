import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import uart
from esphome.components import binary_sensor
from esphome.const import CONF_ID, CONF_MOTION, DEVICE_CLASS_MOTION

DEPENDENCIES = ["uart"]

CONF_DFROBOT_SEN0623_ID = "dfrobot_sen0623_id"

CONF_INSTALL_ANGLE_X = "install_angle_x"
CONF_INSTALL_ANGLE_Y = "install_angle_y"
CONF_INSTALL_ANGLE_Z = "install_angle_z"
CONF_INSTALL_HEIGHT = "install_height"

dfrobot_sen0623_ns = cg.esphome_ns.namespace("dfrobot_sen0623")
DfrobotSen0623Component = dfrobot_sen0623_ns.class_(
    "DfrobotSen0623Component", cg.PollingComponent, uart.UARTDevice
)

CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(DfrobotSen0623Component),
            cv.Optional(CONF_MOTION): binary_sensor.binary_sensor_schema(
                device_class=DEVICE_CLASS_MOTION
            ),
            cv.Optional(CONF_INSTALL_ANGLE_X, default=0): cv.int_,
            cv.Optional(CONF_INSTALL_ANGLE_Y, default=0): cv.int_,
            cv.Optional(CONF_INSTALL_ANGLE_Z, default=0): cv.int_,
            cv.Optional(CONF_INSTALL_HEIGHT): cv.int_,
        }
    )
    .extend(cv.COMPONENT_SCHEMA)
    .extend(uart.UART_DEVICE_SCHEMA)
    .extend(cv.polling_component_schema("30s"))
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await uart.register_uart_device(var, config)

    if config.get(CONF_INSTALL_HEIGHT) is not None:
        cg.add(var.set_install_height(config[CONF_INSTALL_HEIGHT]))

    if any(config.get(x) is not None for x in [CONF_INSTALL_ANGLE_X, CONF_INSTALL_ANGLE_Y, CONF_INSTALL_ANGLE_Z]):
        cg.add(var.set_install_angle(
            config.get(CONF_INSTALL_ANGLE_X, 0),
            config.get(CONF_INSTALL_ANGLE_Y, 0),
            config.get(CONF_INSTALL_ANGLE_Z, 0),
        ))
