#include "src/Renderer/Renderer.h"

#include "src/Mesh/MeshFactory.h"

void Renderer::clear() {
  renderer.clear();
}

void Renderer::draw(const std::string &meshId, std::shared_ptr<Shader> &shader) {
  renderer.draw(MeshFactory::getInstance()->getMesh(meshId), shader);
}