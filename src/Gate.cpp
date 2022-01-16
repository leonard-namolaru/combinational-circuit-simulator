/*
 * Gate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "Gate.hpp"
#include "XorGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include <map>

/**
 * Constructeur 1.
 */
Gate::Gate(const string& nomGate, bool valeurBooleenne) : nomGate{nomGate}, entrees{new vector<Gate*>}, valeurBooleenne{valeurBooleenne}
{

}

/**
 * Constructeur 2.
 */
Gate::Gate(const string& nomGate) : nomGate{nomGate}, entrees{new vector<Gate*>}, valeurBooleenne{false}
{

}


vector<Gate*>* Gate::getEntrees() const{
	return entrees;
}

string Gate::getName() const {
	return nomGate;
}

bool Gate::getValeurBooleenne() {
	return valeurBooleenne;
}

string Gate::getItineraireRecursif() const {
	string str = this->getName();

	if(this->getEntrees()->size() > 0)  {
		str.append("(");
		str.append( this->getEntrees()->at(0)->getItineraireRecursif() );
	}

	if(this->getEntrees()->size() > 1)  {
		str.append( "," );
		str.append( this->getEntrees()->at(1)->getItineraireRecursif() );
	}

	if(this->getEntrees()->size() > 0)  {
		str.append(")");

	}

   return str;
}

Gate* Gate::getGateByName(const string& name, Gate* input1, Gate* input2) {
	Gate* gate = nullptr;
	map<string, int> mapOfGates = {
	        {"xor",1},
			{"XOR",1},
			{"OR",2},
			{"OR_",2},
	        {"or",2},
	        {"or_",2},
			{"AND",3},
	        {"and",3}
	};

	if(mapOfGates.count(name) == 0)
		return nullptr;

	switch(mapOfGates.at(name)) {
		case 1:
				gate = new XorGate(input1, input2);
				break;
		case 2:
				gate = new OrGate(input1, input2);
				break;
		case 3:
				gate = new AndGate(input1, input2);
				break;

	} // switch

	return gate;
}

Gate::~Gate()
{

}
