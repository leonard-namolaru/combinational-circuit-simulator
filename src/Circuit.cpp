#include "Circuit.hpp"
#include <map>

vector<string>* Circuit::affichageInputs(){
	// la debut de chqaue ligne pour un input ressemble à ceci (par exemple) : a:0 -- (6 caractères)
	const int NB_CHAR_AU_DEBUT_CHAQUE_LIGNE = 6; // Le nombre de caractères qui apparaissent toujours au début de chaque ligne d'un input
	map<char,int> memo;
	vector<string>* noms = new vector<string>;

	for(int i = 0 ; i < inputs->size() ; i++) // Nous parcourons le vecteur qui inclut les entrées (inputs)
		memo.insert( make_pair(inputs->at(i)->getInputName(), i));

	int sum = 0;
	for(int i = 0 ; i < gates->size() ; i++){
		sum += gates->at(i)->getEntrees()->size();
	}

	for(int i = 0 ; i < inputs->size() ; i++){ // Nous parcourons le vecteur qui inclut les entrées (inputs)
		affichageCircuit->push_back(new vector<char>); // Pour chaque entrée, nous ajoutons une nouvelle ligne à l'affichage

		// La ligne commence par afficher le nom de l'entrée, sa valeur booléenne ainsi que quelques caractères supplémentaires pour l'affichage

		affichageCircuit->at(i)->push_back( inputs->at(i)->getInputName() ); // Chaque ligne d'entrée commence par l'affichage du nom de l'entrée
		affichageCircuit->at(i)->push_back( ':' ); // Après le nom d'entrée, nous affichons le caractère ':'

		// Après le caractère ':', on présente la valeur booléenne initiale
		// Nous obtenons la valeur booléenne en tant que int, nous transformons l'int en string,
		// puis en utilisant la méthode at() nous obtenons ce nombre en tant que caractère (char) afin qu'il puisse être ajouté au vecteur d'affichage qui se compose de caractères
		affichageCircuit->at(i)->push_back(  to_string( inputs->at(i)->getValEnBinaire() ).at(0) ); // to_string(int __val) ; char& string.at(size_type __n)

		affichageCircuit->at(i)->push_back( ' ' ); // Ajout d'un espace vide à l'affichage
		affichageCircuit->at(i)->push_back( '-' ); // Ajout du caractère '-' à l'affichage
		affichageCircuit->at(i)->push_back( '-' ); // Ajout du caractère '-' à l'affichage

		// Jusqu'à présent, la ligne ressemble à ceci (par exemple) : a:0 --

		for(int j = 0 ; j < sum + (sum / 2) ; j++)
			affichageCircuit->at(i)->push_back('-');
	}

	/* Nous voulons dessiner une trajectoire de départ pour l'entrée.
	 * Dans l'itinéraire, nous ajouterons le caractère '*' en fonction du nombre de portes logiques qui reçoivent l'entrée actuelle en input.
	 * Le caractère '+' est en fait un point qui permet le passage pour d'autres entrées
	 */

	int d = NB_CHAR_AU_DEBUT_CHAQUE_LIGNE;
	for(int i = 0 ; i < gates->size() ; i++ ){
		bool addToVector = false;
		for(int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++) {
			if(gates->at(i)->getEntrees()->at(j)->getName().size() == 1) {
				addToVector = true;
				char name = gates->at(i)->getEntrees()->at(j)->getName().at(0);
				affichageCircuit->at(memo.at(name))->at(d) = '*';
				d += 2;
			}
		}

		if(addToVector)
			noms->push_back(gates->at(i)->getName());

	}

	for(int i = 0 ; i < affichageCircuit->size() ; i++) {
		for( int j = 0; j < affichageCircuit->at(i)->size() ; j++) {
			if(i != 0) {
					if(affichageCircuit->at(i - 1)->at(j) == '+' || affichageCircuit->at(i - 1)->at(j) == '*')
						affichageCircuit->at(i)->at(j) = '+';
			}
		}
	}

	return noms;
} // affichageInputs()

