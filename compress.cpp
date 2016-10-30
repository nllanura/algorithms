#include <iostream>
using namespace std;

string compress(string word) {
	// Check final size
	if(word.empty()) return word;
	int count = 1;
	char current = word[0];
	for(int i = 1; i < word.size(); i++) {
		if(current != word[i]) {
			count++;
			current = word[i];
		}
	}
	int size = 2 * count;
	if(size >= word.size()) return word;

	// Compress
	int curr_index = 1;
	current = word[0];
	count = 1;
	for(int i = 1; i < word.size(); i++) {
		if(current == word[i]) {
			count++;
		} else {
			char new_char = word[i];
			word[curr_index++] = '0' + count;
			word[curr_index++] = new_char;
			current = word[i];
			count = 1;
		}
	}

	return word.substr(0, size);
}

int main() {
	cout << compress("aabcccccaaa") << endl;
	return 0;
}
