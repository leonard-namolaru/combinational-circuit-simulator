#include "Circuit.hpp"
#include <iostream>
#include <map>

vector<Gate*>* Circuit::ajoutInputs(){

	// Corrélation entre le nom d'un input avec le numéro de la ligne de ce input dans le vecteur de l'affichage.
	map<char,int> correlationEntreNomInputAvecNumeroLigneDansAffichage;
	for(unsigned int i = 0 ; i < inputs->size() ; i++) // Nous parcourons le vecteur qui inclut les entrées (inputs)
		correlationEntreNomInputAvecNumeroLigneDansAffichage.insert( make_pair(inputs->at(i)->getName().at(0), i));

	vector<Gate*>* portesLogiquesAvecEntreesQuiSontEntreesDuCircuit = new vector<Gate*>;
	// Le nombre d'entrées des portes logiques qui sont aussi des entrées du circuit
	int nombreEntreesPortesLogiquesQuiSontEntreesDuCircuit = 0;
	for(unsigned int i = 0 ; i < gates->size() ; i++){
		bool check = false;
		for(unsigned int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++) {

			// Si le nom dun Gate est de longeur 1, c'est un InputGate
			if(gates->at(i)->getEntrees()->at(j)->getName().size() == 1){
				check = true;
				nombreEntreesPortesLogiquesQuiSontEntreesDuCircuit++;
			}
		} // for(j)

		if(check) portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->push_back(gates->at(i));
	} // for(i)

	// la debut de chqaue ligne pour un input ressemble à ceci (par exemple) : a:0 -- (6 caractères)
	const int NB_CHAR_AU_DEBUT_CHAQUE_LIGNE = 6; // Le nombre de caractères qui apparaissent toujours au début de chaque ligne d'un input
	int longueurLigneAffichage = NB_CHAR_AU_DEBUT_CHAQUE_LIGNE + nombreEntreesPortesLogiquesQuiSontEntreesDuCircuit*2;

	for(unsigned int i = 0 ; i < inputs->size() ; i++){ // Nous parcourons le vecteur qui inclut les entrées (inputs)
		affichageCircuit->push_back(new vector<char>(longueurLigneAffichage, '-')); // Pour chaque entrée, nous ajoutons une nouvelle ligne à l'affichage

		// La ligne commence par afficher le nom de l'entrée, sa valeur booléenne ainsi que quelques caractères supplémentaires pour l'affichage

		affichageCircuit->at(i)->at(0) = inputs->at(i)->getName().at(0); // Chaque ligne d'entrée commence par l'affichage du nom de l'entrée
		affichageCircuit->at(i)->at(1) =  ':'; // Après le nom d'entrée, nous affichons le caractère ':'

		// Après le caractère ':', on présente la valeur booléenne initiale
		// Nous obtenons la valeur booléenne en tant que int, nous transformons l'int en string,
		// puis en utilisant la méthode at() nous obtenons ce nombre en tant que caractère (char) afin qu'il puisse être ajouté au vecteur d'affichage qui se compose de caractères
		affichageCircuit->at(i)->at(2) =   to_string( inputs->at(i)->getValeurBooleenne() ).at(0); // to_string(int __val) ; char& string.at(size_type __n)

		affichageCircuit->at(i)->at(3) =  ' '; // Ajout d'un espace vide à l'affichage
		affichageCircuit->at(i)->at(4) =  '-'; // Ajout du caractère '-' à l'affichage
		affichageCircuit->at(i)->at(5) =  '-'; // Ajout du caractère '-' à l'affichage
	}

	/* Nous voulons dessiner une trajectoire de départ pour l'entrée.
	 * Dans l'itinéraire, nous ajouterons le caractère '*' en fonction du nombre de portes logiques qui reçoivent l'entrée actuelle en input.
	 * Le caractère '+' est en fait un point qui permet le passage pour d'autres entrées
	 */

	int positionProchainAsterisque = NB_CHAR_AU_DEBUT_CHAQUE_LIGNE; // La position du prochain astérisque
	for(unsigned int i = 0 ; i < portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->size() && positionProchainAsterisque < longueurLigneAffichage; i++) {
		for(unsigned int j = 0 ; j < portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->at(i)->getEntrees()->size(); j++) {

			// Si le nom dun Gate est de longeur 1, c'est un InputGate
			if(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->at(i)->getEntrees()->at(j)->getName().size() == 1) {
				char name = portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->at(i)->getEntrees()->at(j)->getName().at(0);
				affichageCircuit->at(correlationEntreNomInputAvecNumeroLigneDansAffichage.at(name))->at(positionProchainAsterisque) = '*';
				positionProchainAsterisque += 2;
			} // if

		} // for
	} // for

	for(unsigned int i = 1 ; i < affichageCircuit->size() ; i++) {
		for(unsigned int j = 0; j < affichageCircuit->at(i)->size() ; j++) {
			if(affichageCircuit->at(i - 1)->at(j) == '+' || affichageCircuit->at(i - 1)->at(j) == '*')
				affichageCircuit->at(i)->at(j) = '+';
		}
	}

	return portesLogiquesAvecEntreesQuiSontEntreesDuCircuit;
} // ajoutInputs()

