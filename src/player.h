#ifndef PLAYER_H
#define PLAYER_H

#include "defines.h"
#include "entitylist.h"
#include "input.h"
#include <SFML/Graphics.hpp>

class Player : public Entity {
public:
  Player(sf::Vector2f pos, EntityType type, sf::Texture &texture,
         EntityList &list, Input &input, sf::RenderWindow &win);

  void update();
  void draw();
  sf::Sprite *getSprite();

  myfloat getSpeed() const;
  void setSpeed(const myfloat &value);

private:
  enum PlayerLevel { t1, t2, t3, t4, playerLevelSize };
  enum PlayerOrient { n, w, s, e, playerOrientSize };
  enum PlayerAnim { a1, a2, playerAnimSize };

  EntityList &list;
  Input &input;
  sf::RenderWindow &window;
  sf::Sprite sprite;
  sf::Vector2f pos_old;
  myfloat speed;
  int orient;
  int level;
  int anim;
  vector<sf::Vector2u> spriteMap;
  vector<Vector4<float>> spriteBoundsMap;

  void setupSprite();
};

#endif // PLAYER_H
