#pragma once

namespace gui {
class Component {
 public:
  Component() = default;
  virtual ~Component() = default;
  virtual void render() = 0;
};
}  // namespace gui
