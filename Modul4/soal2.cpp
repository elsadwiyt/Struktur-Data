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

void insertAfter(List &L, address P, address Prec) {
    if (Prec != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printInfo(List L) {
    address temp = L.first;
    while (temp != nullptr) {
        cout << temp->info;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n, val, target, newData;
    List L;
    createList(L);

    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> val;
            insertLast(L, alokasi(val));
        }
        cin >> target;
        cin >> newData;
        
        address Prec = L.first;
        while (Prec != nullptr && Prec->info != target) {
            Prec = Prec->next;
        }
        
        if (Prec != nullptr) {
            address P = alokasi(newData);
            insertAfter(L, P, Prec);
        }
        
        printInfo(L);
    }
    return 0;
}