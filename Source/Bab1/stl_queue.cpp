#include <iostream>
#include <queue> //std::queue

int main() {
    std::queue<int> nilai;

    //menambah lima elemen
    for (int i=0; i<5; i++) {
        nilai.push((i+1)*10);
    }

    std::cout<<"Jumlah elemen\t: " <<nilai.size()<<std::endl;
    std::cout<<"Elemen pertama\t: " <<nilai.front()<<std::endl;
    std::cout<<"Elemen terakhir\t: " <<nilai.back()<<std::endl;

    std::cout<<"\nMengambil isi queue:"<<std::endl;
    for (int i=0; i<5; i++) {
        int isi = nilai.front();
        std::cout<<isi<<std::endl;
        nilai.pop();
    }
    return 0;
}