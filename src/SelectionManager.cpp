#include "SelectionManager.h"

SelectionManager* SelectionManager::getInstance() {
  static SelectionManager instance;
  return &instance;
}
