#include "Array-template.h"

template <class T>
Array<T>::Array(int N, int t)
{
     if (N <= 0)
     {
         cout<<"error! неверный размер массива, создаем массив по умолчанию"<<endl;
         n = 1;
         
     }
     else n = N;
     mem = 2*n;
     arr = new T [mem];
     if (t!=0)
         for (int i = 0; i < n; i++)
             arr[i] = 'a' + T(rand()%26);
             //arr[i]=rand()%abs(t);
     else
         for (int i = 0; i < n; i++)
             arr[i] = 0;
}
template <class T>
Array<T>::Array(T* a, int N)
{
    if (N == 0)
    {
        n = N;
        arr = nullptr; //нулевой массив
        mem = 0;
    }
    else
    {
        mem = 2*N;
        arr = new T [mem];
        for (int i = 0; i < N; i++)
            arr[i] = a[i];
        n = N;
    }
}
template <class T>
Array<T>::Array(const Array<T>& A) //A - корректно созданный объект
{
    n = A.n;
    mem = A.mem;
    arr = new T[mem];
    for (int i=0; i<n; i++)
        arr[i] = A.arr[i];
}
template <class T>
Array<T>::~Array()
{
    delete [] arr;
}
template <class T>
Array<T>& Array<T>::operator= (const Array<T>& x) //конструктор копирования (иначе два объекта связаны с одной областью памати)
{
    if (this != &x) //указатель на обьект != указатель на х
    {
        if (mem > x.n)
            n = x.n;
        else
        {
            delete[] arr; //память, привязанная к новому обьекту
            n = x.n;
            mem = x.mem;
            arr = new T[mem];
        }
        for (int i = 0; i < n; i++)
            arr[i] = x.arr[i]; //не было бы элементов массива х, если нет условия
    }
    return *this;
}
template <class T>
Array<T>::Array (Array<T>&& x) noexcept
{
    n = x.n;
    arr = x.arr;
    mem = x.mem;
    x.arr = nullptr; //чтобы деструктор нормально уничтожил память
    
}
template <class T>
Array<T>& Array<T>::operator= (Array<T>&& x) noexcept
{
    if (this != &x) //указатель на обьект != указатель на х
    {
        delete[] arr; //память, привязанная к новому обьекту
        n = x.n;
        arr = x.arr; //отобрали ресурсы
        mem = x.mem;
        x.arr = nullptr;
    }
    return *this;
}
template <typename T>
T Array<T>::EPS() {return 0;}

template <>
float Array<float>::EPS() {return FLT_EPSILON;}

