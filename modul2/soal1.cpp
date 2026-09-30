#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nilai(N);
    long long total = 0;

    for (int i = 0; i < N; i++) {
        cin >> nilai[i];
        total += nilai[i];
    }

    int rata_rata = total / N;

    int jumlah_di_atas = 0;
    for (int i = 0; i < N; i++) {
        if (nilai[i] > rata_rata) {
            jumlah_di_atas++;
        }
    }

    cout << "Rata-rata: " << rata_rata << endl;
    cout << "Di atas rata-rata: " << jumlah_di_atas << endl;

    return 0;
}