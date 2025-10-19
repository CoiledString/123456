#pragma once
#include "esphome.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

namespace esphome {
namespace mp3player {

class MP3PlayerOutput : public Component, public BinaryOutput {
 public:
  void setup() override {
    SoftwareSerial softwareSerial(D5, D2);
    softwareSerial.begin(9600);
    if (!dfplayer_.begin(softwareSerial)) {
      ESP_LOGE("mp3player", "DFPlayer init failed");
      return;
    }
    dfplayer_.volume(30);
  }

  void write_state(bool state) override {
    if (state) {
      dfplayer_.loop(1);
    } else {
      dfplayer_.stop();
    }
  }

 protected:
  DFRobotDFPlayerMini dfplayer_;
};

}  // namespace mp3player
}  // namespace esphome
