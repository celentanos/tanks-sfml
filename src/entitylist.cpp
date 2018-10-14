#include "entitylist.h"

EntityList::EntityList() {}

void EntityList::updateAll() {
  //  std::cout << PixelPerfectTest(*this->at(0)->getSprite(),
  //                                *this->at(1)->getSprite())
  //            << std::endl;
  for (ulong i = 0; i < this->size(); ++i) {
    this->at(i)->update();
    this->at(i)->draw();
  }
}
