/*
 * NorGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "NorGate.hpp"

/**
 * Constructeur.
 */
NorGate::NorGate(Gate *g1 , Gate *g2) : Gate{"NOR", false} {
	entrees->push_back(g1);
	entrees->push_back(g2);
}

bool NorGate::getValeurBooleenne() {
	valeurBooleenne = (!(this->getEntrees()->at(0)->getValeurBooleenne() || this->getEntrees()->at(1)->getValeurBooleenne()));
	return valeurBooleenne;
}

NorGate::~NorGate()
{

}
