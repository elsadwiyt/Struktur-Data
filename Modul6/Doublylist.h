#ifndef DOUBLYLIST_H_INCLUDED
#define DOUBLYLIST_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct infotype {
    string nopol, warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next, prev;
};

struct List {
    address First, Last;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
address findElm(List L, string nopol);
void insertLast(List &L, address P);
void printInfo(List L);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address &Prec, address &P);
void deleteSpecific(List &L, string nopol);

#endif