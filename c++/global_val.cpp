#include <iostream>
#include <cstdlib>
using namespace std;
int result = 100;
int main(){
	cout << "全局变量：" << result << endl;
	int result = 99;
	cout << "局部变量：" << result << endl;
	cout << "全局变量：" << ::result << "，地址为：" << *(&result) << endl;

	int ival = 1024;
	int *p1 = &ival;
	int **p2 = &p1;
	cout << "ival的值为：" << ival << endl;
	cout << "指针p1的值为：" << *p1 << endl;
	cout << "指针p2的值为：" << **p2 << endl;
	return 0;
}
