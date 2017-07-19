#include <iostream>
#include <algorithm>
#include <vector>
#include "print.h"

using namespace std;
//求排列组合时先得对数据进行排序
void test_next_permutation_method() {
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(3);
	printVectorData(ivec.begin(),ivec.end());
	while(next_permutation(ivec.begin(),ivec.end()))
	{
		printVectorData(ivec.begin(),ivec.end());
	}
}

void test_random_shuffle_method () {
	vector<int> ivec;
	for(int i = 0; i <= 9;++i)
		ivec.push_back(i);
	printVectorData(ivec.begin(),ivec.end());

	random_shuffle(ivec.begin(),ivec.end());

	printVectorData(ivec.begin(),ivec.end());

	vector<int>::iterator middle;
	cout << "测试不稳定的分区算法，";
	middle = partition(ivec.begin(),ivec.end(),not1(bind2nd(modulus<int>(),2)));

	printVectorData(ivec.begin(),ivec.end());
	cout << "中间位置为：" << distance(ivec.begin(),middle) + 1 << endl;

	cout << "测试稳定的分区算法，";
	middle = stable_partition(ivec.begin(),ivec.end(),bind2nd(greater<int>(),3));

	printVectorData(ivec.begin(),ivec.end());
	cout << "中间位置为：" << distance(ivec.begin(),middle) + 1 << endl;
}

int main() {
	test_next_permutation_method();
	cout << "--------------------------------" << endl;
	test_random_shuffle_method();
	return 0;
}
