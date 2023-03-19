#include <iostream>
#include <vector>

int main() {
    std::vector<int> angka = {10, 20, 30, 40, 50};

    std::cout<<"Sebelum diganti: "<<std::endl;
    for (auto it=angka.begin(); it != angka.end(); it++) {
        std::cout<<*it<<" ";
    }

    //menambah elemen baru
    angka.pop_back();
    angka.pop_back();

    std::cout<<"Setelah diganti: "<<std::endl;
    for (auto it=angka.begin(); it != angka.end(); it++) {
        std::cout<<*it<<" ";
    }
    return 0;
}