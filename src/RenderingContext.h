#pragma once

#include <memory>
#include <unordered_map>

#include "Object.h"
#include "Renderer/Renderer.h"

enum RenderingContextType { DirectX = 0, OpenGL = 1, Vulcan = 2 };

class RenderingContext : public Renderer {
 public:
  RenderingContext(const RenderingContextType &type);
  ~RenderingContext() = default;

  void Clear() const override;
  void Draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const override;

  int IncludeObject(const Object &object);
  void ExcludeObject(const unsigned int objectId);

 private:
  std::shared_ptr<Renderer> renderer;
  std::unordered_map<unsigned int, Object> objects;
};
