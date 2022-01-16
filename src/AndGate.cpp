/*
 * AndGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "AndGate.hpp"

/**
 * Constructeur.
 */
AndGate::AndGate(Gate *g1, Gate *g2) : Gate{"AND", false}
{
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
