/*
 * XnorGate.hpp
 * Projet : Simulateur de circuit combinatoire - UE Langages à objets avancés 2021 - 2022
 * M1 : Master Informatique fondamentale et appliquée - Université de Paris.
 * @author AIT BENALI faycal, NAMOLARU leonard
 */
#ifndef XNORGATE
#define XNORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"
using namespace std;

class XnorGate : public Gate
{
public:
    XnorGate(Gate *g1, Gate *g2); // Constructeur.
    bool getValeurBooleenne() override;
    virtual ~XnorGate();
};

#endif
