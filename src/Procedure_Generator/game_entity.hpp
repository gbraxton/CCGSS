/*
 * game_entity.hpp
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

#ifndef GAME_ENTITY_HPP_
#define GAME_ENTITY_HPP_

#include <list>
#include <map>

#include <xercesc/sax2/DefaultHandler.hpp>
XERCES_CPP_NAMESPACE_USE

#include "game_entity_component.hpp"

class GameEntity {
public:
	GameEntity(const char *entityName, const std::list<std::pair<const char*, const char*> > *entityAttrs);
	virtual ~GameEntity();

	virtual void addComponent(const char *componentType, const char *componentClass) = 0;
	class StrPtrCompare {
	    public:
	      bool operator()(const char *str1, const char *str2) {
	        return (strcmp(str1, str2) < 0);
	    }
	  };
	virtual std::map<const char*, GameEntityComponent*, StrPtrCompare> *getComponents() = 0;
	const char *getEntityName();
private:
	const char *entityName;
	const std::list<std::pair<const char*, const char*> > *entityAttrs;
};


#endif /* GAME_ENTITY_HPP_ */
