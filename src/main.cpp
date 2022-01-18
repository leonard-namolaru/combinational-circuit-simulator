/*
 * main.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages � objets avanc�s 2021 - 2022
 * M1 : Master Informatique fondamentale et appliqu�e - Universit� de Paris.
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
bool isNumeric(string str) {
   int k=str.length();
   for (int i = 0; i < k; i++)
      if (isdigit(str[i]) == false)
      return false; //when one non numeric value is found, return false
   return true;
}
int main(){

	/* **** EXEMPLE DE CONSTRUCTION D'UN CIRCUIT � L'AIDE DES OBJETS APPROPRI�S **** */

	/* Les entr�es */
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
	 * Une sortie du circuit doit �tre ajout�e � la fois
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

	// Cr�ation du circuit.
	Circuit* circuit = new Circuit(inputsCircuit, gates, ouputs);

	/*
	 * Vous pouvez afficher le r�sultat en ex�cutant le programme
	 * et en s�lectionnant l'option num�ro 1 dans le menu.
	 */

	/* **** MENU **** */

	string choix = "";
    
	string expressionTextuelle;
	do{
		cout << "**** MENU : SIMULATEUR DE CIRCUIT COMBINATOIRE ***" << endl;
		cout << "1- Afficher le circuit" << endl;
		cout << "2- Simulation en mode pas � pas" << endl;
		cout << "3- Changer les valeurs des portes d�entr�e" << endl;
		cout << "4- Afficher sous forme textuelle" << endl;
		cout << "5- Synth�tiser un circuit � partir d'une expression textuelle" << endl;
		cout << "6- Sauvegarder un circuit dans un fichier" << endl;
		cout << "7- Relire un circuit qui est dans un fichier" << endl;
		cout << "8- Quitter" << endl;

		repeat: cout << "Votre choix : ";
		cin >> choix;
		if(! isNumeric(choix)){
			goto repeat;
		}
		if(choix=="1"){
			circuit->afficheCircuit();
		}else if (choix=="2"){
			circuit->simulation();

		}else if (choix=="3"){
			circuit->changerValeursDesPortesEntree();

		}else if (choix=="4"){
			cout << circuit->afficherSousFormeTextuelle() << endl;

		}else if (choix=="5"){
			          cout << "Synthetiser un circuit a partir d'une expression textuelle" << endl;
			          cout << " " << endl;
					  cout << "Veuillez respecter les regles suivantes : " << endl;
					  cout << " 1 - Veuillez ne pas mettre des espaces dans l'expression textuelle." << endl;
			          cout << " 2 - Une porte logique peut avoir comme entr�es deux entrées du circuit ou deux entr�es qui sont des portes logiques. Mais il n'est pas possible de transferer une entree du premier type et une seconde entree du second type.."<< endl;
			          cout << " 3 - Noms des portes logiques utilisables : xor (ou XOR), or (ou OR,OR_ ,or_), and (ou AND), nor (ou NOR),"<< endl;
			          cout << " 4 - xnor (ou XNOR,xno, XNO), nand (ou NAND,nan et NAN) "<< endl;
			          cout << " 5 - Bien qu'un circuit puisse avoir plusieurs entrée , il n'a qu'une sortie."<< endl;
					  cout << "Expression textuelle : ";
					  cin >> expressionTextuelle;
					  delete circuit;
					  circuit = Circuit::expressionTextuelleToCircuit(expressionTextuelle);

		}else if (choix=="6"){
			          circuit->sauvegarderCircuitDansFichier("circuit.txt"); // Sauvegarder un circuit dans un fichier

		}else if (choix=="7"){
                     circuit = Circuit::relireCircuitQuiEstDansUnFichier("circuit.txt"); // Relire un circuit qui est dans un fichier
		}else if (choix=="8"){
			return 0;
		}
		
		else{

			cout << "L'option que vous avez selectionnee n'est pas disponible. Veuillez reessayer." << endl;

		}
       

	} while(choix != "8");
	


	
	return 0;
} // main
