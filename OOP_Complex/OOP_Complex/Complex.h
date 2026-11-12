//#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

//#include <stdio.h>
//#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <iostream>
using namespace std;

class Complex
{
public:
    double re, im;

public:
    Complex(); //конструктор по умолчанию
    Complex(double, double);

    Complex operator+(Complex); //Complex Sum(Complex);  sum=z1+z2||sum=z1.operator+ //перегрузка операций
    Complex operator-(Complex);//Complex Dif(Complex);
    Complex operator*(Complex); //Complex Prod(Complex);
    Complex operator/(Complex);//Complex Quot(Complex);

    Complex Conj();
    double Mod();
    double Arg();

    bool operator==(Complex); //bool Equ(Complex);
    bool operator!=(Complex); //bool NotEqu(Complex);

    double GetRe();
    double GetIm();
    
    friend class MainWindow;
};

#endif          //защита от двойного подключения
