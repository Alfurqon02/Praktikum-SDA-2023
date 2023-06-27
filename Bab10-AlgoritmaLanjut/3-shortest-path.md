# 3 - Shortest Path

Struktur Data Terkait : **Graf**

Algoritma Terkait : **Dijkstra's Algorithm**

## Konsep

Shortest path adalah permasalahan graf yang mencoba mencari **rute** yang memiliki **total bobot edge terkecil** (atau jarak terpendek) antara **dua buah node**. Algoritma yang biasanya digunakan dalam memecahkan permasalahan shortest path adalah algoritma **Dijkstra**.

Berikut adalah contoh hasil generasi shortest path:

![ilustrasi](./img/shortest-path.ppm)

Contoh tersebut mencoba mencari rute terpendek dari **node 1** ke **node 9** dan rute yang dihasilkan adalah **1-2-3-8-9** yang memiliki bobot terkecil (6) di antara opsi rute yang lainnya (7 dan 10).

**Contoh Kasus:** mencari rute terpendek dari rumah ke sekolah.

## Implementasi (Dijkstra's Algorithm)

Cara kerja algoritma Dijkstra adalah sebagai berikut:

1. Buat dua himpunan yang berisi **(1) sekumpulan node yang sudah dikunjungi** dan **(2) sekumpulan node yang belum dikunjungi**
2. Buat dictionary/map yang memetakan **node** dengan suatu nilai **jarak terpendek** untuk mencapai node yang bersangkutan. Mulanya atur semua nilai jarak menjadi tak terhingga (infinite), namun atur jarak node asal menjadi 0 supaya dikunjungi pertamakali
3. Buat dictionary/map yang memetakan **node** dengan suatu node asal (atau **parent**) untuk membangun rute shortest path. Node yang dikunjungi pertama kali tidak perlu memiliki parent
4. Kunjungi semua node selagi himpunan node yang belum dikunjungi masih terisi:
    1. Ambil sebuah node dari himpunan tersebut yang memiliki **nilai jarak terkecil** (jarak didapat dari dictionary/map yang dibuat)
    2. Masukkan node tersebut ke himpunan yang sudah dikunjungi dan keluarkan dari himpunan yang belum dikunjungi
    3. Perbarui seluruh jarak pada node-node tetangga pada himpunan yang belum dikunjungi. Jarak hanya akan diperbarui apabila nilai jarak node asal pada dictionary ditambah dengan bobot dengan node tetangga **lebih kecil** dari nilai jarak node tetangga pada dictionary
    4. Apabila pada langkah sebelumnya jaraknya diperbarui, perbarui juga node parent dari tetangga tersebut supaya mengarah ke node yang dipilih tadi

Untuk contoh dan visualisasinya dapat dilihat [di sini](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/).

Contoh source code juga dapat dilihat [di sini](./3-shortest-path-dijkstra.cpp)