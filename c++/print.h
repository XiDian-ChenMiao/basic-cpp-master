#ifndef _PRINT_H
#define _PRINT_H

#include <iostream>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <string>
void printVectorData(std::vector<int>::iterator begin,std::vector<int>::iterator end){
	std::cout << "vector容器中值为：";
	while(begin != end)
		std::cout << *begin++ << ' ';
	std::cout << std::endl;
}

void printDequeData(std::deque<int>::iterator begin,std::deque<int>::iterator end){
	std::cout << "deque容器中值为：";
	while(begin != end)
		std::cout << *begin++ << ' ';
	std::cout << std::endl;
}

void printListData(std::list<int>::iterator begin,std::list<int>::iterator end){
	std::cout << "list容器中值为：";
	while(begin != end)
		std::cout << *begin++ << ' ';
	std::cout << std::endl;
}

void printMapData(std::map<std::string,size_t>::iterator begin,std::map<std::string,size_t>::iterator end){
	std::cout << "map容器中值为：";
	while(begin != end){
		std::cout << (*begin).first << "出现了" << *(begin).second << "次." << std::endl;
		++begin;
	}

	std::cout << std::endl;
}
#endif
