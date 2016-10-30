#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> product(vector<int> list) {
	// Check for valid array
	assert(list.size() > 1);

	// Init
	vector<int> new_list(list.size(),1);
	new_list[1] = list[0];

	// Greedy Products
	for(int i = 2; i < list.size(); i++) {
		new_list[i] = new_list[i-1] * list[i-1];
	}
	for(int i = new_list.size() - 2; i >= 0; i--) {
		new_list[i] *= list[i+1];
		list[i] *= list[i+1];
	}

	return new_list;
}

void print(vector<int> array) {
	for(int i = 0; i < array.size(); i++) 
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	int a[] = {1, 7, 3, 4};
	vector<int> va(a, a + sizeof(a) / sizeof(int));
	print(va);
	print(product(va));
	return 0;
}
