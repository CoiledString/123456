#pragma once
#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "mp3player.h"

namespace esphome {
namespace mp3player {

MP3PlayerOutput *mp3player_output = new MP3PlayerOutput();

}  // namespace mp3player
}  // namespace esphome
