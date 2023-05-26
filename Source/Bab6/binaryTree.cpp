#include <iostream>

// Struktur data untuk merepresentasikan simpul dalam binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul baru dalam binary tree
Node* createNode(int data) {
    Node* newNode = new Node();
    if (newNode == NULL) {
        std::cout << "Pembuatan simpul gagal. Memori penuh." << std::endl;
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Contoh penggunaan binary tree
int main() {
    // Membuat simpul-simpul dalam binary tree
    Node* root = createNode(1);
    Node* child1 = createNode(2);
    Node* child2 = createNode(3);
    Node* child11 = createNode(4);
    Node* child12 = createNode(5);
    Node* child21 = createNode(6);
    Node* child22 = createNode(7);

    // Menghubungkan simpul-simpul dalam binary tree
    root->left = child1;
    root->right = child2;
    child1->left = child11;
    child1->right = child12;
    child2->left = child21;
    child2->right = child22;
    // root->right->right = child22;

    // Akses data pada simpul-simpul binary tree
    std::cout << "> " << root->data << std::endl;
    std::cout << "Root->Left: " << root->left->data << std::endl;
    std::cout << "Root->Right: " << root->right->data << std::endl;
    std::cout << "Root->Left->Left: " << root->left->left->data << std::endl;
    std::cout << "Root->Left->Right: " << root->left->right->data << std::endl;
    std::cout << "Root->Right->Left: " << root->right->left->data << std::endl;
    std::cout << "Root->Right->Right: " << root->right->right->data << std::endl;

    return 0;
}
