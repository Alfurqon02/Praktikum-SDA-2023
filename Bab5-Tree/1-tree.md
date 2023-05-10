# 1 - Tree

## Konsep Tree

Tree adalah sebuah struktur data abstrak (implementasinya sesuai dengan keinginan pengguna) yang merepresentasikan pohon/hirarki yang tersusun atas `node` - `node` yang saling tersambung. Untuk dianggap sebagai sebuah tree, masing-masing `node` harus memiliki tepat satu orang tua (untuk selanjutnya disebut `parent`), kecuali `root node`, atau `node` yang pertama. Setiap `node` dapat memiliki berapapun anak (untuk selanjutnya disebut `child`), termasuk 0.

Ilustrasi di bawah ini merupakan salah satu contoh struktur data Tree.

<div align="center">

![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5f/Tree_%28computer_science%29.svg/421px-Tree_%28computer_science%29.svg.png)

</div>

Kita bisa melihat bahwa root dari Tree di atas adalah node 2 yang paling atas, yang tidak memiliki `parent`

> Pertanyaan tantangan: Ada banyak jenis struktur data Tree yang mungkin memiliki peraturan yang berbeda-beda dalam pembuatan `node`nya. Apa sajakah contohnya?
Contoh implementasi dari struktur data Tree adalah direktori simbolis untuk berkas yang kalian simpan pada sistem operasi kalian. Untuk masing-masing folder, `root` adalah folder yang kalian buka, dan `children` dari root tersebut adalah semua isi dari folder yang kalian buka.

## Operasi Tree

Sebagai sebuah struktur data, Tree memiliki beberapa operasi yang dapat digunakan untuk memanipulasi data yang disimpan didalamnya. Operasi-operasi tersebut adalah `insertion`, `deletion`, dan `traversal`

Sebelum membuat operasi-operasi tersebut, kita harus membuat struktur data Tree kita terlebih dahulu, karena C++ tidak memiliki struktur Tree bawaan. Implementasi Tree dapat dilakukan dengan berbagai cara, misalkan menggunakan class dan pointer untuk menandakan hubungan. Namun, kita akan menggunakan struct untuk menyimpan data dan vector untuk menyimpan children-children dari Tree kita.

```cpp
// ...
struct Node {
    int m_data;
    vector<Node> m_children;
};
// ...
```

Kita juga dapat menambahkan constructor untuk mempermudah pemrograman kita

```cpp
// ...
Node(int data) {
    m_data = data;
}
// ...
```

Lalu, kita dapat mendefinisikan `node` - `node` yang akan kita gunakan pada main seperti di bawah ini.

```cpp
// ...
Node root(5);
Node child_0_0(3);
Node child_0_1(4);
// ...
```

### Insertion

Insertion adalah operasi yang didefinisikan sebagai aksi memasukkan nilai untuk disimpan pada sebuah Tree. Tergantung dari jenisnya, akan ada banyak aturan mengenai insertion pada Tree. Namun untuk sekarang, kita akan belajar menggunakan Tree yang sederhana.

Pada praktikum kali ini, karena `children` diimplementasikan menggunakan vector dan di-insert menggunakan pushback, maka semua insertion yang dilakukan merupakan insertion sebagai `children` yang paling kanan. Kalian dapat memodifikasi rancangan ini dengan kemampuan menyisipkan masukan di list/array.

```cpp
// ...
void insert(Node node) {
    m_children.push_back(node);
}
// ...
```

Cara penggunaan dari metode ini adalah memanggil metode insert dari node `parent` dari posisi yang kalian masukkan. Sebagai contoh, pada gambar Tree di bagian awal, jika kalian ingin memasukkan `node` 4 maka kalian memanggil metode insert dari `node` 9.

### Deletion

Operasi penghapusan pada struktur data tree dilakukan dengan cara menghapus node sesuai dengan urutan yang kita inginkan. Kita dapat membuat metode delete kita seperti di bawah ini.

```cpp
// ...
bool deleteNodeIndex(unsigned int index) {
    if (m_children.empty()) {
        return false;
    }
    else {
        if (m_children.size() <= index) {
            return false;
        }
        else {
            m_children.erase(m_children.begin() + index);
            return true;
        }
    }
}
// ...
```

