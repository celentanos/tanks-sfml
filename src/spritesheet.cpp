#include "spritesheet.h"

SpriteSheet::SpriteSheet(sf::Texture &texture) {

  sf::Image img = texture.copyToImage();
  for (int y = 0; y < img.getSize().y / sprite_size16; ++y) {
    for (int x = 0; x < img.getSize().x / sprite_size16; ++x) {
      sf::Image i;
      i.create(sprite_size16, sprite_size16);
      i.copy(img, 0, 0,
             sf::IntRect(x * sprite_size16, y * sprite_size16, sprite_size16,
                         sprite_size16));
      imgSheet.push_back(i);
      //      std::cout << i.getSize().x << std::endl;
    }
  }
}

std::vector<sf::Image> const &SpriteSheet::getImgSheet() const {
  return imgSheet;
}
