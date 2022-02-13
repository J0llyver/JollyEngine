#pragma once

class SelectionManager {
 public:
  ~SelectionManager() = default;

  static SelectionManager* getInstance();

 private:
  SelectionManager() = default;
};
