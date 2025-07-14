#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

void ESPNowListener::setup() {
  ESPNowListener::instance = this;  // Save instance for static callback
  WiFi.mode(WIFI_STA);
  esp_now_init();
  esp_now_register_recv_cb(on_espnow_receive);
}

}  // namespace espnow_listener
}  // namespace esphome

