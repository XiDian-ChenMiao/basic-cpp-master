#ifndef _ARRAY_H
#define _ARRAY_H
#include <iostream>

template<typename TYPE>
class Array
{
public:
	Array(int length);
	~Array();
	TYPE& operator[](int offset);
	const TYPE& operator[](int offset) const;
	int getArraySize() const;
private:
	TYPE *elements;
	int arraySize;
};
/*构造函数操作*/
template<typename TYPE>
Array<TYPE>::Array(int length) : arraySize(length)
{
	elements = new TYPE[length];
	for(int i = 0;i < length;++i)
		elements[i] = 0;
}
/*析构函数操作*/
template<typename TYPE>
Array<TYPE>::~Array()
{
	delete []elements;
}
/*重载写数组运算符*/
template<typename TYPE>
TYPE& Array<TYPE>::operator [](int offset)
{
	int arrayLength = this->getArraySize();
	if(offset >= 0 && offset < arrayLength)
		return elements[offset];
	throw string("数组越界异常.");
}
/*重载读数组运算符*/
template<typename TYPE>
const TYPE& Array<TYPE>::operator [](int offset) const
{
	int arrayLength = this->getArraySize();
	if(offset >= 0 && offset < arrayLength)
		return elements[offset];
	throw string("数组越界异常.");
}
template<typename TYPE>
int Array<TYPE>::getArraySize()
{
	return this->arraySize;
}
#endif
