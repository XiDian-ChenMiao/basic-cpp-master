#include <iostream>
#include <cassert>
/*
	使用预处理器进行调试
	1.预处理指令
		#ifndef NDEBUG
			cerr << ... << endl;
		#endif
	2.附加选项：/DNDEBUG
	3.预定义变量
		__FILE__：文件名
		__LINE__：行数
		__TIME__：时间
		__DATE__：日期
	4.assert断言
*/
using namespace std;
int main()
{
#ifndef NDEBUG
	cout << "文件名为：" << __FILE__ << endl;
#endif
	//assert(1 == 2);//断言的使用
	cout << "当前行数为：" << __LINE__ << endl;
	cout << "当前时间为：" << __TIME__ << endl;
	cout << "当前日期为：" << __DATE__ << endl;
	return 0;
}
