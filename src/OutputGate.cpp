#include "OutputGate.hpp"

OutputGate::OutputGate(char name, Gate *g) : Gate{std::string(1,name)}
{
	entrees->push_back(g);
}

OutputGate::~OutputGate()
{
}
