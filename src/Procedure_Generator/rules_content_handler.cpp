/*
 * rules_content_handler.cpp
 *
 *  Created on: Jul 4, 2013
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

#include "rules_content_handler.hpp"

RulesContentHandler::RulesContentHandler(SimulationPackageObject *simPackObj)
:simulationPackageObject(simPackObj), currentElementLevel(kInitialLevel), currentEntity(NULL), entityFactory(new GameEntityFactory()) {};

void RulesContentHandler::startElement(const XMLCh *const uri,
			const XMLCh *const localname,
			const XMLCh *const qname,
			const Attributes &attrs) {
	switch(currentElementLevel) {
    case kRuleLevel:
      // Creating GameEntity
      currentEntity = entityFactory->makeGameEntity(XMLString::transcode(localname, XMLPlatformUtils::fgMemoryManager), convertAttributesToList(attrs));
      simulationPackageObject->addEntity(XMLString::transcode(attrs.getValue(XMLString::transcode("name", XMLPlatformUtils::fgMemoryManager)), XMLPlatformUtils::fgMemoryManager), currentEntity);
      break;
    case kEntityLevel:
      currentEntity->addComponent(XMLString::transcode(localname, XMLPlatformUtils::fgMemoryManager),
          XMLString::transcode(attrs.getValue(XMLString::transcode("class", XMLPlatformUtils::fgMemoryManager))));
      break;
    default:
      break;
	}
  currentElementLevel++;
}

void RulesContentHandler::endElement(const XMLCh *const uri,
			const XMLCh *const localname,
			const XMLCh *const qname){
  currentElementLevel--;
}

const std::list<std::pair<const char*, const char*> > *RulesContentHandler::convertAttributesToList(const Attributes &attrs) {
  if(attrs.getLength()){
    std::list<std::pair<const char*, const char*> > *attrVect =
        new std::list<std::pair<const char*, const char*> >();
    for(XMLSize_t i = 0; i < attrs.getLength(); i++) {
      attrVect->push_back(
          std::make_pair(
              XMLString::transcode(attrs.getLocalName(i), XMLPlatformUtils::fgMemoryManager),
              XMLString::transcode(attrs.getValue(i), XMLPlatformUtils::fgMemoryManager) ) );
    }
    return attrVect;
  }
  return NULL;
}
