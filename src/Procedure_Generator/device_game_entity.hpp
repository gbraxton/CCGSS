/*
 * device_game_entity.hpp
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

#ifndef DEVICE_GAME_ENTITY_HPP_
#define DEVICE_GAME_ENTITY_HPP_

#include <map>

#include <xercesc/sax2/DefaultHandler.hpp>

#include "deck_device_component.hpp"
#include "game_entity.hpp"
#include "game_entity_component.hpp"

class DeviceGameEntity : public GameEntity {
public:
  DeviceGameEntity(const char*, const std::list<std::pair<const char*, const char*> >*);
  ~DeviceGameEntity();

  void addComponent(const char *componentType, const char *componentClass);
  std::map<const char*, GameEntityComponent*, StrPtrCompare> *getComponents();
private:
  std::map<const char*, GameEntityComponent*, StrPtrCompare> deviceComponents;
};


#endif /* DEVICE_GAME_ENTITY_HPP_ */
