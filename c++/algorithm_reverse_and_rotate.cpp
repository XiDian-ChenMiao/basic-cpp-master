#include <iostream>
#include <algorithm>
#include <vector>
#include "print.h"

using namespace std;

void test_reverse_method() {
	vector<int> ivec;
	for(int i = 0;i < 6;i++)
		ivec.push_back(i);
	cout << "逆转vector前，";
	printVectorData(ivec.begin(),ivec.end());
	reverse(ivec.begin(),ivec.end());
	cout << "逆转vector后，";
	printVectorData(ivec.begin(),ivec.end());
}

void test_rotate_method() {
	vector<int> ivec;
	for(int i = 0;i < 6;i++)
		ivec.push_back(i);
	cout << "旋转vector前，";
	printVectorData(ivec.begin(),ivec.end());
	rotate(ivec.begin(),ivec.begin() + 4,ivec.end());//向前平移一个单位长度
	cout << "旋转vector后，";
	printVectorData(ivec.begin(),ivec.end());
}

int main() {
	test_reverse_method();
	cout << "--------------------------------" << endl;
	test_rotate_method();
	return 0;
}
