#include <iostream>
#include <bitset>
#include <string>
using namespace std;
int main()
{
	bitset<32> a;
	cout << a << endl;

	bitset<16> b(0xffff);
	cout << b << endl;

	bitset<32> c(0xffff);
	cout << c << endl;

	bitset<32> d(156);
	cout << d << endl;


	string str("1010010010111");
	bitset<32> e(str,2,5);//从第二位开始连续五个字符
	cout << e << endl;

	bitset<32> f(str,str.size() - 4);//取出后面四位0111
	cout << f << endl;

	bitset<4> g(string("10010"));
	cout << g << endl;

	bool is_set = f.any();//是否有一
	if(is_set)
		cout << "字符串f中至少有一个1." << endl;
	bool is_not_set = f.none();//是否没有一
	if(is_not_set)
		cout << "字符串f中至少没有一个1." << endl;
	int one_count = f.count();
	cout << "字符串f中1的个数为" << one_count << endl;
	f.set(9);
	cout << "设置第九位为1之后，f变为" << f << endl;
	f.flip();
	cout << "反转f之后，f变为" << f << endl;
	f.reset();
	cout << "重置f之后，f变为" << f << endl;

	f.set(2);//将第2位设置为1
	unsigned int result = f.to_ulong();
	cout << "f被转为十进制之后，f变为" << result << endl;

	bitset<8> eightBits;
	cout << "输入八位二进制数：" << endl;
	cin >> eightBits;
	cout << eightBits << endl;
	cout << "有" << eightBits.count() << "个1" << endl;
	cout << "有" << eightBits.size() - eightBits.count() << "个0" << endl;

	bitset<8> eightMoreBits(string("11110000"));
	cout << "eightMoreBits与eightBits相与：" << (eightMoreBits & eightBits) << endl;
	cout << "eightMoreBits与eightBits相或：" << (eightMoreBits | eightBits) << endl;
	cout << "eightMoreBits与eightBits异或：" << (eightMoreBits ^ eightBits) << endl;
	return 0;
}
