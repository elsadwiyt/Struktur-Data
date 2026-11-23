/* file : bstree.cpp
   Implementasi ADT Binary Search Tree pada bstree.h */

#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil) {                    // base case: tempat kosong ketemu
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    /* x sama dengan info: tidak dimasukkan lagi */
}

address findNode(infotype x, address root) {
    if (root == Nil || root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

address mostLeft(address root) {
    if (root == Nil) return Nil;
    while (root->left != Nil) root = root->left;
    return root;
}

address mostRight(address root) {
    if (root == Nil) return Nil;
    while (root->right != Nil) root = root->right;
    return root;
}

void deleteNode(address &root, infotype x) {
    if (root == Nil) return;
    if (x < root->info) {
        deleteNode(root->left, x);
    } else if (x > root->info) {
        deleteNode(root->right, x);
    } else {
        if (root->left == Nil && root->right == Nil) {
            dealokasi(root);              // kasus 1: leaf
            root = Nil;
        } else if (root->left == Nil) {
            address P = root;             // kasus 2: hanya anak kanan
            root = root->right;
            dealokasi(P);
        } else if (root->right == Nil) {
            address P = root;             // kasus 2: hanya anak kiri
            root = root->left;
            dealokasi(P);
        } else {
            address P = mostLeft(root->right);   // kasus 3: dua anak
            root->info = P->info;
            deleteNode(root->right, P->info);
        }
    }
}

void hapusSemua(address &root) {
    if (root != Nil) {
        hapusSemua(root->left);
        hapusSemua(root->right);
        dealokasi(root);
        root = Nil;
    }
}

void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void printPreorder(address root) {
    if (root != Nil) {
        cout << root->info << " - ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

void printPostorder(address root) {
    if (root != Nil) {
        printPostorder(root->left);
        printPostorder(root->right);
        cout << root->info << " - ";
    }
}

int hitungJumlahNode(address root) {
    if (root == Nil) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root, int start) {
    if (root == Nil) return start;
    start = start + root->info;
    start = hitungTotalInfo(root->left, start);
    start = hitungTotalInfo(root->right, start);
    return start;
}

int hitungKedalaman(address root, int start) {
    if (root == Nil) return start;
    int kiri  = hitungKedalaman(root->left,  start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}
