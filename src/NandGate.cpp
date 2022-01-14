#include "NandGate.hpp"


NandGate::NandGate(Gate *g1, Gate *g2) : Gate{"NAN"}
{
    entrees->push_back(g1);
	entrees->push_back(g2);
}

NandGate::~NandGate()
{
}

bool NandGate::getValeurBooleenne() {
	valeurBooleenne = (!(this->getEntrees()->at(0)->getValeurBooleenne() && this->getEntrees()->at(1)->getValeurBooleenne()));
	return valeurBooleenne;
}
