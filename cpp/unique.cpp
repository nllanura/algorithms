#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Node {
public:
	int count;
	int index;

	Node(int count, int index)
	:count(count), index(index)
	{}
};

char unique(string word) {
	unordered_map<char,Node> table;
	// Lower case everything
	transform(word.begin(),word.end(),word.begin(),::tolower);

	// Hash chars and update counts
	for(int i = 0; i < word.size(); i++) {
		if(table.find(word[i]) == table.end()) {
			Node temp_node(0,i);
			table.insert(pair<char,Node>(word[i],temp_node));
		} else {
			table.find(word[i])->second.count++;
		}
	}

	// Find first unique char
	int min_index = -1;
	unordered_map<char,Node>::iterator it;
	for(it = table.begin(); it != table.end(); it++) {
		if(it->second.count == 0 && (min_index < 0 || it->second.index < min_index)) {
			min_index = it->second.index;
		}
	}

	return word[min_index];
}

int main() {
	cout << unique("Allanccnee") << endl;
	return 0;
}
