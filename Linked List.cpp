#include<iostream>
using namespace std;

template <typename T>
class Node{
    public:
    T data;
    Node<T> *next;
};


template <typename T>
class LinkedList{
    private:
    Node<T> *first;

    public:  
    LinkedList(){first = NULL;} // constructor
    LinkedList(T A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, T key);
    int Delete(int index);
    int Length();
};

template <typename T>
LinkedList<T>::LinkedList(T A[], int n){
   Node<T> *last, *t;
   first = new Node<T>;
   first->data = A[0];
   first->next = NULL;
   last = first;

   for(int i = 1; i<n; i++){
       t = new Node<T>;
       t->data = A[i];
       t->next = NULL;
       last->next = t;
       last = t;
   }
}

   template <typename T>
   LinkedList<T>::~LinkedList(){
     
   }

int main(){

    cout<<"dsd";
    return 0;}
