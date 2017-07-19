#include <iostream>
using namespace std;
int main(){
	int i = 1;
	int &r = i;//定义i的引用r
	const int &p = i;//p绑定i，但是不允许通过p来修改i的值
	r = 0;
	cout << "常量引用的值为：" << p << endl;
	return 0;
}