template <class T>
void Array<T>::Set(int m)
{
    if (m <= 0)
    {
        cout<<"error! неверный размер массива, полагаем m = 1"<<endl;
        m = 1;
    }
    n = m;
    if (mem < m)
    {
        delete [] arr;
        mem = 2*n;
        arr = new T [mem];
    }
    cout<<"введите "<< m <<" элементов массива: ";
    for (int i = 0; i < n; i++)
        cin>>arr[i];
}
template <class T>
void Array<T>::Print()
{
    if (n == 0)
        cout<<"массив пустой";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
template <class T>
T& Array<T>::operator[] (int pos)
{
    if (pos < 0)
    {
        cout<<"индекс отрицательный"<<endl;
        return arr[0];
    }
    if (pos >= n)
    {
        cout<<"индекс превышает размер массива"<<endl;
        return arr[n-1];
    }
    return arr[pos];
}
template <class T>
int Array<T>::FindKey(T key)
{
    for (int i = 0; i<n; i++)
        if (arr[i] - key >= -EPS() && arr[i] - key <= EPS())   return i;
    return -1;
}
template <class T>
Array<T> Array<T>::operator+ (T key)
{
    // первый вариант
    T* t = new T[n+1];
    for (int i = 0; i < n; i++)
        t[i] = arr[i];
    t[n] = key;
    Array Res(t, n+1);
    delete[] t;
    return Res;
    //второй вариант
    /*
    Array Res = *this;
    Res+=(key);
    return Res;
     */
}
template <class T>
Array<T>& Array<T>::operator+= (T key) //добавление элемента в конец массива
{
    if (mem >= n + 1)
    {
        n++;
        arr[n-1] = key;
    }
    else
    {
        mem = 2*(n+1);
        T* t = new T[mem];
        for (int i = 0; i < n; i++)
            t[i] = arr[i];
        t[n] = key;
        delete[] arr;
        n++;
        arr = t;
    }
    return *this;
    /* // более оптимальный вариант кода
    int* t = new int[n+1];
    for (int i = 0; i < n; i++)
        t[i] = arr[i];
    t[n] = key;
    delete[] arr;
    n++;
    arr = t;
    return *this;
    */
}
template <class T>
Array<T> Array<T>::operator+ (Array<T> A)
{
    Array<T> Res = *this;
    Res += A;
    return Res;
}
template <class T>
Array<T>& Array<T>::operator+= (Array<T> A)
{
    for (int i = 0; i<A.n; i++)
        (*this) += A.arr[i];
    return *this;
}
template <class T>
Array<T> Array<T>::operator- (T key)
{
    Array<T> Res = *(this);
    int i_key = FindKey(key);
    if (i_key != -1)
    {
        for (int i = i_key; i<n-1; i++)
            Res.arr[i] = Res.arr[i+1];
        Res.n--;
    }
    return Res;
}
template <class T>
Array<T>& Array<T>::operator-= (T key)
{
    int i_key = FindKey(key);
    if (i_key >= 0)
    {
        for (int i = i_key; i<n-1; i++)
            arr[i] = arr[i+1];
        n--;
    }
    return *this;
}
template <class T>
Array<T> Array<T>::DelPosNew(int pos)
{
    Array<T> Res = *(this);
    if ((pos >= 0) && (pos < n) && (n != 0))
    {
        for (int i = pos; i<n-1; i++)
            Res.arr[i] = Res.arr[i+1];
        Res.n--;
    }
    return Res;
}
template <class T>
Array<T>& Array<T>::DelPosEq(int pos)
{
    if ((pos >= 0) && (pos < n) && (n != 0))
    {
        for (int i = pos; i<n-1; i++)
            arr[i] = arr[i+1];
        n--;
    }
    return *this;
}
template <class T>
bool Array<T>::operator== (Array<T> A)
{
    if (n == A.n)
        for (int i = 0; i<n; i++)
            if (arr[i] - A.arr[i] < -EPS() || arr[i] - A.arr[i] > EPS())
                return false;
    if (n != A.n) return false;
    return true;
}
template <class T>
bool Array<T>::operator!= (Array<T> A)
{
    if (n == A.n)
        for (int i = 0; i<n; i++)
            if (arr[i] - A.arr[i] < -EPS() || arr[i] - A.arr[i] > EPS())
                return true;
    if (n != A.n) return true;
    return false;
}
template <class T>
int Array<T>::Max()
{
    int i_max = 0;
    for (int i = 1; i<n; i++)
        if (arr[i] - arr[i_max] > EPS())
            i_max = i;
    return i_max;
}
template <class T>
int Array<T>::Min()
{
    int i_min = 0;
    for (int i = 1; i<n; i++)
        if (arr[i] - arr[i_min] < -EPS())
            i_min = i;
    return i_min;
}
template <class T>
void Array<T>::Sorting()
{
    for(int i = 1; i<n; i++)
        for(int j = i; j>0 && (arr[j-1] - arr[j] > EPS()); j--)
        {
            T tmp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = tmp;
        }
}
template <class T>
int Array<T>::Size()
{
    return n;
}
template <class T>
ostream& operator<< (ostream& r, Array<T>& x)
{//первый вариант
    x.Print();
    return r;
    //второй вариант - быстрее
    /*
     if (x.n == 0)
         cout<<"массив пустой";
     for (int i = 0; i < x.n; i++)
         cout<<x.arr[i]<<" ";
     cout<<endl;
     return r;
     */
}
template <class T>
istream& operator>> (istream& r, Array<T>& x)
{
    int m;
    cout<<"vvedi razmer massiva: ";
    cin>>m;
    x.Set(m);
    return r;
}

