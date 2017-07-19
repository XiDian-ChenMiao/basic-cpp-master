#include <iostream>
#include <string>
#include <new>/*new头文件中有bad_alloc异常类*/
#include "link_queue.h"
#include "array.h"
using namespace std;
/*
	模板包括函数模板和类模板。
*/
int main()
{
	cout << "----------------使用链式队列模板-----------------" << endl;
	Queue<int> queue;
	queue.enqueue(15);
	queue.enqueue(20);
	cout << "出队前，队列中元素为：";
	queue.displayAllElements();
	cout << "出队：" << queue.dequeue() << endl;
	cout << "出队后，队列中元素为：";
	queue.displayAllElements();
	cout << endl;
	cout << "----------------使用数组模板-----------------" << endl;
	Array<int> array(10);
	try{
		array[5] = 10;
		cout << array[5] << endl;
		array[10] = 20;
	}catch(string e){
		cout << e.c_str() << endl;
	}
	return 0;
}
