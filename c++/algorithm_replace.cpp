#include <iostream>
#include <algorithm>
#include <vector>
#include "print.h"
using namespace std;

void test_replace_method() {
	vector<int> ivec;
	for(int i = 1; i <= 9; ++i)
		ivec.push_back(i);
	for(int i = 5; i <= 9; ++i)
		ivec.push_back(i);
	cout << "替换之前，";
	printVectorData(ivec.begin(),ivec.end());
	replace(ivec.begin(),ivec.end(),8,6);
	cout << "替换之后，";
	printVectorData(ivec.begin(),ivec.end());
}

void test_replace_if_method() {
	vector<int> ivec;
	for(int i = 1; i <= 9; ++i)
		ivec.push_back(i);
	for(int i = 5; i <= 9; ++i)
		ivec.push_back(i);
	cout << "替换之前，";
	printVectorData(ivec.begin(),ivec.end());
	replace_if(ivec.begin(),ivec.end(),bind2nd(less<int>(),5),88);
	cout << "替换之后，";
	printVectorData(ivec.begin(),ivec.end());
}

int main(int argc,char **argv) {
	test_replace_method();
	cout << "--------------------------------" << endl;
	test_replace_if_method();
	return 0;
}
