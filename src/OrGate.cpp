#include "OrGate.hpp"

OrGate::OrGate(Gate *g1 , Gate *g2) : Gate{"OR_"} {
	entrees->push_back(g1);
	entrees->push_back(g2);
}

OrGate::~OrGate()
{
}


bool OrGate::getValeurBooleenne() {
	valeurBooleenne = (this->getEntrees()->at(0)->getValeurBooleenne() || this->getEntrees()->at(1)->getValeurBooleenne());
	return valeurBooleenne;
}
