#include "Windows.h"
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;
long moveTo(long x, long oldP, int xy, long oldPy, long newPY);
void doStuff();

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
		//int i = rand() % 8;
		string result;
		for (char c : alternatives[i]) {
			result += generate(c);
		}
		return result;
	}
};

int main()
{
	int amountT = 2000;
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
	grammar.add_rule('K', { "on O", "above O", "in O" });
	//grammar.add_rule('P', { "rotation RJRJRT ", "position X ","extent RJRJR ","material(s) OM ","overlap B ","visibility B ", "amount DDDD to DDDD ","class(s) OM ", "scale D to D ", "Pand P","Pand P","Pand P","Pand P","Pand P","Pand P" });
	grammar.add_rule('P', { "rotation RJRJRT ", "position X ","extent RJRJR ","material(s) OM ","overlap B ","visibility B ", "amount DDDD to DDDD ","class(s) OM ", "scale D to D "});

	grammar.add_rule('R', { "D","DD","DDD" });
	grammar.add_rule('X', { "RRR", "K" });
	grammar.add_rule('M', { "JO","MM","OJO", "" });
	grammar.add_rule('B', { "true","false", });
	grammar.add_rule('D', { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", });
	grammar.add_rule('O', { "YO","YYYY" });
	std::vector<std::string> tempRewrite;
	for (char c = 'a'; c <= 'z'; ++c) {
		tempRewrite.push_back(std::string(1, c));
	}
	grammar.add_rule('Y', tempRewrite);


	std::vector<std::string> digits = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	std::srand(2);
	for (int i = 0; i < 0; i++) {
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
	grammarJson.add_rule('K', { "\\non: O", "\\nabove: O", "\\nin: O"});
	//grammarJson.add_rule('P', { "rotation:[RJRJRT] ", "position:{ X }","extent:[ RJRJR] ","material(s):[ OM] ","overlap: B ","visibility: B ", "amount:[ DDDD]-- [DDDD] ","class(s):[ OM ]", "scale: [D -- D] ", "P--\\nP","P--\\nP","P--\\nP","P--\\nP","P--\\n P","P--/nP" });
	grammarJson.add_rule('P', { "rotation:[ RJRJRT ] ", "position:{ X }","extent:[ RJRJR ] ","material(s):[ OM ] ","overlap: B ","visibility: B ", "amount:[ DDDD ]-- [ DDDD ] ","class(s):[ OM ]", "scale: [D -- D]" });

	grammarJson.add_rule('R', { "D","DD","DDD" });
	grammarJson.add_rule('X', { "RRR", "K" });
	grammarJson.add_rule('M', { "JO","MM","OJO", "" });
	grammarJson.add_rule('B', { "true","false", });
	grammarJson.add_rule('D', { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", });
	grammarJson.add_rule('O', { "YO","YYYY" });
	

	std::vector<std::string> tempRewrite2;
	for (char c = 'a'; c <= 'z'; ++c) {
		tempRewrite2.push_back(std::string(1, c));
	}
	grammarJson.add_rule('Y', tempRewrite2);
	std::srand(2);
	/*for (int i = 0; i < amountT; i++) {
		string sentence = grammarJson.generate('S');
		sentencesJson.push_back(sentence);
		cout << sentence << endl;

	}*/


	std::srand(2);
	std::vector<std::string> sentencesPOnly;

	for (int i = 0; i < amountT; i++) {
		string sentence = grammar.generate('P');
		sentencesPOnly.push_back(sentence);
		cout << sentence << endl;

	}
	std::vector<std::string> sentencesPOnlyJson;
	std::srand(2);
	for (int i = 0; i < amountT; i++) {
		string sentence = grammarJson.generate('P');
		sentencesPOnlyJson.push_back(sentence);
		cout << sentence << endl;

	}


	int cont = 0;
	std::ofstream outfile("sentenceSingle.csv");
	if (outfile.is_open()) {
		outfile << "input" << ",target" << std::endl;
		for (const auto& sentence : sentencesPOnly) {
			if (cont < (amountT / 2)) {
				outfile << sentence << "," << sentencesPOnlyJson[cont] << std::endl;
				cont++;
			}
		}
		outfile.close();
		std::cout << "Sentences exported to sentences.csv" << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing" << std::endl;
	}
	cont = 0;
	std::ofstream outfile2("sentenceTest.csv");
	if (outfile2.is_open()) {
		outfile2 << "input" << ",target" << std::endl;
		for (const auto& sentence : sentencesPOnly) {
			if (cont >= (amountT / 2)) {
				outfile2 << sentence << "," << sentencesPOnlyJson[cont] << std::endl;
				cont++;
			}
		}
		outfile2.close();
		std::cout << "Sentences exported to sentences.csv" << std::endl;
	}
	else {
		std::cerr << "Error opening file for writing" << std::endl;
	}
	// std::ofstream outfile("sentences.csv");
	// 	if (outfile.is_open()) {
	// 		outfile << "input"<<std::endl;
	// 		for (const auto& sentence : sentencesAll) {
	// 			outfile << sentence << " "<<sentencesJson[cont]<<std::endl;
	// 			cont++;
	// 		}
	// 		outfile.close();
	// 		std::cout << "Sentences exported to sentences.csv" << std::endl;
	// 	}
	// 	else {
	// 		std::cerr << "Error opening file for writing" << std::endl;
	// 	}




	return 0;
}
long moveTo(long newP, long oldP, int xy, long oldPy, long newPY)
{
	INPUT Inputs[1] = { 0 };

	double x0 = oldP, y0 = oldPy;
	double x1 = newP, y1 = newPY;
	// do linear interpolation in n steps
	const int randerSteps = rand() % 1500 + 5;
	
	for (int i = 0; i <= randerSteps; ++i) {
		double t = (double)i / randerSteps;
		double xT = (1.0 - t) * x0 + t * x1;
		double yT = (1.0 - t) * y0 + t * y1;
		std::cout << i << ":\tt: " << t << ",\tx: " << xT << ",\ty: " << yT << '\n';
	}











	int randerNegPos = rand() % 250;
	int goer = 0;
	while (randerNegPos != 0 && goer != 0) {

		int randerSign = rand() % 2;
		if ((randerSign == 0 && randerNegPos != 0) || newP < 0)
		{
			randerSign = -1;
		}
		long randerX = rand() % 100 + 1;
		randerX = randerX / rand() % 11 + 1;
		randerX = randerX * randerSign;

		oldP = oldP + randerX;
		
		if (xy == 0) {
			Inputs[0].mi.dx = oldP; // desired X coordinate
			Inputs[0].mi.dy = (oldP + rand() % 103 + 2) / rand() % 11 + 1;
		}
		else{
			Inputs[0].mi.dy = oldP; // desired Y coordinate
			Inputs[0].mi.dx = (oldP + rand() % 100 + 2)/rand()%10 + 1;
		}
		
		//Inputs[0].mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
		Inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE;
		SendInput(1, Inputs, sizeof(INPUT));
		Sleep((rand() % 1000 + 2) / (rand() % 50 + 1) + rand()% 11);
		randerNegPos--;
	}
	return 1;
}

void doStuff()
{
	int howMuch[2000] = { 0 };


	INPUT Inputs[3] = { 0 };
	POINT p;
	GetCursorPos(&p);

	Inputs[0].type = INPUT_MOUSE;
	long x = moveTo(50, p.x, 0, p.y, 50);
	long y = 10;
	Inputs[0].mi.dx = 0; // desired X coordinate
	Inputs[0].mi.dy = 0; // desired Y coordinate
	//Inputs[0].mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
	Inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE;

	for (auto& how_much : howMuch)
	{



		Inputs[1].type = INPUT_MOUSE;
		Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		Sleep((rand() % 101 + 2) / (rand() % 5 + 1));
		Inputs[2].type = INPUT_MOUSE;
		Inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP;

		Sleep((rand() % 1200 + rand() % 141 + 4) / (rand() % 10 + 1));
		Sleep((rand() % 263 + rand() % 5000 + 4) / (rand() % 100 + 1));
		Sleep((rand() % 132 + rand() % 66 + 4) / (rand() % 5 + 1));

		SendInput(2, Inputs, sizeof(INPUT));
		Sleep((rand() % 504 + rand() % 141 + 4) / (rand() % 10 + 1));
		Sleep((rand() % 1500 + rand() % 51 + 4) / (rand() % 100 + 1));
		Sleep((rand() % 1030 + rand() % 201 + 4) / (rand() % 1000 + 1));


		SendInput(2, Inputs, sizeof(INPUT));
		Sleep((rand() % 1000 + rand() % 141 + 4) / (rand() % 10 + 1));
		Sleep((rand() % 500 + rand() % 51 + 4) / (rand() % 100 + 1));
		Sleep((rand() % 100 + rand() % 201 + 4) / (rand() % 1000 + 1));
		Inputs[1].type = INPUT_MOUSE;
		Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
		Inputs[0].type = INPUT_MOUSE;
		Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;


		SendInput(3, Inputs, sizeof(INPUT));
	}
}

void makeSentence()
{
}
