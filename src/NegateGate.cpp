#include "NegateGate.hpp"


NegateGate::NegateGate(Gate *g1) : Gate{"NEG"}
{
    entrees->push_back(g1);
	
}

NegateGate::~NegateGate()
{
}

bool NegateGate::getValeurBooleenne() {
	valeurBooleenne = (! (this->getEntrees()->at(0)->getValeurBooleenne()));
	return valeurBooleenne;
}
