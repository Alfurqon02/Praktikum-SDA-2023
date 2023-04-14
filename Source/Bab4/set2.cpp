#include <iostream>
#include <set>
#include <iterator>

int main() {
    std::set<int> fav_numbers = {10, 20, 30, 40, 50};
    std::cout<<"Sebelum ditambah: "<<std::endl;
    for (auto it = fav_numbers.begin(); it!=fav_numbers.end(); ++it) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    std::set<int>::iterator itr = fav_numbers.begin();
    fav_numbers.insert(60);
    std::advance(itr,2);
    fav_numbers.insert(70);

    std::cout<<"Setelah ditambah: "<<std::endl;
    for (auto it = fav_numbers.begin(); it!=fav_numbers.end(); ++it) {
        std::cout<<*it<<" ";
    }
    return 0;
}