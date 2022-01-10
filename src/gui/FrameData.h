#pragma once

#include "Component.h"

namespace gui {
class FrameData : public Component {
 public:
  FrameData() = default;
  ~FrameData() = default;

  virtual void render();
};
}  // namespace gui
