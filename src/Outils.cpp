#include "Outils.hpp"
#include "Gate.hpp"
#include "XorGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include <map>

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

Gate* Outils::getPorteLogiqueByName(const string& name, Gate* input1, Gate* input2) {
	Gate* gate = nullptr;
	map<string, int> mapOfGates = {
	        {"xor",1},
			{"XOR",1},
			{"OR",2},
	        {"or",2},
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
