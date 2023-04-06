# Analisis Kompleksitas

Pada semester pertama kita telah mempelajari bagaimana membuat algoritma untuk menyelesaikan suatu masalah. Namun, hal tersebut tidak sajalah cukup. Algoritma tidak saja harus benar (efektif), tetapi juga harus mangkus (efisien). Sehingga dapat dikatakan bahwa algoritma yang baik adalah algoritma yang mangkus. Kemangkusan suatu algoritma diukur dari sisi waktu (time) eksekusi serta penggunaan memori (space).

## 1 - Notasi Asimtotik

Terdapat beberapa jenis notasi asimtotik, tetapi kita hanya akan menggunakan dan membahas satu notasi saja, yaitu notasi Big-O. Big-O dipilih karena merupakan notasi yang paling populer dan paling banyak digunakan pada kalangan peneliti ilmu komputer. Notasi Big-O digunakan untuk mengkategorikan algoritma ke dalam fungsi yang menggambarkan batas atas (upper limit) dari pertumbuhan sebuah fungsi ketika masukan dari fungsi tersebut bertambah banyak.

| Fungsi Big-O | Nama       |
| ------------ | ---------- |
| O(1)         | Konstan    |
| O(log N)     | Logaritmik |
| O(N)         | Linear     |
| O(N log N)   | n log n    |
| O(N^2)       | Kuadratik  |
| O(N^m)       | Polinomial |
| O(N!)        | Faktorial  |

## 2 - Contoh Kriteria Kompleksitas

### O(1): Konstan

```cpp
// ...
cout << "Hello, world!" << endl;
// ...
```

Dalam kode di atas "Hello, world!" mencetak hanya sekali di layar. Jadi, kompleksitas waktu adalah konstan: O(1) yaitu setiap kali jumlah waktu yang konstan diperlukan untuk mengeksekusi kode, apa pun sistem operasi atau konfigurasi mesin yang Anda gunakan.

### O(N): Linear

```cpp
// ...
int i, n = 8;
for (i = 1; i <= n; i++) {
   cout << "Hello, world!" << endl;
}
// ...
```

Dalam kode di atas "Hello, world!" akan mencetak N kali. Jadi, kompleksitas waktu dari kode di atas adalah O(N).

### O(N^2): Kuadratik

```cpp
// ...
int a = 0;
for (i = 0; i < N; i++) {
	for (j = N; j > i; j--) {
		a = a + i + j;
	}
}
// ...
```

Kode di atas berjalan total  
= N + (N – 1) + (N – 2) + … 1 + 0  
= N (N + 1) / 2  
= 1/2 N^2 + 1/2 N  
O(N^2) kali.

### O (log N): Logartimik

```cpp
// ...
int a = 0, i = N;
while (i > 0) {
	a += i;
	i /= 2;
}
// ...
```

Kita harus mencari x terkecil sehingga N / 2^x N
x = log(N)


### O(N log N): Linearitmik

```cpp
// ...
int i, j, k = 0;
for (i = N / 2; i <= N; i++) {
	for (j = 2; j <= N; j = j * 2) {
		k = k + N / 2;
	}
}
// ...
```

Jika diperhatikan, j terus berlipat ganda hingga kurang dari atau sama dengan N. Beberapa kali, kita dapat menggandakan angka hingga kurang dari N akan menjadi log(N).  
Mari kita ambil contoh di sini.  
untuk N = 16, j = 2, 4, 8, 16  
untuk N = 32, j = 2, 4, 8, 16, 32  
Jadi, j akan dijalankan untuk langkah-langkah O(log N).  
i berjalan selama N/2 langkah.  
Jadi, langkah total = O(N / 2 * log (N)) = O(N*logN)


## 3 - Perbandingan Pertumbuhan Kompleksitas

![Gambar perbandingan kompleksitas](https://i.ytimg.com/vi/XiGedDZGOM8/hqdefault.jpg?sqp=-oaymwEXCNACELwBSFryq4qpAwkIARUAAIhCGAE=&rs=AOn4CLCoZ7k4wh3HCXJkQQ0zw_wgCF8ymw)

Pengembangan algoritma idealnya diusahakan mendapatkan kompleksitas O(1) atau O(logn). Sayangnya pada kenyataannya kita tidak akan selalu mendapatkan kompleksitas terbaik dalam merancang algoritma. Jika tidak dapat mencapai kompleksitas maksimal, hal terbaik yang dapat kita lakukan ketika mengembangkan solusi dari masalah adalah melihat apakah masalah yang ada dapat diselesaikan dengan algoritma yang ada terlebih dahulu, sebelum mengembangkan algoritma baru. Hal ini memastikan kita mendapatkan kompleksitas yang paling efisien sampai saat pengembangan solusi.

## 4 - Kesimpulan

Pada bagian ini kita telah mempelajari bagaimana melakukan analisa efisiensi algoritma dengan menggunakan notasi Big-O. Kita juga melihat bagaimana algoritma yang paling efisien memiliki kompleksitas O(1), dengan kompleksitas O(n!) sebagai kelas kompleksitas yang paling tidak efisien. Dengan mengerti efisiensi algoritma, diharapkan pembaca dapat memilih dan merancang algoritma yang sesuai dengan kebutuhan untuk menyelesaikan masalah.

## 5 - Soal Praktikum

Carilah dan analisis time complexity dari algoritma berikut:

```cpp
// ...
int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}
// ...
```
