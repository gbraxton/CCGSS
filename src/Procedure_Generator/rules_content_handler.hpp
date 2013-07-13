/*
 * rules_content_handler.hpp
 *
 *  Created on: Jul 3, 2013
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

#ifndef RULES_CONTENT_HANDLER_H_
#define RULES_CONTENT_HANDLER_H_

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>
XERCES_CPP_NAMESPACE_USE

#include "game_entity_factory.hpp"
#include "simulation_package_object.hpp"

class RulesContentHandler : public DefaultHandler {
public:
  enum ElementLevel {
    kInitialLevel = 0,
    kRuleLevel,
    kEntityLevel,
    kComponentLevel,
    kSubComponentLevel
  };

	explicit RulesContentHandler(SimulationPackageObject*);

	virtual void startElement(const XMLCh *const uri,
			const XMLCh *const localname,
			const XMLCh *const qname,
			const Attributes &attrs);

	virtual void endElement(const XMLCh *const uri,
			const XMLCh *const localname,
			const XMLCh *const qname);

private:
	SimulationPackageObject *simulationPackageObject;
	int currentElementLevel;
	GameEntity *currentEntity;
	GameEntityFactory *entityFactory;

	const std::list<std::pair<const char*, const char*> >* convertAttributesToList(const Attributes &attrs);

};


#endif /* RULES_CONTENT_HANDLER_H_ */
