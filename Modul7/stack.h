#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

// Primitif Soal 1
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

// Primitif Soal 2
void pushAscending(Stack &S, infotype x);

// Primitif Soal 3
void getInputStream(Stack &S);

#endif // STACK_H_INCLUDED