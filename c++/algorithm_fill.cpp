#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "print.h"

using namespace std;

void test_fill_method() {
	list<int> ilist;
	ilist.push_back(1);
	ilist.push_back(2);
	ilist.push_back(3);
	cout << "填充之前，";
	printListData(ilist.begin(),ilist.end());
	fill(ilist.begin(),ilist.end(),5);
	cout << "填充之后，";
	printListData(ilist.begin(),ilist.end());
}

void test_fill_n_method() {
	list<int> ilist;
	fill_n(back_inserter(ilist),6,6);
	printListData(ilist.begin(),ilist.end());
}

void test_generate_n_method() {
	list<int> ilist;
	generate_n(back_inserter(ilist),6,rand);
	printListData(ilist.begin(),ilist.end());
}

int main(int argc,char **argv) {
	test_fill_method();
	cout << "--------------------------------" << endl;
	test_fill_n_method();
	cout << "--------------------------------" << endl;
	test_generate_n_method();
	return 0;
}
