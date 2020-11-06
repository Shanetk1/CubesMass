#include "EntityCS.h"

void Entity::addGroup(Group group_)
{
	groupbitSet[group_] = true;
	manager.addToGroup(this, group_);
}