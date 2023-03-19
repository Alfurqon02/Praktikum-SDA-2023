#include <iostream>
#include <stack> //std::stack
using namespace std;

int main() {
    stack<int> usia;

    //menambah 3 elemen: 10, 20, 30;
    for (int i=0; i<=3; i++) {
        usia.push((i+1)*10);
    }

    cout<<"Mengambil isi stack: "<<endl;
    for (int i=0; i<=3; i++) {
        int data = usia.top(); //mengakses nilai elemen terakhir (paling atas)
        cout<<data<<endl;
        usia.pop();
    }
    
    return 0;
}