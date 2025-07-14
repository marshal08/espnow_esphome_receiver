#include "espnow_listener.h"
#include "esphome/core/log.h"

namespace esphome {
namespace espnow_listener {

static ESPNowListener *instance = nullptr;

void ESPNowListener::set_text_sensor(text_sensor::TextSensor *sensor) {
  this->text_sensor_ = sensor;
}

void ESPNowListener::setup() {
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    ESP_LOGE("espnow_listener", "❌ ESP-NOW initialization failed");
    return;
  }

  instance = this;
  esp_now_register_recv_cb([](const uint8_t *mac, const uint8_t *data, int len) {
    if (instance && instance->text_sensor_) {
      std::string payload(reinterpret_cast<const char *>(data), len);
      ESP_LOGI("espnow_listener", "📦 Received: %s", payload.c_str());
      instance->text_sensor_->publish_state(payload);
    }
  });

  ESP_LOGD("espnow_listener", "✅ ESP-NOW initialized");
}

void ESPNowListener::dump_config() {
  ESP_LOGCONFIG("espnow_listener", "ESP-NOW Listener active");
}

}  // namespace espnow_listener
}  // namespace esphome
