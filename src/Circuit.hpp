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
	vector<Gate*>* ajoutInputs();
	void ajoutCheminsApresInputs();
	void ajoutNomsOperationsLogiques(const vector<Gate*>* portesLogiquesAjouterAffichage);
	void ajoutCheminsApresOperationsLogiques();
	void affichageAsterisquesApresChemins(int level);
	void affichageNomsOperationsLogiques2(const vector<Gate*>* gatesVector);
public:
    Circuit(/* args */);
    Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates, vector<OutputGate*>* ouputs);
    virtual ~Circuit();
    void afficheCircuit()  const;
};



#endif
