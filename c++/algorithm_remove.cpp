#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
#include "print.h"
using namespace std;
//删除方法并不是真正的删除，只是将后面的元素向前移动覆盖掉之前的元素，所以容器中的元素空间的个数没变
void test_remove_method() {
	list<int> ilist;
	for(int i = 1; i <= 6; ++i)
	{
		ilist.push_front(i);
		ilist.push_back(i);
	}
	ilist.push_back(9);

	cout << "删除之前，";
	printListData(ilist.begin(),ilist.end());
	cout << "删除之后，";
	list<int>::iterator end = remove(ilist.begin(),ilist.end(),3);//逻辑删除
	printListData(ilist.begin(),ilist.end());
	cout << "\n总共删除了" << distance(end,ilist.end()) << "个3." << endl;

}
//彻底删除掉元素
void test_remove_complete() {
	vector<int> ivec;
	for(int i = 0;i < 6;i++)
		ivec.push_back(i);
	for(int i = 0;i < 6;i++)
		ivec.push_back(i);
	for(int i = 0;i < 6;i++)
		ivec.push_back(i);
	cout << "彻底删除掉5之前，";
	printVectorData(ivec.begin(),ivec.end());
	cout << "彻底删除掉5之后，";
	ivec.erase(remove(ivec.begin(),ivec.end(),5),ivec.end());
	printVectorData(ivec.begin(),ivec.end());
	cout << "彻底删除掉小于4的数之前，";
	printVectorData(ivec.begin(),ivec.end());
	cout << "彻底删除掉小于4的数之后，";
	ivec.erase(remove_if(ivec.begin(),ivec.end(),bind2nd(less<int>(),4)),ivec.end());
	printVectorData(ivec.begin(),ivec.end());
}
//测试remove_copy_if函数来删除并拷贝数值
void test_remove_copy_if_method() {
	vector<int> ivec;
	for(int i = 1;i < 22;i++)
		ivec.push_back(i);
	printVectorData(ivec.begin(),ivec.end());

	multiset<int> iset;
	remove_copy_if(ivec.begin(),ivec.end(),inserter(iset,iset.end()),bind2nd(less<int>(),4));
	cout << "删除掉小于4的数值之后：";
	for(multiset<int>::iterator iter = iset.begin();iter != iset.end();++iter)
		cout << *iter << ' ';
	cout << endl;
}
//删除连续重复的只保留一个数值
void test_unique_method() {
	int srcData[] = {1,2,3,3,3,5,5,6,6,6,6,6,6,8,8,8,8,8,8,8,8};
	list<int> srcList;
	copy(srcData,srcData + sizeof(srcData) / sizeof(srcData[0]),back_inserter(srcList));
	printListData(srcList.begin(),srcList.end());

	list<int>::iterator pos = unique(srcList.begin(),srcList.end());
	printListData(srcList.begin(),srcList.end());

	srcList.erase(pos,srcList.end());
	printListData(srcList.begin(),srcList.end());
}
//主函数
int main() {
	test_remove_method();
	cout << "--------------------------------" << endl;
	test_remove_complete();
	cout << "--------------------------------" << endl;
	test_remove_copy_if_method();
	cout << "--------------------------------" << endl;
	test_unique_method();
	return 0;
}
