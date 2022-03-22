#pragma once

#include "Object.h"
#include "glm/glm.hpp"

#include <list>
#include <memory>

/**
 * This is the component whith which the scenery of a game is created.
 * For more information, refer to the Scenery class.
 */
class SceneryNode : public std::enable_shared_from_this<SceneryNode> {
 public:
  /**
   * Constructor for creating the root node of a scenery tree.
   * @param obejctId: The id of the object which's transformation will be managed by this scenery node.
   */
  SceneryNode(const uint32_t objectId);

  /**
   * Constructor for creating inner nodes or leaves of the scenery tree.
   * @param obejctId: The id of the object which's transformation will be managed by this scenery node.
   * @param parent: The parent of the this scenery node.
   */
  SceneryNode(const uint32_t objectId, std::shared_ptr<SceneryNode> parent);

  /**
   * Destructor
   */
  ~SceneryNode() = default;

  /**
   * Returns the id of the object which's transformation is managed by this scenery node.
   * return objectId.
   */
  const uint32_t getManagedObjectId() const;

  /**
   * Returns the world transformation matrix for the managed object.
   * @return world transformation matrix.
   */
  glm::mat4 getWorldTransformationMatrix() const;

  /**
   * Sets the parent of this node if the current parent equals 'nullptr'.
   * Otherwise this function does nothing.
   */
  void setParent(std::shared_ptr<SceneryNode> newParent);

  /**
   * Creates a new scenery node and adds it to the children of this node.
   * @param objectId: The id of the object which will be managed by the newly created child.
   * @return a shared pointer to the newly created child.
   */
  std::shared_ptr<SceneryNode> createChild(const uint32_t objectId);

  /**
   * Creates a new scenery node and adds it to the children of this node.
   * @param child: The child which will be add to this node's children.
   */
  void addChild(std::shared_ptr<SceneryNode> child);

  /**
   * Returns a reference to this node's list of children.
   * @returns this nodes children.
   */
  std::list<std::shared_ptr<SceneryNode>> &getChildren();

  /**
   * Finds the child which manages an object with objectId.
   * @param objectId: the id of the object which is supposedly  managed by a child.
   * @return iterator to the child, if it exists.
   *         chilren.end(), if the child does not exist.
   */
  std::list<std::shared_ptr<SceneryNode>>::iterator findChildWhichManagesObject(const uint32_t objectId);

  /**
   * Checks if the scenery node has a child which manages an object with objectId.
   * @param objectId: the id of the object which is supposedly  managed by a child.
   * @return true if such a child exists.
   *          false otherwise.
   */
  bool hasChildWhichManagesObject(const uint32_t objectId);

  /**
   * Determinse if this node is a root node by checking if it has a parent.
   * @return true if the parent is NULL
   *          false if the parent is not NULL
   */
  bool isRoot() const;

  /**
   * Returns the parent of this node.
   * If this node is the root node, it return itself, instead.
   * @return parent scenery node.
   */
  std::shared_ptr<SceneryNode> getParent() const;

  /**
   * Removes a child from the children without deleting the child.
   * @param child: the child node which will be removed.
   * @return the removed child node, if it exists.
   *         nullptr otherwise
   */
  void removeChild(std::shared_ptr<SceneryNode> child);

  /**
   * Replaces the current parent of this node with newParent.
   * @param newParent: The replacement parent for the current parent.
   */
  void changeParent(std::shared_ptr<SceneryNode> newParent);

  bool operator==(const SceneryNode &node) const;

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
  std::shared_ptr<SceneryNode> parent;

  /**
   * The children of this scenery node.
   */
  std::list<std::shared_ptr<SceneryNode>> children;

  /**
   * Updates the world transformation matrix according to the referenced object's local transformation and the parent's
   * world space transformation.
   */
  void updateWorldTransformationMatrix();
};
