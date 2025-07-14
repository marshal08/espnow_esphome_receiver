#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

static const auto CONFIG_SCHEMA = register_component<ESPNowListener>("espnow_listener")
  .required("text_sensor", [](ESPNowListener *comp, const esphome::yaml::Node &node) {
    auto *sensor = new esphome::text_sensor::TextSensor();
    sensor->set_name(node["name"].as<std::string>());
    comp->set_text_sensor(sensor);
    esphome::App.register_text_sensor(sensor);
  });

}  // namespace espnow_listener
}  // namespace esphome
