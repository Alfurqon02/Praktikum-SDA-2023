# 1 - Konsep List

List adalah struktur data yang berguna untuk menampung banyak elemen. Terdapat dua contoh implementasinya, yaitu **array list** dan **linked list**. Array list adalah implementasi list yang menggunakan array sebagai penampungnya, kemudian linked list menggunakan self-referential structure dan pointer sebagai penampungnya.

- Array list memiliki kelebihan yaitu elemen di suatu posisi dapat diakses dengan cepat (kompleksitas O(1)), namun memiliki kekurangan yaitu proses memasukkan dan mengeluarkan elemen dalam list membutuhkan waktu yang lebih lama (kompleksitas O(N)) serta mekanisme alokasi memori yang lebih banyak (kompeksitas O(K) di mana K >= N dan K adalah kapasitas maksimum array) apabila ingin menghemat waktu saat memasukkan elemen di masa mendatang.
- Lalu linked list memiliki kelebihan yaitu proses memasukkan dan mengeluarkan elemen membutuhkan waktu yang singkat (kompleksitas O(1)) dan dapat menggunakan memori seefisien mungkin (kompleksitas O(N)), namun untuk mengakses elemen di posisi tertentu membutuhkan waktu yang lebih lama (kompleksitas O(N)).

Dalam hal ini berlaku N adalah jumlah seluruh elemen yang tertampung dalam list.

Dalam bahasa C++, array list diimplementasikan dengan tipe data **std::vector** yang berada dalam header `<vector>`, kemudian linked list diimplementasikan dengan tipe data **std::list** yang berada dalam header `<list>`.

## 1.1. Array List (std::vector)

### Deklarasi

Contoh:
```c++
std::vector<int> fav_numbers;
```

### Operasi

Menambahkan elemen di akhir:
```c++
fav_numbers.push_back(24);
```

Menambahkan elemen di indeks ke-2:
```c++
fav_numbers.insert(fav_numbers.begin() + 2, 48);
```

Menghapus elemen di indeks terakhir:
```c++
fav_numbers.pop_back();
```

Menghapus elemen di indeks ke-2:
```c++
fav_numbers.erase(fav_numbers.begin() + 2);
```

Mengakses elemen di indeks ke-2:
```c++
int num = fav_numbers[2];
```

Iterasi seluruh elemen:
```c++
for (int i = 0; i < fav_numbers.size(); i++) {
    std::cout << "fav_numbers[" << i << "] : " << fav_numbers[i] << std::endl;
}
```

## 1.2. Linked List (std::list)

### Deklarasi

Contoh:
```c++
std::list<int> fav_numbers;
```

### Operasi

Menambahkan elemen di awal:
```c++
fav_numbers.insert(fav_numbers.begin(), 24);
// atau:
fav_numbers.push_front(24);
```

Menambahkan elemen di akhir:
```c++
fav_numbers.insert(fav_numbers.end(), 96);
// atau:
fav_numbers.push_back(96);
```

Menambahkan elemen di posisi ke-3:
```c++
fav_numbers.insert(std::next(fav_numbers.begin(), 2), 48); // #include <iterator> terlebih dahulu
// atau:
fav_numbers.insert(it, 48); // asumsi `it` adalah iterator yang sudah mengarah ke elemen ke-3
```

Menghapus elemen di awal (kompleksitas O(N)):
```c++
fav_numbers.erase(fav_numbers.begin());
// atau:
fav_numbers.pop_front();
```

Menghapus elemen di akhir (kompleksitas O(N)):
```c++
fav_numbers.erase(fav_numbers.end());
// atau:
fav_numbers.pop_back();
```

Mengakses elemen di posisi ke-3:
```c++
std::list<int>::iterator it = std::next(fav_numbers.begin(), 2);
int num = *it;
// atau bisa langsung:
int num = *std::next(fav_numbers.begin(), 2);
// #include <iterator> terlebih dahulu apabila ingin menggunakan std::next
```

Menghapus elemen di posisi ke-3:
```c++
fav_numbers.erase(std::next(fav_numbers.begin(), 2)); // #include <iterator> terlebih dahulu
// atau:
fav_numbers.erase(it); // asumsi `it` adalah iterator yang sudah mengarah ke elemen ke-3
```

Iterasi seluruh elemen:
```c++
for (
    std::list<int>::iterator it = fav_numbers.begin();
    it != fav_numbers.end();
    ++it
) {
    std::cout << "fav_number : " << *it << std::endl;
}
```

## Selengkapnya

- [C++ Vector](https://en.cppreference.com/w/cpp/container/vector)
- [C++ List](https://en.cppreference.com/w/cpp/container/list)
- [C++ Iterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator)
