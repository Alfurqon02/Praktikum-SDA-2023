# 1 - Konsep Rekursi

**Rekursi** adalah sebuah cara untuk mendefinisikan sebuah permasalahan menggunakan _versi permasalahan itu sendiri yang lebih simpel_. Dalam dunia pemrograman, paradigma rekursi biasanya diterapkan dalam pembuatan **Fungsi Rekursif**. **Fungsi Rekursif** adalah sebuah fungsi yang memanggil dirinya sendiri.

Perhatikan potongan kode di bawah.

```cpp
// ...
void recurse() {
    // Logika ...
    recurse();
}

int main() {
    recurse();
}
// ...
```

Pada fungsi `recurse()` terdapat pemanggilan ke fungsi `recurse()` itu sendiri. Alhasil, jika fungsi `recurse()` kita panggil dari `main()` maka akan memanggil dirinya sendiri tanpa henti, yang akan menimbulkan **infinite loop**. Kita akan mempelajari cara untuk menanggulanginya menggunakan **base case** nanti.

## Kegunaan Rekursi dan Interpretasi Matematis

> Mengapa rekursi merupakan paradigma yang penting dan pantas untuk kita pelajari?

Perhatikan contoh di bawah, di mana kita ingin menjumlahkan `n` buah bilangan asli.

```
Pendekatan 1:
    f(n) = 1 + 2 + 3 + 4 + ... + n

Pendekatan 2:
    f(n) = 1            untuk n = 1   <- Base Case
    f(n) = n + f(n-1)   untuk n > 1
```

Apa perbedaan di antara 2 pendekatan di atas? Pendekatan pertama menggunakan metode sekuensial, di mana fungsi hanya menambah-nambahkan angka satu-persatu, sedangkan pendekatan kedua menggunakan konsep rekursi, di mana fungsi `f(n)` memanggil dirinya sendiri dengan parameter yang berbeda. Mari kita lihat bagaimana kedua pendekatan berjalan dengan diberikan `n = 5`.

```
Pendekatan 1:
    f(5) = 1 + 2 + 3 + 4 + 5
    f(5) = 15


Pendekatan 2:
    f(5) = 5 + f(4)
        f(4) = 4 + f(3)
            f(3) = 3 + f(2)
                f(2) = 2 + f(1)
                    f(1) = 1    <- Perhatikan Base Case
                f(2) = 2 + 1 = 3
            f(3) = 3 + 3 = 6
        f(4) = 4 + 6 = 10
    f(5) = 5 + 10 = 15
```

Bisa kita lihat di atas bahwa **pendekatan pertama** bekerja seperti penambahan pada umumnya, yaitu menambahkan elemen bilangan real satu persatu.

Pada **pendekatan kedua**, pada masing-masing `n`, fungsi akan memanggil dirinya sendiri dengan parameter `n - 1`. Kita dapat mendefinisikan dua bagian eksekusi program pada pendekatan kedua di atas. Pertama adalah bagian sebelum base case, di mana pemanggilan fungsi kepada dirinya sendiri terjadi, kedua adalah bagian setelah base case, di mana sudah ditemukan jawaban dari `f(1)`, sehingga nilai `f(1)` tersebut dipropagasikan naik. Dalam kalimat yang lebih sederhana, ekspresi `f(2) = 2 + f(1)` akhirnya dapat dievaluasi karena `f(1)` diketahui, ekspresi `f(3) = 3 + f(2)` dapat dievaluasi karena `f(2)` diketahui, dan seterusnya.

