#include "EntityCS.h"

void Entity::addGroup(Group group_)
{
	groupBitSet[group_] = true;
	this->manager.addToGroup(this, group_);
}
/*
void Entity::addGroup(Group mGroup)
{
	groupBitSet[mGroup] = true;
	manager.addToGroup(this, mGroup);
}*/