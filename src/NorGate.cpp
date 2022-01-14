#include "NorGate.hpp"

NorGate::NorGate(Gate *g1 , Gate *g2) : Gate{"NOR"} {
	entrees->push_back(g1);
	entrees->push_back(g2);
}

NorGate::~NorGate()
{
}


bool NorGate::getValeurBooleenne() {
	valeurBooleenne = (!(this->getEntrees()->at(0)->getValeurBooleenne() || this->getEntrees()->at(1)->getValeurBooleenne()));
	return valeurBooleenne;
}
