#include <iostream>
#include <string>

using namespace std;

int hitungKemunculanKarakter(string kata, char cari) {
    int jumlah = 0;
    for (int i = 0; i < kata.length(); i++) {
        if (kata[i] == cari) {
            jumlah++;
        }
    }
    return jumlah;
}

int main() {
    string kata;
    char karakter;

    cin >> kata;
    cin >> karakter;

    int hasil = hitungKemunculanKarakter(kata, karakter);
    cout << hasil << endl;

    return 0;
}