void Circuit::affichageChemins(){
	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.

	affichageCircuit->push_back( new vector<char> ); // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')

	// Nous parcourons la dernière ligne de l'affichage (La dernière ligne avant la nouvelle ligne que nous venons d'ajouter)
	for(int j = 0 ; j < affichageCircuit->at(nombreDeLignes-1)->size() ; j++) {

		if(affichageCircuit->at(nombreDeLignes-1)->at(j) == '+' || affichageCircuit->at(nombreDeLignes-1)->at(j) == '*' || affichageCircuit->at(nombreDeLignes-1)->at(j) == '|') {
			// Nombre d'emplacements à ajouter à la nouvelle ligne
			int nombreEmplacementsAjouterNouvelleLigne = j - affichageCircuit->at(nombreDeLignes)->size();
			for(int k = 0 ; k < nombreEmplacementsAjouterNouvelleLigne ; k++)
				affichageCircuit->at(nombreDeLignes)->push_back( ' ' );
			affichageCircuit->at(nombreDeLignes)->push_back( '|' );
		} // if
	} // for

} // affichageChemins()


void Circuit::affichageNomsOperationsLogiques(const vector<string>* noms){
	// la debut de chqaue ligne pour un input ressemble à ceci (par exemple) : a:0 -- (6 caractères)
	const int NB_CHAR_AU_DEBUT_CHAQUE_LIGNE = 6; // Le nombre de caractères qui apparaissent toujours au début de chaque ligne d'un input

	int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne

	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit
	int NombreDeLignesDansAffichage = affichageCircuit->size(); // Le nombre de lignes de l'affichage du circuit, y compris la ligne nouvellement ajoutée
	int d = 0;
	for(int i = 0 ; i < affichageCircuit->at(NombreDeLignesDansAffichage - 1)->size() ; i++ ){
		if (affichageCircuit->at(NombreDeLignesDansAffichage - 2)->at(i) == '|' && affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i) == ' ') {
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i) = noms->at(d).at(0);
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i + 1) = noms->at(d).at(1);
			affichageCircuit->at(NombreDeLignesDansAffichage - 1)->at(i + 2) = noms->at(d).at(2);
			d++;

		}
	}

} // affichageNomsOperationsLogiques()

void Circuit::affichageCheminsApresOperationsLogiques(){
	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	affichageCircuit->push_back( new vector<char> ); // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')
	// Nous parcourons la dernière ligne de l'affichage (La dernière ligne avant la nouvelle ligne que nous venons d'ajouter)
	for(unsigned int j = 0 ; j < affichageCircuit->at(nombreDeLignes-1)->size() ; j++) {
		if(affichageCircuit->at(nombreDeLignes-1)->at(j) >= 'A' && affichageCircuit->at(nombreDeLignes-1)->at(j) <= 'Z') {
			// Nombre d'emplacements à ajouter à la nouvelle ligne
			unsigned int nombreEmplacementsAjouterNouvelleLigne = j - affichageCircuit->at(nombreDeLignes)->size();
			for(unsigned int k = 0 ; k < nombreEmplacementsAjouterNouvelleLigne + 1 ; k++)
				affichageCircuit->at(nombreDeLignes)->push_back( ' ' );
			affichageCircuit->at(nombreDeLignes)->push_back( '|' );
			j+=2;
		} // if
	} // for
} // affichageChemins()

void Circuit::affichageAsterisques(){
	affichageCircuit->push_back(new vector<char>);
	bool cond = false;
	for(unsigned int i = 0 ; i < affichageCircuit->at( affichageCircuit->size() -2 )->size() ; i++) {
		if( affichageCircuit->at( affichageCircuit->size() -2 )->at(i) == '|' ){
			int diff = i - affichageCircuit->at( affichageCircuit->size() -1 )->size();
			if(cond){
				diff--;
				cond = false;
			} else {
				cond = true;
			}
			for(int j = 0 ; j < diff ; j++) {
				affichageCircuit->at( affichageCircuit->size() -1 )->push_back(' ');
			}
			affichageCircuit->at( affichageCircuit->size() -1 )->push_back('*');
			affichageCircuit->at( affichageCircuit->size() -1 )->push_back('*');
		}
	}

	int longueurLigne = affichageCircuit->at(0)->size();// Longueur d'une ligne
	affichageCircuit->push_back( new vector<char>(longueurLigne, ' ') ) ; // Ajouter une  ligne à l'affichage du circuit
	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	cond = true;
	for(int i = 0 ; i < affichageCircuit->at(nombreDeLignes - 2)->size() ; i++) {
		if( affichageCircuit->at(nombreDeLignes - 2)->at(i) == '*' ){
			if(i != 0 && affichageCircuit->at(nombreDeLignes - 1)->at(i - 1) == '|') {
				if(cond){
					affichageCircuit->at(nombreDeLignes - 1)->at(i) = '|';
					affichageCircuit->at(nombreDeLignes - 1)->at(i - 1) = ' ';
					cond = false;
				}
				else {
					cond = true;
				}
			}
			else {
				affichageCircuit->at(nombreDeLignes - 1)->at(i) = '|';
			}
		}
	}


} // affichageAsterisques()

