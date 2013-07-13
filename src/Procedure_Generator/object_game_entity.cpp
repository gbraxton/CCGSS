/*
 * object_game_entity.cpp
 *
 *  Created on: Jul 6, 2013
 *      Author: George Braxton IV
 *
 *  Copyright 2013 George Braxton IV
 *
 *  This file is part of CCGSS.
 *
 *  CCGSS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  CCGSS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with CCGSS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "object_game_entity.hpp"

ObjectGameEntity::ObjectGameEntity(const char *entityClass, const std::list<std::pair<const char*, const char*> > *attrs)
:GameEntity(entityClass, attrs){}

ObjectGameEntity::~ObjectGameEntity() {}

void ObjectGameEntity::addComponent(const char *componentType, const char *componentClass) {
  if (strcmp(componentType, "cards")==0) {
    objectComponents.insert(std::make_pair(componentClass, new CardsObjectComponent(componentClass)));
  } else if (strcmp(componentType, "value")==0) {
    objectComponents.insert(std::make_pair(componentClass, new ValueObjectComponent(componentClass)));
  } else if (strcmp(componentType, "boolean")==0) {
    objectComponents.insert(std::make_pair(componentClass, new BooleanObjectComponent(componentClass)));
  }
}

std::map<const char*, GameEntityComponent*, GameEntity::StrPtrCompare> *ObjectGameEntity::getComponents() {
  return &objectComponents;
}
