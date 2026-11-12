#include "BinTree.h"
#include <iostream>
using namespace std;

int main()
{
    int arr[] = {15, 25, 35, 45, 55};
    BinTree T(arr, 5);
    
    cout << "start tree:" << endl;
    T.PrintTree(0, T.GetRoot());
    cout << "count: " << T.Count(T.GetRoot()) << endl << endl;
    
    BinTree T2(T);
    BinTree T3;
    T3 = T;
    BinTree T4 = T2;
    
    BinTree T5 = BinTree(15);
    cout << "t5:" << endl;
    T5.PrintTree(0, T5.GetRoot());
    cout << endl;
    
    int* a = new int[T.Count(T.GetRoot())];
    int n = 0;
    T.TreeTraversal_LCR(T.GetRoot(), a, n);
    cout << "lcr: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    n = 0;
    T.WidthTraversal(T.GetRoot(), a, n);
    cout << "width: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl << endl;
    delete[] a;
    
    cout << "max: " << T.FindMax(T.GetRoot())->GetKey() << endl;
    cout << "min: " << T.FindMin(T.GetRoot())->GetKey() << endl;
    cout << "h: " << T.FindHight(T.GetRoot()) << endl << endl;
    
    
    cout << "add to root:" << endl;
    T.Add(100, T.GetRoot());
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add to root:" << endl;
    T.Add(200, T.GetRoot());
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add to leaf 25:" << endl;
    T.Add(300, T.FindKey(T.GetRoot(), 25));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add to leaf 45:" << endl;
    T.Add(400, T.FindKey(T.GetRoot(), 45));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add to 35:" << endl;
    T.Add(500, T.FindKey(T.GetRoot(), 35));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add to empty tree:" << endl;
    BinTree Te;
    Te.Add(600, Te.GetRoot());
    Te.PrintTree(0, Te.GetRoot());
    cout << endl;
    
    cout << "del leaf 300:" << endl;
    T.Del(T.FindKey(T.GetRoot(), 300));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "del 500:" << endl;
    T.Del(T.FindKey(T.GetRoot(), 500));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "del 25:" << endl;
    T.Del(T.FindKey(T.GetRoot(), 25));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "del root:" << endl;
    T.DelRoot();
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "clear:" << endl;
    T.Clear();
    T.PrintTree(0, T.GetRoot());
    cout << "count: " << T.Count(T.GetRoot()) << endl;
    
    return 0;
}
