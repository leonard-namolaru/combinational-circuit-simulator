#ifndef CIRCUIT
#define CIRCUIT
#include "Gate.hpp"
#include <vector>
#include <iostream>
#include "InputGate.hpp"
#include "OutputGate.hpp"
using namespace std;
class Circuit
{
private:
    /* data */
	vector<InputGate*>* inputs;
	vector<OutputGate*>* ouputs;
	vector<Gate*>* gates;
public:
    Circuit(/* args */);
    ~Circuit();
    void afficheCircuit();
};

Circuit::Circuit(/* args */)
{
}

Circuit::~Circuit()
{
}

Circuit::afficheCircuit()
{
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






#endif
