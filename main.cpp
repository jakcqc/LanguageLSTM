#include "Windows.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;


struct Rule {
	char left;
	std::string right;
};


class Grammar {
public:
	unordered_map<char, vector<string>> rules;

	void add_rule(char lhs, vector<string> rhs) {
		rules[lhs] = rhs;
	}

	string generate(char symbol) {
		if (rules.find(symbol) == rules.end()) {
			return string(1, symbol);
		}
		vector<string> alternatives = rules[symbol];
		int i = rand() % alternatives.size();
		string result;
		for (char c : alternatives[i]) {
			result += generate(c);
		}
		return result;
	}
};

int main()
{
	
	Grammar grammar;
	std::vector<std::string> sentencesAll;
	grammar.add_rule('S', { "N","NN" });
	grammar.add_rule('G', { "varDDD", "nameDDD","myobjectDDD","somevarDDD" });
	grammar.add_rule('Z', {  });
	grammar.add_rule('N', { "object O V P ", "skylight O V L", "terrain O V P", "directionallight O V L" });
	grammar.add_rule('V', { "that has", "with", });
	grammar.add_rule('J', { "-" });
	grammar.add_rule('L', { "intensity DDD lux", "rotation RJRJRT", "L and L" });
	grammar.add_rule('T', { " to RJRJR", "" });
	grammar.add_rule('A', { " to D ", "" });
	grammar.add_rule('K', { " on OJ", " above OJ", " in OJ", "KK","KK"});
	grammar.add_rule('P', { "rotation RJRJRT ", "position X ","extent RJRJR ","material(s) OM ","overlap B ","visibility B ", "amount DDDD to DDDD ","class(s) OM ", "scale DA ", "Pand P","Pand P","Pand P","Pand P","Pand P","Pand P"  });
	grammar.add_rule('R', { "D","DD","DDD" });
	grammar.add_rule('X', { "RRR", "K"});
	grammar.add_rule('M', { "JO","MM","OJO", ""});
	grammar.add_rule('B', { "true","false", });
	grammar.add_rule('D', { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", });
	grammar.add_rule('O', { "YO","YYYY"});
	std::vector<std::string> tempRewrite;
	for (char c = 'a'; c <= 'z'; ++c) {
		tempRewrite.push_back(std::string(1,c));
	}
	grammar.add_rule('Y', tempRewrite);

	
	std::vector<std::string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++) {
		string sentence = grammar.generate('S');
		sentencesAll.push_back(sentence);
		cout << sentence << endl;

	}

	std::ofstream outfile("sentencesR.csv");
	if (outfile.is_open()) {
		for (const auto& sentence : sentencesAll) {
			outfile << sentence << ",";
		}
		outfile.close();
		std::cout << "Sentences exported to sentences.csv" << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing" << std::endl;
	}




	
	return 0;
}
