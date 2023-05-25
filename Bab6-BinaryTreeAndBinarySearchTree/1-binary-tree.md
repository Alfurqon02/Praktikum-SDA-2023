# 1 - Binary Tree

## Konsep Binary Tree
Tree merupakan struktur data yang biasanya tidak kontinu, dimana sebuah node bisa memiliki beberapa "anak" (child node), dan berbeda dengan Graph, jalan menuju sebuah child node hanya bisa dicapai melalui maksimal 1 node, dimana pada Graph, dimungkinkan bahwa 1 node bisa dicapai dari banyak node lainnya. Sebuah node yang tidak memiliki child node sama sekali dinamakan leaf node.

Jenis Tree yang paling umum digunakan adalah Binary Tree, yang sebenarnya memiliki konsep yang sama dengan Tree pada umumnya. Namun bedanya, Binary Tree memiliki jumlah maksimal 2 child, yang secara spesifik dapat disebut left child dan right child.  
  
![Gambar Binary Tree](https://www.geeksforgeeks.org/wp-content/uploads/binary-tree-to-DLL.png)

## Implementasi Binary Tree

Sebuah node Binary Tree berisi bagian-bagian berikut.

1. Data
2. Pointer ke anak kiri
3. Pointer ke anak kanan

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	// Val is the key or the value that
	// has to be added to the data part
	Node(int val)
	{
		data = val;

		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
};

int main()
{

	/*create root*/
	Node* root = new Node(1);
	/* following is the tree after above statement

		    1
		   / \
		NULL NULL
	*/

	root->left = new Node(2);
	root->right = new Node(3);
	/* 2 and 3 become left and right children of 1
				 1
			        / \
			     2	     3
			    / \	     / \
			NULL NULL NULL NULL
	*/

	root->left->left = new Node(4);
	/* 4 becomes left child of 2
		     1
		    / \
		  2	3
		/ \    / \
	      4 NULL NULL NULL
		/ \
	     NULL NULL
	*/

	return 0;
}

```

### Insertion
Idenya adalah untuk melakukan traversal urutan level iteratif dari pohon yang diberikan menggunakan queue. Jika kita menemukan sebuah node yang anak kirinya kosong, kita membuat kunci baru sebagai anak kiri dari node tersebut. Lain jika kita menemukan node yang anak kanannya kosong, kita membuat kunci baru sebagai anak kanan. terus sampai kita menemukan simpul yang anak kiri atau kanannya kosong.  

![Gambar Binary Tree](https://media.geeksforgeeks.org/wp-content/uploads/binary-tree-insertion.png)

```cpp
// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node {
	int data;
	Node* left;
	Node* right;
};

/* Function to create a new node */

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

/* Function to insert element in binary tree */

Node* InsertNode(Node* root, int data)
{
	// If the tree is empty, assign new node address to root
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}

	// Else, do level order traversal until we find an empty
	// place, i.e. either left child or right child of some
	// node is pointing to NULL.
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}

/* Inorder traversal of a binary tree */

void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

// Driver code
int main()
{
	Node* root = CreateNode(10);
	root->left = CreateNode(11);
	root->left->left = CreateNode(7);
	root->right = CreateNode(9);
	root->right->left = CreateNode(15);
	root->right->right = CreateNode(8);

	cout << "Inorder traversal before insertion: ";
	inorder(root);
	cout << endl;

	int key = 12;
	root = InsertNode(root, key);

	cout << "Inorder traversal after insertion: ";
	inorder(root);
	cout << endl;

	return 0;
}

```

Output:
```
Inorder traversal before insertion: 7 11 10 15 9 8 
Inorder traversal after insertion: 7 11 12 10 15 9 8 
```

### Deletion

Algoritma
1. Mulai dari root, temukan node paling dalam dan paling kanan di binary tree dan node yang ingin kita hapus.
2. Ganti data node paling kanan paling dalam dengan node yang akan dihapus.
3. Kemudian hapus node paling kanan paling dalam.  

![Gambar Binary Tree](https://media.geeksforgeeks.org/wp-content/uploads/deletion-in-binary-tree.png)


```cpp
// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int key;
	struct Node *left, *right;
};

/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node* root,
				struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);

	// Do level order traversal until last node
	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;
	struct Node* key_node = NULL;

	// Do level order traversal to find deepest
	// node(temp) and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deletDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}

// Driver code
int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 11;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);

	return 0;
}

```

Output:
```
Inorder traversal before deletion : 7 11 12 10 15 9 8 
Inorder traversal after deletion : 7 8 12 10 15 9 
```
