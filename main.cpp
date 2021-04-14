#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "List/List.hpp"
#include <list>
//using namespace std;

int main ()
{
	ft::list<int> lst;
	lst.push_back(20);
	lst.push_back(45);
	lst.push_back(100);
	lst.push_back(500);
	ft::list<int>::iterator begin = lst.begin();
	ft::list<int>::iterator end = lst.end();
	begin++;
	begin++;
	ft::list<int> myvector;
	myvector.push_back(30);
	myvector.push_back(30);
	lst.splice(begin, myvector);
	begin = lst.begin();
	end = lst.end();
	while (begin != end)
		std::cout << "lst->" << *begin++ << std::endl;
	std::cout << lst.size() << std::endl;
	return 0;
}
