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
    std::cout << lst.front() << std::endl;
    std::cout << lst.back() << std::endl;
    ft::list<int>::iterator begin = lst.begin();
    ft::list<int>::iterator end = lst.end();
    int i = 0;
    while (begin != end) {
        *begin += 10;
        std::cout << "lst->" << *begin++ << std::endl;
        if (*begin == 500)
            lst.erase(begin);

        i++;
//        begin++;
    }
    std::cout << lst.size() << std::endl;
    return 0;
}
