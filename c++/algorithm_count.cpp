#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
void printSetData(set<int>::iterator begin,set<int>::iterator end){
	while(begin != end){
		cout << *begin++ << endl;
	}
}
//打印函数
void printData(int element){
	cout << element << '\t';
}
//创建一个函数对象类
class PrintData{
	public:
		void operator()(int element) const {
			cout << element << '\t';
		}
};
int main(){
	//set<int,greater<int>> a;
	set<int> a;//从小到大排序
	a.insert(9);
	a.insert(3);
	a.insert(5);
	a.insert(1);

	printSetData(a.begin(),a.end());
	for_each(a.begin(),a.end(),printData);
	for_each(a.begin(),a.end(),PrintData());
	cout << "\n集合a中偶数出现个数为：" << count_if(a.begin(),a.end(),not1(bind2nd(modulus<int>(),2)));
	std::string s = "Hello World";
	cout << "\nl出现的次数为：" << count(s.begin(),s.end(),'l') << endl;//获取字符串中l出现的次数
	return 0;
}
