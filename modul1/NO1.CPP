#include <iostream>
using namespace std;
int main(){
    float a, b;

    cout << "masukan bilangan1: ";
    cin >> a; 

    cout << "masukan bilangan2: ";
    cin >> b;

    int tambah = a + b;
    int pengurangan = a - b;
    int pembagian = a / b;
    int perkalian = a * b;

    cout << "penjumlahan: " << tambah << endl;
    cout << "pengurangan: " << pengurangan << endl; 
    cout << "pembagian: " << pembagian << endl;
    cout << "perkalian: " << perkalian << endl;

    return 0;
}