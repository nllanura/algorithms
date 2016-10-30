#include <iostream>
#include <vector>

using namespace std;

class Hash_Entry {
	int key;
	int value;
public:
	Hash_Entry(int key, int value) {
		this->key = key;
		this->value = value;
	}

	int get_key() {
		return this->key;
	}

	int get_value() {
		return this->value;
	}
};

const int TABLE_SIZE = 128;

class Hash_Table {
	vector<Hash_Entry*> table;
public:
	Hash_Table() {
		vector<Hash_Entry*> new_table(TABLE_SIZE, NULL);
		table = new_table;
	}
	
	void put(int key, int value) {
		int hash = key % TABLE_SIZE;
		while(table[hash] != NULL && table[hash]->get_key() != key) {
			hash = (hash + 1) % TABLE_SIZE;
		}
		if(table[hash] != NULL) {
			delete table[hash];
		}
		table[hash] = new Hash_Entry(key, value);
	}

	int get(int key) {
		int hash = key % TABLE_SIZE;
		while(table[hash] != NULL && table[hash]->get_key() != key) {
			hash = (hash + 1) % TABLE_SIZE;
		}
		if(table[hash] == NULL) {
			return -1;
		}
		return table[hash]->get_value();
	}

	~Hash_Table() {
		for(unsigned int i = 0; i < table.size(); i++) {
			if(table[i] != NULL) {
				delete table[i];
			}
		}
	}
};

int main() {
	Hash_Table table;
	table.put(3, 5);
	table.put(8, 20);
	table.put(136, 30);
	cout << table.get(8) << endl;
	cout << table.get(136) << endl;
	return 0;
}
