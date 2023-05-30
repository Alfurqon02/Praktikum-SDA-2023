Berikut adalah perbaikan pada materi Disjoint Set di markdown:

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

## Selengkapnya

- [Disjoint Set (e-Book Pemrograman Kompetitif Dasar)](https://ksn.toki.id/data/pemrograman-kompetitif-dasar.pdf)
