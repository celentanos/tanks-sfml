#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#ifdef QT_DEBUG
#include <iostream>
#endif

#include "defines.h"
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class SpriteSheet {
public:
  SpriteSheet(sf::Texture &texture);

  sf::Texture &getTexture();

  sf::IntRect getBoundingIntRect(uint color, uint enemy, uint tank_level,
                                  uint direction, uint animation);

private:
  sf::Texture &texture;
  vector<vector<vector<vector<vector<Vector4<uint>>>>>>
      tank; // color, enemy, tank, direction, animation

  Vector4<uint> findImgBoundings(sf::Image &img);
};

#endif // SPRITESHEET_H
