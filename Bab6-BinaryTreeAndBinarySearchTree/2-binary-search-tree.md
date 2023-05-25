# 2 - Binary Search Tree

## Konsep Binary Search Tree
Binary Search Tree adalah struktur data Binary Tree berbasis node yang memiliki beberapa aturan seperti berikut:

Subtree sebelah kiri dari sebuah node hanya berisi node dengan kunci (key) yang lebih kecil dari kunci node.<br>
Subtree sebelah kanan dari sebuah node hanya berisi node dengan kunci (key) lebih besar dari kunci node.<br>
Subtree sebelah kiri dan kanan masing-masing juga harus berupa pohon pencarian biner, serta tidak ada kunci yang sama.<br>

![Gambar Binary Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)

## Implementasi Binary Search Tree

### Searching
Ilustrasi untuk mencari 6 di pohon atas:
1. Mulai dari akar.
2. Bandingkan elemen pencarian dengan root, jika kurang dari root, maka panggil subtree kiri secara rekursif, jika tidak panggil subtree kanan secara rekursif.
3. Jika elemen yang dicari ditemukan di mana saja, kembalikan true, jika tidak, kembalikan false.


```cpp
// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	return root;
	
	// Key is greater than root's key
	if (root->key < key)
	return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}
```

### Insertion

Ilustrasi untuk menyisipkan 2 di bawah pohon:
1. Mulai dari akar.
2. Bandingkan elemen penyisipan dengan root, jika kurang dari root, maka panggil subtree kiri secara rekursif, jika tidak panggil subtree kanan secara rekursif.
3. Setelah mencapai akhir, masukkan saja simpul itu di kiri (jika kurang dari arus) yang lain di kanan.

![Gambar Binary Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)


```cpp
// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	// Default constructor.
	BST();

	// Parameterized constructor.
	BST(int);

	// Insert function.
	BST* Insert(BST*, int);

	// Inorder traversal.
	void Inorder(BST*);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		// Insert the first node, if root is NULL.
		return new BST(value);
	}

	// Insert data.
	if (value > root->data) {
		// Insert right node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process right nodes.
		root->right = Insert(root->right, value);
	}
	else {
		// Insert left node data, if the 'value'
		// to be inserted is greater than 'root' node data.

		// Process left nodes.
		root->left = Insert(root->left, value);
	}

	// Return 'root' node, after insertion.
	return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Inorder(root);
	return 0;
}
```

Output:
```
20
30
40
50
60
70
80
```

### Deletion

Ketika kami menghapus sebuah node, tiga kemungkinan muncul.
1) Node yang akan dihapus adalah daunnya: Cukup hapus dari pohonnya.
```
              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70 
         /  \    /  \                     \    /  \ 
       20   40  60   80                   40  60   80
```
2) Node yang akan dihapus hanya memiliki satu anak: Salin anak ke node dan hapus anak
```
              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70 
            \    /  \                          /  \ 
            40  60   80                       60   80
```
3) Node yang akan dihapus memiliki dua anak: Temukan penerus berurutan dari node tersebut. Salin konten penerus inorder ke node dan hapus penerus inorder. Perhatikan bahwa pendahulunya inorder juga dapat digunakan.
```
              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70 
                 /  \                            \ 
                60   80                           80
```
