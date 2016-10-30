#include <iostream>

using namespace std;

string trim(string word) {
	int count = 0;
	for(int i = 0; i < word.size(); i++) {
		if(word[i] != ' ') {
			word[count++] = word[i];
		}
	}
	return word.substr(0, count);
}

int main() {
	cout << trim("a  p pl e") << endl;
	return 0;
}
