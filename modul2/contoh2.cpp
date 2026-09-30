#include <iostream>
using namespace std;

// int main(){
//     char amessage[] = "now is the time";
//     char *pmessage = "now is the time";

//     amessage[0] = 'N';
//     cout << "Isi setelah diubah: " << amessage << endl;

//     pmessage = "waktu telah tiba";
//     cout << "isi pmessage setelah diubah: " << pmessage << endl;

//     return 0;
// }

//FUNGSI(HANYA PUNYA RETURN VALUE)
int maks3(int a, int b, int c) {
    int temp_max = a;
    if(b > temp_max) {
        temp_max = b;
    }
    if(c > temp_max) {
        temp_max = c;
    }
    return temp_max;
}

//PROSEDUR (PAKAI VOID, TIDAK PUNYA RETURN VALUE)
void tulis(int x) {
    for (int i = 0; i < x; i++) {
        cout << "baris ke-" << i+1 << endl;
    }
}

int main() {
    int hasil_maks = maks3(10, 50, 30);
    //memanggil fungsi, nilainya disimpan ke variabel
    cout << "nilai maksimumnya adalah = " << hasil_maks <<endl;

    //memanggil prosedur, langsung jalanin perintahnya
    cout << "memanggil prosedur: " << endl;
    tulis(3);

    return 0;
}