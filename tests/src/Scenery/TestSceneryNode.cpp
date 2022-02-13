#include "Scenery/SceneryNode.h"

#include <gtest/gtest.h>

TEST(TestSceneryNode, CreateAndDestroy) {
  uint32_t rootObject = 0;
  SceneryNode sceneryNode(rootObject, nullptr);
}

TEST(TestSceneryNode, GetParent) {
  uint32_t rootObject = 0;
  SceneryNode sceneryNode(rootObject, nullptr);

  // TODO: Properly implement test
}
