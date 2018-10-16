#include "entitylist.h"
#include "input.h"
#include "spritesheet.h"
#include "tank.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {

  sf::Image image;
  if (!image.loadFromFile("res/texture_atlas_.png"))
    return -1;
  //  image.createMaskFromColor(sf::Color::Black);
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  //  sprite.setTextureRect(sf::IntRect(96, 0, 16, 16));
  //  sprite.scale(2, 2);

  sf::RenderWindow window(sf::VideoMode(400, 400), "Tanks");
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);

  // TEST
  //  SpriteSheet ss(texture);
  //  sf::Sprite s;
  //  sf::Texture t;
  //  t.loadFromImage(ss.getImgSheet().at(12));
  //  s.setTexture(t);
  //  window.draw(s);
  //  window.display();
  SpriteSheet sheet(texture);
  //  sf::Sprite sp;
  //  sp.setTexture(texture);
  //  sp.setTextureRect(sheet.getBoundingsIntRect(2, 1, 1, 0, 1));
  //  sp.scale(2, 2);

  Input input;
  EntityList list;
  Tank player(sf::Vector2f(32, 0), Entity::EntityType::Player, sheet, list,
              input, window);
  //  Tank enemy(sf::Vector2f(0, 0), Entity::EntityType::Enemy, texture, list,
  //             input, window);
  list.push_back(&player);
  //  list.push_back(&enemy);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        input.getKeyMap()->at(event.key.code) = 1;
        break;
      case sf::Event::KeyReleased:
        input.getKeyMap()->at(event.key.code) = 0;
        break;
      default:
        break;
      }
    }

    window.clear();
    list.updateAll();
    window.display();
  }

  return 0;
}
