#include <iostream>
#include <vector>
using namespace std;
/*
	友元有三种：友元函数，友元类，友元类的成员函数；
*/
class Sales_item;
/*友元类的成员函数测试类*/
class SalesManager
{
public:
	unsigned getSalesCount(Sales_item &item);
};
class Sales_item
{
	friend class Person;//友元类
	friend unsigned SalesManager::getSalesCount(Sales_item &item);//友元类的成员函数
	friend double getRevenue(Sales_item &book);//友元函数
private:
	std::string bookNumber;//书号
	unsigned salesCount;//销售数量
	double revenue;//销售额
	static int saleObjCounter;//对象计数器
public:
	//如果出现除默认构造函数之外的其他构造函数，那么就需要编写默认构造函数
	Sales_item() : bookNumber(std::string("大华数据结构")),salesCount(0),revenue(0.00)
	{
		cout << "默认构造函数被调用了." << endl;
	}
	/*全参数构造函数*/
	Sales_item(const string &bookNumber,unsigned salesCount,double revenue)
	{
		this->bookNumber = bookNumber;
		this->salesCount = salesCount;
		this->revenue = revenue;
		++saleObjCounter;
	}
	/*C++提供默认的复制构造函数*/
	Sales_item(const Sales_item &another)
	{
		cout << "复制操作函数被调用了." << endl;
		this->bookNumber = another.bookNumber;
		this->salesCount = another.salesCount;
		this->revenue = another.revenue;
	}
	/*重载赋值运算符*/
	Sales_item& operator=(Sales_item &another)
	{
		cout << "赋值操作符被调用了." << endl;
		this->bookNumber = another.bookNumber;
		this->salesCount = another.salesCount;
		this->revenue = another.revenue;
		return *this;
	}
	/*重载+=运算符*/
	Sales_item& operator+=(const Sales_item &other);
	/*获取对象计数器*/
	static int getSalesObjCounter()
	{
		return saleObjCounter;
	}
	/*获取平均售价*/
	double getAveragePrice() const
	{
		return salesCount != 0 ? revenue / salesCount : 0;
	}
	/*设置书本编号*/
	Sales_item& setBookNumber(std::string _bookNumber)
	{
		this->bookNumber = _bookNumber;
		return *this;
	}
	Sales_item& setSalesCount(unsigned _salesCount)
	{
		this->salesCount = _salesCount;
		return *this;
	}
	std::string getBookNumber() const {
		return this->bookNumber;
	}
	/*打印信息函数*/
	void print()
	{
		cout << "A.编号:" << bookNumber.c_str() << endl;
		cout << "B.销量:" << salesCount << endl;
		cout << "C.销售额:" << revenue << endl;
	}
	/*C++会提供默认的析构函数，如果提供自己写的析构函数，则必须提供自己写的复制构造函数和赋值运算符函数*/
	~Sales_item()
	{
		cout << "执行了析构函数." << endl;
	}
};
/*重载+运算符*/
Sales_item operator+(const Sales_item &front,const Sales_item &tail);
Sales_item& Sales_item::operator+=(const Sales_item &other)
{
	salesCount += other.salesCount;
	revenue += other.revenue;
	return *this;
}
/*重载+运算符*/
Sales_item operator+(const Sales_item &front,const Sales_item &tail)
{
	Sales_item temp(front);
	temp += tail;
	return temp;
}
int Sales_item::saleObjCounter = 0;//初始化Sales_item类的静态成员变量

