#include "List.h"

List::List()
{
    head = new Node(-1);
    tail = new Node(-1, head);
    head->next = tail; //возможно сделать, так как List - друг для Node
    // head->GetNext() = tail;
}
// 1-й способ:
List::List(int n)
{
    head = new Node(-1);
    tail = new Node(-1, head);
    head->next = tail;
    for (int i = 0; i<n; i++)
    {
        int x = rand()%100;
        AddToTail(x);
    }
}
/* 2-й способ:
 List::List(int n): List() //конструктор по умолчанию - дилигирующий конструктор, сам не инициализирует член-данные
 {
     for (int i = 0; i<n; i++)
     {
         int x = rand()%100;
         AddToTail(x);
     }
 }
 */
List::List(int* arr, int n): List()
{
    if (n<=0 || arr == nullptr)
        cout<<"incorrect data"<<endl;
    else
        for (int i = 0; i<n; i++)
            AddToTail(arr[i]);
}
List::List(const List& X): List()
{
    Node* t = X.head->next; //следующий за головой
    while (t != X.tail)
    {
        AddToTail(t->key);
        t = t->next;
    }
}
List::List(List&& X) noexcept: List()
{
    if (X.head->next != X.tail)
    { head->next = X.head->next;
        X.head->next->prev = head;
        
        tail->prev = X.tail->prev;
        X.tail->prev->next = tail;
        
        X.head->next = X.tail;
        X.tail->prev = X.head;
    }
}
List::~List()
{
    Clear();
    delete head;
    delete tail;
}
List& List::operator= (const List& X)
{
    if (this == &X) return *this;
    (*this).Clear();
    Node* t = X.head->next;
    while (t != X.tail)
    {
        AddToTail(t->key);
        t = t->next;
    }
    return *this;
}
List& List::operator= (List&& X) noexcept
{
    if (this == &X) return *this;
    (*this).Clear();
    if (X.head->next != X.tail) 
        {
            head->next = X.head->next;
            X.head->next->prev = head;

            tail->prev = X.tail->prev;
            X.tail->prev->next = tail;
        }
        else
        {
            head->next = tail;
            tail->prev = head;
        }
    X.head->next = X.tail;
    X.tail->prev = X.head;
    return *this;
}
void List::AddAfter(int k, Node* pr)
{
    if (pr == nullptr)
    {
        cout<<"error! incorrect input data"<<endl;
        return;
    }
    Node* t = new Node(k, pr, pr->next);
    pr->next = t;
    t->next->prev = t;
}
void List::AddToTail(int k)
{
    AddAfter(k, tail->prev); //this->AddAfter(k, tail->prev);
}
void List::AddToHead(int k)
{
    AddAfter(k, head);
}
void List::AddToHead(List X)
{
    Node* t = X.tail->prev;
    while (t!= X.head)
    {
        AddToHead(t->key);
        t = t->prev;
    }
}
void List::AddToTail(List X)
{
    Node* t = X.head->next;
    while (t!= X.tail)
    {
        AddToTail(t->key);
        t = t->next;
    }
}
void List::Del(Node* p)
{
    if (p == nullptr)
    {
        cout<<"error! incorrect input data"<<endl;
        return;
    }
    if (p == head || p == tail)
        return;
    Node* p1 = p->prev;
    Node* p2 = p->next;
    p1->next = p2;
    p2->prev = p1; //узел существует, но из списка мы его исключили
    
    delete p;
    p = nullptr;
}
void List::DelTail()
{
    Del(tail->prev);
}
void List::DelHead()
{
    Del(head->next);
}
Node* List::FindKey (int key)
{
    Node* t = head->next;
    while (t != tail)
    {
        if (t->key == key)
            return t;
        t = t->next;
    }
    return nullptr;
}
Node* List::FindPos (int pos)
{
    Node* t = head->next;
    int i = 0;
    while (t != tail && i < pos)
    {
        t = t->next;
        i++;
    }
    if (t == tail) return nullptr;
    return t;
}
bool List::Empty()
{
    if (head->next == tail) return true;
    return false;
}
bool List::NotEmpty()
{
    if (head->next != tail) return true;
    return false;
}
void List::Clear()
{
    Node* t = head->next;
    while (t != tail)
    {
        Node* next = t->next;
        Del(t);
        t = next;
    }
}
bool List::operator == (List X)
{
    Node* t = head->next;
    Node* m = X.head->next;
    while (t != tail && m != X.tail)
    {
        if (t->key != m->key) return false;
        t = t->next;
        m = m->next;
    }
    if (t == tail && m == X.tail) return true;
    return false;
}
bool List::operator != (List X)
{
    if ((*this) == X) return false;
    return true;
}
Node* List::Max()
{
    Node* M = nullptr;
    if (head->next == tail) return M;
    M = head->next;
    Node* t = M->next;
    while (t != tail)
    {
        if (t->key > M->key) M = t;
        t = t->next;
    }
    return M;
}
Node* List::Min()
{
    Node* M = nullptr;
    if (head->next == tail) return M;
    M = head->next;
    Node* t = M->next;
    while (t != tail)
    {
        if (t->key < M->key) M = t;
        t = t->next;
    }
    return M;
}
void List::Sort()
{
    List Res;
    while (head->next!=tail)
    {
        Node *t = (*this).Min();
        Res.AddToTail(t->key);
        Del(t);
    }
    *this = Res;
}
void List::Scan(int n)
{
    Clear();
    int y;
    cout<<"enter "<<n<<" elements of the list: ";
    for (int i = 0; i<n; i++)
    {
        cin>>y;
        AddToTail(y);
    }
}
void List::Print()
{
    Node *t = head->next;
    while (t != tail)
    {
        cout<<t->key<<" ";
        t = t->next;
    }
}
istream& operator>> (istream& is, List& X)
{
    X.Clear();
    int n, y;
    cout<<"enter the length of the list: ";
    is>>n;
    cout<<"enter "<<n<<" elements of the list: ";
    for (int i = 0; i<n; i++)
    {
        is>>y;
        X.AddToTail(y);
    }
    return is;
}
ostream& operator<< (ostream& os, List& X)
{
    X.Print();
    return os;
}
