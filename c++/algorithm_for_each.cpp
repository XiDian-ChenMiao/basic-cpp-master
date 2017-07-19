#include <iostream>
#include <algorithm>
#include <list>

using namespace std;
/*测试for_each方法，使用打印函数print*/
void print(int elem) {
	cout << "打印：" << elem << endl;
}
template<typename T>
class AddValue {
	private:
		T value;
	public:
		AddValue(const T& _value) : value(_value) {
		}
		void operator()(T& element) {
			element += value;
		}
};
/*用于接收for_each方法的返回值*/
class MeanValue {
	private:
		int eleCounter;//元素计数器
		int sum;//元素总和
	public:
		MeanValue() : eleCounter(0),sum(0) {
		}
		/*函数对象方法*/
		void operator()(int ele) {
			eleCounter++;
			sum += ele;
		}
		/*平均数函数*/
		double average() const {
			return static_cast<double>(sum) / static_cast<double>(eleCounter);
		}
		/*类型转换函数*/
		operator double() {
			return static_cast<double>(sum) / static_cast<double>(eleCounter);
		}
};
void test_for_each_method() {
	list<int> ilist;
	for(int i = 0; i <= 9; ++i)
		ilist.insert(ilist.end(),i);
	cout << "未加10之前，list中数据为：\n";
	for_each(ilist.begin(),ilist.end(),print);

	for_each(ilist.begin(),ilist.end(),AddValue<int>(10));

	cout << "\n加上10之后，list中数据为：\n";
	for_each(ilist.begin(),ilist.end(),print);

	MeanValue mv = for_each(ilist.begin(),ilist.end(),MeanValue());
	cout << "\n第一种方法的平均数为：" << mv.average() << endl;

	double average = for_each(ilist.begin(),ilist.end(),MeanValue());
	cout << "\n第二种方法的平均数为：" << average << endl;
}
int main(){
	test_for_each_method();
	return 0;
}
