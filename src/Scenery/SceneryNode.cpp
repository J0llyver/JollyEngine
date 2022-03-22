#include "SceneryNode.h"

#include <algorithm>

SceneryNode::SceneryNode(const uint32_t objectId) : managedObjectId(objectId), parent(nullptr) {}

SceneryNode::SceneryNode(const uint32_t objectId, std::shared_ptr<SceneryNode> parent)
    : managedObjectId(objectId), parent(parent) {
  updateWorldTransformationMatrix();
}

glm::mat4 SceneryNode::getWorldTransformationMatrix() const { return worldTransformationMatrix; }

const uint32_t SceneryNode::getManagedObjectId() const { return managedObjectId; }

void SceneryNode::setParent(std::shared_ptr<SceneryNode> newParent) {
  if (parent == nullptr) {
    parent = newParent;
  }
}

std::shared_ptr<SceneryNode> SceneryNode::createChild(const uint32_t objectId) {
  auto newChild = std::make_shared<SceneryNode>(objectId);

  newChild->setParent(shared_from_this());

  children.push_back(newChild);

  return newChild;
}

void SceneryNode::addChild(std::shared_ptr<SceneryNode> child) {
  child->setParent(shared_from_this());
  children.push_back(child);
}

std::list<std::shared_ptr<SceneryNode>> &SceneryNode::getChildren() { return children; }

std::list<std::shared_ptr<SceneryNode>>::iterator SceneryNode::findChildWhichManagesObject(const uint32_t objectId) {
  auto childHasId = [&](const std::shared_ptr<SceneryNode> child) -> bool {
    return child->getManagedObjectId() == objectId;
  };
  return std::find_if(children.begin(), children.end(), childHasId);
}

bool SceneryNode::hasChildWhichManagesObject(const uint32_t objectId) {
  return findChildWhichManagesObject(objectId) != children.end();
}

bool SceneryNode::isRoot() const { return parent == nullptr; }

std::shared_ptr<SceneryNode> SceneryNode::getParent() const { return parent; }

void SceneryNode::removeChild(std::shared_ptr<SceneryNode> child) {
  auto childIterator = std::find(children.begin(), children.end(), child);

  if (childIterator != children.end()) {
    children.erase(childIterator);
  }
}

void SceneryNode::changeParent(std::shared_ptr<SceneryNode> newParent) {
  parent->removeChild(shared_from_this());
  newParent->addChild(shared_from_this());
  parent = newParent;
}

void SceneryNode::updateWorldTransformationMatrix() {
  // TODO: Replace with model matrix of manage object.
  const glm::mat4 tempModelMatrix(0);
  worldTransformationMatrix = parent->getWorldTransformationMatrix() * tempModelMatrix;
}

bool SceneryNode::operator==(const SceneryNode &node) const { return managedObjectId == node.getManagedObjectId(); }
