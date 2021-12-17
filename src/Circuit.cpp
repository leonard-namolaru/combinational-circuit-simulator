#include "Circuit.hpp"

Circuit::Circuit(vector<InputGate*>* inputsCircuit, vector<Gate*>* gates)
: inputs{inputsCircuit}, affichageCircuit{new vector< vector<char>* >}, gates{gates}  {

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


        int nbetoiles=0;
		for(int k = 5 ; nbetoiles!=counter ; k+=5) {
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
			affichageCircuit->at(i)->push_back( '-' );
	
			if (i==0){
            affichageCircuit->at(i)->push_back( '*' );
			nbetoiles++;
			}else{
				cout << k << ";" << k+4 << endl;
				if(k+4 < affichageCircuit->at(i-1)->size()){

                        if (affichageCircuit->at(i-1)->at(k+4)=='*' || affichageCircuit->at(i-1)->at(k+4)=='+' ){
						  affichageCircuit->at(i)->push_back( '+' );

					    }else{

							  affichageCircuit->at(i)->push_back( '*' );
							  nbetoiles++;
						}


					 }else{

                       affichageCircuit->at(i)->push_back( '*' );
					   nbetoiles++;

					 }
					   
				
                      
                     
					
				
			}
			
			

		}
	}

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
