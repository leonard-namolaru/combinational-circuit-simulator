/*
 * OrGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "OrGate.hpp"

/**
 * Constructeur.
 */
OrGate::OrGate(Gate *g1 , Gate *g2) : Gate{"OR_", false} { // Le nom d'une porte logique comportera toujours 3 caractères.
	entrees->push_back(g1);
	entrees->push_back(g2);
}

bool OrGate::getValeurBooleenne() {
	valeurBooleenne = (this->getEntrees()->at(0)->getValeurBooleenne() || this->getEntrees()->at(1)->getValeurBooleenne());
	return valeurBooleenne;
}

OrGate::~OrGate()
{

}
