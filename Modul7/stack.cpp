#include "stack.h"

// --- SOAL 1 ---
void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.top = S.top + 1;
        S.info[S.top] = x;
    } else {
        cout << "Stack Penuh!" << endl;
    }
}

infotype pop(Stack &S) {
    if (S.top > 0) {
        infotype x = S.info[S.top];
        S.top = S.top - 1;
        return x;
    } else {
        cout << "Stack Kosong!" << endl;
        return -1;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top > 0) {
        push(temp, pop(S));
    }
    S = temp;
}

// --- SOAL 2 ---
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    // Pindahkan elemen yang lebih besar dari x ke stack sementara
    while (S.top > 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    // Masukkan x ke posisi yang sesuai
    push(S, x);

    // Kembalikan elemen dari stack sementara ke S
    while (temp.top > 0) {
        push(S, pop(temp));
    }
}

// --- SOAL 3 ---
void getInputStream(Stack &S) {
    char ch;
    while (cin.get(ch) && ch != '\n') {
        if (ch >= '0' && ch <= '9') {
            push(S, ch - '0');
        }
    }
}