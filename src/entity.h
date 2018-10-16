#ifndef ENTITY_H
#define ENTITY_H

#include "collision.h"
#include "defines.h"
#include <SFML/Graphics.hpp>

class Entity {

public:
  virtual ~Entity();
  enum EntityType { Player, Enemy, Brick, Metall, Water, Wood, Ice };

  // slycing solution
  Entity(const Entity &) = delete;
  void operator=(const Entity &) = delete;

  virtual void update() = 0;
  virtual void draw() = 0;
  virtual sf::Sprite *getSprite() = 0;

protected:
  // slycing solution
  Entity(sf::Vector2f pos, EntityType type);

  sf::Vector2f pos;
  //  sf::Vector2f dim;
  EntityType type;
};

#endif // ENTITY_H
