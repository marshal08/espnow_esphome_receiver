#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

static const auto COMPONENT_SCHEMA = register_component<ESPNowListener>("espnow_listener")
  .then([](ESPNowListener *comp, const esphome::yaml::YAML::Node &config) {
    auto *sensor = new text_sensor::TextSensor();
    sensor->set_name(config["text_sensor"]["name"].as<std::string>());
    comp->set_text_sensor(sensor);
    App.register_text_sensor(sensor);
  });

}  // namespace espnow_listener
}  // namespace esphome
