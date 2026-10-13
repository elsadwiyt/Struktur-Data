#include <iostream>
#include <string>
using namespace std;

struct Buku { string judul; Buku* next; };   // judul sudah termasuk tahun
Buku* head = nullptr;

void insertLast(string j) {
    Buku* b = new Buku{j, nullptr};
    if (!head) { head = b; return; }
    Buku* c = head;
    while (c->next) c = c->next;
    c->next = b;
}

void deleteLast() {
    if (!head) return;
    if (!head->next) { delete head; head = nullptr; return; }
    Buku* c = head;
    while (c->next->next) c = c->next;
    delete c->next;
    c->next = nullptr;
}

int main() {
    string s;
    while (getline(cin, s) && !s.empty()) {      
        size_t p = s.find_last_of(' ');
        insertLast(s.substr(0, p) + " (" + s.substr(p + 1) + ")");
    }
    deleteLast();
    cout << "Daftar Buku:" << endl;
    for (Buku* c = head; c; c = c->next) cout << c->judul << endl;
}