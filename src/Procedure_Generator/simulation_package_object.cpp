/*
 * Simulation_package_object.cpp
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

#include "simulation_package_object.hpp"

SimulationPackageObject::SimulationPackageObject() {}

void SimulationPackageObject::addEntity(const char *entityClass, GameEntity *gameEntity){
	gameEntities.insert(std::make_pair(entityClass, gameEntity));
}

void SimulationPackageObject::printSimPack() { // TODO This is a Test Function
  for(std::map<const char*, GameEntity*>::iterator it = gameEntities.begin(); it != gameEntities.end(); it++) {
    std::cout << it->first << std::endl;
  }
}
