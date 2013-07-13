/*
 * simulation_package_builder.hpp
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

#ifndef SIMULATION_PACKAGE_BUILDER_H_
#define SIMULATION_PACKAGE_BUILDER_H_

#include <iostream>

#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
XERCES_CPP_NAMESPACE_USE

#include "rules_content_handler.hpp"
#include "simulation_package_object.hpp"


/*
 * SimulationPackageBuilder:
 *
 * Parses the rules.xml file and creates the simulation procedure object
 *
 */

class SimulationPackageBuilder {
public:
	/*
	 * SimulationPackageBuilder(char*):
	 * Takes as argument the name of file that defines game structure
	 */
	SimulationPackageBuilder(const char*);

	/*
	 * build():
	 * Builds the SimulationPackageObject
	 */
	SimulationPackageObject* getSimPackageObj();

	void build();

private:
	const char* rulesFile;
	SimulationPackageObject* simPackageObj;
	SAX2XMLReader* parser;
	RulesContentHandler* rulesHandler;
};

#endif /* SIMULATION_PACKAGE_BUILDER_H_ */
