#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <typename T>
class Stack
{
private:
    Node<T> *top;

public:
    Stack() { top = NULL; }
    void push(T x);
    T pop();
    void Display();
    int isEmpty();
    T show();
};

template<typename T>
T Stack<T>::show(){
    return top->data;
}

template <typename T>
void Stack<T>::push(T x)
{
    Node<T> *t = new Node<T>;
    if (t == NULL)
    {
        cout << "Stack is overflowed";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

template <typename T>
T Stack<T>::pop()
{
    T x;
    if (top == NULL)
    {
        cout << "Stack is empty\n";
    }
    else
    {
        Node<T> *temp;
        temp = top;
        x = temp->data;
        top = top->next;
        delete temp;
    }
    return x;
}

template <typename T>
void Stack<T>::Display()
{
    Node<T> *temp;
    temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <typename T>
int Stack<T>::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int isOperand(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 0;
    }
    return 1;
}

int prece(char a)
{
    if (a == '+' || a == '-')
    {
        return 1;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }
    return 0;
}

void convert(char *a)
{
    char *post = new char[strlen(a) + 1];
    Stack<char> stk;
    /*Stack<char>::*/stk.push('\0');
    int i = 0, j = 0;
    char c;
    while (a[j] != '\0')
    {
        if (isOperand(a[j]) )
        {
            post[i++] = a[j++];
        }
        else
        {
            if (prece(stk.show()) < prece(a[j]))
            {
                //cout<<69;
                c = a[j++];
                stk.push(c);
            }
            else
            {
                post[i++] = stk.pop();
            }
        }
    }
        while (!stk.isEmpty())
        {
            post[i++] = stk.pop();
        }
    //ṇṇpost[i] = '\0';
    cout << post << endl;
   // delete post;
}

int main()
{
    char b[] = "a+b*c-d/e\0";
    Stack<char> stk2;
    stk2.push('a');
    stk2.push('b');
   // cout<<stk2.show();
    stk2.pop();
    //stk2.Display();
    convert(b);
    return 0;
}