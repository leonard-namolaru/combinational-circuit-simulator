#include "XorGate.hpp"


XorGate::XorGate(Gate *g1, Gate *g2) : Gate{"XOR"}{
    entrees->push_back(g1);
	entrees->push_back(g2);
}

XorGate::~XorGate()
{
}

bool XorGate::getValeurBooleenne() {
	valeurBooleenne = (this->getEntrees()->at(0)->getValeurBooleenne() ^ this->getEntrees()->at(1)->getValeurBooleenne());
	return valeurBooleenne;
}

