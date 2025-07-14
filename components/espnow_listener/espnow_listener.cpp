#include "espnow_listener.h"

namespace esphome {
namespace espnow_listener {

ESPNowListener *ESPNowListener::instance = nullptr;

class ESPNowListener : public Component {
 public:
  void setup() override;
  void dump_config() override;
};

}  // namespace espnow_listener
}  // namespace esphome

