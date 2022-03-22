#include "Scenery/SceneryNode.h"

#include <gtest/gtest.h>

#include <memory>

TEST(TestSceneryNode, createAndDestroy) {
  // Arrange
  uint32_t rootObject = 0;

  // Act
  auto rootNode = std::make_shared<SceneryNode>(rootObject);

  ASSERT_NE(rootNode, nullptr);
}

TEST(TestSceneryNode, addChild) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);

  const uint32_t objectId = 1;
  auto childNode = std::make_shared<SceneryNode>(objectId);

  // Act
  rootNode->addChild(childNode);

  // Assert
  ASSERT_EQ(rootNode->getChildren().back()->getManagedObjectId(), 1);
}

TEST(TestSceneryNode, getChildren) {
  // Arrange
  auto rootNodeWithoutChildren = std::make_shared<SceneryNode>(0);
  auto rootNodeWithChild = std::make_shared<SceneryNode>(0);

  const uint32_t objectId = 1;
  rootNodeWithChild->createChild(objectId);

  // Act
  std::list<std::shared_ptr<SceneryNode>> &noChildren = rootNodeWithoutChildren->getChildren();
  std::list<std::shared_ptr<SceneryNode>> &oneChild = rootNodeWithChild->getChildren();

  // Assert
  ASSERT_EQ(noChildren.size(), 0);
  ASSERT_EQ(oneChild.size(), 1);
}

TEST(TestSceneryNode, getParent) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);
  std::shared_ptr<SceneryNode> childNode = rootNode->createChild(1);

  // Act
  const auto rootParent = rootNode->getParent();
  const auto childParent = childNode->getParent();

  // Assert
  ASSERT_EQ(rootParent, nullptr);
  ASSERT_EQ(childParent, rootNode);
}

TEST(TestSceneryNode, setParent) {
  // Arrange
  auto parentNode = std::make_shared<SceneryNode>(0);

  const uint32_t objectId = 1;
  auto childNode = std::make_shared<SceneryNode>(objectId);

  // Act
  childNode->setParent(parentNode);

  // Assert
  ASSERT_EQ(*parentNode, *(childNode->getParent()));
}

TEST(TestSceneryNode, findChildWhichManagesObject) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);

  const uint32_t objectId = 1;
  rootNode->createChild(objectId);

  // Act
  auto childIterator = rootNode->findChildWhichManagesObject(objectId);
  auto childrenEnd = rootNode->findChildWhichManagesObject(2);

  // Assert
  ASSERT_NE(childIterator, rootNode->getChildren().end());
  ASSERT_EQ((*childIterator)->getManagedObjectId(), objectId);
  ASSERT_EQ(childrenEnd, rootNode->getChildren().end());
}

TEST(TestSceneryNode, hasChildWhichManagesObject) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);

  const uint32_t objectId = 1;
  rootNode->createChild(objectId);

  // Act
  const uint32_t expectTrue = rootNode->hasChildWhichManagesObject(objectId);
  const uint32_t expectFalse = rootNode->hasChildWhichManagesObject(2);

  // Assert
  ASSERT_EQ(expectTrue, true);
  ASSERT_EQ(expectFalse, false);
}

TEST(TestSceneryNode, isRoot) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);
  std::shared_ptr<SceneryNode> childNode = rootNode->createChild(1);

  // Act
  const bool isRoot = rootNode->isRoot();
  const bool isNoRoot = not childNode->isRoot();

  // Assert
  ASSERT_TRUE(isRoot);
  ASSERT_TRUE(isNoRoot);
}

TEST(TestSceneryNode, removeChild) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);
  std::shared_ptr<SceneryNode> childNode = rootNode->createChild(1);

  // Act
  rootNode->removeChild(childNode);

  // Assert
  ASSERT_TRUE(rootNode->getChildren().empty());
}

TEST(TestSceneryNode, changeParent) {
  // Arrange
  auto rootNode = std::make_shared<SceneryNode>(0);

  const uint32_t objectA = 1;
  auto childA = rootNode->createChild(objectA);

  const uint32_t objectB = 2;
  auto childB = rootNode->createChild(objectB);

  // Act
  childB->changeParent(childA);

  // Assert
  ASSERT_EQ(childB->getParent()->getManagedObjectId(), objectA);
  ASSERT_EQ(childA->getChildren().size(), 1);
}
