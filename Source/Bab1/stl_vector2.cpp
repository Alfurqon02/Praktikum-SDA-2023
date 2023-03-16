#include <iostream>
#include <vector>

int main() {
    std::vector<int> angka = {10, 20, 30, 40, 50};

    //menampilkan elemen 1 sampai 5
    std::cout<<"Iterator maju: "<<std::endl;
    std::vector<int>::iterator it;
    for (it=angka.begin(); it!=angka.end(); ++it) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Iterator mundur: "<<std::endl;
    std::vector<int>::reverse_iterator it1;
    for (it1=angka.rbegin(); it1!=angka.rend(); ++it1) {
        std::cout<<*it1<<" ";
    }

    return 0;
}