unsigned SalesManager::getSalesCount(Sales_item &item)
{
	return item.salesCount;
}
/*友元类的测试类*/
class Person
{
public:
	void printSales(Sales_item &item)
	{
		cout << "友元类：" << endl;
		cout << "书本编号为：" << item.bookNumber.c_str() << endl;
		cout << "销售数量为：" << item.salesCount << endl;
		cout << "销售总额为：" << item.revenue << endl;
	}
};
/*友元函数*/
double getRevenue(Sales_item &book)
{
	return book.revenue;
}
/*智能指针（引用计数）*/
class SmartPointer
{
	friend class UseSmartPointerClass;//声明友元类
private:
	size_t useCounter;//引用计数器
	int *pointer;//int类型的引用
	SmartPointer(int *p) : pointer(p),useCounter(1) {}
	~SmartPointer() {delete pointer;}
};
class UseSmartPointerClass
{
private:
	double otherValue;
	SmartPointer *smartPointer;
public:
	UseSmartPointerClass(int *p,double _otherValue) : smartPointer(new SmartPointer(p)),otherValue(_otherValue)
	{
	}
	/*编写复制构造函数*/
	UseSmartPointerClass(const UseSmartPointerClass &original)
	{
		this->otherValue = original.otherValue;
		this->smartPointer = original.smartPointer;
		++smartPointer->useCounter;//计数器加1
	}
	/*编写赋值操作符函数*/
	UseSmartPointerClass& operator=(const UseSmartPointerClass &original)
	{
		original.smartPointer->useCounter++;
		if(--smartPointer->useCounter == 0)
			delete smartPointer;
		smartPointer = original.smartPointer;
		otherValue = original.otherValue;
		return *this;
	}
	void setOtherValue(double otherValue)
	{
		this->otherValue = otherValue;
	}
	void setPointerValue(int value)
	{
		*this->smartPointer->pointer = value;
	}
	/*打印函数*/
	void print()
	{
		cout << *smartPointer->pointer << "," << otherValue << endl;
	}
	~UseSmartPointerClass()
	{
		if(--smartPointer->useCounter == 0)
			delete smartPointer;
	}
};
/*深复制与浅复制的测试类*/
class CopyTestClass
{
public:
	int testNumber;
	char *testPointer;
	CopyTestClass(int _testNumber,char *_testPointer)
	{
		this->testNumber = _testNumber;
		this->testPointer = new char[20];
		strcpy(this->testPointer,_testPointer);
	}
	/*提供深复制的复制构造函数*/
	CopyTestClass(const CopyTestClass &other)
	{
		cout << "CopyTestClass复制构造函数被执行." << endl;
		this->testNumber = other.testNumber;
		this->testPointer = new char[20];
		if(this->testPointer != 0)
			strcpy(this->testPointer,other.testPointer);
	}
	void print()
	{
		cout << "testNumber:" << testNumber << endl;
		cout << "testPointer:" << testPointer << endl;
	}
	~CopyTestClass()
	{
		delete testPointer;
	}
};

/*主函数*/
int main()
{
	Sales_item book("ISO-001",2,60.0),another(book),next;
	Sales_item *item = new Sales_item;//在这里调用默认构造函数
	delete item;//在这里调用析构函数
	next = book;
	cout << "书本编号为：" << book.getBookNumber().c_str() << endl;
	cout << "复制构造函数的书本编号为：" << another.getBookNumber().c_str() << endl;
	cout << "赋值运算符后的书本编号为：" << next.getBookNumber().c_str() << endl;
	cout << "书本销售额为：" << getRevenue(book) << endl;
	cout << "对象计数器为：" << Sales_item::getSalesObjCounter() << endl;

	Sales_item other("ISO-001",3,80);
	Sales_item temp = other + book;
	temp.print();
	Person person;
	person.printSales(book);

	SalesManager manager;
	cout << "友元类函数：" << manager.getSalesCount(book) << endl;

	vector<Sales_item> vec(2);//先执行默认构造函数构造一个Sales_item类型的对象，然后通过复制构造函数在复制2个
	cout << "unsigned长度为：" << sizeof(unsigned) << endl;

	CopyTestClass a(10,"ChenMiao");
	CopyTestClass b = a;//在这里执行默认的复制构造函数，复制为浅复制
	cout << "b更改之前,a,b对象的情况：" << endl;
	a.print();
	b.print();
	cout << "b更改之后,a对象的情况：" << endl;
	b.testNumber = 25;
	b.testPointer = "Hello";
	a.print();
	b.print();
	int tempValue = 30;
	UseSmartPointerClass c(&tempValue,25.5);
	UseSmartPointerClass d(c);//此处为使用智能指针的浅复制
	cout << "c更改之前,c,d对象的情况：" << endl;
	c.print();
	d.print();
	c.setOtherValue(25.6);
	c.setPointerValue(28);
	cout << "c更改之后,c,d对象的情况：" << endl;
	c.print();
	d.print();
	return 0;
}
