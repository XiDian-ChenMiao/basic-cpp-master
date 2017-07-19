#include <iostream>
#include <vector>
using namespace std;
/*打印向量函数,C++程序员更喜欢形参传递迭代器*/
void print_vector(vector<int>::const_iterator begin,vector<int>::const_iterator end)
{
	while(begin != end)
		cout << "从向量中删除：" << *begin++ << endl;
}
int main()
{
	vector<int> vec;
	int i = 1,result;
	while(i <= 5)
	{
		cout << "向向量中添加：" << i << endl;
		vec.push_back(i++);
	}
	print_vector(vec.begin(),vec.end());
	return 0;
}
