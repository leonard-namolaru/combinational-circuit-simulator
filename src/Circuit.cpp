#include "Circuit.hpp"


void Circuit::affichageInputs(){
	// la debut de chqaue ligne pour un input ressemble à ceci (par exemple) : a:0 -- (6 caractères)
	const int NB_CHAR_AU_DEBUT_CHAQUE_LIGNE = 6; // Le nombre de caractères qui apparaissent toujours au début de chaque ligne d'un input

	for(unsigned int i = 0 ; i < inputs->size() ; i++) { // Nous parcourons le vecteur qui inclut les entrées (inputs)

		/*  Les étapes suivantes seront effectuées pour chacune des entrées du circuit   */

		/*  Étape (1) : La ligne commence par afficher le nom de l'entrée, sa valeur booléenne ainsi que quelques caractères supplémentaires pour l'affichage   */

		affichageCircuit->push_back( new vector<char> ) ; // Pour chaque entrée, nous ajoutons une nouvelle ligne à l'affichage

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

		/*  Étape (2)  Nous voulons dessiner une trajectoire de départ pour l'entrée, principalement en utilisant le caractère '_'.
		 * Dans l'itinéraire, nous ajouterons le caractère '*' en fonction du nombre de portes logiques qui reçoivent l'entrée actuelle en input.
		 * Le caractère '+' est en fait un point qui permet le passage pour d'autres entrées
		 */

		/** Combien de portes logiques reçoivent en entrée l'elemet i du vecteur inputs ? **/
		unsigned int counter = 0; // On stocke dans cette variable le nombre de portes logiques qui reçoivent l'input courant en entrée
		for(unsigned int g = 0 ; g < gates->size() ; g++){ // Nous parcourons le vecteur des portes logiques
			for(unsigned int j = 0 ; j < gates->at(g)->getEntrees()->size() ; j++){ // Pour chacune des portes logiques, nous parcourons son attribut de type vecteur qui comprend une liste de toutes les entrées de cette porte logique
				if( gates->at(g)->getEntrees()->at(j) ==  inputs->at(i) )
					counter++;
			}
		}

		// Maintenant, nous voulons ajouter le caractère '*' en fonction du nombre de portes logiques qui reçoivent ce input en entrée
		for(unsigned int g = 0 ; g < counter ; g++) { // La variable 'counter' : le nombre de portes logiques qui reçoivent l'input courant en entrée
	
			if (i == 0){ // Si c'est la première entrée du circuit
				affichageCircuit->at(i)->push_back( '*' ); // Ajout du caractère '*' à l'affichage
				if(g != counter - 1) // Si l'on s'attend à ajouter encore de caractères de type '*' (c'est-à-dire : si le nombre de caractères '*' ne correspond pas encore à la valeur stockée dans la variable 'counter'
					affichageCircuit->at(i)->push_back( '-' ); // Ajout du caractère '-' à l'affichage pour que ce caractère sépare les caractères de type '*'
			}else{ // <=> (i != 0) // Si ce n'est PAS la première entrée du circuit
				unsigned int longueurLignePrecedente = affichageCircuit->at(i-1)->size();
				unsigned int longueurLigneActuelle = affichageCircuit->at(i)->size();

				// Si nous n'avons pas dépassé la longueur de la ligne précédente, nous devons vérifier ce qui se passe dans la ligne précédente
				// Nous voulons ajouter '*'. Mais si la ligne ci-dessus contient à cette position '*' ou '+' ...
                while (( longueurLigneActuelle < longueurLignePrecedente ) && (affichageCircuit->at(i-1)->at(longueurLigneActuelle) == '*' || affichageCircuit->at(i-1)->at(longueurLigneActuelle) == '+')){
                	affichageCircuit->at(i)->push_back( '+' ); // Ajout du caractère '+' à l'affichage (un point qui permet le passage pour d'autres entrées)
					affichageCircuit->at(i)->push_back( '-' ); // Ajout du caractère '-' à l'affichage pour que ce caractère sépare les caractères de type '*' et de type '+'

					longueurLigneActuelle = affichageCircuit->at(i)->size(); // Nous avons ajouté des éléments dans le vecteur et nous devons donc mettre à jour la valeur stockée dans cette variable
                }

                // La boucle est utilisée car après avoir ajouté les caractères '+' et '-',
                // nous devons nous assurer que même dans le nouvel emplacement où nous voulons ajouter le caractère '*',
                // il n'y a pas au dessus un caractère de type '*' ou '+'

				affichageCircuit->at(i)->push_back( '*' ); // Ajout du caractère '*' à l'affichage
                if(g != counter - 1) // Si l'on s'attend à ajouter encore de caractères de type '*' (c'est-à-dire : si le nombre de caractères '*' ne correspond pas encore à la valeur stockée dans la variable 'counter'
						affichageCircuit->at(i)->push_back( '-' ); // Ajout du caractère '-' à l'affichage pour que ce caractère sépare les caractères de type '*'
			} // else
		} // for(g)
	} // for(i)


	/* Étape (3) : Nous voulons que toutes les lignes qui tracent le début du chemin des entrées aient la même longueur.
	 */

	// Nous recherchons en premier lieu la ligne la plus longue
	unsigned int maxSize = affichageCircuit->at(0)->size();
	for(unsigned int i = 1 ; i < affichageCircuit->size() ; i++) {
		if( affichageCircuit->at(i)->size() > maxSize)
			maxSize = affichageCircuit->at(i)->size();
	}

	// Une fois que nous avons localisé quelle est la longueur de le ligne la plus longue,
	// nous effectuons un ajustement du reste des lignes en fonction de cette longueur

	for(unsigned int i = 0 ; i < affichageCircuit->size() ; i++) { // Nous parcourons toutes les lignes de l'affichage du circuit (qui comprend actuellement une ligne pour chaque entrée)
		unsigned int longueurLigneActuelle = affichageCircuit->at(i)->size(); // La longueur de la ligne actuelle

			if( longueurLigneActuelle < maxSize){ // Si la longueur de ligne actuelle est inférieure à la longueur de ligne maximale
				char dernierElement = affichageCircuit->at(i)->at(longueurLigneActuelle - 1); // On stocke dans une variable la valeur du dernier caractère de la ligne courante
				affichageCircuit->at(i)->pop_back(); // Nous supprimons le dernier caractère de la ligne actuelle

				for(unsigned int j = 0; j < (maxSize - longueurLigneActuelle) + 2 ; j++) {

							// S'il s'agit de la première ligne alors nous n'avons pas besoin de prendre en compte ce qui se passe dans les lignes précédentes
					        // (verifier s'il faut ajouter le caractère '+') et nous ajoutons juste le caractère '-'
							if(i == 0) { // Si c'est la première entrée du circuit
								affichageCircuit->at(i)->push_back( '-' );
							}
							else {
								if(affichageCircuit->at(i - 1)->at(NB_CHAR_AU_DEBUT_CHAQUE_LIGNE + j - 1) == '*' || affichageCircuit->at(i - 1)->at(NB_CHAR_AU_DEBUT_CHAQUE_LIGNE + j - 1) == '+') // si la ligne ci-dessus contient à cette position '*'
									affichageCircuit->at(i)->push_back( '+' );
								else
									affichageCircuit->at(i)->push_back( '-' );
							}
							longueurLigneActuelle = affichageCircuit->at(i)->size(); // Nous avons ajouté des éléments dans le vecteur et nous devons donc mettre à jour la valeur stockée dans cette variable
				} // for(j)
				affichageCircuit->at(i)->push_back( dernierElement ); // Ajout de l'élément que nous avons supprimé de la fin de la ligne
			} // if( longueurLigneActuelle < maxSize)


			// Dans la boucle for précédente, certaines lignes sont devenues plus longues et,
			// par conséquent, la position de certains des caractères « * » a changé.
			// Par conséquent, nous testons pour chacun des caractères '+' s'il est toujours essentiel
			for(unsigned int j = 0; j < affichageCircuit->at(i)->size() ; j++) {
				if(i != 0) {
					if(affichageCircuit->at(i)->at(j) == '+' && j < affichageCircuit->at(i-1)->size()) {
						if(affichageCircuit->at(i - 1)->at(j) != '+' && affichageCircuit->at(i - 1)->at(j) != '*'){
							affichageCircuit->at(i)->erase( affichageCircuit->at(i)->begin() + j  );
							affichageCircuit->at(i)->erase( affichageCircuit->at(i)->begin() + (j - 1)  );
						}
					}
				}

			}

			for(unsigned int j = 0; j < affichageCircuit->at(i)->size() ; j++) {
				if(i != 0) {
					if(j < affichageCircuit->at(i-1)->size()) {
						if(affichageCircuit->at(i - 1)->at(j) == '+' || affichageCircuit->at(i - 1)->at(j) == '*'){
							affichageCircuit->at(i)->at(j) = '+';
						}
					}
				}

			}


			if(i != 0) {
				for(unsigned int j = 0; j < (affichageCircuit->at(i - 1)->size() - affichageCircuit->at(i)->size()) ; j++)
					affichageCircuit->at(i)->push_back( ' ' );
				affichageCircuit->at(i)->push_back( '|' );
			}


		} // for(i)
} // affichageInputs()

