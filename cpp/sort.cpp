#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> rand_array(int size);
void mergesort(vector<int> &array);
void mergesort(vector<int> &array, int low, int high);
void merge(vector<int> &array, int low, int middle, int high);
void quicksort(vector<int> &array);
void quicksort(vector<int> &array, int left, int right);
int partition(vector<int> &array, int left, int right);
void swap(vector<int> &array, int a, int b);
int binary_search(vector<int> &array, int value);

vector<int> rand_array(int size) {
	vector<int> new_array;
	srand(time(NULL));
	for(unsigned int i = 0; i < size; i++) {
		new_array.push_back(rand() % 1000);
	}
	return new_array;
}

void print(vector<int> array) {
	for(unsigned int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void mergesort(vector<int> &array) {
	mergesort(array, 0, array.size() - 1);
}

void mergesort(vector<int> &array, int low, int high) {
	if(low < high) {
		int middle = low + ((high - low) / 2);
		mergesort(array, low, middle);
		mergesort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

void merge(vector<int> &array, int low, int middle, int high) {
	vector<int> helper(array.size(), 0);
	int helper_left = low;
	int helper_right = middle + 1;
	int current = low;

	while(helper_left <= middle && helper_right <= high) {
		if(array[helper_left] <= array[helper_right]) {
			helper[current++] = array[helper_left++];
		} else {
			helper[current++] = array[helper_right++];
		}
	}

	while(helper_left <= middle) helper[current++] = array[helper_left++];
	while(helper_right <= high) helper[current++] = array[helper_right++];
	for(int i = low; i < current; i++) array[i] = helper[i];
}

void quicksort(vector<int> &array) {
	quicksort(array, 0, array.size() - 1);
}

void quicksort(vector<int> &array, int left, int right) {
	if(array.empty()) return;
	int i = left, j = right;
	int pivot = array[left + ((right - left) / 2)];

	while(i <= j) {
		while(array[i] < pivot) i++;
		while(array[j] > pivot) j--;
		if(i <= j) swap(array, i++, j--);
	}

	if(left < j) quicksort(array, left, j);
	if(i < right) quicksort(array, i, right);
}

void swap(vector<int> &array, int a, int b) {
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

int binary_search(vector<int> &array, int value) {
	if(array.empty()) return -1;
	int left = 0, 
	    middle = array.size() / 2, 
	    right = array.size() - 1;
	
	while(left <= right) {
		if(value < array[middle]) {
			right = middle - 1;
		} else if(value > array[middle]) {
			left = middle + 1;
		} else {
			return middle;
		}
		middle = left + ((right - left) / 2);
	}
	return -1;
}

int main() {
	int a[] = {1, 8, 7, 29, 19,
		   58, 2, 49, 41, 12,
		   12, 15, 43, 92, 0,
		   71, 48, 29, 19, 4};
	int b[] = {0};
	int c[] = {};
	int d[] = {1, 3, 2, 4};

	vector<int> v_a (a, a + sizeof(a) / sizeof(int)),
		    v_b (b, b + sizeof(b) / sizeof(int)),
		    v_c (c, c + sizeof(c) / sizeof(int)), 
		    v_d (d, d + sizeof(d) / sizeof(int));

	print(v_a);
	print(v_b);
	print(v_c);
	print(v_d);

/*
	mergesort(v_a);
	mergesort(v_b);
	mergesort(v_c);
	mergesort(v_d);
*/

	quicksort(v_a);
	quicksort(v_b);
	quicksort(v_c);
	quicksort(v_d);

	print(v_a);
	print(v_b);
	print(v_c);
	print(v_d);
/*

	cout << v_a[binary_search(v_a, 29)] << endl;
	cout << v_b[binary_search(v_b, 3)] << endl;
	cout << v_c[binary_search(v_c, 5)] << endl;
*/

	return 0;
}
