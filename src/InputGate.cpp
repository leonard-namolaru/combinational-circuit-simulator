/*
 * InputGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "InputGate.hpp"
#include "Outils.hpp"

/**
 * Constructeur.
 */
InputGate::InputGate(const char nomInputGate) : Gate{std::string(1,nomInputGate), false } {
	// Le nom dune entree (InputGate) ne peut etre que une lettre minuscule.
	try {
		if(nomInputGate < 'a' || nomInputGate > 'z')
			throw 1;
	} catch(int codeErreur) {
		cerr << Outils::getMessageErreurByCodeErreur(codeErreur) << endl;
		exit(EXIT_FAILURE);
	}
}

bool InputGate::getValeurBooleenne() {
	return valeurBooleenne;
}

void InputGate::setValeurBooleenne(bool valeurBool){
	valeurBooleenne = valeurBool;
}


InputGate::~InputGate()
{

}
