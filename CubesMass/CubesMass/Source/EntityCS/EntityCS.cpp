#include "EntityCS.h"
/*
void Entity::addGroup(Group group_)
{
	groupbitSet[group_] = true;
	manager.addToGroup(this, group_);
}*/

void Entity::addGroup(Group mGroup)
{
	groupBitSet[mGroup] = true;
	manager.addToGroup(this, mGroup);
}