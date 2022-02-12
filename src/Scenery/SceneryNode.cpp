#include "SceneryNode.h"

SceneryNode::SceneryNode(const uint32_t objectId, SceneryNode* parent) : managedObjectId(objectId), parent(parent) {
  updateWorldTransformationMatrix();
}

SceneryNode* SceneryNode::getParent() { 
  return parent;
}

uint32_t SceneryNode::getManagedObjectId() const {
  return managedObjectId;
}

Object* SceneryNode::getManagedObject() { 
  // TODO: Implement
  return nullptr;
}

glm::mat4 SceneryNode::getWorldTransformationMatrix() const { return worldTransformationMatrix; }

void SceneryNode::changeParent(SceneryNode& newParent) { parent = &newParent; }

void SceneryNode::createChild(const uint32_t objectId) {
  children.push_back(SceneryNode(objectId, this));  
}

void SceneryNode::addChild(const SceneryNode& sceneryNode) {
  children.push_back(sceneryNode);
}

void SceneryNode::deleteChild(const uint32_t childId) {
  for (auto i = children.begin(); i != children.end(); ++i) {
    if (i->getManagedObjectId() == childId) {
      children.erase(i);
      break;
    }
  }
}

void SceneryNode::updateWorldTransformationMatrix() {
  // TODO: Replace with model matrix of manage object.
  const glm::mat4 tempModelMatrix(0);
  worldTransformationMatrix = parent->getWorldTransformationMatrix() * tempModelMatrix;
}
