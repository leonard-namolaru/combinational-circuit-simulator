#include "OutputGate.hpp"

OutputGate::OutputGate(char name, Gate* g) : Gate{std::string(1,name)}
{
	entrees->push_back(g);
}

OutputGate::~OutputGate()
{
}

bool OutputGate::getValeurBooleenne() {
	valeurBooleenne = this->getEntrees()->at(0)->getValeurBooleenne();
	return valeurBooleenne;
}

