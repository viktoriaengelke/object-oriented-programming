#include "BoolVector.h"
// не содержит повторяющихся элементов, множество содержит символы, маскимальное количество элементов = 256
class Set:public BoolVector
{
    int M; //количество элементов множества
public:
    Set();
    Set(int n); //случайные элементы
    Set(char*);
    Set(const Set&);
    Set(Set&&) noexcept;
    ~Set() {} //своих член-данных в динамич памяти нет, поэтому он пустой, чтобы вызвать деструктор в родительском классе; это виртуальный метод //virtual ~Set() override {}
    Set& operator= (const Set&); //с разными обьектами свзяывается одна и та же память => не удаляем память
    Set& operator= (Set&&);
    
    Set operator+ (char ch); //добавление ch в множество
    Set& operator+= (char ch);
    
    Set operator- (char ch); //удаление из множества
    Set& operator-= (char ch);
    
    Set operator+ (Set S); //обьединение с множеством S
    Set& operator+= (Set S);
    
    Set operator* (Set S); //пересечение с множеством S
    Set& operator*= (Set S);
    
    Set operator/ (Set S); //разность с множеством S (элементы входящие в зис, но не в эс)
    Set& operator/= (Set S);
    
    Set operator~ (); //дополнение до универсального (новое множество) - разность универсального множества и текущего
    
//    bool operator== (Set S);
//    bool operator!= (Set S);
    
    int GetNumber() { return M; } //количество элементов множества
    bool FindKey(char ch);
    
    bool Empty();
    bool NotEmpty();
    
    virtual void Scan(int);
    virtual void Print();
    
    friend ostream& operator<< (ostream& os, Set& X);
    friend istream& operator>> (istream& is, Set& X);
    
    operator int(); //перегрузка операции тип int k = обьект класса Set, возвращаем число элементов (или например букву с самым большим аски кодом)
    

};
