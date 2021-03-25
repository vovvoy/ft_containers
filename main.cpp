#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include "List.hpp"
#include <list>

struct vov{
    int a;
    std::string str;
    double d;
};

std::ostream & operator<<(std::ostream & os, const vov & op){
    os << op.a << std::endl << op.str << std::endl << op.d;
    return os;
}

template <typename T>
void print(T bla){
    std::cout << bla << std::endl;
}

int main ()
{
    vov con;
    con.a = 9;
    con.str = "hell0";
    con.d = 32.32;

    print(con);

    return 0;
}