//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {

	//freopen("input1.txt", "r", stdin);
	string s;
	getline(cin, s);

	vector<string> words;
	stringstream ss(s);
	string word;
	while (ss >> word) 
		words.push_back(word);

	cout << words.size() << '\n';
}