/*
 * simulation_package_object.hpp
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

#ifndef SIMULATION_PACKAGE_OBJECT_HPP_
#define SIMULATION_PACKAGE_OBJECT_HPP_

#include <iostream>
#include <map>

#include <xercesc/util/XMLString.hpp>

#include "game_entity.hpp"

class SimulationPackageObject {
public:
	SimulationPackageObject();
	void addEntity(const char*, GameEntity*);
	void printSimPack();
private:
	std::map<const char*, GameEntity*> gameEntities;
};

#endif /* SIMULATION_PACKAGE_OBJECT_HPP_ */
