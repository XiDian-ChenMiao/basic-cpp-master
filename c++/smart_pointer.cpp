#include <iostream>
#include <memory>/*内包含智能指针的声明*/
using namespace std;
class Dog
{
public:
	void print() const
	{
		cout << "Dog." << endl;
	}
};
void useSmartPtrTest()
{
	std::auto_ptr<int> ptr(new int);
	*ptr = 15;
	Dog *dog = new Dog;
	std::auto_ptr<Dog> pDog(dog);
	cout << "指针指向的int值为：" << *ptr << endl;
	dog->print();
}
int main()
{
	useSmartPtrTest();
	return 0;
}
