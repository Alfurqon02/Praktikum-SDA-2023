# Bubble Sort

## Konsep
Bubble sort adalah algoritma pengurutan sederhana yang bekerja dengan membandingkan pasangan elemen bersebelahan dalam daftar dan menukar mereka jika urutan mereka salah. Ini berulang kali melintasi data hingga tidak ada lagi pertukaran yang perlu dilakukan, sehingga elemen-elemen terurut secara bertahap naik ke posisi yang tepat. Algoritma ini dinamakan "bubble sort" karena elemen-elemen yang lebih kecil "naik ke permukaan" seperti gelembung air saat diurutkan. Meskipun bubble sort mudah dipahami, namun biasanya kurang efisien untuk daftar yang besar karena kompleksitas waktu yang lebih tinggi daripada algoritma pengurutan lainnya.

![Ilustrasi Bubblesort](https://github.com/Alfurqon02/Praktikum-SDA-2023/blob/main/Bab8-Sorting/img/bubblesort.jpg)

### Kelebihan
- Implementasi yang sederhana.
- Cocok untuk data yang hampir terurut

### Kekurangan
- Kompleksitas waktu yang buruk "O(n^2)" 
- Penggunaan memori yang tidak efisien
- Jika ada elemen dengan nilai yang sama, posisi dapat berubah setelah dilakukan sorting

### Contoh Penerapan
berikut source code untuk menerapkan bubble sort pada array [4, 1, 2, 3]

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int array[] = {4, 2, 3, 1};
    int size = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
```

## Tambahan
[Visualisasi Bubble Sort](https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/visualize/)