Cara penggunaan metode di atas adalah dengan memanggilnya pada `parent` dari `node` yang ingin kita hapus, dan memberikan urutan `node` tersebut mulai dari 0, dihitung dari `node` yang paling kiri. Misalnya, pada contoh gambar Tree di atas, jika kita ingin menghapus `node` `4`, maka kita memanggil metode ini seperti `node_9.deleteNodeIndex(0)` karena merupakan satu-satunya `child` maka memiliki indeks 0.

Tatacara deletion pada implementasi kita di atas merupakan recursive deletion, di mana jika kalian menghapus sebuah `node` yang memiliki banyak `child`, maka semua `child` itu akan ikut terhapus.

### Traversal

Traversal dalam struktur data Tree dapat didefinisikan dengan "mengunjungi tiap-tiap `node` tepat satu kali". Ada beberapa jenis Tree traversal yang ada, seperti `postorder`, `preorder`, dan `inorder`. Kita tidak akan menggunakan `inorder` pada praktikum ini karena jenis traversal itu hanya digunakan untuk binary tree. Tree traversal `postorder` dan `preorder` memiliki pseudocode seperti di bawah ini.

```
Preorder
  1. Datangi salah satu node sebagai parent
  2. Proses node tersebut
  3. Iterasi seluruh children dari node tersebut, untuk setiap iterasi
  mengulangi langkah 1 dengan node yang sedang dijelajahi sebagai parentnya
Postorder
  1. Datangi salah satu node sebagai parent
  2. Iterasi seluruh children dari node tersebut, untuk setiap iterasi
     mengulangi langkah 1 dengan node yang sedang dijelajahi sebagai parentnya
  3. Proses node tersebut
```

> Untuk penggunaan Tree traversal secara interaktif, silakan melihat video praktikum
Kita dapat membuat metode traversal kita seperti potongan di bawah ini. Perhatikan bagaimana kita menggunakan `depth` untuk memberikan _style_ ke kode kita supaya lebih mudah dipahami hubungannya dengan `node` lainnya (apakah ancestor, sibling, atau descendant).

```cpp
// ...
void _preOrder(unsigned int depth = 0) {
    for (unsigned int i = 0; i < depth; i++) {
        cout << "--";
    }
    cout << "> " << m_data << '\n';
    for (unsigned int i = 0; i < m_children.size(); i++) {
        m_children[i]._preOrder(depth + 1);
    }
}
void preOrder() {
    cout << "Preorder Traversal: \n";
    _preOrder();
}
void _postOrder(unsigned int depth = 0) {
    for (unsigned int i = 0; i < m_children.size(); i++) {
        m_children[i]._postOrder(depth + 1);
    }
    for (unsigned int i = 0; i < depth; i++) {
        cout << "--";
    }
    cout << "> " << m_data << '\n';
}
void postOrder() {
    cout << "Postorder Traversal: \n";
    _postOrder();
}
// ...
```

## Contoh Penggunaan Library

Di sini kita akan mencoba menerapkan gambar Tree di atas dalam struktur data yang sudah kita buat. Sebagai contoh, kita hanya akan menggunakan 2 kedalaman dari gambar tersebut (hanya sampai baris 2, 10, 6, 9).

1. Pertama, kita dapat mendeklarasikan objek-objek `node` kita. Kita akan menggunakan variabel `root` untuk root dan `child_{id}` untuk penamaan children.

```cpp
// ...
Node root(2);
Node child_0(7);
Node child_1(5);
Node child_2(2);
Node child_3(10);
Node child_4(6);
Node child_5(9);
// ...
```

2. Lalu, kita dapat memasukkan child ke parentnya satu-persatu menggunakan insert.

```cpp
// ...
child_0.insert(child_2);
child_0.insert(child_3);
child_0.insert(child_4);
child_1.insert(child_5);
root.insert(child_0);
root.insert(child_1);
// ...
```

> Pertanyaan Tantangan:
>
> Mengapa kita melakukan insert dari bawah? Mengapa kita tidak melakukan insert mulai dari `root`? Apa yang terjadi jika kita melakukan insert mulai dari `root`? Mengapa hal itu bisa terjadi?
3. Setelah ini, kalian dapat menggunakan operasi lainnya seperti delete atau traversal. Mari kita coba melakukan Preorder traversal

```cpp
// Tree.cpp
// ...
root.preOrder();
// ...
```

```
Output:
Preorder Traversal:
> 2
--> 7
----> 2
----> 10
----> 6
--> 5
----> 9
Postorder Traversal:
----> 2
----> 10
----> 6
--> 7
----> 9
--> 5
> 2
```