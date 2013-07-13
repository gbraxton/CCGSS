/*
 * game_entity_factory.cpp
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

#include "game_entity_factory.hpp"


GameEntityFactory::GameEntityFactory(){};

GameEntity* GameEntityFactory::makeGameEntity(const char *entityClass, const std::list<std::pair<const char*, const char*> > *attrs){
  if(strcmp(entityClass, "device") == 0) {
    return new DeviceGameEntity(entityClass, attrs);
  } else if(strcmp(entityClass, "object") == 0) {
    return new ObjectGameEntity(entityClass, attrs);
  } else if(strcmp(entityClass, "procedure") == 0) {
    return new ProcedureGameEntity(entityClass, attrs);
  } else if (strcmp(entityClass, "evaluator") == 0){
    return new EvaluatorGameEntity(entityClass, attrs);
  }
  return NULL;
}
