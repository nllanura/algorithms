#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Min_Heap {
	int capacity;
	int size;
	vector<int> items;

	int get_left_child_index(int parent_index) { return parent_index * 2 + 1; }
	int get_right_child_index(int parent_index) { return parent_index * 2 + 2; }
	int get_parent_index(int parent_index) { return (parent_index - 1) / 2; }

	bool has_left_child(int parent_index) { return get_left_child_index(parent_index) < size; }
	bool has_right_child(int parent_index) { return get_right_child_index(parent_index) < size; }
	bool has_parent(int parent_index) { return get_parent_index(parent_index) >= 0; }

	int left_child(int parent_index) { return items[get_left_child_index(parent_index)]; }
	int right_child(int parent_index) { return items[get_right_child_index(parent_index)]; }
	int parent(int parent_index) { return items[get_parent_index(parent_index)]; }

	void swap(int parent_1, int parent_2) {
		int temp = items[parent_1];
		items[parent_1] = items[parent_2];
		items[parent_2] = temp;
	}

	void ensure_extra_cap() {
		if(size == capacity) {
			for(unsigned int i = 0; i < capacity; ++i) items.push_back(0);
			capacity *= 2;
		}
	}

	void heapify_up() {
		int index = size - 1;
		while(has_parent(index) && parent(index) > items[index]) {
			swap(get_parent_index(index), index);
			index = get_parent_index(index);
		}
	}

	void heapify_down() {
		int index = 0;
		while(has_left_child(index)) {
			int small_child_index = get_left_child_index(index);
			if(has_right_child(index) && right_child(index) < left_child(index)) {
				small_child_index = get_right_child_index(index);
			}
			if(items[index] < items[small_child_index]) {
				return;
			} else {
				swap(index, small_child_index);
			}
			index = small_child_index;
		}
	}

public:
	Min_Heap()
	:capacity(10), size(0)	{
		vector<int> items(capacity, 0);
		this->items = items;
	}

	int peek() {
		try {
			if(size == 0) throw 0;
		} catch(...) {
			cout << "Illegal Access\n";
			exit(EXIT_FAILURE);
		}
		return items[0];
	}

	int poll() {
		try {
			if(size == 0) throw 0;
		} catch(...) {
			cout << "Illegal Access\n";
			exit(EXIT_FAILURE);
		}
		int item = items[0];
		items[0] = items[--size];
		heapify_down();
		return item;
	}

	void add(int item) {
		ensure_extra_cap();
		items[size++] = item;
		heapify_up();
	}
};

int main() {
	Min_Heap heap;
	heap.add(8);
	heap.add(4);
	heap.add(23);
	heap.add(3);
	heap.add(12);
	heap.add(94);
	heap.add(45);
	heap.add(0);
	heap.add(-10);
	heap.add(73);
	heap.add(-23);
	heap.add(-85);

	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;

	heap.add(8);
	heap.add(4);
	heap.add(23);
	heap.add(3);
	heap.add(12);
	heap.add(94);
	heap.add(45);
	heap.add(0);
	heap.add(-10);
	heap.add(73);
	heap.add(-23);
	heap.add(-85);

	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;
	cout << heap.poll() << endl;



	return 0;
}
