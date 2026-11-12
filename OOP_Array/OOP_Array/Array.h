#ifndef ARRAY_H
#define ARRAY_H
#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Array
{
    int *arr, n, mem; //n-размер массива
    //второй вариант: int *arr, n, mem;     //mem - память, выделенная под массив
public:
//    Array(); //конструктор по умолчанию
//    Array(int N); //n-размер массива, массив заполняется нулями
//    Array(int N, int t); //если t == 0, массив заполняется нулями, если t!= 0, массив заполняется случайными числами
//    
    //Можно заменить 3 конструктора одним:
    Array(int n = 1, int t = 0); //с параметром mem-ничего не передаем, выделаем память в два раза больше,чем реальный размер массива
    Array(int* a, int N);
    
    Array(const Array&); //конструктор копирования => обязательно деструктор, перегрузка оператора присвоения
    ~Array(); //деструктор
    Array& operator= (const Array&); // перегрузка оператора присвоения
    
    Array (Array&&) noexcept; //конструктор перемещения noexept - говорим компилятору, что все нормально
    Array& operator= (Array&&) noexcept; //оператор присвоения по перемещению
    
    void Set(int m); //ввод массива из m чисел с клавиатуры
    void Print(); //вывод массива на консоль
    
    int& operator[] (int pos); //возвращаем элемент на позиции pos
    int FindKey(int key); //возвращаем позицию первого вхождения key или -1, если key в массиве нет
    
    Array operator+ (int key); //добавление элемента в конец массива (создается новый объект)
    Array& operator+= (int key); //изменение существующего объекта
    
    Array operator+ (Array A); //добавление целого массива в конец массива (создается новый объект)
    Array& operator+= (Array A); //изменение существующего объекта
    
    Array operator- (int key); //удаляется первое вхождение key (создается новый объект), если key не было в массиве - не изменять массив (создать копию)
    Array& operator-= (int key); //изменение существующего объекта
    
    Array DelPosNew(int pos); //удаление обьекта на позиции в новом массиве
    Array& DelPosEq(int pos); //изменить массив (может понадобиться функция сдвига влево ShiftLeft и уменьшение размера массива, можно написать в privat, тк она не работет с обьектом)
    
    bool operator== (Array A);
    bool operator!= (Array A); //перегрузка операторов сравнения
    
    int Max(); //нахождение первой позиции максимума
    int Min(); //нахождение первой позиции минимума
    
    void Sorting(); //сортировка массива
    
    int Size();
    Array operator^(int p);

    friend ostream& operator<< (ostream& r, Array& x); //обьявление дружественного метода вывода. вместо print
    friend istream& operator>> (istream& r, Array& x); //обьявление дружественного метода ввода
    
};
#endif
