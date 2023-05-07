
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
std::string apply_rules(std::string inSentences);
string apply_rules(string sentence) {
    unordered_map<string, string> replacements = {
        {"rotation", "rotaion:"},
        {"scale", "scale:"},
        {"materials", "material:["},
        {"terrain", "terrain:{"}
    };

    for (auto& [word, replacement] : replacements) {
        size_t pos = 0;
        while ((pos = sentence.find(word, pos)) != string::npos) {
            sentence.replace(pos, word.length(), replacement);
            pos += replacement.length();
        }
    }

    return sentence;
}
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
	int amountT = 10;
	Grammar grammar;
	std::vector<std::string> sentencesAll;
	grammar.add_rule('S', { "N", "Nas well as N" });
	grammar.add_rule('G', { "varDDD", "nameDDD","myobjectDDD","somevarDDD" });
	grammar.add_rule('Z', {  });
	grammar.add_rule('N', { "object O with P ", "skylight O with L", "terrain O with P", "directionallight O with L" });
	grammar.add_rule('V', { "that has", "with", });
	grammar.add_rule('J', { "-" });
	grammar.add_rule('L', { "intensity DDD lux ", "rotation RJRJRT ", "Land L" });
	grammar.add_rule('T', { " to RJRJR", "" });
	grammar.add_rule('A', { " to D ", "" });
	grammar.add_rule('K', { "on O", "above O", "in O", "K-K","K-K"});
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
	
	std::srand(2);
	for (int i = 0; i < amountT; i++) {
		string sentence = grammar.generate('S');
		sentencesAll.push_back(sentence);
		cout << sentence << endl;

	}
		
	Grammar grammarJson;	
	std::vector<std::string> sentencesJson;
	grammarJson.add_rule('S', { "N}", "N }--\\nN" });
	grammarJson.add_rule('G', { "varDDD", "nameDDD","myobjectDDD","somevarDDD" });
	grammarJson.add_rule('Z', {  });
	grammarJson.add_rule('N', { "object:{ \\nO:{\\nP ", "skylight:{\\nO:{\\nL", "terrain:{\\nO:{\\nP", "directional_light:{\\nO:{\\nL" });
	grammarJson.add_rule('V', { "that has", "with", });
	grammarJson.add_rule('J', { "-" });
	grammarJson.add_rule('L', { "intensity: DDD", "rotation: RJRJRT", "L--\\nL}" });
	grammarJson.add_rule('T', { " ] -- [RJRJR", "" });
	grammarJson.add_rule('A', { " -- D ", "" });
	grammarJson.add_rule('K', { "\\non: O", "\\nabove: O", "\\nin: O", "K--K","K--K"});
	grammarJson.add_rule('P', { "rotation:[RJRJRT] ", "position:{ X }","extent:[ RJRJR] ","material(s):[ OM] ","overlap: B ","visibility: B ", "amount:[ DDDD]-- [DDDD] ","class(s):[ OM ]", "scale: [DA] ", "P--\\nP","P--\\nP","P--\\nP","P--\\nP","P--\\n P","P--/nP"  });
	grammarJson.add_rule('R', { "D","DD","DDD" });
	grammarJson.add_rule('X', { "RRR", "K"});
	grammarJson.add_rule('M', { "JO","MM","OJO", ""});
	grammarJson.add_rule('B', { "true","false", });
	grammarJson.add_rule('D', { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", });
	grammarJson.add_rule('O', { "YO","YYYY"});
std::vector<std::string> tempRewrite2;
	for (char c = 'a'; c <= 'z'; ++c) {
		tempRewrite2.push_back(std::string(1,c));
	}
	grammarJson.add_rule('Y', tempRewrite2);
	std::srand(2);
	for (int i = 0; i < amountT; i++) {
		string sentence = grammarJson.generate('S');
		sentencesJson.push_back(sentence);
		cout << sentence << endl;

	}

int cont = 0;
	// std::ofstream outfile("sentences.csv");
	// if (outfile.is_open()) {
	// 	outfile << "input" << ",target"<<std::endl;
	// 	for (const auto& sentence : sentencesAll) {
	// 		outfile << sentence << ","<<sentencesJson[cont]<<std::endl;
	// 		cont++;
	// 	}
	// 	outfile.close();
	// 	std::cout << "Sentences exported to sentences.csv" << std::endl;
	// }
	// else {
	// 	std::cerr << "Error opening file for writing" << std::endl;
	// }
std::ofstream outfile("sentences.csv");
	if (outfile.is_open()) {
		outfile << "input"<<std::endl;
		for (const auto& sentence : sentencesAll) {
			outfile << sentence << " "<<sentencesJson[cont]<<std::endl;
			cont++;
		}
		outfile.close();
		std::cout << "Sentences exported to sentences.csv" << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing" << std::endl;
	}



	
	return 0;
}
