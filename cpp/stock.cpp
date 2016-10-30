#include <iostream>
#include <vector>
using namespace std;

int profit(vector<int> list) {
	if(list.empty()) return 0;
	int min_index = 0;
	int profit = -list[0];
	for(int i = 1; i < list.size(); i++) {
		if(list[i] >= list[min_index]) {
			int temp_profit = list[i] - list[min_index];
			if(profit < temp_profit) {
				profit = temp_profit;
			}
		} else {
			min_index = i;
		}
	}
	if(profit < 0) {
		int min_1 = list[0];
		int min_2 = list[1];
		profit = min_2 - min_1;
		for(int i = 2; i < list.size(); i++) {
			min_1 = min_2;	
			min_2 = list[i];
			if((min_2 - min_1) > profit) {
				profit = min_2 - min_1;
			}
		}
	}
	return profit;
}

int main() {
	int stock_arr1[] = {10, 7, 5, 8, 11, 9};
	int stock_arr2[] = {8, 10, 2, 4, 9};
	int stock_arr3[] = {20, 15, 8, 6, 2};
	int stock_arr4[] = {20, 20, 20, 20};
	vector<int> stocks1(stock_arr1, stock_arr1 + sizeof(stock_arr1) / sizeof(int));
	vector<int> stocks2(stock_arr2, stock_arr2 + sizeof(stock_arr2) / sizeof(int));
	vector<int> stocks3(stock_arr3, stock_arr3 + sizeof(stock_arr3) / sizeof(int));
	vector<int> stocks4(stock_arr4, stock_arr4 + sizeof(stock_arr4) / sizeof(int));

	cout << profit(stocks1) << endl << profit(stocks2) << endl << profit(stocks3) << endl << profit(stocks4) << endl;
	return 0;
}
