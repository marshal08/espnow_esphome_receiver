#pragma once
#include "esphome/core/component.h"
#include "esphome/components/text_sensor/text_sensor.h"
#include <esp_now.h>
#include <WiFi.h>

namespace esphome {
namespace espnow_listener {

typedef struct {
  char topic[32];
  char payload[32];
} Message;

class ESPNowListener : public Component {
 public:
  text_sensor::TextSensor *text_sensor;

  void set_text_sensor(text_sensor::TextSensor *sensor) {
    text_sensor = sensor;
  }

  void setup() override {
    WiFi.mode(WIFI_STA);
    esp_now_init();
    esp_now_register_recv_cb(on_espnow_receive);
  }

  static void on_espnow_receive(const uint8_t *mac, const uint8_t *data, int len) {
    Message msg;
    memcpy(&msg, data, sizeof(msg));
    ESP_LOGI("espnow_listener", "Received %s → %s", msg.topic, msg.payload);
    if (instance && instance->text_sensor != nullptr) {
      instance->text_sensor->publish_state(std::string(msg.payload));
    }
  }

  static ESPNowListener *instance;
};

ESPNowListener *ESPNowListener::instance = nullptr;

}  // namespace espnow_listener
}  // namespace esphome

