#include <iostream>

using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void tukarPosisiArray(int arr1[3][3], int arr2[3][3], int r, int c) {
    int *p1 = &arr1[r][c];
    int *p2 = &arr2[r][c];
    tukarPointer(p1, p2);
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "=== Array A awal ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B awal ===" << endl;
    tampilArray(B);

    tukarPosisiArray(A, B, 1, 1);

    cout << "\n>>> Setelah penukaran posisi [1][1] <<<" << endl;
    cout << "\n=== Array A ===" << endl;
    tampilArray(A);
    cout << "\n=== Array B ===" << endl;
    tampilArray(B);

    return 0;
}