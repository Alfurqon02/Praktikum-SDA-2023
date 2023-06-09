# Selection Sort

## Konsep
Selection sort adalah algoritma pengurutan sederhana yang bekerja dengan mencari elemen terkecil dari daftar dan menukar elemen tersebut dengan elemen pertama. Kemudian, mencari elemen terkecil kedua dari daftar yang belum terurut dan menukar elemen tersebut dengan elemen kedua. Proses ini berlanjut hingga seluruh daftar terurut. Algoritma ini dinamakan "selection sort" karena pada setiap langkahnya, algoritma memilih elemen terkecil dari sisa daftar yang belum terurut dan memindahkannya ke posisi yang sesuai.

![Ilustrasi Selection Sort](https://github.com/Alfurqon02/Praktikum-SDA-2023/blob/main/Bab8-Sorting/img/selectionsort.png)

### Kelebihan
- Sederhana dan mudah dipahami
- Dapat menjaga urutan relatif dari elemen elemen yang sama

### Kekurangan
- Kompleksitas waktu yang tinggi "O(n^2)"
- Tidak efisien untuk data yang hampir terurut
- Penggunaan memori yang tidak efisien

### Contoh Penerapan

```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    int array[] = {7, 2, 8, 1, 4};
    int size = sizeof(array) / sizeof(array[0]);

    selectionSort(array, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

```

## Tambahan
[Visualisasi Selection Sort](https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/)