/**
 * Une methode qui recherche les positions des caractères '+' et '*' dans la dernière ligne du vecteur qui stocke l'affichage du circuit
 * et ajoute aux mêmes positions dans la ligne en dessous le caractère '|'
 */
void Circuit::ajoutCheminsApresInputs(){
	int longueurLigne = affichageCircuit->at(0)->size(); // Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ); // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')

	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.

	// Nous parcourons l'avant-dernière ligne de l'affichage (La dernière ligne avant la nouvelle ligne que nous venons d'ajouter)
	for(unsigned int i = 0 ; i < affichageCircuit->at(nombreDeLignes-2)->size() ; i++) {
		if(affichageCircuit->at(nombreDeLignes-2)->at(i) == '+' || affichageCircuit->at(nombreDeLignes-2)->at(i) == '*')
			affichageCircuit->at(nombreDeLignes - 1)->at(i) = '|';
	} // for

} // ajoutCheminsApresInputs()


void Circuit::ajoutNomsOperationsLogiques(const vector<Gate*>* portesLogiquesAjouterAffichage){
	int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne

	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit
	int NombreDeLignesDansAffichage = affichageCircuit->size(); // Le nombre de lignes de l'affichage du circuit, y compris la ligne nouvellement ajoutée
	unsigned int d = 0;
	for(unsigned int i = 0 ; (i < affichageCircuit->at(NombreDeLignesDansAffichage - 1)->size()) && (d < portesLogiquesAjouterAffichage->size()) ; i++ ){
		if (affichageCircuit->at(NombreDeLignesDansAffichage - 2)->at(i) == '|' && affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i) == ' ') {
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i) = portesLogiquesAjouterAffichage->at(d)->getName().at(0);
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i + 1) = portesLogiquesAjouterAffichage->at(d)->getName().at(1);
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i + 2) = portesLogiquesAjouterAffichage->at(d)->getName().at(2);
			d++;

		}
	}

} // ajoutNomsOperationsLogiques()

void Circuit::ajoutCheminsApresOperationsLogiques(){
	unsigned int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')

	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.

	// Nous parcourons la dernière ligne de l'affichage (La dernière ligne avant la nouvelle ligne que nous venons d'ajouter)
	for(unsigned int i = 0 ; i < affichageCircuit->at(nombreDeLignes-2)->size() ; i++) {

		if(affichageCircuit->at(nombreDeLignes-2)->at(i) >= 'A' && affichageCircuit->at(nombreDeLignes-2)->at(i) <= 'Z') {
			if ((i != 0) && (affichageCircuit->at(nombreDeLignes-2)->at(i - 1) >= 'A' && affichageCircuit->at(nombreDeLignes-2)->at(i - 1) <= 'Z')) {
				if ((i != longueurLigne - 1) && ( (affichageCircuit->at(nombreDeLignes-2)->at(i + 1) >= 'A' && affichageCircuit->at(nombreDeLignes-2)->at(i + 1) <= 'Z') || (affichageCircuit->at(nombreDeLignes-2)->at(i + 1) == '_') ))
					affichageCircuit->at(nombreDeLignes-1)->at(i) = '|';
			} // if
		} // if

	} // for
} // ajoutCheminsApresOperationsLogiques()

