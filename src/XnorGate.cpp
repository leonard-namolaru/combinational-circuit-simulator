#include "XnorGate.hpp"


XnorGate::XnorGate(Gate *g1, Gate *g2) : Gate{"XNO"}{
    entrees->push_back(g1);
	entrees->push_back(g2);
}

XnorGate::~XnorGate()
{
}

bool XnorGate::getValeurBooleenne() {
	valeurBooleenne = (!(this->getEntrees()->at(0)->getValeurBooleenne() ^ this->getEntrees()->at(1)->getValeurBooleenne()));
	return valeurBooleenne;
}

