#include "Circuit.hpp"


void Circuit::affichageInputs(){
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		affichageCircuit->push_back( new vector<char> ) ;
		affichageCircuit->at(i)->push_back( inputs->at(i)->getInputName() );
		affichageCircuit->at(i)->push_back( ':' );
		affichageCircuit->at(i)->push_back(  to_string( inputs->at(i)->getValEnBinaire() ).at(0) );
		affichageCircuit->at(i)->push_back( ' ' );

		unsigned int counter = 0;
		for(unsigned int j = 0 ; j < gates->size() ; j++){
			if( gates->at(i)->getEntrees()->at(i) ==  inputs->at(i) )
				counter++;
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
		for(unsigned int j = 0 ; j < gates->size() ; j++){
			if( gates->at(i)->getEntrees()->at(j) ==  inputs->at(i)) {
					unsigned int nombreEmplacementsAjouterNouvelleLigne; // Nombre d'emplacements à ajouter à la nouvelle ligne
					if(e < emplacements.size())
						nombreEmplacementsAjouterNouvelleLigne = emplacements.at(e) - affichageCircuit->at(affichageCircuitSize - 1)->size();
					else
						nombreEmplacementsAjouterNouvelleLigne = 0;

					for(unsigned int k = 0 ; k < 5 ; k++)
							affichageCircuit->at(affichageCircuitSize - 1)->push_back( ' ' );

						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(0) );
						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(1) );
						affichageCircuit->at(affichageCircuitSize - 1)->push_back( gates->at(i)->getName().at(2) );
						e++;
			} // if
		} // fot(j)

	} // for(i)
} // affichageNomsOperationsLogiques()



Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates)
: inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >}, gates{gates}  {
	affichageInputs();
	affichageChemins();
	 affichageNomsOperationsLogiques();// Afficher les noms des opérations logiques


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
