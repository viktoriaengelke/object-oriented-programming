#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <float.h>
using namespace std;

template <class T> class Array
{
    T *arr;
    int n, mem; //n-размер массива
    //второй вариант: int *arr, n, mem;     //mem - память, выделенная под массив
public:
//    Array(); //конструктор по умолчанию
//    Array(int N); //n-размер массива, массив заполняется нулями
//    Array(int N, int t); //если t == 0, массив заполняется нулями, если t!= 0, массив заполняется случайными числами
//
    //Можно заменить 3 конструктора одним:
    Array(int n = 1, int t = 0); //с параметром mem-ничего не передаем, выделаем память в два раза больше,чем реальный размер массива
    Array(T* a, int N);
    
    Array(const Array&); //конструктор копирования => обязательно деструктор, перегрузка оператора присвоения
    ~Array(); //деструктор
    Array<T>& operator= (const Array<T>&); // перегрузка оператора присвоения
    
    Array (Array<T>&&) noexcept; //конструктор перемещения noexept - говорим компилятору, что все нормально
    Array<T>& operator= (Array<T>&&) noexcept; //оператор присвоения по перемещению
    
    void Set(int m); //ввод массива из m чисел с клавиатуры
    void Print(); //вывод массива на консоль
    
    T& operator[] (int pos); //возвращаем элемент на позиции pos
    int FindKey(T key); //возвращаем позицию первого вхождения key или -1, если key в массиве нет
    
    Array<T> operator+ (T key); //добавление элемента в конец массива (создается новый объект)
    Array<T>& operator+= (T key); //изменение существующего объекта
    
    Array<T> operator+ (Array<T> A); //добавление целого массива в конец массива (создается новый объект)
    Array<T>& operator+= (Array<T> A); //изменение существующего объекта
    
    Array<T> operator- (T key); //удаляется первое вхождение key (создается новый объект), если key не было в массиве - не изменять массив (создать копию)
    Array<T>& operator-= (T key); //изменение существующего объекта
    
    Array<T> DelPosNew(int pos); //удаление обьекта на позиции в новом массиве
    Array<T>& DelPosEq(int pos); //изменить массив (может понадобиться функция сдвига влево ShiftLeft и уменьшение размера массива, можно написать в privat, тк она не работет с обьектом)
    
    T EPS();
    
    bool operator== (Array<T> A);
    bool operator!= (Array<T> A); //перегрузка операторов сравнения
    
    int Max(); //нахождение первой позиции максимума
    int Min(); //нахождение первой позиции минимума
    
    void Sorting(); //сортировка массива
    
    int Size();
    
    template <typename U>
    friend ostream& operator<< (ostream& r, Array<U>& x); //обьявление дружественного метода вывода. вместо print
    template <typename U>
    friend istream& operator>> (istream& r, Array<U>& x); //обьявление дружественного метода ввода
    
};

#include "Array.inl"

