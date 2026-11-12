#include "BinTree.h"

class SBinTree: public BinTree
{
public:
    SBinTree(): BinTree() {};
    SBinTree(int n); //случойное дерево поиска из n элементов
    SBinTree(int* a, int n); //дерево поиска из массива
    SBinTree(const SBinTree& T): BinTree(T) {};
    SBinTree(SBinTree&& T): BinTree(T) {};
    virtual ~SBinTree() {};
    
    SBinTree& operator= (const SBinTree&);
    SBinTree& operator= (SBinTree&&);
    
    virtual void Add(int k, Node* p) override;
    virtual void Del(Node *p) override;
    virtual void DelRoot() override;
    virtual Node* FindKey(Node *p, int k) override;
    virtual Node* FindMax(Node *p) override;
    virtual Node* FindMin(Node *p) override;
    
};