void Circuit::affichageChemins(){
	int nombreDeLignes = affichageCircuit->size(); // Le nombre de lignes maintenant stockées dans le vecteur qui représente l'affichage du circuit.
	affichageCircuit->push_back( new vector<char> ); // Ajouter une nouvelle ligne à l'affichage du circuit pour stocker des chemins (caractères '|')
	// Nous parcourons la dernière ligne de l'affichage (La dernière ligne avant la nouvelle ligne que nous venons d'ajouter)
	for(unsigned int j = 0 ; j < affichageCircuit->at(nombreDeLignes-1)->size() ; j++) {
		if(affichageCircuit->at(nombreDeLignes-1)->at(j) == '+' || affichageCircuit->at(nombreDeLignes-1)->at(j) == '*' || affichageCircuit->at(nombreDeLignes-1)->at(j) == '|') {
			// Nombre d'emplacements à ajouter à la nouvelle ligne
			unsigned int nombreEmplacementsAjouterNouvelleLigne = j - affichageCircuit->at(nombreDeLignes)->size();
			for(unsigned int k = 0 ; k < nombreEmplacementsAjouterNouvelleLigne ; k++)
				affichageCircuit->at(nombreDeLignes)->push_back( ' ' );
			affichageCircuit->at(nombreDeLignes)->push_back( '|' );
		} // if
	} // for

	bool cond = true;
	for(unsigned int i = 0 ; i < affichageCircuit->at(nombreDeLignes)->size() -1 ; i++){
		if( affichageCircuit->at(nombreDeLignes)->at(i) == '|' && affichageCircuit->at(nombreDeLignes)->at(i) == affichageCircuit->at(nombreDeLignes)->at(i+1) ){
			if(cond){
				affichageCircuit->at(nombreDeLignes)->at(i) = ' ';
				affichageCircuit->at(nombreDeLignes)->at(i + 1) = '|';
				cond = false;
			} else {
				affichageCircuit->at(nombreDeLignes)->at(i) = '|';
				affichageCircuit->at(nombreDeLignes)->at(i + 1) = ' ';
				cond = true;
			}
		}
	}
} // affichageChemins()


