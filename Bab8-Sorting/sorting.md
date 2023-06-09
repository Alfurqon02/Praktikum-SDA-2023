# Sorting

## Bubble Sort
Bubble sort adalah algoritma pengurutan sederhana yang bekerja dengan membandingkan pasangan elemen bersebelahan dalam daftar dan menukar mereka jika urutan mereka salah. Ini berulang kali melintasi data hingga tidak ada lagi pertukaran yang perlu dilakukan, sehingga elemen-elemen terurut secara bertahap naik ke posisi yang tepat. Algoritma ini dinamakan "bubble sort" karena elemen-elemen yang lebih kecil "naik ke permukaan" seperti gelembung air saat diurutkan. Meskipun bubble sort mudah dipahami, namun biasanya kurang efisien untuk daftar yang besar karena kompleksitas waktu yang lebih tinggi daripada algoritma pengurutan lainnya.

![Ilustrasi Bubblesort](https://github.com/Alfurqon02/Praktikum-SDA-2023/blob/main/Bab8-Sorting/img/bubble.jpg)

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

## Selection Sort
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

## Insertion Sort
Insertion sort adalah algoritma pengurutan sederhana yang bekerja dengan membagi daftar menjadi dua bagian: bagian terurut dan bagian belum terurut. Algoritma ini memproses satu elemen pada satu waktu dan memasukkannya ke posisi yang tepat dalam bagian terurut. Algoritma ini lebih efisien daripada bubble sort dan selection sort dalam beberapa kasus.

![Ilustrasi Insertion Sort](https://github.com/Alfurqon02/Praktikum-SDA-2023/blob/main/Bab8-Sorting/img/insertionsort.jpg)

### Kelebihan
- Sederhana dan mudah dipahami
- Efisien untuk jumlah data yang hampir terurut
- Dapat menjaga urutan relatif dari elemen yang bernilai sama

### Kekurangan
- Kompleksitas waktu yang tinggi "O(n^2)"
- Tidak efisien untuk reverse sorting (pengurutan terbalik)
- Penggunaan memori yang tidak efisien

```cpp
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        arr[j + 1] = key;
    }
}

int main() {
    int array[] = {23, 56, 9, 103, 77};
    int size = sizeof(array) / sizeof(array[0]);

    insertionSort(array, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

```

## Tambahan
[Visualisasi Sorting](https://www.hackerearth.com/practice/algorithms/sorting)