#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <vector>
using namespace std;
/*find和find_if对于所有的容器都适用，其为线性查找*/
void testFindMethod(){
	list<int> iList;
	for(int i = 0;i <= 9;++i)
		iList.insert(iList.end(),i);
	for(int i = 0;i <= 9;++i)
		iList.insert(iList.end(),i);

	for(list<int>::iterator iter = iList.begin(); iter != iList.end(); ++iter)
		cout << *iter << endl;

	list<int>::iterator posIter1;
	posIter1 = find(iList.begin(),iList.end(),4);

	list<int>::iterator posIter2;
	if(posIter1 != iList.end())
	{
		posIter2 = find(++posIter1,iList.end(),4);
	}
	if(posIter1 != iList.end() && posIter2 != iList.end())
	{
		posIter1--;
		posIter2++;
		for(list<int>::iterator begin = posIter1; begin != posIter2; ++begin)
			cout << *begin << '\t';
	}
}

void testFindIfMethod(){
	vector<int> iVec;
	for(int i = 0;i <= 9;++i)
		iVec.push_back(i);

	for(vector<int>::iterator iter = iVec.begin();iter != iVec.end();++iter)
		cout << *iter << '\t';

	vector<int>::iterator pos;
	pos = find_if(iVec.begin(),iVec.end(),bind2nd(greater<int>(),3));
	cout << "第一个大于3的数为：" << *pos << endl;

	pos = find_if(iVec.begin(),iVec.end(),not1(bind2nd(modulus<int>(),3)));
	cout << "第一个能被3整除的数为：" << *pos << endl;
}

/*使用关联容器的find成员方法*/
void testAttributeFindMethod(){
	set<int> iSet;
	iSet.insert(43);
	iSet.insert(-78);
	iSet.insert(23);

	for(set<int>::iterator iter = iSet.begin(); iter != iSet.end(); ++iter)
		cout << *iter << '\t';

	set<int>::iterator pos = iSet.find(43);
	if(pos != iSet.end())
		cout << "找到43" << endl; //查找速率要比线性查找更快
}

/*查找String*/
void testStringFindMethod(){
	string s("Hello");
	string::size_type pos = s.find("ll");
	cout << (pos != string::npos ? "找到了" : "没找到") << endl;
}
int main(){
	testStringFindMethod();
	return 0;
}
