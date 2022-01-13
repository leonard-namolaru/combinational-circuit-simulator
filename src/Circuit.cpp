#include "Circuit.hpp"
#include <map>

vector<Gate*>* Circuit::ajoutInputs(){

	// Corrélation entre le nom d'un input avec le numéro de la ligne de ce input dans le vecteur de l'affichage.
	map<char,int> correlationEntreNomInputAvecNumeroLigneDansAffichage;
	for(unsigned int i = 0 ; i < inputs->size() ; i++) // Nous parcourons le vecteur qui inclut les entrées (inputs)
		correlationEntreNomInputAvecNumeroLigneDansAffichage.insert( make_pair(inputs->at(i)->getInputName(), i));

	vector<Gate*>* portesLogiquesAvecEntreesQuiSontEntreesDuCircuit = new vector<Gate*>;
	for(unsigned int i = 0 ; i < gates->size() ; i++){
		for(unsigned int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++) {

			// Si le nom dun Gate est de longeur 1, c'est un InputGate
			if(gates->at(i)->getEntrees()->at(j)->getName().size() == 1)
				portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->push_back(gates->at(i));
		} // for(j)
	} // for(i)

	// Le nombre d'entrées des portes logiques qui sont aussi des entrées du circuit
	int nombreEntreesPortesLogiquesQuiSontEntreesDuCircuit = portesLogiquesAvecEntreesQuiSontEntreesDuCircuit->size();
	// la debut de chqaue ligne pour un input ressemble à ceci (par exemple) : a:0 -- (6 caractères)
	const int NB_CHAR_AU_DEBUT_CHAQUE_LIGNE = 6; // Le nombre de caractères qui apparaissent toujours au début de chaque ligne d'un input
	int longueurLigneAffichage = NB_CHAR_AU_DEBUT_CHAQUE_LIGNE + nombreEntreesPortesLogiquesQuiSontEntreesDuCircuit*2;

	for(unsigned int i = 0 ; i < inputs->size() ; i++){ // Nous parcourons le vecteur qui inclut les entrées (inputs)
		affichageCircuit->push_back(new vector<char>(longueurLigneAffichage, '-')); // Pour chaque entrée, nous ajoutons une nouvelle ligne à l'affichage

		// La ligne commence par afficher le nom de l'entrée, sa valeur booléenne ainsi que quelques caractères supplémentaires pour l'affichage

		affichageCircuit->at(i)->at(0) = inputs->at(i)->getInputName(); // Chaque ligne d'entrée commence par l'affichage du nom de l'entrée
		affichageCircuit->at(i)->at(1) =  ':'; // Après le nom d'entrée, nous affichons le caractère ':'

		// Après le caractère ':', on présente la valeur booléenne initiale
		// Nous obtenons la valeur booléenne en tant que int, nous transformons l'int en string,
		// puis en utilisant la méthode at() nous obtenons ce nombre en tant que caractère (char) afin qu'il puisse être ajouté au vecteur d'affichage qui se compose de caractères
		affichageCircuit->at(i)->at(2) =   to_string( inputs->at(i)->getValEnBinaire() ).at(0); // to_string(int __val) ; char& string.at(size_type __n)

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

void Circuit::affichageAsterisquesApresChemins(int level){
	unsigned int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')

	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	bool alternance = false;


	for(unsigned int i = 0 ; i < affichageCircuit->at( affichageCircuit->size() -2 )->size() ; i++) {
		if( affichageCircuit->at( affichageCircuit->size() -2 )->at(i) == '|' ){
			if(alternance){
				alternance = false;
				affichageCircuit->at( affichageCircuit->size() -1 )->at(i) = '*';
				for(unsigned int j = i - 1, count = 0 ; count < level && j > 0 ; j--, count++)
					affichageCircuit->at( affichageCircuit->size() -1 )->at(j) = '*';
			} else {
				alternance = true;
				affichageCircuit->at( affichageCircuit->size() -1 )->at(i) = '*';
				for(unsigned int j = i + 1, count = 0 ; count < level && j < longueurLigne ; j++, count++)
					affichageCircuit->at( affichageCircuit->size() -1 )->at(j) = '*';
			}
		}
	}

	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit
	nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	alternance = true;
	for(int i = 0 ; i < affichageCircuit->at(nombreDeLignes - 2)->size() ; i++) {
		if( affichageCircuit->at(nombreDeLignes - 2)->at(i) == '*' ){
				if(alternance){
					if( i != 0 && affichageCircuit->at(nombreDeLignes - 2)->at(i - 1) == '*') {
						if( i != longueurLigne - 1 && affichageCircuit->at(nombreDeLignes - 2)->at(i + 1) == ' ') {
								affichageCircuit->at(nombreDeLignes - 1)->at(i) = '|';
								alternance = false;
								i++;
						}
					}
				}
				else {
					if( i != 0 && affichageCircuit->at(nombreDeLignes - 2)->at(i - 1) == ' ') {
						if( i != longueurLigne - 1 && affichageCircuit->at(nombreDeLignes - 2)->at(i + 1) == '*') {
							affichageCircuit->at(nombreDeLignes - 1)->at(i) = '|';
							alternance = true;
							i++;
						}
					}
				}
		}
	}


} // affichageAsterisquesApresChemins()

void Circuit::affichageNomsOperationsLogiques2(const vector<Gate*>* gatesVector){

	int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	vector<Gate*>* gatesVector2 = new vector<Gate*>;

	int NombreDeLignesDansAffichage = affichageCircuit->size(); // Le nombre de lignes de l'affichage du circuit, y compris la ligne nouvellement ajoutée

	for(int i = 0 ; i < gates->size() ; i++ ){
		bool check = true;
		for(int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++) {
			bool found = false;
			for(int k = 0 ; k < gatesVector->size() ; k++) {
				if(gatesVector->at(k) == gates->at(i)->getEntrees()->at(j))
					found = true;
			}

			if(!found) check = false;
		}

		if(check) gatesVector2->push_back(gates->at(i));
	}

	ajoutNomsOperationsLogiques(gatesVector2);

} // affiintchageNomsOperationsLogiques2()



Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates, vector<OutputGate*>* ouputs)
: inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >}, gates{gates}, ouputs{ouputs}  {
	vector<Gate*>* portesLogiquesAvecEntreesQuiSontEntreesDuCircuit = ajoutInputs();
	ajoutCheminsApresInputs();
	ajoutNomsOperationsLogiques(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit);// Afficher les noms des opérations logiques
	ajoutCheminsApresOperationsLogiques();
	affichageAsterisquesApresChemins(1);
	affichageNomsOperationsLogiques2(portesLogiquesAvecEntreesQuiSontEntreesDuCircuit);
	ajoutCheminsApresOperationsLogiques();
	affichageAsterisquesApresChemins(3);
}

Circuit::Circuit()
{

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
