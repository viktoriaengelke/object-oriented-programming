#include <iostream>
#include "Set.h"
using namespace std;

int main()
{
    char s[12] = "hello world";
    Set S1(s);
    cout<<"S1 = ";
    S1.Print();
    cout<<endl;
    cout<<"S1.GetNumber() = "<<S1.GetNumber()<<endl;
    
    Set S2 = S1;
    cout<<"S2 = "<<S2<<endl;
    if (S1 == S2) cout<<"S1 == S2"<<endl;
    else cout<<"S1 != S2"<<endl;
    
    if (S2.FindKey('o')) S2 -= 'o';
    else S2 += 'o';
    if (S2.FindKey('a')) S2 -= 'a';
    else S2 += 'a';
    cout<<"S2 = "<<S2<<endl;
    if (S1 == S2) cout<<"S1 == S2"<<endl;
    else cout<<"S1 != S2"<<endl;
    
    Set S3;
    cout<<"S3 = "<<S3<<endl;
    if (S3.Empty()) cout<<"S3 is empty"<<endl;
    else cout<<"S3 is not empty"<<endl;
    
    S3.Scan(6);
    if (S3.Empty()) cout<<"S3 is empty"<<endl;
    else cout<<"S3 is not empty"<<endl;
    cout<<"S3 = "<<S3<<endl;
    
    Set S4 = S3 - 'y' + 'i';
    cout<<"S4 = "<<S4<<endl;
    
    Set T1 = S2 + S4;
    Set T2 = S2 * S4;
    Set T3 = S2 / S4;
    cout<<"T1 = "<<T1<<endl;
    cout<<"T2 = "<<T2<<endl;
    cout<<"T3 = "<<T3<<endl;
    
    Set T4 = ~S2;
    Set T5 = T4 * S2;
    cout<<"T4 = "<<T4<<endl;
    if (T5.Empty()) cout<<"T5 is empty"<<endl;
    else cout<<"T5 is not empty"<<endl;

    
    Set S5;
    cin>>S5;
    cout<<"S5 = "<<S5<<endl;
    
    S5 *= S1;
    cout<<"S5 = "<<S5<<endl;
    
    S5 = S5 + T2;
    cout<<"S5 = "<<S5<<endl;
    
    Set S6;
    S6 = S1;
    if (S5 == S6) cout<<"S5 == S6"<<endl;
    else cout<<"S5 != S6"<<endl;
}
