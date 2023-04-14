# 2 - Map

## Konsep Map

Map (atau **pemetaan**) adalah struktur data yang *memetakan* suatu nilai ke nilai lain. Sederhananya, suatu nilai yang berada dalam dalam map berkorespondensi dengan nilai lain (bisa dengan tipe data yang berbeda).

Dalam praktiknya, map sering digunakan sebagai solusi pengganti indeks berbasis integer pada array (misalnya diganti menjadi indeks berbasis string).

Seperti halnya set, map juga umumnya direpresentasikan dalam bentuk binary search tree supaya proses menambah, menghapus, dan mencari elemen bisa dilakukan seefisien mungkin (kompleksitas O(log N)).

Dalam C++, struktur data map terletak dalam header `<map>`.

## Deklarasi

Mendeklarasikan map yang memetakan string ke suatu struct `Mahasiswa`:
```c++
std::map<std::string, Mahasiswa> data_mhs;
```

## Operasi

### Assignment

Mengaitkan mahasiswa dengan indeks **M0520047** dengan obyek dari struct pada map `data_mhs`:
```c++
Mahasiswa mhs;
mhs.nama = "Michael Raditya Krisnadhi";
mhs.prodi = "Informatika";
mhs.angkatan = 2020;
data_mhs["M0520047"] = mhs;
```

### Access

Mendapatkan obyek mahasiswa dengan indeks **M0520047** dari map `data_mhs`:
```c++
Mahasiswa mhs = data_mhs["M0520047"];
std::cout << "Nama: " << mhs.nama << std::endl;
std::cout << "Prodi: " << mhs.prodi << std::endl;
std::cout << "Angkatan: " << mhs.angkatan << std::endl;
```

Untuk memaninpulasi obyek mahasiswa dengan indeks **M0520047** dalam map `data_mhs`:
```c++
data_mhs["M0520047"].nama = "Miko";

// atau menggunakan reference:

Mahasiswa &mhs = data_mhs["M0520047"];
mhs.nama = "Miko";
```

Mengecek apakah mahasiswa dengan indeks **M0520047** berada dalam `data_mhs`:
```c++
if (data_mhs.count("M0520047") == 1) {
    std::cout << "M0520047 merupakan mahasiswa UNS" << std::endl;
} else {
    std::cout << "M0520047 bukan merupakan mahasiswa UNS" << std::endl;
}
```

### Removal

Menghapus **M0520047** dari `data_mhs`:
```c++
data_mhs.erase("M0520047");
```

### Iteration

Iterasi seluruh elemen `data_mhs`:
```c++
for (
    std::map<std::string, Mahasiswa>::iterator it = data_mhs.begin();
    it != data_mhs.end();
    ++it
) {
    std::cout << it->first << ": " << it->second.nama << std::endl;
}
```

## Selengkapnya

- [C++ Map](https://en.cppreference.com/w/cpp/container/map)
