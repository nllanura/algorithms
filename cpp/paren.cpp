#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void print_pairs(int n) {
	//Base case
	if(n == 0) return;
	if(n == 1) cout << "()";
	
	//Store the parentheses
	vector<string> parens;
	parens.push_back("()");
	for(int i = 1; i < n; i++) {
		vector<string> new_parens;
		for(int j = 0; j < parens.size(); j++) {
			new_parens.push_back("()" + parens[j]);
			new_parens.push_back('(' + parens[j] + ')');
			new_parens.push_back(parens[j] + "()");
		}
		parens = new_parens;
	}

	//Remove duplicates
	unordered_set<string> unique;
	for(int i = 0; i < parens.size(); i++) {
		unique.insert(parens[i]);
	}
	unordered_set<string>::iterator begin;
	for(begin = unique.begin(); begin != unique.end(); begin++) {
		cout << *begin << " ";
	}
}

int main() {
	print_pairs(0);	
	cout << endl;
	print_pairs(1);	
	cout << endl;
	print_pairs(2);	
	cout << endl;
	print_pairs(3);	
	cout << endl;
	print_pairs(4);	
	cout << endl;

	return 0;
}
