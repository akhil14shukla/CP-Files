#include <iostream>
#include "Queueclass.h"
#include "StackH.h"

using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *lchild = NULL;
    T data;
    int balance = 0;
    Node<T> *rchild = NULL;
};

template <typename T>
class Tree
{
public:
    Node<T> *root;

public:
    Tree()
    {
        root = NULL;
    }
    void create();
    void pre(Node<T> *p);
    void level();
    int count(Node<T> *p);
    Node<T> *Insert1(T x, Node<T> *p);
    int Search(T x);
    int Search1(T x);
    Node<T> *Delete(T x, Node<T> *p);
    int height(Node<T> *p);
    Node<T> *InPre(Node<T> *p);
    Node<T> *InSucc(Node<T> *p);
    void Retrieve(T a[]);
    Node<T> *LLRotation(Node<T> *p);
    Node<T> *LRRotation(Node<T> *p);
    int Balance(Node<T> *p);
};

template <typename T>
void Tree<T>::create() //Simple creation
{
    Node<T> *p;
    root = new Node<T>;
    p = root;
    T x;
    Stack<Node<T> *> s1;
    Queue<Node<T> *> q(10);
    cout << "feed me ";
    cin >> p->data;
    s1.push(root);
    q.enqueue(root);
    if (p->data != -1)
    {
        while (!q.isEmpty())
        {
            //p = s1.pop();
            p = q.dequeue();
            cout << "Value for left child of " << p->data;
            cin >> x;
            if (x != -1)
            {
                Node<T> *temp = new Node<T>;
                temp->lchild = NULL;
                temp->rchild = NULL;
                temp->data = x;
                p->lchild = temp;
                q.enqueue(temp);
                //s1.push(p->lchild);
                //p = temp;
            }
            cout << "Value for right child of " << p->data;
            cin >> x;
            if (x != -1)
            {
                Node<T> *temp = new Node<T>;
                temp->lchild = NULL;
                temp->rchild = NULL;
                //p = q.dequeue();
                temp->data = x;
                p->rchild = temp;
                q.enqueue(temp);
                //s1.push(p->rchild);
                //p = p->rchild;
                //q.enqueue(p);
            }

            //p = q.dequeue();
        }
    }
}
template <typename T>
void Tree<T>::pre(Node<T> *p)
{
    if (p != NULL)
    {
        if (p->lchild != NULL)
            pre(p->lchild);
        cout << p->data << " ";
        if (p->rchild != NULL)
            pre(p->rchild);
    }
}

template <typename T>
void Tree<T>::level()
{
    Queue<Node<T> *> q1(10);
    Node<T> *temp, *p = root;
    q1.enqueue(p);
    while (!q1.isEmpty())
    {
        temp = q1.dequeue();
        cout << temp->data << " ";
        if (temp->lchild != NULL)
        {
            q1.enqueue(temp->lchild);
        }
        if (temp->rchild != NULL)
        {
            q1.enqueue(temp->rchild);
        }
    }
}

template <typename T>

int Tree<T>::count(Node<T> *p) //counts number of leaf nodes
{
    static int z = 0; //foloow below comments to count all nodes
    int x, y;
    if (p != NULL)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        if (x == 0 && y == 0) // remove this and add return x+y+1;
            z++;              // remove this
    }
    else
        return 0;
    return z; // remove this
}

template <typename T>
Node<T> *Tree<T>::Insert1(T x, Node<T> *p) //Sorted Insert
{
    if (p == NULL)
    {
        Node<T> *temp = new Node<T>;
        temp->data = x;
        if (p == root)
        {
            root = temp;
        }
        return temp;
    }
    if (x > p->data)
    {
        p->rchild = Insert1(x, p->rchild);
    }
    else
    {
        p->lchild = Insert1(x, p->lchild);
    }
    if (Balance(p) == 2 && Balance(p->lchild) == 1)  //Similarly for R
    {
        p = LLRotation(p);                          // Do the same for RR Rotation and others
    }
    else if (Balance(p) == 2 && Balance(p->lchild) == -1)
    {
        p = LRRotation(p);
    }
    return p;
}

template <typename T>
int Tree<T>::Balance(Node<T> *p)
{
    return height1(p->lchild) - height1(p->rchild);
}

template <typename T>
Node<T> *Tree<T>::LLRotation(Node<T> *p)
{
    Node<T> *temp;
    temp = p;
    p = p->lchild;
    temp->lchild = p->rchild;
    p->rchild = temp;
    if (temp == root)
    {
        root = p;
    }
    return p;
}

template <typename T>
Node<T> *Tree<T>::LRRotation(Node<T> *p)
{
    Node<T> *pl = p->lchild;
    Node<T> *plr = pl->rchild;
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;
    if (p == root)
    {
        root = plr;
    }
    return plr;
}

