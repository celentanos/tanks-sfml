#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "collision.h"
#include "entity.h"
#include <iostream>
#include <vector>

using namespace Collision;

using namespace std;

class EntityList : public vector<Entity *> {
public:
  EntityList();

  void updateAll();
};

#endif // ENTITYLIST_H
