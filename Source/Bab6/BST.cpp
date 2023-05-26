#include <iostream>

// Struktur data untuk merepresentasikan simpul dalam BST
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul baru dalam BST
Node* createNode(int data) {
    Node* newNode = new Node();
    if (newNode == nullptr) {
        std::cout << "Pembuatan simpul gagal. Memori penuh." << std::endl;
        return nullptr;
    }
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Fungsi untuk memasukkan nilai ke dalam BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk mencetak BST secara inorder (urutan menaik)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Contoh penggunaan Binary Search Tree
int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Traversal inorder BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
