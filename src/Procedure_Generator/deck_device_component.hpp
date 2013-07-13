/*
 * deck_device_component.hpp
 *
 *  Created on: Jul 9, 2013
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

#ifndef DECK_DEVICE_COMPONENT_HPP_
#define DECK_DEVICE_COMPONENT_HPP_

#include <vector>

#include "card.hpp"
#include "game_entity_component.hpp"

//TODO This class should only specify that a deck be used.
//      The container and cards would be implemented by the
//      Simulation module.

class DeckDeviceComponent : public GameEntityComponent {
public:
  DeckDeviceComponent(const char *name);
private:
  std::vector<Card> deck[52];
};


#endif /* DECK_DEVICE_COMPONENT_HPP_ */
