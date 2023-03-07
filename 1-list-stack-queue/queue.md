# 3 - Queue

Queue adalah struktur data FIFO (first-in-first-out) atau FCFS (first-come-first-serve) yang artinya elemen yang dimasukkan pertama, ialah yang pertama kali harus keluar, sama halnya dengan antrean. Perhatikan contoh ilustrasi di bawah:

![Ilustrasi](https://img.freepik.com/free-vector/people-waiting-queue-bank-machine_74855-4458.jpg?size=626&ext=jpg&ga=GA1.2.1411813280.1638403200)

Dalam bahasa C++, queue dapat diakses melalui header `<queue>` dan memanfaatkan linked list sebagai tempat penyimpanannya.

## 2.1. Deklarasi

Contoh:
```c++
std::queue<std::string> atm;
```

## 2.2. Operasi

### Push atau Enqueue

Memasukkan elemen ke bagian belakang antrean:
```c++
atm.push("John Nash");
```

### Front atau Head

Mengakses elemen yang berada di antrean paling depan:
```c++
std::string depan = atm.front();
```

### Back atau Tail

Mengakses elemen yang berada di antrean paling belakang:
```c++
std::string belakang = atm.back();
```

### Pop atau Dequeue

Mengeluarkan elemen yang berada di antrean paling depan:
```c++
atm.pop();
```

## Selengkapnya

- [C++ Queue](https://en.cppreference.com/w/cpp/container/queue)
