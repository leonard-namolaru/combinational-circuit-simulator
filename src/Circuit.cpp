#include "Circuit.hpp"

Circuit::Circuit(vector<InputGate*>* inputsCircuit) : inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >} {

	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		affichageCircuit->push_back( new vector<char> ) ;
		affichageCircuit->at(i)->push_back( inputs->at(i)->getInputName() );
		affichageCircuit->at(i)->push_back( ' ' );
		affichageCircuit->at(i)->push_back( ':' );
		affichageCircuit->at(i)->push_back( ' ' );
		affichageCircuit->at(i)->push_back( ' ' );
		affichageCircuit->at(i)->push_back(  to_string( inputs->at(i)->getValEnBinaire() ).at(0) );

		int counter = 0;
		//for(unsigned int j = 0 ; j < gates->size() ; j++){
		//	if( gates->at(i)->listeOfInputsOfTheGate->at(i) ==  inputs->at(i) )
		//		counter++;
		//}
		counter = 2; // TEST
		if(counter != 0){
			affichageCircuit->at(i)->push_back( ' ' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '*' );
		}

		for(int k = 0 ; k < counter -1 ; k ++) {
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '*' );

		}
	}

}

Circuit::Circuit(/* args */)
{
}

Circuit::~Circuit()
{
}


void Circuit::afficheCircuit() const {
	cout << "Affiche circuit" << endl;
	for(unsigned int i = 0 ; i < affichageCircuit->size() ; i++){
		for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
			cout << affichageCircuit->at(i)->at(j);
		}
		cout << endl;
	}
	cout << endl;

}
