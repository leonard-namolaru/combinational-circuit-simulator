/*
 * OutputGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "OutputGate.hpp"
#include "Outils.hpp"

/**
 * Constructeur.
 */
OutputGate::OutputGate(const char nomOutputGate, Gate* g) : Gate{std::string(1,nomOutputGate), false}
{
	// Le nom dune sortie (OutputGate) ne peut etre que une lettre majuscule.
	try {
		if(nomOutputGate < 'A' || nomOutputGate > 'Z')
			throw 2;
	} catch(int codeErreur) {
		cerr << Outils::getMessageErreurByCodeErreur(codeErreur) << endl;
		exit(EXIT_FAILURE);
	}
	entrees->push_back(g);
}

bool OutputGate::getValeurBooleenne() {
	valeurBooleenne = this->getEntrees()->at(0)->getValeurBooleenne();
	return valeurBooleenne;
}

OutputGate::~OutputGate()
{

}
