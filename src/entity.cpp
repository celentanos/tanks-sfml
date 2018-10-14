#include "entity.h"

Entity::Entity(sf::Vector2f pos, EntityType type) {
  this->pos = pos;
  this->type = type;
}
