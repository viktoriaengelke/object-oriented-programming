#include <iostream>
#include <cfloat> //для DBL_EPSILON
#include "Complex.h"

//конструктор копирования и деструктор не нужен, тк данные хранятся в стеке

Complex::Complex() 
{
    re = 0;
    im = 0;
}
Complex::Complex(double R, double I)
{
    re = R;
    im = I;
}
Complex Complex::operator+(Complex z)
{
    Complex Res;
    Res.re = re + z.re;
    Res.im = im + z.im;
    return Res;
}

Complex Complex::operator-(Complex z)
{
    Complex Res;
    Res.re = re - z.re;
    Res.im = im - z.im;
    return Res;
}

Complex Complex::operator*(Complex z)
{
    Complex Res;
    Res.re = re * z.re - im * z.im;
    Res.im = im * z.re + z.im * re;
    return Res;
}

Complex Complex::operator/(Complex z)
{
    Complex Res;
    Res.re = (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im);
    Res.im = (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im);
    return Res;

}

Complex Complex::Conj() //комплексно-сопряженное
{
    Complex Res = *this; //указатель на число которое его вызывает
    Res.im *= (-1);
    return Res;
}

double Complex::Mod()
{
    return sqrt(re*re+im*im);
}

double Complex::Arg()
{
    double eps = DBL_EPSILON;
    double fi = 0;
    if (fabs(re) < eps && fabs(im) < eps)
        return fi;
    if (re >= eps)
    {
        fi = atan(im / re); //арктангенс
        return fi;
    }
    if (re <= -eps)
    {
        fi = atan(im / re) + M_PI; //константа пи
        return fi;
    }
    if (im >= eps)
    {
        fi = M_PI_2; //константа пи/2
        return fi;
    }
    else
    {
        fi = -M_PI_2; //константа -пи/2
        return fi;
    }
}

bool Complex::operator==(Complex z)
{
    double eps = DBL_EPSILON;
    if (fabs(re - z.re) < eps && fabs(im - z.im) < eps)
        return true;
    return false;
}

bool Complex::operator!=(Complex z)
{
    double eps = DBL_EPSILON;
    if (fabs(re - z.re) < eps && fabs(im - z.im) < eps)
        return false;
    return true;
}

double Complex::GetRe()
{
    return re;
}
double Complex::GetIm()
{
    return im;
}
//void Complex::Output()
//{
//    double eps = DBL_EPSILON;
//    if (fabs(re) > eps) //по модулю больше эпсилон и значит не равно 0
//        std::cout << re;
//    if (im >= eps)
//        std::cout << '+' << im << 'i';
//    if (im <= -eps)
//        std::cout << im << 'i';
//    if (fabs(re) < eps && fabs(im) < eps)
//        std::cout << 0;
//}
