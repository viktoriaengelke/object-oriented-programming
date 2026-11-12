#include "Set.h"

Set::Set(): BoolVector(256)  { M = 0;}

Set::Set(int n): BoolVector(256)
{
    char x;
    M = 0;
    for (int i = 0; M < n; i++)
    {
        x = rand()%256;
        SetUp1((UC)x);
        M = Weight();
    }
}
Set::Set(char* s): BoolVector(256)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        SetUp1((UC)s[i]);
    M = Weight();
}
Set::Set(const Set& S): BoolVector(S) {M = S.M;} //преобразование по умолчанию

Set::Set(Set&& S) noexcept: BoolVector(S) {M = S.M;} //вызывается перемещающий конструктор
Set& Set::operator=(const Set& S)
{
    if (this != &S)
    {
        BoolVector::operator=(S);
        M = S.M;
    }
    return *this;
}
Set& Set::operator= (Set&& S)
{
    if (this != &S)
    {
        BoolVector::operator=(S);
        M = S.M;
        S.M = 0;
    }
    return *this;
}
Set Set::operator+ (char ch)
{
    Set Res = *this;
    Res.SetUp1((UC)ch);
    Res.M = Res.Weight();
    return Res;
}
Set& Set::operator+= (char ch)
{
    SetUp1((UC)ch);
    M = Weight();
    return *this;
}
Set Set::operator+ (Set S)
{
    Set Res = *this;
    Res |= S;
    Res.M = Res.Weight();
    return Res;
}
Set& Set::operator+= (Set S)
{
    (*this) = (*this) + S;
    M = Weight();
    return *this;
}
Set Set::operator- (char ch)
{
    Set Res = *this;
    Res.SetUp0((UC)ch);
    Res.M = Res.Weight();
    return Res;
}
Set& Set::operator-= (char ch)
{
    (*this) = (*this) - ch;
    M = Weight();
    return *this;
}
Set Set::operator/ (Set S)
{
    Set Res = *this;
    Set Cross = (*this)*S;
    Res ^= Cross;
    Res.M = Res.Weight();
    return Res;
}
Set& Set::operator/= (Set S)
{
    (*this) = (*this)/S;
    M = Weight();
    return *this;
}
Set Set::operator* (Set S)
{
    Set Res = *this;
    Res &= S;
    Res.M = Res.Weight();
    return Res;
}
Set& Set::operator*= (Set S)
{
    (*this) = (*this) * S;
    M = Weight();
    return *this;
}
Set Set::operator~ ()
{
    Set Res = *this;
    Res.BoolVector::operator!();
    Res.M = Res.Weight();
    return Res;
}
//bool Set::operator== (Set S)
//{
//    for (int i = 0; i<32; i++)
//        if (bv[i] != S.bv[i]) return false;
//    return true;
//}
//bool Set::operator!= (Set S) // ничего нового не делаем => нам не нужны эти методы (кроме конструкторов)
//{
//    if (this->BoolVector::operator!= (S)) return false;
//    return true;
//}
bool Set::FindKey(char ch)
{
    Set K = *this;
    K.SetUp0((UC)ch);
    if (*this == K) return false;
    return true;
}
bool Set::Empty()
{
    if (M == 0) return true;
    return false;
}
bool Set::NotEmpty()
{
    if (M != 0) return true;
    return false;
}
void Set::Scan(int k)
{
    cout<<"enter the set elements: ";
    char s[256];
    cin.getline(s, 256);
    (*this) = Set(s);
}
void Set::Print()
{
    for (int i = 0; i<256; i++)
        if ((*this)[i] == '1')
        {
            char ch = i;
            cout<<ch<<" ";
        }
}
istream& operator>> (istream& is, Set& X)
{
    cout<<"enter the set elements: ";
    char s[256];
    is.getline(s, 256);
    X = Set(s);
    return is;
}
ostream& operator<<(ostream& os, Set& X)
{
    for (int i = 0; i < 256; i++)
    {
        if (X[i] == '1')
        {
            char ch = i;
            os<<ch<<" ";
        }
    }
    return os;
}

/* второй вариант - сами отслеживаем отсутствие повторений
 {
     cout<<"enter the number of elements: ";
     int N;
     is>>N;
     cout<<"enter "<<n<<" elements of the set: ";
     char* s = new char [N+1];
     gets(s);
     X = Set(s);
     delete []s;
     return is;
 }
 */
