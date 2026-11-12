#pragma once
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
//#include <string.h>

using namespace std;

class Polinom
{
    int* a; // динамическая область памяти => конструктор копирования + конструктр перемещения
    int n; //степень многочлена
public:
    Polinom (int N = 0);
    Polinom (int* b, int m); // m -- размер массива b
    Polinom (const Polinom&);
    Polinom (Polinom&&);
    Polinom& operator= (const Polinom&);
    Polinom& operator= (Polinom&&);
    ~Polinom() {delete [] a;}
    
    T EPS(); //для специализации класса-шаблона
    
    int& operator[] (int pos);
    
    Polinom operator+ (Polinom);
    Polinom operator- (Polinom);
    Polinom operator* (int);
    
    bool operator == (Polinom);
    bool operator != (Polinom);
    
    friend ostream operator<< (ostream &r, Polinom &X);
    friend istream operator>> (istream &r, Polinom &X);
};
