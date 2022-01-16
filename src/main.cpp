#include <iostream>
#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "XorGate.hpp"
#include "Circuit.hpp"

int main(){

	/* Les entrées */

	InputGate *a = new InputGate('a');
	InputGate *b = new InputGate('b');
	InputGate *c = new InputGate('c');
	InputGate *d = new InputGate('d');
	InputGate *e = new InputGate('e');
	InputGate *f = new InputGate('f');

	vector<InputGate*>* inputsCircuit = new vector<InputGate*>;
	inputsCircuit->push_back(a);
	inputsCircuit->push_back(b);
	inputsCircuit->push_back(c);
	inputsCircuit->push_back(d);
	inputsCircuit->push_back(e);
	inputsCircuit->push_back(f);

	/* Les portes logiques */

	Gate *or1 = new OrGate(a,b);
	Gate *and1 = new AndGate(a,b);
	Gate *or2 = new OrGate(c,d);
	Gate *and2 = new AndGate(c,d);
	Gate *and3 = new AndGate(e,f);
	Gate *and4 = new AndGate(a,b);
	Gate *or3 = new OrGate(a,f);
	Gate *or4 = new OrGate(d,f);

	Gate *xor1 = new XorGate(or1,and1);
	Gate *and5 = new AndGate(or2,and2);
	Gate *or5 = new OrGate(and3,and4);
	Gate *xor2 = new XorGate(or3,or4);

	Gate *or6 = new OrGate(xor1,and5);
	Gate *xor3 = new XorGate(or5,xor2);

	Gate *and6 = new AndGate(or6,xor3);

	OutputGate *A = new OutputGate('A', and6);


	vector<Gate*>* gates = new vector<Gate*>;
	gates->push_back(or1);
	gates->push_back(and1);
	gates->push_back(or2);
	gates->push_back(and2);
	gates->push_back(and3);
	gates->push_back(and4);
	gates->push_back(or3);
	gates->push_back(or4);

	gates->push_back(xor1);
	gates->push_back(and5);
	gates->push_back(or5);
	gates->push_back(xor2);

	gates->push_back(or6);
	gates->push_back(xor3);

	gates->push_back(and6);
	gates->push_back(A);


	/* Les sorties du Circuit  */


	vector<OutputGate*>* ouputs = new vector<OutputGate*>;
	ouputs->push_back(A);

	Circuit* circuit = new Circuit(inputsCircuit, gates, ouputs);

	int choix = 1;
	string expressionTextuelle;
	do{
		cout << "**** MENU : simulateur de circuit combinatoire ***" << endl;
		cout << "1- Afficher le circuit" << endl;
		cout << "2- Simulation en mode pas à pas" << endl;
		cout << "3- Changer les valeurs des portes d’entrée" << endl;
		cout << "4- Afficher sous forme textuelle les fonctions de sortie à l’aide des variables d’entrée" << endl;
		cout << "5- Synthétiser un circuit à partir d'une expression textuelle" << endl;
		cout << "6- Sauver un circuit dans un fichier" << endl;
		cout << "7- Relire un circuit qui est dans un fichier" << endl;
		cout << "8- Quitter" << endl;

		cout << "Votre choix : ";
		cin >> choix;

		switch(choix) {

			case 1 : circuit->afficheCircuit();
					 break;
			case 2 : circuit->simulation();
					 break;
			case 3 : circuit->changerValeursDesPortesEntree();
					 break;
			case 4 : cout << circuit->afficherSousFormeTextuelle() << endl;
			         cout << endl;
					 break;
			case 5 :  cout << "Synthétiser un circuit à partir d'une expression textuelle" << endl;
					  cout << "Expression textuelle : ";
					  cin >> expressionTextuelle;
					  circuit = circuit->expressionTextuelleToCircuit(expressionTextuelle);
					   break;
			case 8 : // Quitter
				     break;
			default : cout << "Option pas dispo" << endl;
		}

	} while(choix != 8);

	return 0;
}