Contoh di atas mungkin merupakan contoh yang sangat naif untuk implementasi fungsi rekursif, namun merupakan kasus yang mudah untuk dijelaskan. Jika kalian sudah memahami konsep di atas, cobalah untuk memahami kasus yang lebih complicated seperti [recursive factorial](https://www.google.com/search?q=recursive+factorial) atau [recursion tree traversal](https://www.google.com/search?q=tree+traversal+recursion).

## Bagian-bagian Algoritma Rekursif

> Disclaimer: Ada banyak opini pakar mengenai pembagian dari algoritma rekursif. Materi yang diberikan di bawah mungkin berbeda dengan opini beberapa pakar, namun kami nilai cukup untuk membentuk pemahaman mengenai fungsi rekursif.

### 1. Base Case

Sepanjang materi, ada beberapa pembahasan mengenai Base Case. Base Case merupakan batasan yang **harus dibuat setiap kali kita membuat sebuah fungsi rekursif** supaya fungsi yang baru saja kita buat tidak menjadi _infinite loop_ atau perulangan infinit yang disebabkan oleh perulangan/rekursi yang tidak dibatasi.

Jika penjelasan di atas kurang dapat dimengerti, perhatikan potongan kode di bawah ini.

```c++
// Potongan 1
while (true) {
    doSomething();
}

// Potongan 2
int i = 0;
while (i < 5) {
    doSomething();
    i++;
}
```

Pada potongan pertama, perulangan `while` dieksekusi tanpa batasan. Alhasil, apapun yang berada dalam blok perulangan `while` tersebut akan dieksekusi tanpa henti. Namun, pada potongan kedua, perulangan yang sama dieksekusi dengan batas, yaitu `i < 5`, sehingga perulangan tersebut hanya dilakukan 5 kali. Ini merupakan sebuah konsep yang cukup mirip dengan Base Case di fungsi rekursif, dengan detil yang sedikit berbeda. Perhatikan contoh di bawah ini.

```
f(n) = 1            untuk n = 1   <- Base Case
f(n) = n + f(n-1)   untuk n > 1
```

Seperti yang dapat kita lihat di atas, definisi `f(n) = 1` pada `n = 1` merupakan batas yang kita buat supaya fungsi rekursif kita dapat berhenti di sebuah titik `n`. Perhatikan analisis variabel per titik `n` untuk `f(n)` di bawah ini.

```
f(5) = 5 + f(4)
f(4) = 4 + f(3)
    ...
f(2) = 1 + f(1)
f(1) = 1        <- Base Case
```

Di saat komputer memulai komputasi dengan `n = 5`, komputer mengevaluasi statement `f(5) = 5 + f(4)`. Setelah itu, karena komputer diminta untuk memanggil `f(4)`, maka komputer mengevaluasi statement `f(4) = 4 + f(3)`, dan seterusnya untuk setiap pemanggilan fungsi, hingga komputer mencapai `f(1)`. Di titik tersebut, komputer mengetahui jika solusi dari fungsi tersebut adalah `1`. Komputer lalu mengeluarkan memorinya untuk fungsi-fungsi sebelumnya, dimulai dengan `f(2)` yang akan mengevaluasi `f(2) = 1 + f(1)`, hanya saja nilai `f(1)` sudah diketahui. Step ini diulangi untuk setiap fungsi, hingga pemanggilan fungsi pertama sewaktu komputer memulai komputasi.

### 2. Simplifikasi Permasalahan

Komponen simplifikasi permasalahan pada fungsi rekursif dapat didefinisikan sebagai pengurangan panjang statement yang harus dieksekusi komputer. Dengan menggunakan rumus `f` yang sama, komputer yang menghitung `f(3)` secara langsung (bukan rekursif), maka komputer akan mengeksekusi 3 suku penambahan `(1 + 2 + 3)`, sedangkan komputer yang menghitung `f(3)` secara rekursif akan mengeksekusi 2 suku penambahan 2 kali, beserta 1 base case. Konsep simplifikasi/pemecahan masalah ini akan dipelajari lebih lanjut pada algoritma _divide and conquer_.

## Pranala Luar

Jika teman-teman mengalami kesulitan dalam memahami materi ini, atau ingin mendapatkan opini/pembawaan lain terhadap materi ini, kami menyarankan beberapa bacaan di bawah

1. [Materi Fungsi Rekursif materi KP 2022](https://github.com/XnoahR/KP2022/blob/main/Bab4-CFunction/4-Rekursi.md)
2. [Materi _recursion_ GeeksForGeeks](https://www.geeksforgeeks.org/recursion/)
