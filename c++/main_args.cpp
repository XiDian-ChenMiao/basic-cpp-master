#include <iostream>
using namespace std;
/*带参数的主函数-命令行选项*/
int main(int argc,char **argv)
{
	//argv[0]是程序的名称，而不是命令行选项
	int argcCount = 1;
	if(argc != 1)
	{
		while(argcCount != argc)
		{
			cout << "命令行参数：" << argv[argcCount++] << endl;
		}
	}
	return 0;
}
