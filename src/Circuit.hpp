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
	vector< vector<Gate*>* >* simulationPasParPas;

	vector<Gate*>* ajoutInputs();
	void ajoutCheminsApresInputs();
	void ajoutNomsOperationsLogiques(const vector<Gate*>* portesLogiquesAjouterAffichage);
	void ajoutCheminsApresOperationsLogiques();
	void ajoutAsterisquesApresChemins(unsigned int level);
	vector<Gate*>* trouverLesPortesLogiquesSuivantes(const vector<Gate*>* portesLogiquesPrecedentes);
public:
    Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates, vector<OutputGate*>* ouputs);
    virtual ~Circuit();
    void afficheCircuit()  const;
    void simulation(); // Simulation en mode pas à pas
    void changerValeursDesPortesEntree();// Changer les valeurs des portes d’entrée
    Circuit* expressionTextuelleToCircuit(const string& expressionTextuelle);

};



#endif
