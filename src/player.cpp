#include "player.h"

Player::Player(sf::Vector2f pos, EntityType type, sf::Texture &texture,
               EntityList &list, Input &input, sf::RenderWindow &win)
    : Entity(pos, type), list(list), input(input), window(win) {
  sprite.setTexture(texture);
  speed = 1;
  orient = 0;
  level = 0;
  anim = 0;

  for (int level = 0; level < playerLevelSize; ++level) {
    for (int orient = 0; orient < playerOrientSize; ++orient) {
      for (int anim = 0; anim < playerAnimSize; ++anim) {
        spriteMap.push_back(
            sf::Vector2u((((orient * playerAnimSize) + anim) * sprite_size16),
                         level * sprite_size16));
      }
    }
  }
  //  sf::Color c;
  //  for (int level = 0; level < playerLevelSize; ++level) {
  //    for (int orient = 0; orient < playerOrientSize; ++orient) {
  //      for (int anim = 0; anim < playerAnimSize; ++anim) {
  //        sf::Image img = texture.copyToImage();
  //        float n = -1;
  //        float w = sprite_size1;
  //        float s = -1;
  //        float e = -1;
  //        float et;
  //        for (int zeile = 0; zeile < level * sprite_size1 + sprite_size1;
  //             ++zeile) {
  //          for (int spalte = 0;
  //               spalte < (((orient * playerAnimSize) + anim) * sprite_size1)
  //               +
  //                            sprite_size1;
  //               ++spalte) {
  //            et = spalte / (((orient * playerAnimSize) + anim) *
  //            sprite_size1); c = img.getPixel(spalte, zeile); if (c.a > 127) {
  //              if (n == -1)
  //                n = zeile;
  //              if (w > spalte)
  //                w = spalte;
  //              if (e < et)
  //                e = et;
  //              if (s < zeile)
  //                s = zeile;
  //            }
  //          }
  //        }
  //        spriteBoundsMap.push_back(Vector4<float>(n, w, s, e));
  //      }
  //    }
  //  }
}

void Player::update() {
  pos_old = pos;
  if (type == EntityType::Player) { // TEMP
    if (input.getKeyMap()->at(sf::Keyboard::Key::Up) == 1) {
      pos.y -= speed;
      orient = n;
      anim = !anim;
    } else if (input.getKeyMap()->at(sf::Keyboard::Key::Down) == 1) {
      pos.y += speed;
      orient = s;
      anim = !anim;
    } else if (input.getKeyMap()->at(sf::Keyboard::Key::Left) == 1) {
      pos.x -= speed;
      orient = w;
      anim = !anim;
    } else if (input.getKeyMap()->at(sf::Keyboard::Key::Right) == 1) {
      pos.x += speed;
      orient = e;
      anim = !anim;
    }
    setupSprite();
    for (ulong i = 0; i < list.size(); ++i) {
      if (list.at(i) != this)
        if (Collision::BoundingBoxTest(*this->getSprite(),
                                       *list.at(i)->getSprite())) {
          pos = pos_old;
        }
    }
  }
}

void Player::draw() {
  setupSprite();
  window.draw(sprite);
}

sf::Sprite *Player::getSprite() { return &sprite; }

myfloat Player::getSpeed() const { return speed; }

void Player::setSpeed(const myfloat &value) { speed = value; }

void Player::setupSprite() {
  sprite.setPosition(pos.x, pos.y);
  int isprite = level * playerOrientSize * playerAnimSize +
                orient * playerAnimSize + anim;
  sprite.setTextureRect(sf::IntRect(spriteMap.at(isprite).x,
                                    spriteMap.at(isprite).y, sprite_size16,
                                    sprite_size16));
  sprite.setScale(sprite_scale, sprite_scale);
}
