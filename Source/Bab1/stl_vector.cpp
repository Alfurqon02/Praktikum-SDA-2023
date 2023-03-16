#include <iostream>
#include <vector> //std::vector

int main() {
    std::vector<int> angka;
    //menambah elemen
    for (size_t i=0; i<5; i++) {
        angka.push_back((i+1)*10);
    }

    //menampilkan elemen
    for (size_t i=0; i<angka.size(); i++) {
        std::cout<<angka[i]<<" ";
    }
    return 0;
}