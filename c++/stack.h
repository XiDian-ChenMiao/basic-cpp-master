#ifndef __STACK_H
#define __STACK_H
/*
		和普通类一样，类模板也可以拥有静态成员。所不同的是，它们是类模板实例化后生成模板类的静态成员；也就是说，对于一个类模板
	的每一个实例化类，其静态成员为该实例化类所有的对象所共享。
		和普通类静态成员的初始化一样，类模板的静态成员也需要在类中声明，在类外定义。

		I.类模板的静态数据成员的初始化形式和普通类相似，但必须指定类模板的具体实例化类型参数；
		II.类模板的静态数据成员只能为同一类型的模板类对象所共享，不同类型的模板类对象的静态数据成员互不干扰。
*/
template <class T>
class Stack
{
	public:
		//构造函数
		Stack(int _size)
		{
			size = _size;
			top = bottom = new T[size];//栈空间分配
		}
		//压栈操作
		void push(const T& item)
		{
			//如果栈满，程序终止
			if(isStackFull())
			{
				cerr << "栈空间已满." << endl;
				exit(1);
			}
			*top++ = item;//将新元素压入栈顶，栈顶指针加1
		}
		//弹栈操作
		T pop()
		{
			T temp;
			//如果栈空，程序终止
			if(isStackEmpty())
			{
				cerr << "栈内容为空." << endl;
				exit(1);
			}
			top--;
			temp = *top;
			return temp;
		}
		//判断栈是否为空的函数
		bool isStackEmpty() const
		{
			return top <= bottom;
		}
		//判断栈是否为满的函数
		bool isStackFull() const
		{
			return (top - bottom) > size;
		}
	private:
		T *top;//栈顶指针
		T *bottom;//栈尾指针
		int size;//栈的大小
};
#endif
