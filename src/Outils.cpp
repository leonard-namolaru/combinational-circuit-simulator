#include "Outils.hpp"
#include "Gate.hpp"
#include "XorGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include <map>

/**
 * vector<string>* Outils::StringTokenizer(string str, string delim) : Diviser une chaîne en jetons.
 * Le string de l'argument delim est le délimiteur pour séparer les jetons. Le string délimiteur lui-même n'est pas traités comme un jeton.
 * La fonction renvoie un pointeur vers un vecteur avec tous les jetons.
 */
vector<string>* Outils::StringTokenizer(string str, string delim) {
	const size_t NOT_FOUND = -1;
	vector<string>* tokens = new vector<string>;

	unsigned int indexDelim = str.find(delim);
	while (indexDelim != NOT_FOUND) {
		string nextToken = str.substr(0, indexDelim);
		str = str.substr(indexDelim + 1);

		tokens->push_back(nextToken);
		indexDelim = str.find(delim);
	}

	tokens->push_back(str);

	return tokens;
}

/**
 * vector<string>* Outils::StringVectorTokenizer(vector<string>* strVecteur, string delim)
 * Diviser toutes les chaînes stockées dans un vecteur de chaînes en jetons.
 * La fonction renvoie un pointeur vers un vecteur avec tous les jetons.
 */
vector<string>* Outils::StringVectorTokenizer(vector<string>* strVecteur, string delim) {
	const size_t NOT_FOUND = -1;
	vector<string>* tokens = new vector<string>;
	unsigned int indexDelim;

	for(unsigned int i = 0 ; i < strVecteur->size() ; i++) {
		indexDelim = strVecteur->at(i).find(delim);
		while (indexDelim != NOT_FOUND) {
			string nextToken = strVecteur->at(i).substr(0, indexDelim);
			strVecteur->at(i) = strVecteur->at(i).substr(indexDelim + 1);

			if (nextToken.size() != 0)
				tokens->push_back(nextToken);
			indexDelim = strVecteur->at(i).find(delim);
		}
		if (strVecteur->at(i).size() != 0)
			tokens->push_back(strVecteur->at(i));
	}

	return tokens;
}

/**
 * Gate* Outils::getPorteLogiqueByName(const string& name, Gate* input1, Gate* input2)
 */
Gate* Outils::getPorteLogiqueByName(const string& name, Gate* input1, Gate* input2) {
	Gate* gate = nullptr;
	map<string, int> mapOfGates = {
	        {"xor",1},
			{"XOR",1},
			{"OR",2},
			{"OR_",2},
	        {"or",2},
	        {"or_",2},
			{"AND",3},
	        {"and",3}
	};

	if(mapOfGates.count(name) == 0)
		return nullptr;

	switch(mapOfGates.at(name)) {
		case 1:
				gate = new XorGate(input1, input2);
				break;
		case 2:
				gate = new OrGate(input1, input2);
				break;
		case 3:
				gate = new AndGate(input1, input2);
				break;

	} // switch

	return gate;
}

string Outils::gateToStringWithGatesNames(Gate* gate) {
	string str = gate->getName();

	if(gate->getEntrees()->size() > 0)  {
		str.append("(");
		str.append( gateToStringWithGatesNames(gate->getEntrees()->at(0)) );
	}

	if(gate->getEntrees()->size() > 1)  {
		str.append( "," );
		str.append( gateToStringWithGatesNames(gate->getEntrees()->at(1)) );
	}

	if(gate->getEntrees()->size() > 0)  {
		str.append(")");

	}

   return str;
}


/**
 * string Outils::getMessageErreurByCodeErreur(int codeErreur)
 */
string Outils::getMessageErreurByCodeErreur(int codeErreur) {

	switch(codeErreur) {
		case 1 : return "Le nom dune entree (InputGate) ne peut etre que une lettre minuscule. Une tentative a apparemment ete faite pour utiliser un autre caractere a cette fin.";
			     break;
		case 2 : return "Le nom dune sortie (OutputGate) ne peut etre que une lettre majuscule. Une tentative a apparemment ete faite pour utiliser un autre caractere a cette fin.";
			     break;
		default : return "Une erreur s'est produite mais malheureusement le système n'est pas en mesure de fournir une description plus détaillée";
	}

	return "";

}
