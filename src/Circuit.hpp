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
	vector< vector<char>* >* affichageCircuit;
	void affichageInputs();
	void affichageChemins();
	void affichageNomsOperationsLogiques();
	void affichageCheminsApresOperationsLogiques();
	void affichageAsterisques();
public:
    Circuit(/* args */);
    Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates);
    ~Circuit();
    void afficheCircuit() const;
};



#endif
