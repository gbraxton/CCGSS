/*
 * card.hpp
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

#ifndef CARD_HPP_
#define CARD_HPP_

#include <cstddef>
#include <vector>

struct Card {
  Card() : face(NULL), suit(NULL), value(0) {}
  Card(const char* face, const char* suit, int value) : face(face), suit(suit), value(value) {}
  const char* face;
  const char* suit;
  int value;
};


#endif /* CARD_HPP_ */
