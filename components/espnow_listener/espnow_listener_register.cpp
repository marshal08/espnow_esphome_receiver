#include "espnow_listener.h"
#include "esphome/core/application.h"

ESPHOME_NAMESPACE_BEGIN

namespace espnow_listener {

ESPHomeComponentFactory::RegisterHelper __register_espnow_listener("espnow_listener", [](ConfigReader &config, Application &app) {
  auto *comp = new ESPNowListener();
  auto *sensor = new text_sensor::TextSensor();
  comp->set_text_sensor(sensor);
  app.register_component(comp);
  app.register_text_sensor("ESP-NOW Payload", sensor);  // You can customize name later in YAML
  return comp;
});

}  // namespace espnow_listener

ESPHOME_NAMESPACE_END
