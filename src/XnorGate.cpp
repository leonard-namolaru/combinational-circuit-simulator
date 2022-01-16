/*
 * XnorGate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "XnorGate.hpp"

/**
 * Constructeur.
 */
XnorGate::XnorGate(Gate *g1, Gate *g2) : Gate{"XNO", false}{ // Le nom d'une porte logique comportera toujours 3 caractères.
    entrees->push_back(g1);
	entrees->push_back(g2);
}

bool XnorGate::getValeurBooleenne() {
	valeurBooleenne = (!(this->getEntrees()->at(0)->getValeurBooleenne() ^ this->getEntrees()->at(1)->getValeurBooleenne()));
	return valeurBooleenne;
}

XnorGate::~XnorGate()
{

}
