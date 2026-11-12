#include "BinaryTreeSearch.h"
#include <iostream>
using namespace std;

int main()
{
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    SBinTree T(a, 7);
    
    cout << "start tree:" << endl;
    T.PrintTree(0, T.GetRoot());
    cout << "count: " << T.Count(T.GetRoot()) << endl;
    cout << "h: " << T.FindHight(T.GetRoot()) << endl << endl;
    
    int* a1 = new int[T.Count(T.GetRoot())];
    int n = 0;
    T.TreeTraversal_LCR(T.GetRoot(), a1, n);
    cout << "lcr: ";
    for (int i = 0; i < n; i++) cout << a1[i] << " ";
    cout << endl;
    delete[] a1;
    
    cout << "max: " << T.FindMax(T.GetRoot())->GetKey() << endl;
    cout << "min: " << T.FindMin(T.GetRoot())->GetKey() << endl << endl;
    
    cout << "-add-" << endl;
    
    cout << "add 10:" << endl;
    T.Add(10, T.GetRoot());
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add 90:" << endl;
    T.Add(90, T.GetRoot());
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "add 55:" << endl;
    T.Add(55, T.GetRoot());
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "-copy-" << endl;
    SBinTree T2(T);
    T2.PrintTree(0, T2.GetRoot());
    cout << endl;
    
    cout << "-del-" << endl;
    
    cout << "del leaf 10:" << endl;
    T.Del(T.FindKey(T.GetRoot(), 10));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "del node 70:" << endl;
    T.Del(T.FindKey(T.GetRoot(), 70));
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "del root:" << endl;
    T.DelRoot();
    T.PrintTree(0, T.GetRoot());
    cout << endl;
    
    cout << "-find-" << endl;
    cout << "find 55: " << (T.FindKey(T.GetRoot(), 55) != NULL) << endl;
    cout << "find 100: " << (T.FindKey(T.GetRoot(), 100) != NULL) << endl;
    
    cout << "max: " << T.FindMax(T.GetRoot())->GetKey() << endl;
    cout << "min: " << T.FindMin(T.GetRoot())->GetKey() << endl << endl;
    
    SBinTree T3 = T2;
    cout << "t3:" << endl;
    T3.PrintTree(0, T3.GetRoot());
    cout << "t2:" << endl;
    T2.PrintTree(0, T2.GetRoot());
    cout << endl;
    
    cout << "-clear-" << endl;
    T.Clear();
    T.PrintTree(0, T.GetRoot());
    cout << "count: " << T.Count(T.GetRoot()) << endl;
    
    return 0;
}
