#include <iostream>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;
/*查找连续*/
void test_Search_N_Method(){
	deque<int> iDeq;
	for(int i = 1; i <= 9; ++i)
		iDeq.push_back(i);
	iDeq.push_back(3);
	iDeq.push_back(3);
	for(deque<int>::iterator iter = iDeq.begin(); iter != iDeq.end(); ++iter)
		cout << *iter << endl;

	deque<int>::iterator pos = search_n(iDeq.begin(),iDeq.end(),2,3);
	cout << (pos != iDeq.end() ? "找到连续2个3" : "没找到连续2个3") << ",下标的位置在：" << distance(iDeq.begin(),pos) + 1 << endl;

	pos = search_n(iDeq.begin(),iDeq.end(),3,6,greater<int>());//查找3个连续大于6的数
	cout << (pos != iDeq.end() ? "找到连续3个大于6的数" : "没找到连续2个3") << endl;
}

bool checkEven(int elem,bool even){
	return even ? elem % 2 == 0 : elem % 2 == 1;
}

/*从容器自前向后查找*/
void test_Search_method(){
	deque<int> ideq;
	for(int i = 2; i <= 7; ++i)
		ideq.insert(ideq.end(),i);
	for(deque<int>::iterator iter = ideq.begin(); iter != ideq.end(); ++iter)
		cout << *iter << endl;

	list<int> ilist;
	for(int i = 3; i <= 5; ++i)
		ilist.insert(ilist.end(),i);
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << endl;

	deque<int>::iterator pos = search(ideq.begin(),ideq.end(),ilist.begin(),ilist.end());//从deque中查找list中的数据
	if(pos != ideq.end()){
		cout << "找到内容，位置在：" << distance(ideq.begin(),pos) + 1 << endl;
	} else {
		cout << "没有找到内容" << endl;
	}

	bool checkEvenArgs[3] = {true,false,true};
	pos = search(ideq.begin(),ideq.end(),checkEvenArgs,checkEvenArgs + 3,checkEven);
	if(pos != ideq.end()){
		cout << "找到内容，位置在：" << distance(ideq.begin(),pos) + 1 << endl;
	} else {
		cout << "没有找到内容" << endl;
	}
}

/*从容器自后向前查找*/
void test_Find_End_method(){
	deque<int> ideq;
	for(int i = 1; i <= 7; ++i)
		ideq.insert(ideq.end(),i);
	for(int i = 1; i <= 7; ++i)
		ideq.insert(ideq.end(),i);
	for(deque<int>::iterator iter = ideq.begin(); iter != ideq.end(); ++iter)
		cout << *iter << ' ';

	list<int> ilist;
	for(int i = 2; i <= 5; ++i)
		ilist.insert(ilist.end(),i);
	for(list<int>::iterator iter = ilist.begin(); iter != ilist.end(); ++iter)
		cout << *iter << endl;

	deque<int>::iterator pos = find_end(ideq.begin(),ideq.end(),ilist.begin(),ilist.end());//从deque中查找最后一个出现list中的数据的位置
	if(pos != ideq.end()){
		cout << "找到内容，位置在：" << distance(ideq.begin(),pos) + 1 << endl;
	} else {
		cout << "没有找到内容" << endl;
	}
}

/*主函数*/
int main(){
	test_Search_method();
	return 0;
}
