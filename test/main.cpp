#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



//#include <iostream>
//#include "srcs/ft_containers.hpp"
//
//int main(){
//	ft::map<char, int> first;
//	first['a'] = 200;
//	first['c'] = 65;
//	first['b'] = 100;
//	first.insert(ft::pair<char, int>('z', 1));
//	ft::map<char, int>::iterator begin = first.begin();
//	ft::map<char, int>::iterator end = first.end();
//	while (begin != end){
//		std::cout << (*begin).second << std::endl;
//		begin++;
//	}
//	return (0);
//}