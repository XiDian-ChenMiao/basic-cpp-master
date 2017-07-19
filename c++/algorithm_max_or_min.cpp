#include <iostream>
#include <deque>
#include <algorithm>
bool absLess(int first,int second){
	return abs(first) < abs(second);
}
using namespace std;
int main(){
	deque<int> iDeq;
	for(int i = 2;i <= 8;++i)
		iDeq.insert(iDeq.end(),i);
	for(int i = -3;i <= 5;++i)
		iDeq.insert(iDeq.end(),i);
	iDeq.insert(iDeq.end(),-12);

	for(deque<int>::iterator iter = iDeq.begin(); iter != iDeq.end(); ++iter)
		cout << *iter << endl;

	cout << "Deque容器中最小值为：" << *min_element(iDeq.begin(),iDeq.end()) << endl;
	cout << "Deque容器中最大值为：" << *max_element(iDeq.begin(),iDeq.end()) << endl;
	cout << "Deque容器中绝对值最小为：" << *min_element(iDeq.begin(),iDeq.end(),absLess) << endl;
	cout << "Deque容器中绝对值最大为：" << *max_element(iDeq.begin(),iDeq.end(),absLess) << endl;
	return 0;
}
