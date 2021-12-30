#include "RenderingContext.h"

#include <stdexcept>

#include "Renderer/OpenGlRenderer.h"

RenderingContext::RenderingContext(const RenderingContextType &type) {
  switch (type) {
    case RenderingContextType::DirectX: {
      std::runtime_error("DirectX has not been integrated into the engine yet. Please use another graphics API.");
      // TODO: Implement DirectX Renderer
      break;
    }
    case RenderingContextType::OpenGL: {
      renderer = std::make_shared<OpenGlRenderer>();
      break;
    }
    case RenderingContextType::Vulcan: {
      std::runtime_error("Vulcan has not been integrated into the engine yet. Please use another graphics API.");
      // TODO: Implement Vulcan Renderer
      break;
    }
    default: {
      renderer = std::make_shared<OpenGlRenderer>();
    }
  }
}

void RenderingContext::Clear() const { renderer->Clear(); }

void RenderingContext::Draw(const Mesh &mesh, std::shared_ptr<Shader> &shader) const { renderer->Draw(mesh, shader); }

int RenderingContext::IncludeObject(const Object &object) {
  int objectId = objects.size();

  objects.insert(std::pair<unsigned int, Object>(objectId, object));

  return objectId;
}

void RenderingContext::ExcludeObject(const unsigned int objectId) { objects.erase(objectId); }
