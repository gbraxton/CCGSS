/*
 * procedure_game_entity.cpp
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

#include "procedure_game_entity.hpp"

ProcedureGameEntity::ProcedureGameEntity(const char *entityClass, const std::list<std::pair<const char*, const char*> > *attrs)
  : GameEntity(entityClass, attrs) {}

ProcedureGameEntity::~ProcedureGameEntity() {}

void ProcedureGameEntity::addComponent(const char *componentType, const char *componentClass){
  //TODO
}

std::map<const char*, GameEntityComponent*, GameEntity::StrPtrCompare> *ProcedureGameEntity::getComponents() {
  return &procedureComponents;
}
