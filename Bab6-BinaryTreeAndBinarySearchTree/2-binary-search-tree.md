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

```cpp
// C++ program to demonstrate
// delete operation in binary
// search tree
#include <bits/stdc++.h>
using namespace std;

struct node {
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do
// inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		cout << root->key <<" ";
		inorder(root->right);
	}
}

/* A utility function to
insert a new node with given key in
* BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

// Driver Code
int main()
{
	/* Let us create following BST
		    50
		   /  \
		  30   70
		 / \   / \
	        20 40 60 80 */
	struct node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);

	cout << "Inorder traversal of the given tree \n";
	inorder(root);

	cout << "\nDelete 20\n";
	root = deleteNode(root, 20);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 30\n";
	root = deleteNode(root, 30);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	cout << "\nDelete 50\n";
	root = deleteNode(root, 50);
	cout << "Inorder traversal of the modified tree \n";
	inorder(root);

	return 0;
}

// This code is contributed by shivanisinghss2110

```

Output:
```
Inorder traversal of the given tree 
20 30 40 50 60 70 80
Delete 20
Inorder traversal of the modified tree
30 40 50 60 70 80
Delete 30
Inorder traversal of the modified tree
40 50 60 70 80
Delete 50
Inorder traversal of the modified tree
40 60 70 80
```
