#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/*
	标准IO库：面向对象的标准库
	A.继承：基类-->派生类
	B.3个头文件
	C.9个标准库类型
	D.IO对象不可复制或赋值

	继承结构如下：
			 |--ofstream
	ostream--|--ostringstream
			 |--\
				 \ 	       |--stringstream
				 iostream--|
				 /         |--fstream
			 |--/
	istream--|--istringstream
			 |--ifstream

	文件模式：
	A.文件模式选项：
		in（输入模式）,
		out（输出模式）,
		app（附加模式）,
		ate（文件结尾模式）,
		trunc（裁剪模式）,
		binary（二进制模式）
	B.文件模式组合
		out,out|app,out|trunc,in,in|out,in|out|ate,in|out|trunc
*/
/*流的条件状态检测测试*/
void check_inputstream(istream &in)
{
	//保存原有流的状态
	istream::iostate oldState = cin.rdstate();
	cin.setstate(istream::badbit | istream::failbit);
	cin.clear(istream::badbit);

	cout << "检测cin输入流：";
	if(cin.bad())
		cout << "cin.bad" << endl;
	if(cin.fail())
		cout << "cin.fail" << endl;
	if(cin.eof())
		cout << "cin.eof" << endl;
	if(cin.good())
		cout << "cin.good" << endl;
	//恢复原有流的状态
	cin.clear(oldState);
}
/*检查状态函数*/
void check_state(istream &in)
{
	int sum = 0,value;
	check_inputstream(cin);
	while(cin >> value,!cin.eof())
	{
		if(cin.bad())
			throw std::runtime_error("IO Stream Break.");
		if(cin.fail())
		{
			cerr << "Bad Data,Try Again." << endl;
			cin.clear();//将标志位清除
			cin.ignore(200,'\n');//将错误忽略
			continue;
		}
		sum += value;
		cout << "和为：" << sum << endl;
	}
}
/*较好的打开文件流的函数*/
ifstream& open_file(ifstream &stream,const string &fileName)
{
	stream.close();
	stream.clear();
	stream.open(fileName.c_str());
	return stream;
}
/*字符串流测试函数*/
void stringStreamTest()
{
	ostringstream stringStream;//定义字符串输出流
	stringStream << "我是陈苗";//输出字符串到内存中
	cout << stringStream.str() << endl;
	stringStream << "My Name Is ChenMiao.";//将采用追加字符串的形式
	cout << stringStream.str() << endl;
}
/*主函数*/
int main()
{
	ofstream outFile("Test.txt");//在项目目录下生成Test.txt文件，并且直接与文件绑定
	outFile << "我是陈苗." << endl;
	outFile.close();

	string fileName = "Hello.txt";
	string content;
	ifstream inFile;
	inFile.open(fileName.c_str());//只能导入C语言风格的字符串
	if(!inFile)
	{
		cerr << "打开输入流错误." << endl;
		return -1;
	}
	while(inFile >> content)
		cout << "读到内容：" << content << endl;
	inFile.close();

	if(!open_file(inFile,fileName))
	{
		cerr << "打开输入流错误" << endl;
		return -1;
	}
	stringStreamTest();

	ostringstream formatMessage;
	formatMessage << "姓名：" << "陈苗" << "\n" << "年龄：" << 23 << "\n" << "成绩：" << 85.5 << "\n";
	cout << formatMessage.str();

	istringstream inFormatMessage(formatMessage.str());
	string name,dump;
	int age;
	double score;
	inFormatMessage >> dump;
	inFormatMessage >> name;
	inFormatMessage >> dump;
	inFormatMessage >> age;
	inFormatMessage >> dump;
	inFormatMessage >> score;
	cout << name << "," << age << "," << score << endl;
	return 0;
}
