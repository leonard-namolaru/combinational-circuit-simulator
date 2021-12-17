#include "Circuit.hpp"


void Circuit::affichageInputs(){
	for(unsigned int i = 0 ; i < inputs->size() ; i++) {
		affichageCircuit->push_back( new vector<char> ) ;
		affichageCircuit->at(i)->push_back( inputs->at(i)->getInputName() );
		affichageCircuit->at(i)->push_back( ' ' );
		affichageCircuit->at(i)->push_back( ':' );
		affichageCircuit->at(i)->push_back( ' ' );
		affichageCircuit->at(i)->push_back(  to_string( inputs->at(i)->getValEnBinaire() ).at(0) );

		int counter = 0;
		for(unsigned int j = 0 ; j < gates->size() ; j++){
			if( gates->at(i)->getEntrees()->at(i) ==  inputs->at(i) )
				counter++;
		}

        int nbEtoiles=0;
		for(unsigned int k = 5 ; nbEtoiles!=counter ; k+=5) {
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
	
			if (i == 0){
				affichageCircuit->at(i)->push_back( '*' );
				nbEtoiles++;
			}else{
				if(k+4 < affichageCircuit->at(i-1)->size()){
                        if (affichageCircuit->at(i-1)->at(k+4)=='*' || affichageCircuit->at(i-1)->at(k+4)=='+' ){
						  affichageCircuit->at(i)->push_back( '+' );
					    }else{
							  affichageCircuit->at(i)->push_back( '*' );
							  nbEtoiles++;
						} // else
				}else{
                       affichageCircuit->at(i)->push_back( '*' );
					   nbEtoiles++;
				} // else
			} // else
		} // for(k)
	} // for(i)
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
