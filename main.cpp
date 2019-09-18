#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
   // Tester::execute();
    SelfList<int> list(SelfList<int>::Transpose);

    list.insert(14);
    list.insert(16);
    list.print();
    list.insert(15);
    list.insert(17);
    list.insert(122);
    list.insert(13);
    std::cout<<list.find(16)<<std::endl;
    list.print();
    std::cout<<list.find(122)<<std::endl;
    list.print();
    list.remove(16);
    std::cout<<list.find(22)<<std::endl;
    list.print();
    list.find(13);
    list.find(13);
    list.print();

    return EXIT_SUCCESS;
}

