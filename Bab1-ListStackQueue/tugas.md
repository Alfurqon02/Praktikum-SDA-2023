# Tugas Praktikum List, Stack, & Queue

NOTE

1. Gunakan bahasa **C++**
2. Kumpulkan semua source code pada assignment Google Classroom **(jangan di-ZIP)**, diberi format: **NamaKelas_PSDA01_NIM_NamaLengkap_Nomor Soal.cpp**, 

   misal apabila mengumpulkan nomor 1 : **B_PSDA01_M0520047_MohammadAlFurqon_1.cpp**

## No. 1 - List

Ikuti langkah-langkah berikut **(bobot: 40%)**:

1. Buatlah list untuk menyimpan data berupa sekumpulan string: **Rambutan**, **Jambu**, **Jeruk**, **Melon**, **Semangka**, **Durian**
2. Bagi list menjadi 2 bagian (list1 dan list2), dengan isi list1 : **Rambutan**, **Jambu**, **Jeruk** dan isi list2 : **Melon**, **Semangka**, **Durian**
3. Lalu hapus **Jambu** dari list1 dan **Durian** dari list2
4. Setelah itu, tampilkan isi dari kedua list tersebut

Contoh Output: 
```
Seluruh List:
Rambutan
Jambu
Jeruk
Melon
Semangka
Durian
List 1:
Rambutan
Jeruk
List 2:
Melon
Semangka
```

Anda boleh menggunakan array list (std::vector) ataupun linked list (std::list)

## No. 2 - Stack

Selesaikan permasalahan di bawah menggunakan stack **(bobot: 30%)**:

Ronald memiliki tumpukan buku sebagai berikut (urut dari posisi teratas):

- Implementation of Linear Algebra
- Data Structure and Algorithm 2nd Edition
- Linear Algebra and Its Applications
- Introduction to OpenCV Library (Python)
- Introduction to Machine Learning
- Data Structure and Algorithm 1st Edition
- Machine Learning
- Database Management System (Expert Edition)
- Database Management System (Beginner Edition)


Suatu saat Ronald ingin mengurutkan tumpukan buku tersebut agar terurut dan menjual buku berjudul **Introduction to OpenCV Library (Python)** sehingga tumpukan buku tersebut menjadi seperti berikut:

- Linear Algebra and Its Applications
- Implementation of Linear Algebra
- Introduction to Machine Learning
- Machine Learning
- Data Structure and Algorithm 1st Edition
- Data Structure and Algorithm 2nd Edition
- Database Management System (Beginner Edition)
- Database Management System (Expert Edition)

Buatlah program yang mensimulasikan permasalahan tersebut menggunakan stack! Program tidak harus menampilkan isi stack ke layar ataupun menerima input. Asisten akan menilai ketepatan dari source code yang dibuat.

**DILARANG KERAS MEMBUAT ULANG STACK**

## No. 3 - Queue

Selesaikan permasalahan di bawah menggunakan queue (dan stack) **(bobot: 30%)**:

Komputer Pak Dengklek memiliki berbagai macam perintah:

|Perintah|Deskripsi|
|--|--|
|PUSH 0|Memasukkan angka 0 ke atas stack|
|PUSH 1|Memasukkan angka 1 ke atas stack|
|TOP|Menampilkan angka yang berada di atas stack|
|POP|Mengeluarkan angka yang berada di atas stack|

Komputer tersebut bekerja dengan cara menerima input kemudian memasukkannya ke dalam queue, lalu dieksekusi oleh mesin dengan cara membaca isi queue tersebut. Dengan demikian, apabila komputer pak dengklek menerima perintah (urut):

- PUSH 0
- PUSH 0
- TOP
- PUSH 1
- TOP
- POP
- POP
- TOP

Maka akan menampilkan output berupa:
```
010
```

Buatlah program yang mensimulasikan permasalahan tersebut menggunakan queue (dan stack)! Anda bebas memasukkan perintah apapun ke dalam queue dan melalui manapun (melalui source code atau user input atau file input).
