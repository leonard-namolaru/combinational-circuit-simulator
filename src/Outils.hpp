#ifndef OUTILS
#define OUTILS

#include <iostream>
#include <vector>
#include "Gate.hpp"

using namespace std;

class Outils {
public:
	static vector<string>* StringTokenizer(string str, string delim);
	static vector<string>* StringVectorTokenizer(vector<string>* strVecteur, string delim);
	static Gate* getPorteLogiqueByName(const string& name, Gate* input1, Gate* input2);
	static string gateToStringWithGatesNames(Gate* gate);
};

#endif /* OUTILS */
