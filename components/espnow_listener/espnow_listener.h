#pragma once
#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"

namespace esphome {
namespace espnow_listener {

class ESPNowListener : public Component {
 public:
  void set_text_sensor(text_sensor::TextSensor *sensor) { this->sensor_ = sensor; }
  void setup() override;
  void dump_config() override;
  void loop() override {}

 protected:
  text_sensor::TextSensor *sensor_;
};

}  // namespace espnow_listener
}  // namespace esphome
