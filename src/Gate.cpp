#include "Gate.hpp"

Gate::Gate(const string name) : entrees{new vector<Gate*>}, name{name}
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

string Gate::getName() const {
	return name;
}
