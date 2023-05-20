# Tugas Praktikum Set dan Map

Note:

- Kerjakan dengan bahasa C++
- Kumpulkan semua source code dengan format **Kelas_PSDA04_NIM_Nama Lengkap_Nomor Soal.cpp** dalam assignment Google Classroom **(jangan di-ZIP)**

## Nomor 1 - Set

Lengkapi source code berikut dengan mengikuti instruksinya: **(bobot: 30%)**

```c++
#include <iostream>
#include <set>

// mengecek apakah `n` adalah bilangan prima
// return: `true` jika bilangan prima, `false` jika tidak
bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::set<int> prime_numbers;

    // generate bilangan prima dari 1 sampai 100
    // dan masukkan ke dalam himpunan `prime_numbers`
    // tulis code anda di sini

    // cek bilangan prima
    std::cout << "Send Ctrl+C to exit" << std::endl;
    while (true) {
        int num;
        std::cout << "Enter a number: ";
        std::cin >> num;

        // cek apakah `num` adalah bilangan prima dari 1 dan 100
        // fungsi is_prime() memiliki kompleksitas O(N), adakah versi yang lebih baik?
        // jika ada, perbaiki kondisi dalam if di bawah
        if (is_prime(num) && (1 <= num) && (num <= 100)) {
            std::cout << num << " is a prime number between 1 and 100" << std::endl;
        } else {
            std::cout << num << " is not a prime number between 1 and 100" << std::endl;
        }
    }

    return 0;
}
```

## Nomor 2 - Map

Buatlah sebuah program dengan ketentuan dasar sebagai berikut: **(bobot: 70%)**

- Program ini merupakan program simulasi e-commerce sederhana yang memiliki database produk.
- Tiap produk memiliki kode, nama, stok, dan harga.
- Anda sebagai pelanggan memiliki saldo awal.
- Anda bisa memilih salah satu produk yang akan dibeli (berdasarkan kode) dan menginputkan jumlahnya yang akan dibeli.
- Ketika anda sudah membeli produk, kurangi stok produk dengan jumlah yang anda beli. Sesuaikan juga saldo akhir anda.

Buatlah sekreatif mungkin dalam bahasa C++ menggunakan bantuan map!