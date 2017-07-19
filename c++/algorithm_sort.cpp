#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "print.h"
using namespace std;
//测试局部排序算法partial_sort
void test_partial_sort_method() {
	vector<int> ivec;

	for(int i = 0;i <= 9;++i)
		ivec.push_back(i);
	for(int i = 2;i <= 8;++i)
		ivec.push_back(i);
	cout << "排序前五个元素之前，";
	printVectorData(ivec.begin(),ivec.end());
	partial_sort(ivec.begin(),ivec.begin() + 5,ivec.end());
	cout << "排序前五个元素之后，";
	printVectorData(ivec.begin(),ivec.end());
}
//测试局部排序并拷贝的算法partial_sort_copy
void test_partial_sort_copy_method() {
	vector<int> ivec;
	deque<int> ideq(6);

	for(int i = 0;i <= 9;++i)
		ivec.push_back(i);
	for(int i = 2;i <= 8;++i)
		ivec.push_back(i);
	cout << "拷贝并排序元素之前，";
	printVectorData(ivec.begin(),ivec.end());
	partial_sort_copy(ivec.begin(),ivec.end(),ideq.begin(),ideq.end());
	cout << "拷贝并排序元素之后，";
	printDequeData(ideq.begin(),ideq.end());
}
//测试第n个元素排序的算法nth_element
void test_nth_element_method() {
	vector<int> ivec;

	for(int i = 0;i <= 9;++i)
		ivec.push_back(i);
	for(int i = 2;i <= 8;++i)
		ivec.push_back(i);
	cout << "排序前三个元素之前，";
	printVectorData(ivec.begin(),ivec.end());
	nth_element(ivec.begin(),ivec.begin() + 3,ivec.end());

	cout << "排序前三个元素之后，";
	printVectorData(ivec.begin(),ivec.end());
}
//测试堆排序算法
void test_heap_method() {
	vector<int> ivec;

	for(int i = 0;i <= 9;++i)
		ivec.push_back(i);
	for(int i = 2;i <= 8;++i)
		ivec.push_back(i);
	cout << "建堆操作之前，";
	printVectorData(ivec.begin(),ivec.end());
	//建堆操作
	make_heap(ivec.begin(),ivec.end());

	cout << "建堆操作之后，";
	printVectorData(ivec.begin(),ivec.end());

	pop_heap(ivec.begin(),ivec.end());//将最大的元素放在容器末尾
	ivec.pop_back();//删除掉最大元素
	cout << "删除掉最大元素之后，";
	printVectorData(ivec.begin(),ivec.end());

	ivec.push_back(17);
	cout << "添加17操作之后，";
	printVectorData(ivec.begin(),ivec.end());
	cout << "重新调整堆之后，";
	push_heap(ivec.begin(),ivec.end());
	printVectorData(ivec.begin(),ivec.end());
	//把堆排序变为普通排序
	sort_heap(ivec.begin(),ivec.end());
	cout << "堆排序操作之后，";
	printVectorData(ivec.begin(),ivec.end());
}
//主函数
int main(int argc,char **argv) {
	test_partial_sort_method();
	cout << "--------------------------------" << endl;
	test_partial_sort_copy_method();

	cout << "--------------------------------" << endl;
	test_nth_element_method();

	cout << "--------------------------------" << endl;
	test_heap_method();
	return 0;
}