template <typename T>
int Tree<T>::Search(T x) //General Search
{
    Node<T> *p = root;
    Stack<Node<T> *> s1;
    s1.push(root->rchild);
    while (!s1.isEmpty())
    {
        if (p != NULL)
        {
            if (p->data == x)
            {
                return 1;
            }
            if (p->rchild != NULL)
            {
                s1.push(p->rchild);
            }
            p = p->lchild;
        }
        else
        {
            p = s1.pop();
        }
    }
    return -1;
}

template <typename T>
int Tree<T>::Search1(T x) //binary search
{
    Node<T> *p = root;
    while (p)
    {
        if (p->data == x)
        {
            return 1;
        }
        if (x > p->data)
        {
            p = p->rchild;
        }
        else
        {
            p = p->lchild;
        }
    }
    return 0;
}

template <typename T>
Node<T> *Tree<T>::Delete(T x, Node<T> *p)
{
    if (x > p->data)
    {
        p->rchild = Delete(x, p->rchild);
    }
    else if (x < p->data)
    {
        p->lchild = Delete(x, p->lchild);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            Node<T> *q = InPre(p);
            p->data = q->data;
            p->lchild = Delete(q->data, p->lchild);
        }
        else if (height(p->lchild) < height(p->rchild))
        {
            Node<T> *q = InSucc(p);
            p->data = q->data;
            p->rchild = Delete(q->data, p->rchild);
        }
        else if (p->rchild == NULL && p->lchild == NULL)
        {
            delete p;
            return NULL;
        }
    }
    if (Balance(p) == 2 && Balance(p->lchild) == 1)     //Similarly for R 
    {
        p = LLRotation(p);                              // Do the same for RR Rotation and others
    }
    else if (Balance(p) == 2 && Balance(p->lchild) == -1)
    {
        p = LRRotation(p);
    }
    else if (Balance(p) == 2 && Balance(p->lchild) == 0){
        p = LLRotation(p);
    }

    return p;
}

template <typename T>
int Tree<T>::height(Node<T> *p)
{
    if (p == NULL)
        return 0;
    int x = height(p->lchild);
    int y = height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

template <typename T>
int height1(Node<T> *p)
{
    if (p == NULL)
        return 0;
    int x = height1(p->lchild);
    int y = height1(p->rchild);
    return x > y ? x + 1 : y + 1;
}

template <typename T>
Node<T> *Tree<T>::InSucc(Node<T> *p)
{
    p = p->rchild;
    while (p != NULL && p->lchild != NULL)
        p = p->lchild;
    // cout << p->data;
    return p;
}
template <typename T>
Node<T> *Tree<T>::InPre(Node<T> *p)
{
    p = p->lchild;
    while (p != NULL && p->rchild != NULL)
        p = p->rchild;
    //cout << p->data;
    return p;
}

template <typename T>
void Tree<T>::Retrieve(T a[])
{
    Stack<Node<T> *> s1;
    Node<T> *temp = new Node<T>;
    temp->data = a[0];
    root = temp;
    //s1.push(root);
    int i = 1;
    while (a[i] != -1)
    {
        if (a[i] < temp->data)
        { //can add equal to sign also
            Node<T> *p = new Node<T>;
            p->data = a[i];
            temp->lchild = p;
            s1.push(temp);
            temp = p;
        }
        else
        {
            if (!s1.isEmpty())
            {
                if (s1.show()->data > a[i])
                {
                    Node<T> *p = new Node<T>;
                    p->data = a[i];
                    temp->rchild = p;
                    temp = p;
                }
                else
                {
                    Node<T> *p = new Node<T>;
                    p->data = a[i];
                    temp = s1.pop();
                    temp->rchild = p;
                    temp = p;
                }
            }
            else
            {
                Node<T> *p = new Node<T>;
                p->data = a[i];
                temp->rchild = p;
                temp = p;
            }
        }
        i = i + 1;
    }
}

int main()
{
    Tree<int> tr;
    tr.root = NULL;
    //tr.create();
    tr.Insert1(5, tr.root);
    tr.Insert1(7, tr.root);
    //tr.Insert1(10, tr.root);
    tr.Insert1(2, tr.root);
    tr.Insert1(3, tr.root);
    tr.Delete(7, tr.root);
    //tr.Insert1(9, tr.root);
    //tr.Delete(9, tr.root);
    //cout << endl;
    //int a[9] = {30, 20, 10, 15, 25, 40, 50, 45, -1};
    //tr.Retrieve(a);
    tr.pre(tr.root);
    cout << endl;
    //cout << tr.Search1(21) << endl;
    //tr.InPre(tr.root->rchild);
    tr.level();
    //cout<<endl;
    //cout<<tr.count(tr.root);
    return 0;
}