#include "Gate.hpp"

Gate::Gate(const string name) : entrees{new vector<Gate*>}, name{name}, valeurBooleenne{false}
{
}

Gate::Gate(const string name, bool valeurBooleenne) : entrees{new vector<Gate*>}, name{name}, valeurBooleenne{valeurBooleenne}
{

}


Gate::~Gate()
{
}


vector<Gate*>* Gate::getEntrees() const{
	return entrees;
}

string Gate::getName() const {
	return name;
}

bool Gate::getValeurBooleenne() {
	return valeurBooleenne;
}
