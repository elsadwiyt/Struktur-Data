/* file : rekursif.h
   Kumpulan fungsi rekursif (Modul 10 bagian 10.1 sampai 10.4)
   beserta pembanding iteratifnya (10.3) */

#ifndef REKURSIF_H_INCLUDE
#define REKURSIF_H_INCLUDE

/* pangkat 2: f(0) = 1, f(x) = 2 * f(x-1) */
int pangkat_2(int x);

/* x pangkat y, base case y == 1 (y harus >= 1) */
int pangkat(int x, int y);

/* faktorial, mengembalikan 0 untuk bilangan negatif */
long long faktorial(long long a);

/* faktorial yang mencetak jejak masuk dan keluar tiap pemanggilan,
   level dipakai untuk jorokan, panggil dengan level = 0 */
long long faktorialTrace(long long a, int level);

/* pembanding rekursif dan iteratif */
extern long long jumlahPanggilan;     // penghitung pemanggilan fibRekursif
long long fibRekursif(int n);
long long fibIteratif(int n);
long long faktorialIteratif(long long a);

#endif
