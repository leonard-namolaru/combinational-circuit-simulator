/*
 * AndGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages � objets avanc�s 2021 - 2022
 * M1 : Master Informatique fondamentale et appliqu�e - Universit� de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "AndGate.hpp"
#include "CircuitException.hpp"

/**
 * Constructeur.
 */
AndGate::AndGate(Gate *g1, Gate *g2) : Gate{"AND", false}
{
	// La longueur du nom d'une entr�e qui est aussi une entr�e du circuit est d'un caract�re,
	// la longueur du nom d'une entr�e qui est une porte logique est de 3 caract�res.
	try {
		if(g1->getName().size() != g2->getName().size())
			throw CircuitException("Une porte logique peut avoir comme entr�es deux entr�es du circuit ou deux entr�es qui sont des portes logiques. Mais il n'est pas possible de transf�rer une entr�e du premier type et une seconde entr�e du second type.");
	} catch(const CircuitException& circuitException) {
	cerr << circuitException.getMessage() << endl;
	exit(EXIT_FAILURE);
	}

    entrees->push_back(g1);
	entrees->push_back(g2);
}

bool AndGate::getValeurBooleenne() {
	valeurBooleenne = (this->getEntrees()->at(0)->getValeurBooleenne() && this->getEntrees()->at(1)->getValeurBooleenne());
	return valeurBooleenne;
}

AndGate::~AndGate()
{

}
