#pragma once

#include "Object.h"
#include "glm/glm.hpp"

#include <list>

/**
 * This is the component whith which the scenery of a game is created.
 * For more information, refer to the Scenery class.
 */
class SceneryNode {
 public:
  /**
   * Constructor for creating inner nodes or leaves of the scenery tree.
   * @param obejctId: The id of the object which's transformation will be managed by this scenery node.
   * @param parent: The parent of the this scenery node.
   */
  SceneryNode(const uint32_t objectId, SceneryNode* parent);

  /**
   * Destructor
   */
  ~SceneryNode() = default;

  /**
   * Returns the parent of this node.
   * If this node is the root node, it returns itself, instead.
   * @returns parent scenery node.
   */
  SceneryNode* getParent();

  /**
   * Returns the id of the object which's transformation is managed by this scenery node.
   * returns objectId.
   */
  uint32_t getManagedObjectId() const;

  /**
   * Returns the object which's transformation is managed by this scenery node
   * returns managed object.
   */
  Object* getManagedObject();

  /**
   * Returns the world transformation matrix for the managed object.
   * @returns world transformation matrix.
   */
  glm::mat4 getWorldTransformationMatrix() const;

  /**
   * Replaces the current parent of this node with newParent.
   * @param newParent: The replacement parent for the current parent.
   */
  void changeParent(SceneryNode &newParent);

  /**
   * Creates a new scenery node and adds it to the children of this node.
   * @param obejctId: The id of the object which's transformation will be managed by child node
   */
  void createChild(const uint32_t objectId);

  /**
   * Adds an existing scenery node to this nodes children.
   */
  void addChild(const SceneryNode &sceneryNode);

  /**
   * Deletes the child with 'childId' from the scenery.
   * @param childId: the id of the child which will be removed.
   */
  void deleteChild(const uint32_t childId);

  /**
   * Updates the world transformation matrix according to the referenced object's local transformation and the parent's
   * world space transformation.
   */
  void updateWorldTransformationMatrix();

 private:
  /**
   * The id of the object which's transformation is managed by this scenery node.
   */
  uint32_t managedObjectId;

  /**
   * Stores the world transformation matrix of the managed object.
   */
  glm::mat4 worldTransformationMatrix;

  /**
   * A reference to the parent of this scenery node.
   * If this is the root node, the reference should be a nullptr.
   */
  SceneryNode* parent;

  /**
   * The children of this scenery node.
   */
  std::list<SceneryNode> children;
};
