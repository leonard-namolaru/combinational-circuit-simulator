/*
 * main.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include <iostream>
#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "XorGate.hpp"
#include "Circuit.hpp"
#include "CircuitException.hpp"
int main(){

	/* **** EXEMPLE DE CONSTRUCTION D'UN CIRCUIT À L'AIDE DES OBJETS APPROPRIÉS **** */

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

	/* La sortie du circuit  */
	OutputGate *A = new OutputGate('A', and6);

	/*
	 * IMPORTANT !
	 * Une sortie du circuit doit être ajoutée à la fois
	 * au vecteur des portes logiques (gates) et au vecteur des sorties (ouputs).
	 */

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

	vector<OutputGate*>* ouputs = new vector<OutputGate*>;
	ouputs->push_back(A);

	// Création du circuit.
	Circuit* circuit = new Circuit(inputsCircuit, gates, ouputs);

	/*
	 * Vous pouvez afficher le résultat en exécutant le programme
	 * et en sélectionnant l'option numéro 1 dans le menu.
	 */

	/* **** MENU **** */

	int choix = 1;
	string expressionTextuelle;
	do{
		cout << "**** MENU : SIMULATEUR DE CIRCUIT COMBINATOIRE ***" << endl;
		cout << "1- Afficher le circuit" << endl;
		cout << "2- Simulation en mode pas à pas" << endl;
		cout << "3- Changer les valeurs des portes d’entrée" << endl;
		cout << "4- Afficher sous forme textuelle" << endl;
		cout << "5- Synthétiser un circuit à partir d'une expression textuelle" << endl;
		cout << "6- Sauvegarder un circuit dans un fichier" << endl;
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
			case 4 : cout << endl;
					 cout << circuit->afficherSousFormeTextuelle() << endl;
			         cout << endl;
					 break;
			case 5 :  cout << "Synthétiser un circuit à partir d'une expression textuelle" << endl;
			          cout << "Veuillez ne pas utiliser d'espaces svp. Un exemple du plus petit circuit qui peut être créé : A=and(a,b)" << endl;
			          cout << "Une porte logique peut avoir comme entrées deux entrées du circuit ou deux entrées qui sont des portes logiques. Mais il n'est pas possible de transférer une entrée du premier type et une seconde entrée du second type.."<< endl;
			          cout << "Noms des portes logiques utilisables : xor (ainsi que XOR), or (ainsi que OR,OR_ et or_), and (ainsi que AND), nor (ainsi que NOR),"<< endl;
			          cout << "xnor (ainsi que XNOR,xno et XNO), nand (ainsi que NAND,nan et NAN) "<< endl;
			          cout << "Bien qu'un circuit puisse être créé avec de nombreuses entrées, la limitation est que le circuit ne peut contenir qu'une seule sortie."<< endl;
					  cout << "Expression textuelle : ";
					  cin >> expressionTextuelle;
					  delete circuit;
					  circuit = Circuit::expressionTextuelleToCircuit(expressionTextuelle);
					  break;
			case 6 : circuit->sauvegarderCircuitDansFichier("circuit.txt"); // Sauvegarder un circuit dans un fichier
				     break;
			case 7 : delete circuit;
				     circuit = Circuit::relireCircuitQuiEstDansUnFichier("circuit.txt"); // Relire un circuit qui est dans un fichier
				     break;
			case 8 : // Quitter
				     break;
			default :cout << endl;
				     cout << "L'option que vous avez sélectionnée n'est pas disponible. Veuillez réessayer." << endl;
				     cout << endl;
		} // switch
	} while(choix != 8);
	return 0;
} // main
