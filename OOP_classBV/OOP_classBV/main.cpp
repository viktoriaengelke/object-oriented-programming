#include <iostream>
#include "BoolVector.h"

int main()
{
    BoolVector B1;
    BoolVector B2(10);
    BoolVector B3("111011101110");
    BoolVector B4("111011101110", 10);
    BoolVector B5("111011101110", 16);
    cout<<"B1 = "<<B1<<endl;
    cout<<"B2 = "<<B2<<endl;
    cout<<"B3 = "<<B3<<endl;
    cout<<"B4 = "<<B4<<endl;
    cout<<"B5 = "<<B5<<endl;
    int w_B3 = B3.Weight();
    int w_B5 = B5.Weight();
    cout<<"Weight B3 = "<<w_B3<<endl;
    cout<<"Weight B5 = "<<w_B5<<endl;
    if (B3 != B5) cout<<"B3 != B5"<<endl;
    else cout<<"B3 = B5"<<endl;
    BoolVector B6 = B5;
    cout<<"B5 = "<<B5<<endl;
    cout<<"B6 = "<<B6<<endl;
    cin>>B2;
    cout<<"B2 = "<<B2<<endl;
    B1 = B2;
    cout<<"B1 = "<<B1<<endl;
    if (B1 == B2) cout<<"B1 = B2"<<endl;
    else cout<<"B1 != B2"<<endl;
    BoolVector V1;
    V1 = B1 & B3;
    BoolVector V2;
    V2 = B1|B3;
    BoolVector V3;
    V3 = B1^B3;
    cout<<"V1 = "<<V1<<endl;
    cout<<"V2 = "<<V2<<endl;
    cout<<"V3 = "<<V3<<endl;
    B1&=B3;
    if (B1 == V1) cout<<"B1 = V1"<<endl;
    else cout<<"B1 != V1"<<endl;
    B2 |= B3;
    if (B2 == V2) cout<<"B2 = V2"<<endl;
    else cout<<"B2 != V2"<<endl;
    !B1;
    cout<<"~B1 = "<<B1<<endl;
    cout<<"B1[4] = "<<B1[4]<<endl;
    cout<<"B1[5] = "<<B1[5]<<endl;
    B1.SetUp1(11);
    B1.SetUp0(7);
    B1.Invert(9);
    cout<<"B1 = "<<B1<<endl;
    B1.SetUp1(3, 5);
    B1.Invert(3, 1);
    cout<<"B1 = "<<B1<<endl;
    BoolVector V4;
    V4 = B1<<4;
    cout<<"V4 = "<<V4<<endl;
    B1>>=4;
    cout<<"B1 = "<<B1<<endl;
    if (B1 == V4) cout<<"B1 = V4"<<endl;
    else cout<<"B1 != V4"<<endl;
}
