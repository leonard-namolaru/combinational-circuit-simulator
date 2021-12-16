#include "Circuit.hpp"

Circuit::Circuit(vector<InputGate*>* inputsCircuit) : inputs{inputsCircuit} {

}

Circuit::Circuit(/* args */)
{
}

Circuit::~Circuit()
{
}


void Circuit::afficheCircuit() const {
	cout << "Affiche circuit" << endl;
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		cout << inputs->at(i)->getInputName() << ": " << inputs->at(i)->getValEnBinaire();
		int counter = 0;
		//for(unsigned int j = 0 ; j < gates->size() ; j++){
		//	if( gates->at(i)->listeOfInputsOfTheGate->at(i) ==  inputs->at(i) )
		//		counter++;
		//}
		counter = 2; // TEST
		if(counter != 0)
			cout << " --*";

		for(int k = 0 ; k < counter -1 ; k ++)
			cout << "-----*" << endl;
		cout << endl;
	}

}
