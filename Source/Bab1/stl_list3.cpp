#include <iostream>
#include <list>

bool sama(int previous, int next) {
        return previous==next;
    }

int main() {
    int a[] = {10,10,20,20,20,20,30,30,30,40,40,40,50};
    std::list<int> list3(a, a + sizeof(a)/sizeof(int));

    std::cout<<"Sebelum elemen duplikat dihapus;"<<std::endl;
    for (auto it=list3.begin(); it!=list3.end(); ++it) {
        std::cout<<*it<<" ";
    }

    //menghapus nilai duplikat
    list3.unique(sama);

    std::cout<<"\nSetelah elemen duplikat dihapus;"<<std::endl;
    for (auto it=list3.begin(); it!=list3.end(); ++it) {
        std::cout<<*it<<" ";
    }
}