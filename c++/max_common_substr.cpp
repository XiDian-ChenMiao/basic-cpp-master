#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *max_common_substr(char *str1,char *str2){
	int i,j;
	char *shortstr,*longstr;
	char *substr;
	//判断是否参数存在为空指针
	if(NULL == str1 || NULL == str2)
		return NULL;
	//找寻长串与短串
	if(strlen(str1) <= strlen(str2))
	{
		shortstr = str1;
		longstr = str2;
	}else{
		shortstr = str2;
		longstr = str1;
	}
	//如果短串已经是长串的子串，则最长公共子串就为短串
	if(strstr(longstr,shortstr))
		return shortstr;
	//申请一块大小为短串长度加1的堆内存，这块内存用于保存最大公共子串
	substr = (char *)malloc(sizeof(char) * (strlen(shortstr) + 1));
	for(i = strlen(shortstr) - 1;i > 0;i--){
		for(j = 0;j < strlen(shortstr) - i;j++){
			memcpy(substr,&shortstr[j],i);
			substr[i] = '\0';
			if(strstr(longstr,substr) != NULL)
				return substr;
		}
	}
	return NULL;
}
int main(){
	char *str1 = (char *)malloc(256);
	char *str2 = (char *)malloc(256);
	char *max_common_substr_result = NULL;
	printf("请输入主串：");
	gets(str1);
	printf("请输入子串：");
	gets(str2);
	max_common_substr_result = max_common_substr(str1,str2);
	printf("最长公共子串为：%s.\n",max_common_substr_result);
	system("pause");
	return 0;
}
