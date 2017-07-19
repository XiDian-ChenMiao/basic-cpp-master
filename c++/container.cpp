#include <iostream>
#include "print.h"
#include <map>
using namespace std;

int main(){
	map<string,size_t> word_count;
	string word;
	while(cin >> word)
		++word_count[word];
	printMapData(word_count.begin(),word_count.end());
	return 0;
}
