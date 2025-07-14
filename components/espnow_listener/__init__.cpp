#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

static const auto CONFIG_SCHEMA = register_component<ESPNowListener>("espnow_listener")
  .overrideable()
  .add_required_sub_component("text_sensor");

}  // namespace espnow_listener
}  // namespace esphome
