# 2 - Disjoint Set

## Konsep Disjoint Set

Disjoint Set adalah struktur data yang memungkinkan pengelompokan data berdasarkan kesamaan. Salah satu contoh penerapan sederhana dari struktur data ini adalah jejaring pertemanan di media sosial. Perhatikan ilustrasi berikut:

- Terdapat 5 orang, yaitu: Andi, Budi, Caca, Deni, dan Edo.
- Andi berteman dengan Budi.
- Budi berteman dengan Caca.
- Deni berteman dengan Edo.
- Sebagai hasilnya, Caca berada dalam satu jaringan pertemanan dengan Andi (meskipun melalui perantara Budi).
- Namun, Caca tidak berada dalam satu jaringan pertemanan dengan Edo (karena jaringan pertemanan Edo hanya dengan Deni).

## Implementasi Disjoint Set

Disjoint Set dapat diimplementasikan menggunakan array atau map yang memetakan setiap data ke perwakilan (representative) dari kelompoknya.

Untuk memastikan kesamaan kelompok antara dua data, disjoint set melacak perwakilan dari setiap data hingga mencapai akar kelompok. Jika kedua data memiliki perwakilan yang sama, maka mereka berada dalam kelompok yang sama.

Berikut adalah contoh definisi struktur data untuk kasus jejaring pertemanan:

```c++
std::map<std::string, std::string> perwakilan;

// Awalnya, setiap orang diwakili oleh dirinya sendiri,
// sehingga Andi berada dalam kelompok yang terpisah, begitu juga Budi, dan seterusnya
perwakilan["Andi"] = "Andi";
perwakilan["Budi"] = "Budi";
perwakilan["Caca"] = "Caca";
perwakilan["Deni"] = "Deni";
perwakilan["Edo"] = "Edo";
```

Berikut adalah contoh implementasi fungsi untuk menjalin pertemanan:

```c++
// Fungsi untuk mencari perwakilan kelompok pertemanan,
// merupakan bagian "find" dalam algoritma "union-find"
std::string find(std::string X) {
    if (perwakilan[X] == X) {
        return X;
    }
    return find(perwakilan[X]);
}

// Fungsi untuk menjalin pertemanan antara A dengan B,
// merupakan bagian "union" dalam algoritma "union-find"
void merge(std::string A, std::string B) {
    std::string perwakilanA = find(A);
    std::string perwakilanB = find(B);

    perwakilan[perwakilanA] = perwakilanB;

    // Analisis:
    // Dalam contoh kasus pertemanan, jika grup Deni-Edo bergabung dengan grup Andi-Budi-Caca,
    // maka kedua perwakilan kelompok digabungkan.
    // Misalnya, awalnya Deni dan Edo diwakili oleh Deni dan Andi diwakili oleh dirinya sendiri.
    // Setelah penggabungan, kedua kelompok Deni-Edo dan Andi-Budi-Caca akan diwak

ili oleh Andi.
    // Dengan demikian, Deni (diwakili oleh Andi) berada dalam kelompok yang sama dengan Budi (juga diwakili oleh Andi).
}

// ...

merge("Andi", "Budi");
merge("Budi", "Caca");
merge("Deni", "Edo");
```

Untuk memeriksa apakah dua orang berada dalam jaringan pertemanan yang sama, cukup lakukan:

```c++
if (find("Andi") == find("Deni")) {
    std::cout << "Andi dan Deni berada dalam satu jaringan yang sama" << std::endl;
}
```

## Analisis dan Operasi Disjoint Set

Setelah memahami konsep dasar Disjoint Set, penting untuk mempelajari beberapa operasi dan analisis yang terkait dengan struktur data ini. Berikut ini adalah beberapa hal yang perlu diperhatikan:

### Operasi Utama

Disjoint Set memiliki dua operasi utama yang umum digunakan:

1. **Find**: Operasi ini digunakan untuk mencari perwakilan (representative) dari suatu elemen atau mencari kelompok mana elemen tersebut termasuk. Dengan menggunakan operasi ini, kita dapat mengetahui apakah dua elemen berada dalam kelompok yang sama atau tidak. Operasi ini umumnya memiliki kompleksitas waktu yang cepat, seperti O(α(n)), di mana α(n) adalah inverse dari fungsi Ackermann.

2. **Union**: Operasi ini digunakan untuk menggabungkan dua kelompok (atau pohon) menjadi satu kelompok. Dengan melakukan operasi ini, kita mengubah perwakilan satu kelompok untuk menunjuk ke perwakilan kelompok lainnya. Operasi ini juga umumnya memiliki kompleksitas waktu yang cepat, seperti O(α(n)), di mana α(n) adalah inverse dari fungsi Ackermann.

### Analisis Waktu dan Ruang

Kompleksitas waktu dan ruang adalah aspek penting dalam memilih dan mengimplementasikan Disjoint Set. Beberapa implementasi yang umum digunakan, seperti *weighted union*, *path compression*, atau *rank-based union*, dapat mempengaruhi performa struktur data ini. 

- *Weighted Union*: Salah satu teknik yang dapat digunakan adalah *weighted union*, di mana saat melakukan operasi *union*, kita menyatukan dua kelompok berdasarkan bobot (size atau rank) masing-masing kelompok. Dengan menggunakan teknik ini, kita dapat mengurangi tinggi pohon yang terbentuk dan mempercepat operasi *find*.

- *Path Compression*: Teknik ini digunakan untuk memperpendek jalur pencarian saat melakukan operasi *find*. Saat mencari perwakilan dari suatu elemen, kita dapat mengubah semua elemen di jalur pencarian tersebut untuk langsung menunjuk ke perwakilan, sehingga mengurangi waktu yang dibutuhkan untuk pencarian selanjutnya.

Pemilihan teknik implementasi dan analisis kompleksitas waktu dan ruang dapat mempengaruhi efisiensi dan kinerja Disjoint Set pada skenario penggunaan tertentu.

### Contoh Implementasi Lain

Selain implementasi dengan menggunakan `map` atau `array` seperti yang telah dijelaskan sebelumnya, terdapat beberapa struktur data lain yang dapat digunakan untuk implementasi Disjoint Set, seperti *disjoint-set forest* menggunakan *array of sets* atau *disjoint-set forest* menggunakan *forest of trees*.

## Selengkapnya

Untuk informasi lebih lanjut tentang Disjoint Set, termasuk algoritma Union-Find, analisis kompleksitas, dan variasi implementasi, Anda dapat merujuk ke sumber-sumber berikut:

- [Disjoint Set (e-Book Pemrograman Kompetitif Dasar)](https://ksn.toki.id/data/pemrograman-kompetitif-dasar.pdf)
- [Disjoint Set Data Structure (GeeksforGeeks)](https://www.geeksforgeeks.org/disjoint-set-data-structures/)
- [Union-Find (CP Algorithms)](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
- [Disjoint Set Union - Union Find (AlgoExpert)](https://www.algoexpert.io/data-structures/disjoint-set-union)