void Circuit::ajoutAsterisquesApresChemins(unsigned int level){
	unsigned int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')

	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	bool alternance = false;
	vector<int> memo;

	for(unsigned int i = 0 ; i < affichageCircuit->at( affichageCircuit->size() -2 )->size() ; i++) {
		unsigned int j, count;
		if( affichageCircuit->at( affichageCircuit->size() -2 )->at(i) == '|' ){
			if(alternance){
				alternance = false;
				affichageCircuit->at( affichageCircuit->size() -1 )->at(i) = '*';
				for(j = i - 1, count = 0 ; count < level && j > 0 ; j--, count++)
					affichageCircuit->at( affichageCircuit->size() -1 )->at(j) = '*';
				memo.push_back(j + 1);
			} else {
				alternance = true;
				affichageCircuit->at( affichageCircuit->size() -1 )->at(i) = '*';
				for(j = i + 1, count = 0 ; count < level && j < longueurLigne ; j++, count++)
					affichageCircuit->at( affichageCircuit->size() -1 )->at(j) = '*';
				memo.push_back(j - 1);
			}
		}
	}

	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit
	nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	for(unsigned int i = 0 ; i < memo.size() ; i++)
		affichageCircuit->at(nombreDeLignes - 1)->at(memo.at(i)) = '|';
} // ajoutAsterisquesApresChemins()

vector<Gate*>* Circuit::trouverLesPortesLogiquesSuivantes(const vector<Gate*>* portesLogiquesPrecedentes){
	vector<Gate*>* portesLogiquesSuivantes = new vector<Gate*>;

	for(unsigned int i = 0 ; i < gates->size() ; i++ ){
		bool check = true;
		for(unsigned int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++) {
			bool found = false;
			for(unsigned int k = 0 ; k < portesLogiquesPrecedentes->size() ; k++) {
				if(portesLogiquesPrecedentes->at(k) == gates->at(i)->getEntrees()->at(j))
					found = true;
			}

			if(!found) check = false;
		}
		if(check) portesLogiquesSuivantes->push_back(gates->at(i));
	}
	return portesLogiquesSuivantes;
} // trouverLesPortesLogiquesSuivantes()

void Circuit::ajoutOuputs(){
	int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit

	int NombreDeLignesDansAffichage = affichageCircuit->size(); // Le nombre de lignes de l'affichage du circuit, y compris la ligne nouvellement ajoutée
	unsigned int d = 0;
	for(unsigned int i = 0 ; i < affichageCircuit->at(NombreDeLignesDansAffichage - 2)->size() && d < ouputs->size() ; i++ ){
		if (affichageCircuit->at(NombreDeLignesDansAffichage - 2)->at(i) == '|'){
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i) = ouputs->at(d)->getName().at(0);
			d++;
		}
	}
} // ajoutOuputs()

Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates, vector<OutputGate*>* ouputs)
: inputs{inputsCircuit}, ouputs{ouputs}, gates{gates}, affichageCircuit{new vector< vector<char>* >}, simulationPasParPas{new vector< vector<Gate*>* >} {

	vector<Gate*>* portesLogiquesAvecEntreesQuiSontEntreesDuCircuit = ajoutInputs();
	simulationPasParPas->push_back(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit);

	ajoutCheminsApresInputs();
	ajoutNomsOperationsLogiques(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit);// Afficher les noms des opérations logiques
	ajoutCheminsApresOperationsLogiques();

	vector<Gate*>* portesLogiquesSuivantes = trouverLesPortesLogiquesSuivantes(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit);
	vector<Gate*>* portesLogiquesPrecedentes = portesLogiquesAvecEntreesQuiSontEntreesDuCircuit;
	int level = 1;
	int index = 1;
	while(portesLogiquesSuivantes->size() != 0) {
		simulationPasParPas->push_back(portesLogiquesSuivantes);

		ajoutAsterisquesApresChemins(level);
		ajoutNomsOperationsLogiques(portesLogiquesSuivantes);// Afficher les noms des opérations logiques
		ajoutCheminsApresOperationsLogiques();

		level = level + (2 * index);
		index++;

		portesLogiquesPrecedentes = portesLogiquesSuivantes;
		portesLogiquesSuivantes = trouverLesPortesLogiquesSuivantes(portesLogiquesPrecedentes);
	}
	ajoutOuputs();
}


