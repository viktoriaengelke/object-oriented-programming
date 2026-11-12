#include "BinaryTreeSearch.h"

void SBinTree::Add(int k, Node* p)
{
    if (p == root && p == NULL)
    {
        root = new Node(k);
        return;
    }
    if (p == NULL)
    {
        cout<<"error in Add!"<<endl;
        return;
    }
    if (k < p->key)
    {
        if (p->left == NULL)
        {
            Node *q = new Node(k, NULL, NULL, p);
            p->left = q;
        }
        else Add(k, p->left);
    }
    else
    {
        if (p->right == NULL)
        {
            Node *q = new Node(k, NULL, NULL, p);
            p->right = q;
        }
        else Add(k, p->right);
    }
}
void SBinTree::Del(Node *p)
{
    if (p == root)
    {
        DelRoot();
        return;
    }
    if (p == NULL) return;
    
    Node *q = p->parent;
    // p - лист
    if (p->left == NULL && p->right == NULL)
    {
        if (q->left == p) q->left = NULL;
        else q->right = NULL;
        delete p;
        //p = NULL;
        return;
    }
    // у p нет левого поддерева
    if (p->left == NULL)
    {
        if (q->left == p) q->left = p->right;
        else q->right = p->right;
        p->right->parent = q;
        delete p;
        return;
    }
    // у p нет правого поддерева
    if (p->right == NULL)
    {
        if (q->left == p) q->left = p->left;
        else q->right = p->left;
        p->left->parent = q;
        delete p;
        return;
    }
    // у p есть оба поддерева
    Node *t = p->left;
    if (t->right == NULL)
    {
        if (q->left == p) q->left = t;
        else q->right = t;
        t->parent = q;
        t->right = p->right;
        p->right->parent = t;
        delete p;
        return;
    }
    else
    {
        while (t->right != NULL) t = t->right;
        t->parent->right = t->left;
        if (t->left != NULL) t->left->parent = t->parent;
        //1-й вариант (маленькое инф поле)
        p->key = t->key;
        delete t;
        return;
        
        /* //2-й вариант
        if (q->left == p) q->left = t;
        else q->right = t;
        t->parent = q;
        t->left = p->left;
        t->right = p->right;
         
        p->left->parent = t;
        p->right->parent = t
         
        delete p;
        return;
         */
    }
}
SBinTree::SBinTree(int n): BinTree()
{
    for (int i = 0; i < n; i++)
        {
            int k = rand() % 100;
            Add(k, GetRoot());
        }
}
SBinTree::SBinTree(int* a, int n): BinTree()
{
    for(int i = 0; i < n; i++)
    {
        Add(a[i], GetRoot());
    }
}
SBinTree& SBinTree::operator= (const SBinTree& X)
{
    //BinTree::operator =(X);
    if (this == &X) return *this;
       Clear();
       if (X.root == NULL)
       {
           root = NULL;
           return *this;
       }
       root = new Node(X.root->key);
       Copy(X.root->left, root, 0);
       Copy(X.root->right, root, 1);
       return *this;
}
SBinTree& SBinTree::operator= (SBinTree&& X)
{
    if (this == &X) return *this;
        Clear();
        root = X.root;
        X.root = NULL;
        return *this;
}
void SBinTree::DelRoot()
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        root = NULL;
        return;
    }
    Node* t;
    if (root->right != NULL)
    {
        t = root->right;
        while (t->left != NULL)
            t = t->left;
    }
    else
    {
        t = root->left;
        while (t->right != NULL)
            t = t->right;
    }
    
    root->key = t->key;
    Del(t);
}
Node* SBinTree::FindKey(Node *p, int k)
{
    if (p == NULL) return NULL;
    if (p->key == k) return p;

    if (p->key > k) return FindKey(p->left, k);
    else return FindKey(p->right, k);
}
Node* SBinTree::FindMax(Node *p)
{
    if (p == NULL) return NULL;
    while (p->right != NULL) p = p->right;
    return p;
}
Node* SBinTree::FindMin(Node *p)
{
    if (p == NULL) return NULL;
    while (p->left != NULL) p = p->left;
    return p;
}
