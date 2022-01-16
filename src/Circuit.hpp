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
	/* **** DATA **** */
	vector<InputGate*>* inputs;
	vector<OutputGate*>* ouputs;
	vector<Gate*>* gates;
	vector< vector<char>* >* affichageCircuit;
	vector< vector<Gate*>* >* simulationPasParPas;

	/* **** LA CONSTRUCTION DE L'AFFICHAGE DU CIRCUIT **** */
	vector<Gate*>* ajoutInputs();
	void ajoutCheminsApresInputs();
	void ajoutNomsOperationsLogiques(const vector<Gate*>* portesLogiquesAjouterAffichage);
	void ajoutCheminsApresOperationsLogiques();
	void ajoutAsterisquesApresChemins(unsigned int level);
	vector<Gate*>* trouverLesPortesLogiquesSuivantes(const vector<Gate*>* portesLogiquesPrecedentes);
public:
    Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates, vector<OutputGate*>* ouputs);
    virtual ~Circuit();
    void simulation(); // Simulation en mode pas à pas
    Circuit* expressionTextuelleToCircuit(const string& expressionTextuelle);

    void changerValeursDesPortesEntree();// Permet de changer les valeurs booléennes des entrées du circuit (false par défaut)
    void afficheCircuit()  const;
    string afficherSousFormeTextuelle() const; // Renvoie une chaîne de caractères qui représente le circuit.
};



#endif
