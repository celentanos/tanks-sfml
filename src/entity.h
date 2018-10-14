#ifndef ENTITY_H
#define ENTITY_H

#include "collision.h"
#include "defines.h"
#include <SFML/Graphics.hpp>

class Entity {
public:
  enum EntityType { Player, Enemy, Brick, Metall, Water, Wood, Ice };

  Entity(sf::Vector2f pos, EntityType type);
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual sf::Sprite *getSprite() = 0;

protected:
  sf::Vector2f pos;
  sf::Vector2f dim;
  EntityType type;
};

#endif // ENTITY_H
