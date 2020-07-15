#include<string.h>
using namespace std;
template <typename T>
class Nodestack
{
public:
    T data;
    Nodestack<T> *next;
};

template <typename T>
class Stack
{
private:
    Nodestack<T> *top;

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
    Nodestack<T> *t = new Nodestack<T>;
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
        Nodestack<T> *temp;
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
    Nodestack<T> *temp;
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