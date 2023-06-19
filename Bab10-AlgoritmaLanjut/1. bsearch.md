# 1 - Binary Search

Struktur Data Terkait : **Array List**

## Konsep

Binary search adalah suatu algoritma searching / pencarian efektif yang memiliki kompleksitas waktu O(log N). Satu-satunya syarat yang harus dimiliki oleh algoritma ini adalah elemen-elemennya di dalam array yang **harus sudah terurut**.

Cara kerja algoritma ini adalah membagi terus area pencarian menjadi dua bagian dan mencarinya di bagian yang memiliki kemungkinan terdapat elemen yang dicari sedangkan bagian yang lain diabaikan (lantas algoritma ini dikategorikan memiliki kompleksitas O(log N)).

Cara menentukan bagian area yang tepat adalah membandingkan urutan nilai yang dicari dengan nilai pada tengah-tengah area, kemudian cek:

- Apabila nilai yang dicari memiliki urutan lebih kecil dari nilai tengah maka bagian kirilah yang akan dipilih
- Kemudian apabila nilai yang dicari memiliki urutan lebih besar dari nilai tengah maka bagian kananlah yang akan dipilih
- Selebihnya apabila nilai yang dicari sama dengan nilai tengah maka elemen tersebut sudah ditemukan.

Pencarian dihentikan apabila area yang dicari sudah tidak memiliki elemen lagi (alias elemen tidak ditemukan).

Berikut adalah visualisasinya:

![visualisasi](https://d18l82el6cdm1i.cloudfront.net/uploads/bePceUMnSG-binary_search_gif.gif)

## Implementasi

```c++
#include <iostream>
#include <string>
#include <vector>

int find_mahasiswa(const std::vector<std::string> &array, std::string target, int batas_kiri, int batas_kanan) {
    if (batas_kiri > batas_kanan) {
        // artinya sudah tidak ada elemen lagi
        // target tidak ditemukan (return -1)
        return -1;
    }

    // ambil elemen tengah sebagai pembanding
    int tengah = (batas_kiri + batas_kanan) / 2;
    std::string pembanding = array[tengah];

    if (target < pembanding) {
        // target berada di sebelah kiri pembanding
        // geser batas kanan supaya area pencarian selanjutnya berada di sebelah kiri
        // cari lagi secara rekursif dalam area yang lebih kecil (bagian kiri)
        return find_mahasiswa(array, target, batas_kiri, tengah - 1);
    }
    if (target > pembanding) {
        // target berada di sebelah kanan pembanding
        // geser batas kiri supaya area pencarian selanjutnya berada di sebelah kanan
        // cari lagi secara rekursif dalam area yang lebih kecil (bagian kanan)
        return find_mahasiswa(array, target, tengah + 1, batas_kanan);
    }

    // target ditemukan, return indeksnya
    return tengah;
}

int main() {
    std::vector<std::string> mahasiswa;

    // semua nama harus sudah terurut
    mahasiswa.push_back("Arnold");
    mahasiswa.push_back("Brett");
    mahasiswa.push_back("Cliffe");
    mahasiswa.push_back("Kurt");
    mahasiswa.push_back("Minh");
    mahasiswa.push_back("Pheonix");
    mahasiswa.push_back("Shark");

    std::string cari;
    std::cout << "Masukkan nama yang ingin dicari: ";
    std::cin >> cari;

    // mulanya atur pinggiran array supaya menjadi batas-batasnya
    int indeks = find_mahasiswa(mahasiswa, cari, 0, mahasiswa.size() - 1);

    if (indeks != -1) {
        std::cout << cari << " berada pada indeks ke-" << indeks << std::endl;
    } else {
        std::cout << cari << " tidak ditemukan" << std::endl;
    }

    return 0;
}
```