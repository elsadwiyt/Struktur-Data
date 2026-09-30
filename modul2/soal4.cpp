#include <iostream>

using namespace std;

// Prosedur (void) dengan parameter Pass by Reference menggunakan '&'
void swapDanKaliSepuluh(int &a, int &b) {
    // Proses penukaran nilai (swap) tanpa fungsi bawaan
    int temp = a;
    a = b;
    b = temp;

    // Mengalikan masing-masing nilai yang sudah ditukar dengan 10
    a *= 10;
    b *= 10;
}

int main() {
    int x, y;

    // Menerima input
    cin >> x >> y;

    // Memanggil prosedur
    swapDanKaliSepuluh(x, y);

    // Mencetak hasil akhir
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}