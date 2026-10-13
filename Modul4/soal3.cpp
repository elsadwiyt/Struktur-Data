#include <iostream>

using namespace std;

typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    return P;
}

bool isEmpty(List L) {
    return L.first == nullptr;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

int sumList(List L) {
    int total = 0;
    address temp = L.first;
    while (temp != nullptr) {
        total += temp->info;
        temp = temp->next;
    }
    return total;
}

int main() {
    int n, val;
    List L;
    createList(L);

    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> val;
            insertLast(L, alokasi(val));
        }
        cout << sumList(L) << endl;
    }
    return 0;
}