#include <iostream>
#include <string>
using namespace std;
//对字符串函数的类型声明
typedef bool (*StringCompare)(const string &,const string &);
typedef std::string::size_type (*StringLength)(const string &,const string &);

/*常量指针做参数的加法函数*/
int add(const int *a,const int *b)
{
	return *a + *b;
}
/*通过指针打印数组函数*/
void printArrayByPointer(const int *array,size_t length)
{
	int i = 0;
	for(;i < length;++i)
		cout << "打印：" << *(array + i);
	cout << endl;
}
/*通过引用打印数组函数*/
void printArrayByRef(int (&array)[5])
{
	int i = 0;
	for(;i < 5;++i)
		cout << "打印：" << *(array + i);
	cout << endl;
}
/*打印多维数组函数*/
void printMultiArray(int (*multiArray)[2],const size_t rowSize)
{
	int row = 0,col = 0;
	for(;row < rowSize;++row)
	{
		for(;col < 2;++col)
			cout << multiArray[row][col] << '\t';
		cout << endl;
	}
}
/*
	A.为了保证与C语言兼容，C++将如下两个函数等同处理
	void print(int a){...}
	void print(const int a){...}
*/
/*交换函数*/
void swap(int *a,int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*非引用形参都是原变量的拷贝，而引用形参都是原变量*/
void swapByRef(int &a,int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}
/*交换两个指针*/
void swapByRefAndPointer(int *&a,int *&b)
{
	int *temp = a;
	a = b;
	b= temp;
}
/*打印字符串，C语言字符串为字符数组*/
void printChars(const char *charArray)
{
	while(*charArray != NULL)
		cout << *charArray++ << '\t';
	cout << endl;
}
/*返回常量引用，引用可做左值*/
const int& returnConstRef(const int &a)
{
	return a;
}
/*字符串长度比较函数*/
bool lengthCompare(const string &front,const string &tail)
{
	return front.size() == tail.size();
}
/*求两字符串总长度*/
string::size_type sumLength(const string &front,const string &tail)
{
	return front.size() + tail.size();
}
/*
	函数参数的类型必须与要返回的指向函数的指针要求的函数参数类型一致，并且返回值类型必须也一致。
*/
string::size_type (*strSumLength(const string &welcome))(const string &front,const string &tail)
{
	cout << "打印：" << welcome << endl;
	return sumLength;
}
/*采用类型定义*/
StringLength strSumLengthDef(const string &printStr)
{
	cout << "打印：" << printStr << endl;
	return sumLength;
}
/*主函数*/
int main()
{
	//函数指针的声明
	bool (*func_pointer)(const string &,const string &);
	func_pointer = &lengthCompare;
	func_pointer = lengthCompare;
	StringCompare cmpStrPtr = lengthCompare;//将函数指针初始化为字符串比较函数地址
	StringLength lenStrPtr = sumLength;
	cout << (*func_pointer)("Chen","Miao") << endl;
	cout << func_pointer("Chenm","MiaoMiao") << endl;
	cout << (*cmpStrPtr)("Daqinzhidi","ChenMiao") << endl;
	cout << lenStrPtr("Daqinzhidi","ChenMiao") << endl;
	cout << strSumLength("Hello C++")("Daqinzhidi","ChenMiao") << endl;
	cout << strSumLengthDef("My name is ChenMiao.")("Daqinzhidi","ChenMiao") << endl;
	/*
		可以用指向非常量的指针初始化指向常量的指针，但不能用指向非常量的指针去初始化指向非常量的指针。
	*/
	cout << "-------------------const知识点使用总结------------------------" << endl;
	double iVal = 123.35;
	const int &refVal = iVal;//若为常量引用，则引用类型可与被引用的类型不一致
	const int otherRef = iVal;//引用不是对象，只是被引用变量的别名
	const int &ref = 43;
	int a = 15;
	int b = 20;
	/*以常量指针作为参数的函数，传递形参时可以用常量指针也可以用非常量指针。*/
	const int m = 10;
	const int n = 10;
	cout << "a,b两数相加测试：" << add(&a,&b) << endl;
	cout << "m,n两数相加测试：" << add(&m,&n) << endl;
	swap(&a,&b);
	cout << "a,b两数交换测试：a = " << a << ",b = " << b << endl;
	swapByRef(a,b);
	cout << "a,b两数交换测试：a = " << a << ",b = " << b << endl;
	int *p = &a;
	int *q = &b;
	swapByRefAndPointer(p,q);
	cout << "a,b两数交换测试：a = " << a << ",b = " << b << endl;
	cout << "引用值为：" << refVal << otherRef << ",43的地址为：" << &ref << endl;

	cout << "----------------------数组打印函数测试-------------------------" << endl;
	int array[5] = {1,2,3,5,4};
	printArrayByPointer(array,5);
	printArrayByRef(array);
	//多维数组定义
	int multiArray[][2] = {
		{1,2},
		{2,3}
	};
	printMultiArray(multiArray,2);

	cout << "--------------标准字符串string类型知识点使用总结---------------" << endl;
	char welcome[] = "C++ is unbelievable.";
	printChars(welcome);
	string str("我是陈苗");
	cin >> str;
	std::getline(cin,str);//通过getline函数获取输入字符串
	cout << str << endl;
	return 0;
}
