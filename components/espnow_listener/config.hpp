#pragma once

#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

static const auto CONFIG_SCHEMA = register_component<ESPNowListener>("espnow_listener")
  .required("text_sensor", [](const YAML::Node &node, ESPNowListener *comp) {
    auto *sensor = new text_sensor::TextSensor();
    sensor->set_name(node["name"].as<std::string>());
    comp->set_text_sensor(sensor);
    App.register_text_sensor(sensor);
  });

}  // namespace espnow_listener
}  // namespace esphome
