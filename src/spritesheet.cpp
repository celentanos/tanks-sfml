#include "spritesheet.h"

SpriteSheet::SpriteSheet(sf::Texture &texture) {

  //  sf::Image img = texture.copyToImage();
  //  for (int y = 0; y < img.getSize().y / sprite_size16; ++y) {
  //    for (int x = 0; x < img.getSize().x / sprite_size16; ++x) {
  //      sf::Image i;
  //      i.create(sprite_size16, sprite_size16);
  //      i.copy(img, 0, 0,
  //             sf::IntRect(x * sprite_size16, y * sprite_size16,
  //             sprite_size16,
  //                         sprite_size16));
  //      imgSheet.push_back(i);
  //      //      std::cout << i.getSize().x << std::endl;
  //    }
  //  }

  sf::Image img = texture.copyToImage();

  // tanks ---------------------------------------------------------------------
  Vector4<unsigned int> v;
  for (int color_x = 0; color_x < 2; ++color_x) {
    for (int color_y = 0; color_y < 2; ++color_y) {
      for (int enemy_t = 0; enemy_t < 2; ++enemy_t) {
        for (int tank_t = 0; tank_t < 4; ++tank_t) {
          for (int direction_t = 0; direction_t < 4; ++direction_t) {
            for (int anim_t = 0; anim_t < 2; ++anim_t) {
              int x = (color_x * 128) + (direction_t * 32) * (anim_t * 16);
              int y = (color_y * 128) + (enemy_t * 64) + (tank_t * 16);
              sf::Image img2;
              img2.create(16, 16);
              img2.copy(img, 0, 0, sf::IntRect(x, y, 16, 16));
              v = findImgBoundings(img2);
              tank.at(color_x + color_y + 1)
                  .at(enemy_t)
                  .at(tank_t)
                  .at(direction_t)
                  .at(anim_t) = v;
            }
          }
        }
      }
    }
  }
}

Vector4<unsigned int> SpriteSheet::findImgBoundings(sf::Image &img) {
  unsigned int x1 = static_cast<unsigned int>(-1); // top
  unsigned int x2 = 0;                             // bottom
  unsigned int y1 = static_cast<unsigned int>(-1); // left
  unsigned int y2 = 0;                             // right

  sf::Color c;
  sf::Color cTransparent(0, 0, 1, 0);
  for (unsigned int y = 0; y < img.getSize().y; ++y) {
    for (unsigned int x = 0; x < img.getSize().x; ++x) {
      c = img.getPixel(x, y);
      if (c != cTransparent) {
        if (x < x1)
          x1 = x;
        if (x > x2)
          x2 = x;
        if (y < y1)
          y1 = y;
        if (y > y2)
          y2 = y;
      }
    }
  }
  Vector4<unsigned int> v(x1, y1, (x2 - x1) + 1, (y2 - y1) + 1);
  return v;
}
