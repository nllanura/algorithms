#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int> &array, int left, int right) {
	//if(left < 0 || left > right || right > array.size() - 1) return;
	int mid = left + ((right - left) / 2);
	for(int i = 0; i <= mid - left; i++) {
		int temp = array[left + i];
		array[left + i] = array[right - i];
		array[right - i] = temp;
	}
}

void merge(vector<int> &A, vector<int> &B) {
	int a_end = A.size() - B.size() - 1,
	    b_start = 0,
	    current = A.size() - 1;

	reverse(A, 0, a_end);

	while(a_end >= 0 && b_start < B.size()) {
		if(A[a_end] <= B[b_start]) {
			A[current] = A[a_end];
			a_end--;
		} else {
			A[current] = B[b_start];
			b_start++;
		}
		current--;
	}

	if(a_end > 0) {
		for(; a_end > 0; a_end--, current--) {
			A[current] = A[a_end];
		}
	}

	if(b_start < B.size()) {
		for(; b_start < B.size(); b_start++, current--) {
			A[current] = B[b_start];
		}
	}
	reverse(A, 0, A.size() - 1);
}

void print(vector<int> &array) {
	for(int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
}

int main() {

	int a[] = {1, 4, 7, 9, 14, 0, 0, 0, 0};
	int b[] = {0, 3, 4, 10};
	vector<int> v_a(a, a + sizeof(a) / sizeof(int));
	vector<int> v_b(b, b + sizeof(b) / sizeof(int));

	print(v_a);
	print(v_b);
	merge(v_a, v_b);
	print(v_a);

	return 0;
}
