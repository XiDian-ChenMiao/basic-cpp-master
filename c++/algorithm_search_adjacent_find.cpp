#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*adjacent_find查找容器中是否有两个连续相同的元素*/
void test_adjacent_find_method(){
	vector<int> ivec;
	ivec.push_back(-2);
	ivec.push_back(1);
	ivec.push_back(1);
	ivec.push_back(5);
	ivec.push_back(10);

	vector<int>::iterator pos = adjacent_find(ivec.begin(),ivec.end());
	if(pos != ivec.end()) {
		cout << "找到连续两个相等的元素，位置在：" << distance(ivec.begin(),pos) + 1 << endl;
	} else {
		cout << "未能找到连续两个相等的元素." << endl;
	}
}
/*在容器中查找是否出现连续的两个数，后面的数是前面的数的二倍*/
bool doubled(int first,int second){
	return first * 2 == second;
}
void test_adjacent_find_method_by_doubled(){
	vector<int> ivec;
	ivec.push_back(-2);
	ivec.push_back(1);
	ivec.push_back(1);
	ivec.push_back(5);
	ivec.push_back(10);

	vector<int>::iterator pos = adjacent_find(ivec.begin(),ivec.end(),doubled);
	if(pos != ivec.end()) {
		cout << "找到连续两个相等的元素并且后面的数是前面的数的二倍，位置在：" << distance(ivec.begin(),pos) + 1 << endl;
	} else {
		cout << "未能找到连续两个相等的元素." << endl;
	}
}

int main(){
	test_adjacent_find_method_by_doubled();
	return 0;
}
