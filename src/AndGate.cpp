#include "AndGate.hpp"


AndGate::AndGate(Gate *g1, Gate *g2) : Gate{"AND"}
{
    entrees->push_back(g1);
	entrees->push_back(g2);
}

AndGate::~AndGate()
{
}
Gate* AndGate::operationLogique(){
    return nullptr;
}
