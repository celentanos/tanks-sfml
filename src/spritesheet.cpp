#include "spritesheet.h"

SpriteSheet::SpriteSheet(sf::Texture &texture) : texture(texture) {
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
  Vector4<uint> v;
  for (size_t color_y = 0; color_y < 2; ++color_y) {
    for (size_t color_x = 0; color_x < 2; ++color_x) {
      vector<vector<vector<vector<Vector4<uint>>>>> a4;
      tank.push_back(a4);
      for (size_t enemy_t = 0; enemy_t < 2; ++enemy_t) {
        vector<vector<vector<Vector4<uint>>>> a3;
        tank.at(color_x + (color_y * 2)).push_back(a3);
        for (size_t tank_t = 0; tank_t < 4; ++tank_t) {
          vector<vector<Vector4<uint>>> a2;
          tank.at(color_x + (color_y * 2)).at(enemy_t).push_back(a2);
          for (size_t direction_t = 0; direction_t < 4; ++direction_t) {
            vector<Vector4<uint>> a1;
            tank.at(color_x + (color_y * 2))
                .at(enemy_t)
                .at(tank_t)
                .push_back(a1);
            for (size_t anim_t = 0; anim_t < 2; ++anim_t) {
              int x = static_cast<int>((color_x * 128) + (direction_t * 32) +
                                       (anim_t * 16));
              int y = static_cast<int>((color_y * 128) + (enemy_t * 64) +
                                       (tank_t * 16));
              sf::Image img2;
              img2.create(16, 16);
              img2.copy(img, 0, 0, sf::IntRect(x, y, 16, 16));
              v = findImgBoundings(img2);

              tank.at(color_x + (color_y * 2))
                  .at(enemy_t)
                  .at(tank_t)
                  .at(direction_t)
                  .push_back(Vector4<uint>(v.x + x, v.y + y, v.w, v.h));
            }
          }
        }
      }
    }
  }
}

sf::Texture &SpriteSheet::getTexture() { return texture; }

sf::IntRect SpriteSheet::getBoundingsIntRect(uint color, uint enemy,
                                             uint tank_level, uint direction,
                                             uint animation) {
  if (tank.size() > color)
    if (tank.at(color).size() > enemy)
      if (tank.at(color).at(enemy).size() > tank_level)
        if (tank.at(color).at(enemy).at(tank_level).size() > direction)
          if (tank.at(color).at(enemy).at(tank_level).at(direction).size() >
              animation)
            return sf::IntRect(tank.at(color)
                                   .at(enemy)
                                   .at(tank_level)
                                   .at(direction)
                                   .at(animation)
                                   .x,
                               tank.at(color)
                                   .at(enemy)
                                   .at(tank_level)
                                   .at(direction)
                                   .at(animation)
                                   .y,
                               tank.at(color)
                                   .at(enemy)
                                   .at(tank_level)
                                   .at(direction)
                                   .at(animation)
                                   .w,
                               tank.at(color)
                                   .at(enemy)
                                   .at(tank_level)
                                   .at(direction)
                                   .at(animation)
                                   .h);
  // TODO: error output
  return sf::IntRect(0, 0, 0, 0);
}

Vector4<uint> SpriteSheet::findImgBoundings(sf::Image &img) {
  uint x1 = static_cast<uint>(-1); // top
  uint x2 = 0;                     // bottom
  uint y1 = static_cast<uint>(-1); // left
  uint y2 = 0;                     // right

  sf::Color c;
  sf::Color cTransparent(0, 0, 1, 0);
  for (uint y = 0; y < img.getSize().y; ++y) {
    for (uint x = 0; x < img.getSize().x; ++x) {
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
  Vector4<uint> v(x1, y1, (x2 - x1) + 1, (y2 - y1) + 1);
  return v;
}
