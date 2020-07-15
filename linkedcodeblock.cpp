#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *first;

public:
    LinkedList() { first = NULL; } // constructor
    LinkedList(T A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, T key);
    int Delete(int index);
    int Length();
    void Merge(LinkedList A, LinkedList B);
};

template <typename T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *last, *t;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Node<T> *temp = first;
    while (first)
    {
        first = first->next;
        delete temp;
        temp = first;
    }
}

template <typename T>
void LinkedList<T>::Display()
{
    Node<T> *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template <typename T>
int LinkedList<T>::Length()
{
    Node<T> *temp = first;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
void LinkedList<T>::Insert(int index, T key)
{
    Node<T> *temp, *count;

    if (index < 0 || index > Length())
    {
        return;
    }
    temp = new Node<T>;
    temp->data = key;
    temp->next = NULL;
    if (index == 0)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        count = first;
        for (int i = 0; i < index - 1; i++)
        {
            count = count->next;
        }
        temp->next = count->next;
        count->next = temp;
    }
}

template <typename T>
int LinkedList<T>::Delete(int index)
{
    Node<T> *temp, *count;
    int x;

    if (index < 0 || index > Length())
    {
        return -1;
    }
    if (index == 1)
    {
        temp = first;
        first = first->next;
        x = temp->data;
        delete temp;
    }
    else
    {
        count = first;
        for (int i = 0; i < index - 1; i++)
        {
            temp = count;
            count = count->next;
        }
        temp->next = count->next;
        x = count->data;
        delete count;
    }
}

template <typename T>
void LinkedList<T>::Merge(LinkedList A, LinkedList B)
{
    Node<T> *last, *third;
    if (A.first->data > B.first->data)
    {
        last = B.first;
        third = B.first;
        B.first = B.first->next;
        last->next = NULL;
    }
    else
    {
        last = A.first;
        third = A.first;
        A.first = A.first->next;
        last->next = NULL;
    }

    while (A.first != NULL && B.first != NULL)
    {
        if (A.first->data > B.first->data)
        {
            last->next = B.first;
            last = last->next;
            B.first = B.first->next;
            last->next = NULL;
        }
        else
        {
            last->next = A.first;
            last = last->next;
            A.first = A.first->next;
            last->next = NULL;
        }
    }
    if (A.first != NULL)
    {
        last->next = A.first;
    }
    if (B.first != NULL)
    {
        last->next = B.first;
    }
    first = third;
}
int main()
{
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8};
    int C[] = {0};
    LinkedList<int> T1(C, 1);
    LinkedList<int> A1(A, 4);
    LinkedList<int> B1(B, 4);
    T1.Merge(A1, B1);
    A1.Insert(2, 25);
    A1.Display();
    //T1.Display();
    return 0;
}
