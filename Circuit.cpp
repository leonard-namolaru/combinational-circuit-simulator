#include "Circuit.hpp"

void Circuit::afficheCircuit() const {
	cout << "Affiche circuit" << endl;
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		cout << inputs->at(i)->inputName << ": " << inputs->at(i)->initialValue;
		int counter = 0;
		for(unsigned int j = 0 ; j < gates->size() ; j++){
			if( gates->at(i)->listeOfInputsOfTheGate->at(i) ==  inputs->at(i) )
				counter++;
		}

		if(counter != 0)
			cout << "- -*";

		for(int k = 0 ; k < counter -1 ; k ++)
			cout << "- - - - -*" << endl;
		cout << endl;
	}

}
