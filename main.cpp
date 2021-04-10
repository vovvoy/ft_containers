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
    lst.
    std::cout << lst.front() << std::endl;
    std::cout << lst.back() << std::endl;
    ft::list<int>::reverse_iterator begin = lst.rbegin();
    ft::list<int>::reverse_iterator end = lst.rend();
    while (begin != end) {
        *begin += 10;
        std::cout << "lst->" << *begin++ << std::endl;
    }
    return 0;
}
