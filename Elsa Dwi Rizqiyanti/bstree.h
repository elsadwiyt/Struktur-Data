/* file : bstree.h
   ADT Binary Search Tree dengan representasi pointer (linked list)
   Modul 10 bagian 10.7 sampai 10.9 */

#ifndef BSTREE_H_INCLUDE
#define BSTREE_H_INCLUDE

#include <cstddef>

#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left, right;
};

/********* manajemen memori *********/
address alokasi(infotype x);
/* mengembalikan address node baru berisi x, left dan right = Nil */

void dealokasi(address P);
/* I.S. P terdefinisi
   F.S. memori P dikembalikan ke sistem */

/********* operasi dasar *********/
void insertNode(address &root, infotype x);
/* I.S. tree boleh kosong
   F.S. x masuk ke posisi yang sesuai aturan BST, duplikat diabaikan */

address findNode(infotype x, address root);
/* mengembalikan address node dengan info = x, Nil jika tidak ada */

void deleteNode(address &root, infotype x);
/* I.S. tree boleh kosong
   F.S. node dengan info = x dihapus, tree tetap memenuhi aturan BST */

void hapusSemua(address &root);
/* I.S. tree boleh kosong
   F.S. seluruh node di-dealokasi, root = Nil */

/********* traversal *********/
void printInorder(address root);     // kiri, root, kanan
void printPreorder(address root);    // root, kiri, kanan
void printPostorder(address root);   // kiri, kanan, root

/********* perhitungan *********/
int hitungJumlahNode(address root);
/* banyak node di dalam BST */

int hitungTotalInfo(address root, int start);
/* total info seluruh node, start = nilai awal penjumlahan (biasanya 0) */

int hitungKedalaman(address root, int start);
/* kedalaman maksimal dalam jumlah node, start = 0 (root saja bernilai 1) */

/********* most-left dan most-right *********/
address mostLeft(address root);      // node dengan nilai terkecil
address mostRight(address root);     // node dengan nilai terbesar

#endif
