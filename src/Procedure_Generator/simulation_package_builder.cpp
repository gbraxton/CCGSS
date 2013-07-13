/*
 * simulation_package_builder.cpp
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

#include "simulation_package_builder.hpp"

SimulationPackageBuilder::SimulationPackageBuilder(const char* rulesFile)
    : rulesFile(rulesFile),
      simPackageObj(new SimulationPackageObject()),
      parser(XMLReaderFactory::createXMLReader()),
      rulesHandler(new RulesContentHandler(simPackageObj)) {
  parser->setContentHandler(rulesHandler);
	parser->setErrorHandler(rulesHandler);
	try{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException& toCatch){
		//TODO Exception Handling
	}
}

SimulationPackageObject* SimulationPackageBuilder::getSimPackageObj() {
  return simPackageObj;
}

void SimulationPackageBuilder::build(){
	try {
		parser->parse(rulesFile);
	}
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
		       << message << "\n";
		XMLString::release(&message);
	}
	catch (const SAXParseException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Exception message is: \n"
				<< message << "\n";
		XMLString::release(&message);
	}
	catch (...) {
		std::cout << "Unexpected Exception \n" ;
	}
}
