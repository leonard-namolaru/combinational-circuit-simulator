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


Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates)
: inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >}, gates{gates}  {
	affichageInputs();


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
