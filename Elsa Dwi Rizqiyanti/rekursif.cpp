/* file : rekursif.cpp
   Implementasi fungsi-fungsi pada rekursif.h */

#include <iostream>
#include "rekursif.h"
using namespace std;

long long jumlahPanggilan = 0;

int pangkat_2(int x) {
    if (x == 0) {                  // kondisi khusus (base case)
        return 1;
    } else {                       // pemanggilan diri (recursive case)
        return 2 * pangkat_2(x - 1);
    }
}

int pangkat(int x, int y) {
    if (y == 1) {
        return x;
    } else {
        return x * pangkat(x, y - 1);
    }
}

long long faktorial(long long a) {
    if (a == 1 || a == 0) {
        return 1;
    } else if (a > 1) {
        return a * faktorial(a - 1);
    } else {
        return 0;
    }
}

/* fungsi bantu internal, hanya terlihat di file ini */
static void spasi(int n) {
    for (int i = 0; i < n; i++) cout << "   ";
}

long long faktorialTrace(long long a, int level) {
    spasi(level);
    cout << "masuk   faktorial(" << a << ")" << endl;
    long long hasil;
    if (a == 1 || a == 0) {
        hasil = 1;
    } else {
        hasil = a * faktorialTrace(a - 1, level + 1);
    }
    spasi(level);
    cout << "keluar  faktorial(" << a << ") = " << hasil << endl;
    return hasil;
}

long long fibRekursif(int n) {
    jumlahPanggilan++;
    if (n <= 1) return n;
    return fibRekursif(n - 1) + fibRekursif(n - 2);
}

long long fibIteratif(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

long long faktorialIteratif(long long a) {
    long long hasil = 1;
    for (long long i = 2; i <= a; i++) hasil *= i;
    return hasil;
}
