#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "List/List.hpp"
#include <list>
//using namespace std;

//int main ()
//{
//	ft::list<int> lst;
//	lst.push_back(20);
//	lst.push_back(45);
//	lst.push_back(100);
//	lst.push_back(500);
//	ft::list<int>::iterator begin = lst.begin();
//	ft::list<int>::iterator end = lst.end();
//	begin++;
//	begin++;
//	ft::list<int> myvector;
//	myvector.push_back(30);
//	myvector.push_back(30);
//	lst.splice(begin, myvector);
//	begin = lst.begin();
//	end = lst.end();
//	while (begin != end)
//		std::cout << "lst->" << *begin++ << std::endl;
//	std::cout << lst.size() << std::endl;
//	return 0;
//}

int main ()
{
	ft::list<int> first;
	ft::list<int> second;

	first.assign (7,100);                      // 7 ints with value 100

	second.assign (first.begin(),first.end()); // a copy of first

	int myints[]={1776,7,4};
	first.assign (myints,myints+3);            // assigning from array

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	return 0;
}
