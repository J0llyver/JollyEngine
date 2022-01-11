#pragma once

#include "Component.h"

namespace gui {
class FrameData : public Component {
 public:
  FrameData() = default;
  ~FrameData() = default;

  virtual void render();
  virtual ComponentType getType();
};
}  // namespace gui
