import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import text_sensor
from esphome.const import CONF_NAME

espnow_listener_ns = cg.esphome_ns.namespace("espnow_listener")
ESPNowListener = espnow_listener_ns.class_("ESPNowListener", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(ESPNowListener),
    cv.Required("text_sensor"): text_sensor.TEXT_SENSOR_SCHEMA,
})

async def to_code(config):
    var = cg.new_Pvariable(config[cv.GenerateID()])
    await cg.register_component(var, config)
    sens = await text_sensor.new_text_sensor(config["text_sensor"])
    cg.add(var.set_text_sensor(sens))
