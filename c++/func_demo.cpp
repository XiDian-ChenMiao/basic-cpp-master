#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*函数对象*/
struct FuncObj
{
	//重载函数调用符
	int operator()(int value) {return value > 0 ? value : -value;}
};
/*自定义函数对象模板，与class一样struct可以增加属性保存状态*/
template<typename TYPE> struct DisplayElement
{
	int callCounter;
	DisplayElement() : callCounter(0) {}
	void operator()(const TYPE &value) {
		++callCounter;
		cout << value << '\t';
	}
};
template<typename TYPE> struct JustifyCanMultiple
{
	TYPE multi;//除数
	JustifyCanMultiple(const TYPE &_multi) : multi(_multi) {}
	bool operator()(const TYPE &element) const {
		return element % multi == 0;
	}
};
/*
	转换运算符必须注意：
		A.必须是成员函数；
		B.不能指定返回类型；
		C.形参表必须是空的；
		D.必须显式的返回一个指定类型的值；
		E.不应该改变被转换对象，通常定义为const
*/
template<typename TYPE> class Dog
{
private:
	TYPE age;
public:
	Dog(const TYPE &_age) : age(_age) {}
	/*转换运算符*/
	operator TYPE() const {return age;}
};
int main()
{
	FuncObj funcObj;
	cout << funcObj(-23) << endl;

	vector<int> vec;
	for(int i = 0;i < 10;++i)
		vec.push_back(i);
	//利用STL库中提供的函数进行输出打印
	DisplayElement<int> result;
	JustifyCanMultiple<int> canMulti(2);

	result = for_each(vec.begin(),vec.end(),result);
	vector<int>::iterator iter = find_if(vec.begin(),vec.end(),canMulti);

	cout << "函数被调用了：" << result.callCounter << "次。" << endl;
	cout << "向量中第一个能被2整除的数为：" << *iter << endl;

	Dog<int> dog(15);
	int age = dog;
	cout << "狗的年龄是：" << age << endl;
	return 0;
}
