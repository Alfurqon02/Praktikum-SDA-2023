#include <iostream>
#include <map>

int main() {
    struct Mahasiswa {
        std::string nama;
        std::string prodi;
        int angkatan;
    };

    std::map<std::string, Mahasiswa> data_mhs;
    Mahasiswa mhs;
    mhs.nama = "Bella Aster Kevia";
    mhs.prodi = "Informatika";
    mhs.angkatan = 2025;
    data_mhs["M0525025"] = mhs;

    data_mhs["M0525025"].nama = "Afan";
    mhs = data_mhs["M0525025"];
    // std::cout << "Nama: " << mhs.nama << std::endl;
    // std::cout << "Prodi: " << mhs.prodi << std::endl;
    // std::cout << "Angkatan: " << mhs.angkatan << std::endl;

    // if (data_mhs.count("M0525025") == 0) {
    //     std::cout << "M0525025 bukan merupakan mahasiswa UNS" << std::endl;
    // } else {
    //     std::cout << "M0525025 merupakan mahasiswa UNS" << std::endl;
    // }

    // data_mhs.erase("M0525025");
    // mhs = data_mhs["M0525025"];
    // std::cout << "Nama: " << mhs.nama << std::endl;
    // std::cout << "Prodi: " << mhs.prodi << std::endl;
    // std::cout << "Angkatan: " << mhs.angkatan << std::endl;

    for (
        std::map<std::string, Mahasiswa>::iterator it = data_mhs.begin();
        it != data_mhs.end();
        ++it
    ) {
        std::cout << it->first << ": " << it->second.prodi << std::endl;
    }

    // std::map<std::string, int> map = {
    //     ("pertama", 10),
    //     ("kedua", 20),
    //     ("ketiga", 30)
    // };

    // std::cout<<map("satu");
}