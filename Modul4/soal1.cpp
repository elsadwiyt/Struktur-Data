#include <iostream>
#include <string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

void insertLast(Node*& head, string nama) {
    Node* newNode = new Node{nama, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFirst(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    cout << "Melayani: " << temp->nama << endl;
    head = head->next;
    delete temp;
}

void tampilkanAntrean(Node* head) {
    if (head == nullptr) {
        cout << "Antrean kosong" << endl;
        return;
    }
    cout << "Antrean: ";
    while (head != nullptr) {
        cout << head->nama;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int pilihan;
    string nama;

    while (cin >> pilihan && pilihan != 3) {
        if (pilihan == 1) {
            cin >> nama;
            insertLast(head, nama);
            tampilkanAntrean(head);
        } else if (pilihan == 2) {
            deleteFirst(head);
            tampilkanAntrean(head);
        }
    }
    return 0;
}