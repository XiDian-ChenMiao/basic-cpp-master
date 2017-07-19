#include <iostream>
using namespace std;
/*
	三种继承方式public,protected,private主要是将对应的属性放置在按照继承方式放置的位置上。
	继承之后，如果想改变属性修饰符，则可以使用using关键字。如using ClassName::属性名称；

	其中public继承方式称为接口继承，其余两种private和protected继承方式称为实现继承；

	在C++中，struct和class的用法一致，两者可以相互替换；
	class默认的继承方式为：private，属性默认为private
	struct默认的继承方式为：public，而且属性默认为public

	从派生类转换为基类是自动的，但是从基类转换为派生类需要强制转换。
	有派生类到基类的转换方式有两种：引用转换（指针转换）和对象转换，如果要用多态特性，就不能采用对象转换的方式；

	在派生类中访问static成员的方法：
		A.基类名::成员名
		B.子类名::成员名
		C.对象.成员名
		D.指针->成员名
		E.成员名
	如果在一个类中出现了虚函数，则相应的其析构函数也要设置为virtual
*/
class BaseA
{
public:
	BaseA(){cout << "调用BaseA的构造函数." << endl;}
	~BaseA(){cout << "调用BaseA的析构函数." << endl;}
};
class BaseB
{
public:
	BaseB(){cout << "调用BaseB的构造函数." << endl;}
	~BaseB(){cout << "调用BaseB的析构函数." << endl;}
};
class Derived : public BaseA,public BaseB
{
public:
	Derived(){cout << "调用Derived的构造函数." << endl;}
	~Derived(){cout << "调用Derived的析构函数." << endl;}
};
int main()
{
	BaseA a = Derived();
	return 0;
}
