# 2 - Konsep Stack

Stack adalah struktur data LIFO (last-in-first-out) yang artinya elemen yang dimasukkan terakhir, ialah yang pertama kali harus keluar, sama halnya dengan tumpukan buku. Perhatikan contoh ilustrasi di bawah:

![Ilustrasi](https://visualgo.net/img/stack_illustration.png)

Dalam bahasa C++, stack dapat diakses melalui header `<stack>` dan memanfaatkan linked list sebagai tempat penyimpanannya.

## 2.1. Deklarasi

Contoh:
```c++
std::stack<std::string> books;
```

## 2.2. Operasi

### Push

Memasukkan elemen ke bagian atas stack:
```c++
books.push("HTML for Babies");
```

### Top

Mengakses elemen yang berada di bagian atas stack:
```c++
std::string pick = books.top();
```

### Pop

Mengeluarkan elemen yang berada di bagian atas stack:
```c++
books.pop();
```

## Selengkapnya

- [C++ Stack](https://en.cppreference.com/w/cpp/container/stack)
