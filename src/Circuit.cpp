#include "Circuit.hpp"


void Circuit::affichageInputs(){
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		affichageCircuit->push_back( new vector<char> ) ;
		affichageCircuit->at(i)->push_back( inputs->at(i)->getInputName() );
		affichageCircuit->at(i)->push_back( ':' );
		affichageCircuit->at(i)->push_back(  to_string( inputs->at(i)->getValEnBinaire() ).at(0) );
		affichageCircuit->at(i)->push_back( ' ' );

		unsigned int counter = 0;
		for(unsigned int g = 0 ; g < gates->size() ; g++){
			for(unsigned int j = 0 ; j < gates->at(g)->getEntrees()->size() ; j++){
				if( gates->at(g)->getEntrees()->at(j) ==  inputs->at(i) )
					counter++;
			}
		}

		affichageCircuit->at(i)->push_back( '-' );
		affichageCircuit->at(i)->push_back( '-' );

		for(unsigned int k = 0 ; k < counter ; k++) {
	
			if (i == 0){
				affichageCircuit->at(i)->push_back( '*' );
				if(k != counter - 1)
					affichageCircuit->at(i)->push_back( '-' );
			}else{ // <=> (i != 0)
				if( k+6 < affichageCircuit->at(i-1)->size() ){
                        if (affichageCircuit->at(i-1)->at(k+6) == '*' || affichageCircuit->at(i-1)->at(k+6) == '+'){
						  affichageCircuit->at(i)->push_back( '+' );
						  affichageCircuit->at(i)->push_back( '-' );
	                      affichageCircuit->at(i)->push_back( '*' );
							if(k != counter - 1)
								affichageCircuit->at(i)->push_back( '-' );

					    }else{
							  affichageCircuit->at(i)->push_back( '*' );
						} // else
				}else{
                       affichageCircuit->at(i)->push_back( '*' );
				} // else
			} // else
		} // for(k)
	} // for(i)

	unsigned int indexMaxSize = 0 , maxSize = affichageCircuit->at(0)->size();
	for(unsigned int i = 1 ; i < affichageCircuit->size() ; i++) {
		if( affichageCircuit->at(i)->size() > maxSize) {
			maxSize = affichageCircuit->at(i)->size();
			indexMaxSize= i;
		}
	}

	for(unsigned int i = 0 ; i < affichageCircuit->size() ; i++) {
		unsigned int sizeI = affichageCircuit->at(i)->size();
		if( sizeI < maxSize) {
			if( i < indexMaxSize){
				affichageCircuit->at(i)->pop_back();
				for(unsigned int j = 0; j < (maxSize - sizeI) + 2 ; j++)
					affichageCircuit->at(i)->push_back( '-' );
				affichageCircuit->at(i)->push_back( '*' );

				if(i != affichageCircuit->size() - 1) {
					for(unsigned int j = 0; j < (affichageCircuit->at(i)->size() - affichageCircuit->at(i+1)->size()) ; j++)
						affichageCircuit->at(i +1)->push_back( ' ' );
					affichageCircuit->at(i +1)->push_back( '|' );
				}

			}
		}

	}

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
