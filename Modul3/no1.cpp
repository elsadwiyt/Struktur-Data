#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) {
        cout << "Jumlah maksimal adalah 10!\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << ":\n";
        cout << "Nama        : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM         : ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS   : ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS   : ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas : ";
        cin >> mhs[i].tugas;

        mhs[i].nilai_akhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n================ DATA MAHASISWA ================\n";
    for (int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i + 1 << ": " << mhs[i].nama 
             << " | NIM: " << mhs[i].nim 
             << " | Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }

    return 0;
}