#include <iostream>
#include <set>

int main() {
    std::set<int> fav_numbers = {10, 20, 30, 40, 50};
    std::cout<<"Penelurusan maju: "<<std::endl;
    for (auto it = fav_numbers.begin(); it!=fav_numbers.end(); ++it) {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Penelurusan mundur: "<<std::endl;
    for (auto it = fav_numbers.rbegin(); it!=fav_numbers.rend(); ++it) {
        std::cout<<*it<<" ";
    }
    return 0;
}