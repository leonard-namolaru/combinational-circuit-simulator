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
	vector<Gate*>* affichageInputs();
	void affichageChemins();
	void affichageNomsOperationsLogiques(const vector<Gate*>* noms);
	void affichageCheminsApresOperationsLogiques();
	void affichageAsterisques();
	void affichageNomsOperationsLogiques2(const vector<Gate*>* gatesVector);
public:
    Circuit(/* args */);
    Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates);
    ~Circuit();
    void afficheCircuit()  const;
};



#endif
