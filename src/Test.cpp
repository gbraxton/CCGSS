#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"

#include <iostream>

#include <xercesc/util/PlatformUtils.hpp>
XERCES_CPP_NAMESPACE_USE

#include "Procedure_Generator/cards_object_component.hpp"
#include "Procedure_Generator/simulation_package_builder.hpp"
#include "Procedure_Generator/game_entity.hpp"
#include "Procedure_Generator/device_game_entity.hpp"
#include "Procedure_Generator/object_game_entity.hpp"
#include "Procedure_Generator/evaluator_game_entity.hpp"
#include "Procedure_Generator/procedure_game_entity.hpp"

void thisIsATest() {
	ASSERTM("start writing tests", true);
}

void cardsObjectComponentTest() {
  Card card1("A", "S", 1);
  Card card2("J", "S", 10);
  CardsObjectComponent coc("cards");
  coc.getCards()->push_back(&card1);
  coc.getCards()->push_back(&card2);
  ASSERT(coc.getCards()->size() == 2);
  ASSERT(strcmp(coc.getCards()->at(0)->face, "A")==0);
  ASSERT(strcmp(coc.getCards()->at(1)->face, "J")==0);
}

void gameEntityTest() {
  GameEntity *ge[] = {new DeviceGameEntity("device", NULL),
        new ObjectGameEntity("object", NULL),
        new EvaluatorGameEntity("evaluator", NULL)};
  ge[0]->addComponent("deck", "deck");
  ge[1]->addComponent("cards", "cards");
  ge[1]->addComponent("value", "value");
  ge[1]->addComponent("boolean", "contains_ace");

  ge[0]->getComponents()->at("deck");
  dynamic_cast<CardsObjectComponent*>(ge[1]->getComponents()->at("cards"))->getCards()->push_back(new Card("A", "S", 1));
  dynamic_cast<BooleanObjectComponent*>(ge[1]->getComponents()->at("contains_ace"))->setTrue();
  int oldVal = dynamic_cast<ValueObjectComponent*>(ge[1]->getComponents()->at("value"))->getValue();
  dynamic_cast<ValueObjectComponent*>(ge[1]->getComponents()->at("value"))->setValue(oldVal + 1);
  dynamic_cast<CardsObjectComponent*>(ge[1]->getComponents()->at("cards"))->getCards()->push_back(new Card("J", "S", 10));
  oldVal = dynamic_cast<ValueObjectComponent*>(ge[1]->getComponents()->at("value"))->getValue();
  dynamic_cast<ValueObjectComponent*>(ge[1]->getComponents()->at("value"))->setValue(oldVal + 10);
  Card *card = dynamic_cast<CardsObjectComponent*>(ge[1]->getComponents()->at("cards"))->getCards()->at(0);
  ASSERT(strcmp(card->face, "A")==0);
  ASSERT(strcmp(card->suit, "S")==0);
  ASSERT(dynamic_cast<BooleanObjectComponent*>(ge[1]->getComponents()->at("contains_ace"))->getValue());
  card = dynamic_cast<CardsObjectComponent*>(ge[1]->getComponents()->at("cards"))->getCards()->at(1);
  ASSERT(strcmp(card->face, "J")==0);
  ASSERT(strcmp(card->suit, "S")==0);
  int val = dynamic_cast<ValueObjectComponent*>(ge[1]->getComponents()->at("value"))->getValue();
  ASSERT(val == 11);
}

void runSuite(){
	cute::suite s;
	s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(gameEntityTest));
	s.push_back(CUTE(cardsObjectComponentTest));
	cute::ide_listener lis;
	cute::makeRunner(lis)(s, "The Suite");
}

int main(){
	try{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException& toCatch){
		return 1;
	}
  runSuite();
  XMLPlatformUtils::Terminate();

    return 0;
}



