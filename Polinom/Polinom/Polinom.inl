#include "Polinom.h"
template <class T>
Polinom<T>::Polinom (int N)
{
    if (N < 0)
    {
        cout<<"error! incorrect degree. we set degree by 0"<<endl;
        N = 0;
    }
    n = N;
    a = new T [n+1];
    for (int i = 0; i<n; i++)
        a[i] = 0;
}
template <class T>
Polinom<T>::Polinom (int* b, int m)
{
    if (b == nullptr)
    {
        cout<<"error! incorrect data. we set polinom by 0"<<endl;
        n = 0;
        a = new T [1];
        a[0] = 0;
    }
    else
    {
        n = m;
        a = new int [n+1];
        for (int i = 0; i<n; i++)
            a[i] = b[i];
    }
}
template <class T>
Polinom<T>::Polinom (const Polinom<T>& X)
{
    n = X.n;
    a = new T[n+1];
    for (int i = 0; i<n; i++)
        a[i] = X.a[i];
}
template <class T>
Polinom<T>::Polinom (Polinom<T>&& X) //конструктор перемещения - отбираем ресурсы
{
    n = X.n;
    a = X.a;
    X.a = nullptr;
}
template <class T>
Polinom<T>& Polinom<T>::operator= (const Polinom<T>& X) //оператор присвоение
{
    if (this != &X)
    {
        delete []a;
        n = X.n;
        a = new T [n+1];
        for (int i = 0; i<n; i++)
            a[i] = X.a[i];
    }
    return *this;
}
template <class T>
Polinom<T>& Polinom<T>::operator= (Polinom<T>&& X) //присвоение с перемщением - отбираем ресурсы
{
    if (this != &X)
    {
        delete []a;
        n = X.n;
        a = X.a;
        X.a = nullptr;
    }
    return *this;
}
template <class T>
T& Polinom<T>::operator[] (int pos)
{
    try
    {
        if (pos < 0) throw 0;
        if (pos > n) throw "incorrect data (pos>n)";
    }
    catch(int i)
    {
        cout<<"incorrect data (pos<0)"<<endl;
        return a[i];
    }
    catch(const char* s)
    {
        cout<<s<<endl;
        return a[n];
    }
    return a[pos];
}
template <>
int Polinom<int>::EPS() {return 0;}

template <>
float Polinom<float>::EPS() {return FLT_EPSILON;}

template <>
double Polinom<double>::EPS() {return DBL_EPSILON;}

template <class T>
Polinom<T> Polinom<T>::operator+ (Polinom<T> X)
{
    int N = n;
    if (N < X.n) N = X.n;
    Polinom<T> Res(N);
    int i;
    for (i = 0; i<=n && i<=X.n; i++)
        Res.a[i] = a[i] + X.a[i];
    while (i<=n)
    {
        Res.a[i] = a[i];
        i++;
    }
    while (i<=X.n)
    {
        Res.a[i] = X.a[i];
        i++;
    }
    int k = 0; //количество нулевых старших коэффициентов
    for (i = N; i > 0 && (Res.a[i] >= -EPS() && Res.a[i] <= EPS()); i--) k++;
    
    if (k > 0)
    {
        T* t = new T [N-k+1];
        for (int i = 0; i<=N-k; i++)
            t[i] = Res.a[i];
        delete [] Res.a;
        Res.a = t;
        Res.n = N - k;
    }
    return Res;
}
template <class T>
Polinom<T> Polinom<T>::operator- (Polinom<T> X)
{
    int N = n;
    if (N < X.n) N = X.n;
    Polinom<T> Res(N);
    int i;
    for (i = 0; i<=n && i<=X.n; i++)
        Res.a[i] = a[i] - X.a[i];
    while (i<=n)
    {
        Res.a[i] = a[i];
        i++;
    }
    while (i<=X.n)
    {
        Res.a[i] = -X.a[i];
        i++;
    }
    int k = 0; //количество нулевых старших коэффициентов
    for (i = N; i > 0 && (Res.a[i] >= -EPS() && Res.a[i] <= EPS()); i--) k++;
    
    if (k > 0)
    {
        T* t = new T [N-k+1];
        for (int i = 0; i<=N-k; i++)
            t[i] = Res.a[i];
        delete [] Res.a;
        Res.a = t;
        Res.n = N - k;
    }
    return Res;
}
template <class T>
Polinom<T> Polinom<T>::operator* (T k)
{
    Polinom<T> Res;
    if (k >= -EPS() && k <= EPS()) return Res;
    delete []Res.a;
    Res.a = new T [n+1];
    Res.n = n;
    for (int i = 0; i<=n; i++)
        Res.a[i] = a[i]*k;
    return Res;
}
template <class T>
bool Polinom<T>::operator == (Polinom<T> X)
{
    if (n != X.n) return false;
    for (int i = 0; i < n; i++)
        if (a[i]-X.a[i] < -EPS() || a[i]-X.a[i] > EPS()) return false;
    return true;
}
template <class T>
bool Polinom<T>::operator != (Polinom<T> X)
{
    if (n != X.n) return true;
    for (int i = 0; i < n; i++)
        if (a[i]-X.a[i] < -EPS() || a[i]-X.a[i] > EPS()) return true;
    return false;
}
template <class T>
ostream operator<< (ostream &r, Polinom<T> &X)
{
    if (X.n == 0)
    {
        r<<X.a[0]<<endl;
        return r;
    }
    if (X.a[0]<-EPS() || X.a[0]>EPS())
        r<<X.a[0];
    for (int i = 1; i<=X.n; i++)
        if (X.a[i] > EPS()) r<<'+'<<X.a[i]<<"x^"<<i;
        else if (X.a[i] < -EPS()) r<<X.a[i]<<"x^"<<i;
    r<<endl;
    return r;
}
template <class T>
istream operator>> (istream &r, Polinom<T> &X)
{
    int N;
    cout<<"enter degree of the polinom: ";
    r>>N;
    if (X.n != N)
    {
        delete []X.a;
        X.n = N;
        X.a = new T [N+1];
    }
    cout<<"enter "<<N+1<<" coefficient of the polinom: ";
    for (int i = 0; i<=N; i++)
        r>>X.a[i];
    return r;
}
