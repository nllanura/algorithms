#include <iostream>
#include <vector>
using namespace std;

#define MAX(a,b) a > b ? a : b

// Recursive solution. Requires O(n) time and O(n) additional space.
int masseuse_r(vector<int> times, vector<int> &memo, int index) {
	if(index == times.size()) return 0;
	if(index == times.size() - 1) return times[index];
	if(index == times.size() - 2) return MAX(times[index], times[index+1]);
	memo[index] = MAX(times[index] + masseuse_r(times, memo, index+2), masseuse_r(times, memo, index+1));
	return memo[index];
}

// Iterative solution. Requires O(n) time and O(1) additional space.
int masseuse_i(vector<int> times) {
	if(times.empty()) return 0;
	if(times.size() == 1) return times[0];
	if(times.size() == 2) return MAX(times[0], times[1]);
	int max = times[0];
	for(int i = 2; i < times.size(); i++) {
		times[i] += max;
		max = MAX(max, times[i-1]);
	}
	return MAX(times[times.size()-1],times[times.size()-2]);
}

int main() {
	int times[] = {75, 15, 60, 60, 30, 45, 105, 90};
	//int times[] = {30, 15, 60, 75, 45, 15, 15, 45};
	//int times[] = {30, 15, 60, 45};
	//int times[] = {};
	//int times[] = {49};
	//int times[] = {49, 93};
	vector<int> time_vec(times, times + sizeof(times) / sizeof(int));
	vector<int> memo(time_vec.size(), 0);
	cout << masseuse_r(time_vec, memo, 0) << endl;
	cout << masseuse_i(time_vec) << endl;
	return 0;
}
