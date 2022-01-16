/*
 * Gate.cpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#include "Gate.hpp"

/**
 * Constructeur 1.
 */
Gate::Gate(const string& nomGate, bool valeurBooleenne) : nomGate{nomGate}, entrees{new vector<Gate*>}, valeurBooleenne{valeurBooleenne}
{

}

/**
 * Constructeur 2.
 */
Gate::Gate(const string& nomGate) : nomGate{nomGate}, entrees{new vector<Gate*>}, valeurBooleenne{false}
{

}


vector<Gate*>* Gate::getEntrees() const{
	return entrees;
}

string Gate::getName() const {
	return nomGate;
}

bool Gate::getValeurBooleenne() {
	return valeurBooleenne;
}

Gate::~Gate()
{

}
