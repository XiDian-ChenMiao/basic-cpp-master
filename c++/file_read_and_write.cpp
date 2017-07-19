#include <iostream>
#include <stdio.h>
using namespace std;

const int DEFAULT_RETURN = 0;
const int FILE_IN_EXCEPTION = 1;
const int FILE_OUT_EXCEPTION = 2;
const int FILE_INOROUT_EXCEPTION = 3;
/*自定义文件拷贝函数，抛出错误值为数字*/
int file_copy_by_digit(const char *srcFile,const char *destFile)
{
	FILE *file_in,*file_out;
	file_in = fopen(srcFile,"rb");
	if(file_in == NULL)
		throw FILE_IN_EXCEPTION;
	file_out = fopen(destFile,"wb");
	if(file_out == NULL)
		throw FILE_OUT_EXCEPTION;
	char buffer[256];
	size_t bytes_in,bytes_out;
	while((bytes_in = fread(buffer,1,256,file_in)) != 0)
	{
		bytes_out = fwrite(buffer,1,bytes_in,file_out);
		if(bytes_in != bytes_out)
			throw FILE_INOROUT_EXCEPTION;
	}
	fclose(file_in);
	fclose(file_out);
	return DEFAULT_RETURN;
}

/*自定义文件拷贝函数，抛出错误值为字符串*/
int file_copy_by_string(const char *srcFile,const char *destFile)
{
	FILE *file_in,*file_out;
	file_in = fopen(srcFile,"rb");
	if(file_in == NULL)
		throw "源文件打开错误！";
	file_out = fopen(destFile,"wb");
	if(file_out == NULL)
		throw "目标文件打开错误！";
	char buffer[256];
	size_t bytes_in,bytes_out;
	while((bytes_in = fread(buffer,1,256,file_in)) != 0)
	{
		bytes_out = fwrite(buffer,1,bytes_in,file_out);
		if(bytes_in != bytes_out)
			throw "文件读写错误！";
	}
	fclose(file_in);
	fclose(file_out);
	return DEFAULT_RETURN;
}
/*自定义异常类*/
class BaseException {};
class OpenSrcException : protected BaseException {};
class OpenDestException : protected BaseException {};
class CopyException : protected BaseException {};
/*自定义文件拷贝函数，抛出错误值为异常类*/
int file_copy_by_class(const char *srcFile,const char *destFile)
{
	FILE *file_in,*file_out;
	file_in = fopen(srcFile,"rb");
	if(file_in == NULL)
		throw OpenSrcException();
	file_out = fopen(destFile,"wb");
	if(file_out == NULL)
		throw OpenDestException();
	char buffer[256];
	size_t bytes_in,bytes_out;
	while((bytes_in = fread(buffer,1,256,file_in)) != 0)
	{
		bytes_out = fwrite(buffer,1,bytes_in,file_out);
		if(bytes_in != bytes_out)
			throw CopyException();
	}
	fclose(file_in);
	fclose(file_out);
	return DEFAULT_RETURN;
}

/*主函数*/
int main()
{
	int copy_result;
	try{
		copy_result = file_copy_by_digit("E:\\1.txt","E:\\2.txt");
		copy_result = file_copy_by_string("E:\\1.txt","E:\\3.txt");
		copy_result = file_copy_by_class("E:\\1.txt","E:\\4.txt");
	}catch(int exception_code){
		cout << "发生异常，错误码为：" << exception_code << endl;
	}catch(const char *exception_string){
		cout << "发生异常，错误信息为：" << exception_string << endl;
	}catch(OpenSrcException exception_instance){
		cout << "打开源文件异常！" << endl;
	}catch(OpenDestException e){
		cout << "打开目标文件异常！" << endl;
	}catch(CopyException e){
		cout << "文件拷贝异常！" << endl;
	}catch(...){
		cout << "发生异常！" << endl;
	}
	if(copy_result == DEFAULT_RETURN)
		cout << "文件拷贝成功！" << endl;
	return 0;
}
