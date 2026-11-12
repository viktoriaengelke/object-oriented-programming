#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include "Array.h"

int main()
{
    Array mas1;
    mas1.Set(5);
    mas1.Print();

    Array mas2 = mas1;
    cout<<"mas2: "<<mas2<<endl;
    
    if (mas1 == mas2)
        cout<<"mas1 = mas2"<<endl;
    else
        cout<<"mas1 != mas2"<<endl;
    
    mas1+=6;
    mas1.Print();
    if (mas1 != mas2)
        cout<<"mas1 != mas2"<<endl;
    else
        cout<<"mas1 = mas2"<<endl;
    
    Array mas3 = mas1 + 7;
    cout<<"mas3: "<<mas3<<endl;
    
    mas3.DelPosEq(1);
    cout<<"mas3: "<<mas3<<endl;
    
    Array mas4 = mas3.DelPosNew(mas3.Size() - 1);
    cout<<"mas4: "<<mas4<<endl;
    
    mas1-=1;
    cout<<"mas1: "<<mas1<<endl;
    if (mas1 == mas4)
        cout<<"mas1 = mas4";
    else
        cout<<"mas1 != mas4";
    
    int n;
    cout<<"enter n: ";
    cin>>n;
    int* b = new int [n];
    
    srand(time(0));
    for (int i = 0; i<n; i++)
        b[i] = rand() % 100;
    Array mas5(b, n);
    
    int t = mas5.Max();
    cout<<"index max element in mas5: "<<t<<"max element: "<<mas5[t]<<endl;
    
    int m = mas5.Min();
    cout<<"index min element in mas5: "<<m<<"min element: "<<mas5[m]<<endl;
    
    mas5.Sorting();
    cout<<"mas5: "<<mas5<<endl;
    
    Array mas6  = mas1 + mas5;
    cout<<"mas6: "<<mas6<<endl;
    
    Array mas7(4);
    cout<<"mas7: ";
    cin>>mas7;
    
    if (mas7.FindKey(1) > 0) cout<<"mas7 has 1"<<endl;
    else cout<<"mas7 has not 1"<<endl;
    
    if (mas7.FindKey(10) > 0) cout<<"mas7 has 10"<<endl;
    else cout<<"mas7 has not 10"<<endl;
        
    Array mas8 = mas7 - 1;
    mas8 = mas7 - 10;
    cout<<"mas8: "<<mas8<<endl;

    
    mas4 += mas7;
    cout<<"mas4: "<<mas4<<endl;
    
    if (mas6 == mas4) cout<<"mas6 = mas4"<<endl;
    else cout<<"mas6 != mas4"<<endl;
    
    mas4 = mas6;
    cout<<"mas4: "<<mas4<<endl;
    
    Array mas9 = mas4^3;
    cout<<"mas9: "<<mas9<<endl;
}