void Circuit::affichageNomsOperationsLogiques(){
	affichageCircuit->push_back( new vector<char> ) ; // Ajouter une  ligne à l'affichage du circuit
	unsigned int affichageCircuitSize = affichageCircuit->size();
	vector<int> emplacements;
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		emplacements.clear();
		for(unsigned int j = 0 ; j < affichageCircuit->at(i)->size() ; j++){
			if( affichageCircuit->at(i)->at(j) ==  '*' )
				emplacements.push_back(j);
		} // for(j)

		unsigned int e = 0;
		bool found = false;
		for(unsigned int g = 0 ; g < gates->size() ; g++){
			found = false;
			for(unsigned int j = 0 ; (j < gates->at(g)->getEntrees()->size()) && (found == false) ; j++){

				if( gates->at(g)->getEntrees()->at(j) ==  inputs->at(i) ) {

					for(unsigned int d = 0 ; d < emplacements.size() ; d++) {
						if(emplacements.at(d) < affichageCircuit->at(affichageCircuitSize - 1)->size()){
							if (!(affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(d)) <= 'A' && affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(d)) >= 'Z') && affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(d)) != '_'){
								found = true;
							}
						}
					}

					if(found == true)
						continue;
					int nombreEmplacementsAjouterNouvelleLigne; // Nombre d'emplacements à ajouter à la nouvelle ligne
					if(e < emplacements.size()) {
						if(emplacements.at(e) > affichageCircuit->at(affichageCircuitSize - 1)->size()){
							nombreEmplacementsAjouterNouvelleLigne = emplacements.at(e) - affichageCircuit->at(affichageCircuitSize - 1)->size();

							for(int k = 0 ; k < nombreEmplacementsAjouterNouvelleLigne ; k++)
									affichageCircuit->at(affichageCircuitSize - 1)->push_back( ' ' );

							affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(0) );
							affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(1) );
							affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(2) );
						}
						else {
							if ((affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e)) <= 'A' && affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e)) >= 'Z') && affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e)) != '_'){
								affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e)) = gates->at(i)->getName().at(0);
								affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e) + 1) = gates->at(i)->getName().at(1);
								affichageCircuit->at(affichageCircuitSize - 1)->at(emplacements.at(e) + 2) = gates->at(i)->getName().at(2);
							}
						}
					}
					else {
						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(0) );
						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(1) );
						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(2) );
					}

					e++;
				} // if
			} // for(j)
		} // for(g)
	} // for(i)
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
	affichageInputs();
	affichageChemins();
	affichageNomsOperationsLogiques();// Afficher les noms des opérations logiques
	affichageCheminsApresOperationsLogiques();
	affichageAsterisques();
	affichageChemins();
	affichageNomsOperationsLogiques2();
	affichageCheminsApresOperationsLogiques();


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
