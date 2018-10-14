#include "input.h"

Input::Input() {
  for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
    keyMap.push_back(0);
}

vector<int> *Input::getKeyMap() { return &keyMap; }
