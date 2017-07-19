#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*测试find_first_of方法:查找任何一个*/
void test_Find_First_Of_Method(){
	vector<int> ivec;//存储数据的向量对象
	list<int> ilist;//存储被查找的数据链表
	for(int i = 1; i <= 11; ++i)
		ivec.push_back(i);
	cout << "向量中数据为：";
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << ' ';
	ilist.push_back(3);
	ilist.push_back(6);
	ilist.push_back(9);

	vector<int>::iterator pos = find_first_of(ivec.begin(),ivec.end(),ilist.begin(),ilist.end());
	if(pos != ivec.end()){
		cout << "找到内容，且第一个查找到的位置为：" << distance(ivec.begin(),pos) + 1 << endl;
	} else {
		cout << "未能查找到内容" << endl;
	}
}

/*使用find_first_of方法 + 逆向迭代器来模拟生成find_last_of方法*/
void test_Find_Last_Of_Method(){
	vector<int> ivec;//存储数据的向量对象
	list<int> ilist;//存储被查找的数据链表
	for(int i = 1; i <= 11; ++i)
		ivec.push_back(i);
	cout << "向量中数据为：";
	for(vector<int>::iterator iter = ivec.begin(); iter != ivec.end(); ++iter)
		cout << *iter << ' ';
	ilist.push_back(3);
	ilist.push_back(6);
	ilist.push_back(9);
	vector<int>::reverse_iterator rpos = find_first_of(ivec.rbegin(),ivec.rend(),ilist.begin(),ilist.end());
	cout << "找到的位置为：" << distance(ivec.begin(),rpos.base()) << endl;
}

int main(){
	test_Find_Last_Of_Method();
	system("pause");
	return 0;
}
