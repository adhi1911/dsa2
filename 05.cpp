#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool lBit;
    bool rBit;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    newNode->lBit = newNode->rBit = 1; // Initialize as threads
    return newNode;
}

void preorderThread(Node* curr, Node*& prev) {
    if (curr == nullptr)
        return;

    if (prev != nullptr) {
        prev->right = curr;
        prev->rBit = 0; // Right pointer is not a thread
    }

    if (curr->left == nullptr) {
        curr->left = prev; // Left pointer is a thread
        curr->lBit = 0;
    } else {
        curr->lBit = 1; // Left pointer is not a thread
    }

    prev = curr;

    if (curr->lBit == 1)
        preorderThread(curr->left, prev);
    if (curr->right != nullptr)
        preorderThread(curr->right, prev);
}

void preorderTraversal(Node* root) {
    Node* curr = root;
    while (curr) {
        cout << curr->data << " ";

        if (curr->lBit == 1)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    Node* prev = nullptr;
    preorderThread(root, prev);

    cout << "Preorder Traversal: ";
    preorderTraversal(root);

    return 0;
}