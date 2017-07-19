#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
	串的匹配算法解析：
		1.朴素的匹配算法(BF)：
			BF算法的时间复杂度O(strlen(S) * strlen(T))，空间复杂度O(1)。
            int BF_Algothrim(SString S, SString T, int pos){
            	//返回T在S中第pos个字符之后的位置
               	i=pos;
               	j=1;
               	k=0;
              	while(i< = S[0] && j< = T[0] ){
                  	if (S[i+k] = = T[j] ){
                  		++k;
                  		++j;
                  	}   //继续比较后续字符
                  	else{
                  		i=i+1;
                  		j=1;
                  		k=0;
                  	} //指针回溯到 下一首位，重新开始
              }
              if(j>T[0]) return i; //子串结束，说明匹配成功
              else return  0;
            }
		2.KMP算法：
			KMP算法的时间复杂度O(strlen(S) + strlen(T))，空间复杂度O(strlen(T))。
			KMP算法的本质便是：针对待匹配的模式串的特点，判断它是否有重复的字符，
			从而找到它的前缀与后缀，进而求出相应的Next数组，最终根据next数组而进行KMP匹配
*/
//得到模式串的next数组
void get_next(char const* T,int length,int *next){
	int i = 0,j = -1;
	next[i] = -1;
	if(j == -1 || T[i] == T[j]){
		i++;
		j++;
		if(T[i] != T[j])
			next[i] = j;
		else
			next[i] = next[j];
	}
	else
		j = next[j];
}
//利用get_next函数得到的next数组结合KMP算法来求解模式串在主串的pos位置之后第一次出现的位置
int KMP_Algothrim(char const* S,int sLength,char const* T,int tLength,int *next,int pos){
	int i = pos,j = 0;
	while(i < sLength && j < tLength){
		if( j == -1 || S[i] == T[j] )
        {
            ++i;
            ++j;
        }
        else
        	j = next[j];
	}
	if(j >= tLength)
		return i - tLength;
	else
		return -1;
}
int main(int argc, char const *argv[])
{
	char *S = "CHENMIAO";//主串
	char *T = "CHEN";//模式串
	int next[strlen(T)];//next数组
	get_next(T,strlen(T),next);
	printf("首次出现位置为:%d\n",KMP_Algothrim(S,strlen(S),T,strlen(T),next,0));
	system("pause");
	return 0;
}
