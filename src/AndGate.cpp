#include "AndGate.hpp"


AndGate::AndGate(Gate *g1, Gate *g2) : Gate{"AND"}
{
    entrees->push_back(g1);
	entrees->push_back(g2);
}

AndGate::~AndGate()
{
}

bool AndGate::getValeurBooleenne() {
	valeurBooleenne = (this->getEntrees()->at(0)->getValeurBooleenne() && this->getEntrees()->at(1)->getValeurBooleenne());
	return valeurBooleenne;
}
