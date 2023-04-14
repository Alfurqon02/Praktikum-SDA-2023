#include <iostream>
#include <set>
#include <iterator>

int main() {
    std::set<int> fav_numbers = {10, 20, 10, 30, 40, 50};
    std::cout<<"Sebelum dihapus: "<<std::endl;
    for (auto it = fav_numbers.begin(); it!=fav_numbers.end(); ++it) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    // std::set<int>::iterator itr = fav_numbers.begin();
    // itr++;
    // fav_numbers.erase(itr);
    // std::advance(itr,2);
    // fav_numbers.erase(itr);
    fav_numbers.erase(10);

    std::set<int>::iterator itr = fav_numbers.find(40); // temukan angka 36
    fav_numbers.erase(itr);

    std::cout<<"Setelah dihapus: "<<std::endl;
    for (auto it = fav_numbers.begin(); it!=fav_numbers.end(); ++it) {
        std::cout<<*it<<" ";
    }
    return 0;
}