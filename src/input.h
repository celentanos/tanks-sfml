#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>
#include <vector>

using namespace std;

class Input {
public:
  Input();
  vector<int> keyMap;
  vector<int> *getKeyMap();
};

#endif // INPUT_H
