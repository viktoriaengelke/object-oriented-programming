#pragma once
#include <iostream>
using namespace std;

class Node
{
    int key;
    Node *left, *right;
    Node *parent; //узел знает кто его родитель
public:
    Node(int k = 0, Node *L = NULL, Node *R = NULL, Node *P = NULL): key(k), left(L), right(R), parent(P) {};
    int GetKey() {return key;}
    friend class BinTree;
    friend class SBinTree;
};

class BinTree
{
protected:
    Node *root; //указатель на корень дерева
    Node* Tree(int n, Node *p); //создает случайное идеально сбалансированное (количество вершин в левом и правом поддереве на любом уровне различается не больше чем на 1) дерево из n узлов, p - узел к которому крепится дерево (предок дерева)
    void Copy(Node *q, Node *p, int k); //копирование дерева с корнем q, p - предок корня нового дерева, k = 0 - копируем как левого потомка, k = 1 - копируем как правого потомка
public:
    BinTree() {root = NULL;}
    BinTree(int n); //создание случайного дерева из n узлов
    BinTree(int *a, int n); //создание дерева из массива
    BinTree(const BinTree& X) noexcept;//констурктор копирования
    BinTree(BinTree&& X) noexcept;
    virtual ~BinTree();
    BinTree& operator= (BinTree&) noexcept;
    BinTree& operator= (BinTree&&) noexcept;
    
    virtual void Add(int k, Node* p); //p - корень дерева (поддерева), в которое добавляем узел, но необязательного именно в него
    virtual void Del(Node *p); //удаление узла p
    virtual void DelRoot();
    
    //обходы в глубину
    void TreeTraversal_LCR(Node *p, int* a, int &n); //обход лево-корень-право
    void TreeTraversal_LRC(Node *p, int* a, int &n); //обход лево-право-корень
    void TreeTraversal_RLC(Node *p, int* a, int &n); //обход право-лево-корень
    //обход в ширину через очередь - выводим узел - потомков в очередь, делаем пока очередь не опустеет
    void WidthTraversal(Node *p, int* a, int &n);
    
    /* второй более простой вараинт - вывод ключей не в массив, а на консоль
     //обходы в глубину
     void TreeTraversal_LCR(Node *p); //обход лево-корень-право
     void TreeTraversal_LRC(Node *p); //обход лево-право-корень
     void TreeTraversal_RLC(Node *p); //обход право-лево-корень
     //обход в ширину
     void WidthTraversal(Node *p);
     */
    
    virtual Node* FindKey(Node *p, int k); //нахождение ключа
    virtual Node* FindMax(Node *p); //нахождение максимума
    virtual Node* FindMin(Node *p);
    int FindHight(Node *p); //поиск высоты дерева с корнем p
    int Count(Node *p); //количество узлов
    
    void PrintTree(int k, Node *p); //k - отступ от левой границы консоли
    void Clear(); //уничтожает все дерево кроме корня
    Node* GetRoot() {return root;}
};
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    

