/*
 * Gate.hpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#ifndef GATE
#define GATE

#include <vector>
#include <iostream>
class InputGate;
class OutputGate;

using namespace std;

class Gate
{
protected:
   string nomGate;
   vector<Gate*>* entrees;
   bool valeurBooleenne; // Valeur booléenne.
public:
    Gate(const string& nomGate, bool valeurBooleenne); // Constructeur 1.
    Gate(const string& nomGate); // Constructeur 2.
    virtual ~Gate();

    vector<Gate*>* getEntrees() const;
    string getName() const;
    virtual bool getValeurBooleenne();
};

#endif
