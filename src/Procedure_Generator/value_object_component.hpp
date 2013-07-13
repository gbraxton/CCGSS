/*
 * value_object_component.hpp
 *
 *  Created on: Jul 10, 2013
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

#ifndef VALUE_OBJECT_COMPONENT_HPP_
#define VALUE_OBJECT_COMPONENT_HPP_

#include "game_entity_component.hpp"

class ValueObjectComponent : public GameEntityComponent {
public:
  ValueObjectComponent(const char *name);
  int getValue();
  void setValue(int val);
private:
  int value;
};


#endif /* VALUE_OBJECT_COMPONENT_HPP_ */
