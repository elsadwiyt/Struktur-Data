/* file : main.cpp
   Program utama demo Modul 10: memanggil rekursif.h dan bstree.h
   Compile : g++ main.cpp rekursif.cpp bstree.cpp -o tree_modular */

#include <iostream>
#include "rekursif.h"
#include "bstree.h"
using namespace std;

void demoRekursif() {
    cout << "\n##################################################" << endl;
    cout << "BAGIAN A. REKURSIF" << endl;
    cout << "##################################################" << endl;

    cout << "\n--- A1. pangkat_2 (rumus 10.1) ---" << endl;
    for (int x = 0; x <= 4; x++) {
        cout << "2^" << x << " = " << pangkat_2(x) << endl;
    }

    cout << "\n--- A2. pangkat x^y (contoh 10.4) ---" << endl;
    cout << "2^4 = " << pangkat(2, 4) << endl;
    cout << "3^3 = " << pangkat(3, 3) << endl;
    cout << "5^1 = " << pangkat(5, 1) << endl;
    cout << "Catatan: pangkat(x, 0) TIDAK aman, base case hanya y == 1" << endl;
    cout << "         sehingga y = 0 akan rekursi tanpa henti (stack overflow)" << endl;

    cout << "\n--- A3. faktorial (contoh 10.4) ---" << endl;
    for (int n = 0; n <= 6; n++) {
        cout << n << "! = " << faktorial(n) << endl;
    }
    cout << "(-3)! = " << faktorial(-3) << "  (kasus negatif, dikembalikan 0)" << endl;

    cout << "\n--- A4. trace faktorial(4): tumpukan pemanggilan ---" << endl;
    faktorialTrace(4, 0);

    cout << "\n--- A5. kekurangan rekursif (10.3) ---" << endl;
    jumlahPanggilan = 0;
    long long fr = fibRekursif(25);
    cout << "fibonacci(25) rekursif : " << fr
         << " (jumlah pemanggilan fungsi = " << jumlahPanggilan << ")" << endl;
    cout << "fibonacci(25) iteratif : " << fibIteratif(25)
         << " (satu fungsi, satu perulangan)" << endl;
    cout << "faktorial(10) iteratif : " << faktorialIteratif(10)
         << " (sama dengan rekursif: " << faktorial(10) << ")" << endl;
}

void demoBST() {
    cout << "\n##################################################" << endl;
    cout << "BAGIAN B. BINARY SEARCH TREE" << endl;
    cout << "##################################################" << endl;

    cout << "\n--- B1. Latihan 1 dan 2: insert 1,2,6,4,5,3,6,7 ---" << endl;
    address root = Nil;
    int data[] = {1, 2, 6, 4, 5, 3, 6, 7};         // angka 6 kedua = duplikat
    for (int i = 0; i < 8; i++) insertNode(root, data[i]);
    cout << "inorder     : ";
    printInorder(root);
    cout << endl;
    cout << "kedalaman   : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total       : " << hitungTotalInfo(root, 0) << endl;

    cout << "\n--- B2. Search ---" << endl;
    int cari[] = {4, 9};
    for (int i = 0; i < 2; i++) {
        address P = findNode(cari[i], root);
        if (P != Nil) cout << "findNode(" << cari[i] << ") : ketemu, info = " << P->info << endl;
        else          cout << "findNode(" << cari[i] << ") : tidak ditemukan" << endl;
    }
    hapusSemua(root);

    cout << "\n--- B3. Latihan 3: tree Gambar 10-18 (insert 6,4,7,2,5,1,3) ---" << endl;
    int data2[] = {6, 4, 7, 2, 5, 1, 3};
    for (int i = 0; i < 7; i++) insertNode(root, data2[i]);
    cout << "preorder    : ";  printPreorder(root);  cout << endl;
    cout << "inorder     : ";  printInorder(root);   cout << endl;
    cout << "postorder   : ";  printPostorder(root); cout << endl;

    cout << "\n--- B4. Most-left dan most-right ---" << endl;
    cout << "most-left  (terkecil) : " << mostLeft(root)->info << endl;
    cout << "most-right (terbesar) : " << mostRight(root)->info << endl;

    cout << "\n--- B5. Delete ---" << endl;
    cout << "awal                    : ";  printPreorder(root);  cout << "(preorder)" << endl;
    deleteNode(root, 1);
    cout << "hapus 1 (leaf)          : ";  printPreorder(root);  cout << "(preorder)" << endl;
    deleteNode(root, 2);
    cout << "hapus 2 (1 anak)        : ";  printPreorder(root);  cout << "(preorder)" << endl;
    deleteNode(root, 6);
    cout << "hapus 6 (root, 2 anak)  : ";  printPreorder(root);  cout << "(preorder)" << endl;
    cout << "inorder tetap terurut   : ";  printInorder(root);   cout << endl;

    hapusSemua(root);
}

int main() {
    int pilih;
    do {
        cout << "\n===== DEMO MODUL 10 =====" << endl;
        cout << "1. Rekursif" << endl;
        cout << "2. Binary Search Tree" << endl;
        cout << "3. Jalankan semuanya" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih : ";
        if (!(cin >> pilih)) break;

        switch (pilih) {
            case 1: demoRekursif(); break;
            case 2: demoBST(); break;
            case 3: demoRekursif(); demoBST(); break;
            case 0: cout << "Selesai." << endl; break;
            default: cout << "Pilihan tidak valid" << endl;
        }
    } while (pilih != 0);
    return 0;
}
