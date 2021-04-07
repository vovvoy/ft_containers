#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "List/List.hpp"
#include <list>
//using namespace std;

int main ()
{
    ft::list<int> mylist;

    // set some initial content:
    for (int i=1; i<10; ++i) mylist.push_back(i);

    mylist.resize(5);
    mylist.resize(8,100);
    mylist.resize(12);
    return 0;
}
