#include "XorGate.hpp"


XorGate::XorGate(Gate *g1, Gate *g2) : Gate{"XOR"}{
    entrees->push_back(g1);
	entrees->push_back(g2);

}

XorGate::~XorGate()
{
}

Gate* XorGate::operationLogique(){
    return nullptr;
}
