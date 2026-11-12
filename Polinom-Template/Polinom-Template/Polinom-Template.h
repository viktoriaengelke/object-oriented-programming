#pragma once
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <string.h>

using namespace std;

template <class T>
{
    T* a;
    int n;
public:
    Polinom (int N = 0);
    Polinom (T* b, int m);
    Polinom (const Polinom<T>&);
    Polinom (Polinom<T>&&);
    Polinom<T>& operator= (const Polinom<T>&);
    Polinom<T>& operator= (Polinom<T>&&);
    ~Polinom() {delete [] a;}
    
    T& operator[] (int pos);
    
    Polinom<T> operator+ (Polinom<T>);
    Polinom<T> operator- (Polinom<T>);
    Polinom<T> operator* (T);
    
    bool operator == (Polinom<T>);
    bool operator != (Polinom<T>);
    
    template <class T>
    friend ostream operator<< (ostream &r, Polinom<T> &X);
    
    template <class T>
    friend istream operator>> (istream &r, Polinom<T> &X);
};

#include "Polinom.inl" 

