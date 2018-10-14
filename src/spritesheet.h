#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#ifdef QT_DEBUG
#include <iostream>
#endif

#include "defines.h"
#include <SFML/Graphics.hpp>
#include <vector>

class SpriteSheet {
public:
  SpriteSheet(sf::Texture &texture);

  std::vector<sf::Image> const &getImgSheet() const;

private:
  std::vector<sf::Image> imgSheet;
};

#endif // SPRITESHEET_H
