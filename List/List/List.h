#pragma once
//#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class List; //упреждающее обьявление класса (чтобы компилятор нашел класс)

class Node //узел
{
    int key;
    Node *prev, *next; //указатели на предыдущий и следующий узлы
public:
    Node(int k = 0, Node* P = nullptr, Node* N = nullptr)
    {
        key = k;
        prev = P;
        next = N;
    }
    int& GetKey() {return key;}
    Node*& GetPrev() {return prev;} //ссылка на указатель - возможность изменения
    Node*& GetNext() {return next;}
    
    friend class List;
};

class List
{
    Node* head;
    Node* tail;
public:
    List();
    List(int n); //создает список из n реальных узлов (случайные числа)
    List(int* arr, int n); //список из массива
    List(const List&); //список в динамической области памяти => конструктор копирования
    List(List&&) noexcept;
    ~List();
    List& operator= (const List&);
    List& operator= (List&&) noexcept;
    
    void AddAfter(int k, Node* pr); //добавление узла после узла pr
    void AddToHead(int k); //добавление узла в голову
    void AddToTail(int k); //добавление узла в хвост
    
    void AddToHead(List); //добавление списка в голову
    void AddToTail(List); //добавление списка в хвост
    
    void Del(Node* p); //удаление узла по указателю p
    void DelHead();
    void DelTail();
    
    Node* FindKey(int k);
    Node* FindPos(int pos); 
    
    int Count(); //считаем количество узлов
    
    bool Empty();
    bool NotEmpty();
    
    void Clear(); //удаляет реальный список
    
    bool operator== (List); //узлы с одинаковыми данными в одинаковом порядке (равные длины)
    bool operator!= (List);
    
    Node* Max();
    Node* Min();
    
    void Sort(); //запускаем min, создаем новый список, помещаем туда min, удаляем из старого и тд пока в списке не остались только фикт голова и хвост, потом this = этот список
    void Scan(int n);
    void Print();
    friend ostream& operator<< (ostream& os, List& X);
    friend istream& operator>> (istream& is, List& X);
};