Circuit::~Circuit()
{
}


void Circuit::afficheCircuit() const {
	for(unsigned int i = 0 ; i < affichageCircuit->size() ; i++){
		for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
			cout << affichageCircuit->at(i)->at(j);
		}
		cout << endl;
	}
	cout << endl;

}

/**
 * Simulation en mode pas à pas
 */
void Circuit::simulation() {
	cout << endl;

	cout << "**********************************************************************************************************************" << endl;
	cout << "Bonjour et bienvenue au simulateur de circuit combinatoire !" << endl;
	cout <<	"La simulation sera effectuée en mode pas à pas, c’est-à-dire qu’à chaque pas l’information franchit au plus une porte," << endl;
	cout <<	"et durant toutes les étapes vous pourrez voir dans l’affichage la progression de l’information" << endl;
	cout << "**********************************************************************************************************************" << endl;

	cout << endl;

	unsigned int nbInputs =  inputs->size();
	for(unsigned int i = 0 ; i < nbInputs ; i++){
		for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
			cout << affichageCircuit->at(i)->at(j);
		}
		cout << endl;
	}
	cout << endl;

	cout << "**********************************************************************************************************************" << endl;
	for(unsigned i = 0 ; i < inputs->size() ; i++)
		cout << inputs->at(i)->getName() << " : " << inputs->at(i)->getValeurBooleenne() << "     ";
	cout << endl;
	cout << "**********************************************************************************************************************" << endl;

	int position = nbInputs;
	for(unsigned int numeroDePas = 0 ; numeroDePas < simulationPasParPas->size() ; numeroDePas++) {

		for(unsigned int i = position ; i < position + 2 && i < affichageCircuit->size() ; i++){
			for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
				cout << affichageCircuit->at(i)->at(j);
			}
			cout << endl;
		}


		int stop = 1;
		for(unsigned int i = 0 ; i < simulationPasParPas->at(numeroDePas)->size() ; i++) {
			cout << "**********************************************************************************************************************" << endl;
			for(unsigned int j = 0  ; (j < stop) && (stop <=  simulationPasParPas->at(0)->size()) ; j++) {
					cout << simulationPasParPas->at(numeroDePas)->at(j)->getName() << "(" << simulationPasParPas->at(numeroDePas)->at(j)->getEntrees()->at(0)->getName() << "," <<  simulationPasParPas->at(numeroDePas)->at(j)->getEntrees()->at(1)->getName() << ") : " << simulationPasParPas->at(numeroDePas)->at(j)->getValeurBooleenne() << "     ";
			}
			cout << endl;
			cout << "**********************************************************************************************************************" << endl;
			stop++;
		}
		cout << endl;

		position = position + 4;
	}


}

void Circuit::changerValeursDesPortesEntree() {
	for(unsigned int i = 0 ; i < inputs->size() ; i++){
		cout << "Nom de l'entrée : " << inputs->at(i)->getName() << " ; Valeur : " << inputs->at(i)->getValeurBooleenne() << endl;
		cout << "Nouvelle valeur [1 / 0] : ";
		int tmp = inputs->at(i)->getValeurBooleenne();
		cin >> tmp;
		inputs->at(i)->setValeurBooleenne(tmp);
		cout << endl;
	}
	cout << endl;

	for(unsigned int i = 0 ; i < inputs->size() ; i++)
		affichageCircuit->at(i)->at(2) = to_string( inputs->at(i)->getValeurBooleenne() ).at(0); // to_string(int __val) ; char& string.at(size_type __n)
}
