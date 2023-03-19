#include <iostream>
#include <list>

int main() {
    int a[] = {10,20,30,40,50,50};
    std::list<int> list2(a, a + sizeof(a)/sizeof(int));

    for (auto it=list2.begin(); it!=list2.end(); ++it) {
        std::cout<<*it<<" ";
    }

    //menghapus elemen pertama
    list2.pop_front();
    list2.remove(50);

    std::cout<<"Setelah dihapus: "<<std::endl;

    for (auto it=list2.begin(); it!=list2.end(); ++it) {
        std::cout<<*it<<" ";
    }
}