#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include "print.h"
using namespace std;


void test_swap_ranges_method() {
	vector<int> ivec;
	deque<int> ideq;

	for(int i = 1; i <= 9; ++i)
		ivec.push_back(i);
	cout << "交换前数据为：" << endl;

	printVectorData(ivec.begin(),ivec.end());

	for(int i = 11; i <= 23; ++i)
		ideq.push_back(i);

	printDequeData(ideq.begin(),ideq.end());

	cout << "交换后数据为：" << endl;
	deque<int>::iterator pos;//如果到了ideq.end()表明数据已经交换，如果不等于则没交换。返回值为交换以后后面没有交换的第一个数

	pos = swap_ranges(ivec.begin(),ivec.end(),ideq.begin());
	printVectorData(ivec.begin(),ivec.end());
	printDequeData(ideq.begin(),ideq.end());
}

int main() {
	test_swap_ranges_method();

	return 0;
}
