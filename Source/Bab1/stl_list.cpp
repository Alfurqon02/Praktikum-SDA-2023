#include <iostream>
#include <list>

int main() {
    int a[] = {10,20,30,40,50};
    std::list<int> list1(a, a + sizeof(a)/sizeof(int));

    // iterator maju
    std::cout<<"Iterator maju: " <<std::endl;
    std::list<int>::iterator it;
    for (it=list1.begin(); it!=list1.end(); ++it) {
        std::cout<<*it<<" ";
    }
}