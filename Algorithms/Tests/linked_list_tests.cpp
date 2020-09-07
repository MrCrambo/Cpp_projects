#include "../Common/linked_list.h"
#include <iostream>

int main(int argc, char * argv[])
{
    algorithms::common::LinkedList<int> list;
    
    list.append(1);
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.append(2);
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.append(4);
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.append(7);
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;

    list.remove();
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.remove();
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.remove();
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;
    list.remove();
    std::cout << "Head is " << list.head() << " and size is " << list.size() << std::endl;

    return 0;
}
