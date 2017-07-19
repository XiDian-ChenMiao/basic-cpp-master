#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
/*
	STL算法：区间的比较
		A.equal方法：两区间内数据是否全部相等比较
		B.mismatch方法:第一个不相等的数据
		C.lexicographical_compare方法
*/
void printListData(list<int>::iterator begin,list<int>::iterator end) {
	while(begin != end)
		cout << *begin++ << ' ';
}
/*测试equal方法*/
void test_equal_method(){
	list<int> allList,searchList;
	for(int i = 1; i <= 9; ++i)
		allList.insert(allList.end(),i);

	for(int i = 1; i <= 9; ++i)
		searchList.insert(searchList.end(),i);

	cout << "元素链表为：";
	printListData(allList.begin(),allList.end());

	cout << "\n待查链表为：";
	printListData(searchList.begin(),searchList.end());

	if(equal(allList.begin(),allList.end(),searchList.begin()))
		cout << "\n待查区间与元素区间相等" << endl;
}
/*测试mismatch方法*/
void test_mismatch_method(){

}
/*测试lexicographical_compare方法*/
void test_lexicographical_compare_method(){

}
/*主函数*/
int main(){
	test_equal_method();
	return 0;
}
