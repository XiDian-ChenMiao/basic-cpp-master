#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
#include <vector>
/*
	在已排好序容器中的查找算法测试程序
		A.binary_search()
		B.includes()

		C.lower_bound() --|
		D.upper_bound() --|(在关联式容器中存在类似的成员函数，查找效果更佳)
		E.equal_range() --|
*/
using namespace std;

/*二分查找算法测试*/
void test_binary_search_method() {
	deque<int> ideq;
	for(int i = 0; i <= 9; ++i)
		ideq.insert(ideq.end(),i);

	cout << "deque中元素为：";
	for(deque<int>::iterator iter = ideq.begin(); iter != ideq.end(); ++iter)
		cout << *iter << ' ';
	if(binary_search(ideq.begin(),ideq.end(),5))
		cout << "\n在容器中有5这个元素" << endl;
	else
		cout << "\n在容器中没有5这个元素" << endl;
}
/*测试includes方法*/
void test_includes_method() {
	vector<int> ivec;
	for(int i = 0; i <= 8; ++i)
		ivec.push_back(i);
	cout << "vector中元素为：";
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << ' ';
	int searchedArray[] = {1,3,7};
	if(includes(ivec.begin(),ivec.end(),searchedArray,searchedArray + 3))
		cout << "\n在容器中出现了待查找元素" << endl;
	else
		cout << "\n在容器中未出现待查找元素" << endl;
}
/*测试lower_bound方法*/
void test_lower_bound_method() {
	list<int> ilist;
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	ilist.sort();
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << ' ';
	list<int>::iterator first_pos = lower_bound(ilist.begin(),ilist.end(),5);
	if(first_pos != ilist.end())
		cout << "第一个5出现的位置为：" << distance(ilist.begin(),first_pos) + 1 << endl;
	ilist.insert(first_pos,5);
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << ' ';
}
/*测试upper_bound（返回查找元素的下一个位置）方法*/
void test_upper_bound_method() {
	list<int> ilist;
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	ilist.sort();
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << ' ';
	list<int>::iterator first_pos = upper_bound(ilist.begin(),ilist.end(),5);
	if(first_pos != ilist.end())
		cout << "最后一个5出现的位置为：" << distance(ilist.begin(),first_pos) << endl;
}
/*测试equal_range（返回pair类型的lower_bound和upper_bound共同的结果）方法*/
void test_equal_range_method() {
	list<int> ilist;
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	for(int i = 0; i <= 8; ++i)
		ilist.insert(ilist.end(),i);
	ilist.sort();
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << ' ';
	pair<list<int>::iterator,list<int>::iterator> resultPair = equal_range(ilist.begin(),ilist.end(),5);
	cout << "第一个5出现的位置为：" << distance(ilist.begin(),resultPair.first) + 1<< endl;
	cout << "最后一个5出现的位置为：" << distance(ilist.begin(),resultPair.second) + 1<< endl;
}
/*主函数*/
int main(){
	test_equal_range_method();
	return 0;
}