void Circuit::affichageNomsOperationsLogiques2(){
	affichageCircuit->push_back( new vector<char> ) ; // Ajouter une  ligne à l'affichage du circuit
	vector<string> liste;
	vector<Gate*> liste2;
	for( int i = 0 ; i < affichageCircuit->at( affichageCircuit->size() - 3 )->size() ; i++){
		if(  affichageCircuit->at( affichageCircuit->size() - 3 )->at(i) == '*' ){
			bool cond = false;
			string str = "";
			if(!cond && affichageCircuit->at( affichageCircuit->size() - 5 )->at(i - 1) != ' ') str += affichageCircuit->at( affichageCircuit->size() - 5 )->at(i - 1);
			str += affichageCircuit->at( affichageCircuit->size() - 5 )->at(i);
			str += affichageCircuit->at( affichageCircuit->size() - 5 )->at(i + 1);
			if(!cond && affichageCircuit->at( affichageCircuit->size() - 5 )->at(i + 2) != ' ') str += affichageCircuit->at( affichageCircuit->size() - 5 )->at(i + 2);
			if(cond)
				cond = false;
			else
				cond = true;

			liste.push_back(  str );
			i++;
		}
	}

	for(int i = 0 ; i < gates->size() ; i++ ) {
		bool add = true;
		for(int j = 0 ; j < gates->at(i)->getEntrees()->size() ; j++){
			bool found = false;
			for(int k = 0 ; k < liste.size() ; k++) {
				if( liste.at(k) == gates->at(i)->getEntrees()->at(j)->getName() ){
					found = true;
				}
			}
			if(!found)
				add = false;
		}

		if(add){
			liste2.push_back(gates->at(i));
		}
	}
	int d = 0;
	for( int i = 0 ; i < affichageCircuit->at( affichageCircuit->size() - 2 )->size() && d < liste2.size(); i++){
		if(  affichageCircuit->at( affichageCircuit->size() - 2 )->at(i) == '|' ){
			int diff = i - affichageCircuit->at( affichageCircuit->size() - 1 )->size();
			for(int j = 0 ; j < diff ; j++) {
				affichageCircuit->at( affichageCircuit->size() - 1 )->push_back( ' ' );
			}
			affichageCircuit->at( affichageCircuit->size() - 1 )->push_back(liste2.at(d)->getName().at(0));
			affichageCircuit->at( affichageCircuit->size() - 1 )->push_back(liste2.at(d)->getName().at(1));
			affichageCircuit->at( affichageCircuit->size() - 1 )->push_back(liste2.at(d)->getName().at(2));

			i+=2;
		}
	}

} // affiintchageNomsOperationsLogiques2()



Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates)
: inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >}, gates{gates}  {
	vector<string>* noms = affichageInputs();
	affichageChemins();
	affichageNomsOperationsLogiques(noms);// Afficher les noms des opérations logiques
	affichageCheminsApresOperationsLogiques();
	affichageAsterisques();
	affichageNomsOperationsLogiques2();
	affichageCheminsApresOperationsLogiques();
	affichageAsterisques();

}

Circuit::Circuit()
{

}

Circuit::~Circuit()
{
}


void Circuit::afficheCircuit() const {
	cout << "Affiche circuit" << endl;
	for(unsigned int i = 0 ; i < affichageCircuit->size() ; i++){
		for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
			cout << affichageCircuit->at(i)->at(j);
		}
		cout << endl;
	}
	cout << endl;

}
