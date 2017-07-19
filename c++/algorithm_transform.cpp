#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
void printVector(vector<int>::iterator begin,vector<int>::iterator end) {
	cout << "vector中数据为：";
	while(begin != end)
		cout << *begin++ << ' ';
	cout << endl;
}

void printList(list<int>::iterator begin,list<int>::iterator end) {
	cout << "list中数据为：";
	while(begin != end)
		cout << *begin++ << ' ';
	cout << endl;
}

void test_transform_method() {
	list<int> ilist;
	vector<int> ivec;

	for(int i = 1;i <= 9;++i)
		ilist.insert(ilist.end(),i);
	printList(ilist.begin(),ilist.end());
	//变换到自身
	transform(ilist.begin(),ilist.end(),ilist.begin(),negate<int>());
	printList(ilist.begin(),ilist.end());
	//变换到其他容器
	transform(ilist.begin(),ilist.end(),back_inserter(ivec),bind2nd(multiplies<int>(),10));
	printVector(ivec.begin(),ivec.end());

	ivec.clear();

	transform(ilist.begin(),ilist.end(),ilist.rbegin(),back_inserter(ivec),plus<int>());
	printVector(ivec.begin(),ivec.end());
}

void test_transform_method_by_func() {

}
int main() {
	test_transform_method();
	cout << "--------------------------------" << endl;
	test_transform_method_by_func();
	return 0;
}
