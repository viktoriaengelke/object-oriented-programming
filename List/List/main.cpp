#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List S1;
    S1.AddToHead(1);
    S1.AddToTail(10);
    S1.Print();
    
    List S2(6);
    cout<<"S2 = "<<S2<<endl;
    Node* Max = S2.Max();
    Node* Min = S2.Min();
    cout<<"S2.Max = "<<Max->GetKey()<<endl;
    cout<<"S2.Min = "<<Min->GetKey()<<endl;
    S2.Sort();
    cout<<"S2 = "<<S2<<endl;
    
    Node* S2_2 = S2.FindPos(2);
    cout<<"S2_2 = "<<S2_2->GetKey()<<endl;
    S2.Del(S2_2);
    cout<<"S2 = "<<S2<<endl;
    
    Node* S2_6 = S2.FindPos(6);
    if (S2_6 == nullptr) cout<<"List S2 does not have 6 elements"<<endl;
    
    S2.DelTail();
    cout<<"S2 = "<<S2<<endl;
    
    List S3 = S1;
    if (S3 == S1) cout<<"S3 == S1"<<endl;
    else cout<<"S3 != S1"<<endl;
    
    if (S3.Empty()) cout<<"S3 is empty"<<endl;
    else cout<<"S3 is not empty"<<endl;
    
    int* a;
    a = new int [6];
    for (int i = 0; i<6; i++)
        a[i] = rand()%20;
    
    List S4(a, 6);
    cout<<"S4 = "<<S4<<endl;
    if (S4.FindKey(25) == nullptr) cout<<"S4 has not 25"<<endl;
    else cout<<"S4 has 25"<<endl;
    
    S4.AddToTail(25);
    cout<<"S4 = "<<S4<<endl;
    
    List S5 = S2;
    cout<<"S5 = "<<S5<<endl;
    if (S5.FindKey(4) != nullptr) {
        S5.Del(S5.FindKey(4));
        cout<<"S5 has 4, S5 = "<<S5<<endl;
    }
    else
    {
        S5.AddToTail(4);
        cout<<"S5 has not 4, S5 = "<<S5<<endl;
    }
    cin>>S5;
    if (S5 == S4) cout<<"S5 == S4"<<endl;
    else cout<<"S5 != S4"<<endl;
    
    S5.AddToTail(S4);
    S5.AddToHead(S1);
    cout<<"S5 = "<<S5<<endl;
}
