#include "Gate.hpp"

Gate::Gate() : entrees{new vector<Gate*>}
{
}

Gate::~Gate()
{
}

Gate* Gate::operationLogique(){
    return nullptr;
}

vector<Gate*>* Gate::getEntrees() const{
	return entrees;
}
