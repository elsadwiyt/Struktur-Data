#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);
    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x.nopol) != NULL) {
            cout << "nomor polisi sudah terdaftar\n";
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    cout << "\n===================================\n";

    string cariNopol;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> cariNopol;
    
    address hasilCari = findElm(L, cariNopol);
    if (hasilCari != NULL) {
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan.\n";
    }

    cout << "\n===================================\n";

    string hapusNopol;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;
    
    deleteSpecific(L, hapusNopol); 

    cout << "\nDATA LIST 1\n\n";
    printInfo(L);

    return 0;
}