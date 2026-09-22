#include <iostream>
#include <string>
#include <vector>

using namespace std;

string konversiTeks(int n) {
    vector<string> satuan = {"nol", "satu", "dua", "tiga", "empat", "lima", 
                             "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas"};

    if (n < 0 || n > 100) {
        return "Angka di luar jangkauan (0 - 100)";
    }

    if (n < 12) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n % 10] + " belas";
    } else if (n < 100) {
        string hasil = satuan[n / 10] + " puluh";
        if (n % 10 != 0) {
            hasil += " " + satuan[n % 10];
        }
        return hasil;
    } else if (n == 100) {
        return "seratus";
    }
    return "";
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    cout << angka << " : " << konversiTeks(angka) << endl;

    return 0;
}