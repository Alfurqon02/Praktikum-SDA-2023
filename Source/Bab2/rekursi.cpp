#include <iostream>

using namespace std;

int hitungFaktorial(int input) {
    if (input > 1) {
        return input*hitungFaktorial(input-1);
    }
    else return 1;
}

int main() {
    cout<<"Hitung Faktorial dengan Rekursi \n";

    int angka;
    cout<<"Masukkan angka: \n";
    cin>>angka;

    cout<<angka<<"! = "<<hitungFaktorial(angka);
    cout<<endl;

    return 0;
}