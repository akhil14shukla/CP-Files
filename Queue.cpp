#include<iostream>
using namespace std;

template <typename T>
class Queue{              //Circular Queue
public:
int size;
int front;
int rear;
T *Q;
public:
Queue(int size){
    this->size = size;
    this->front = this->rear = -1;
    this->Q = new T[size];
}
void enqueue(T x){
    if((rear+1)%size == front){
       cout<<"Queue is full";
    }
    else{
        rear = (rear+1)%size;
        Q[rear] = x;
    }
}

T dequeue(){
    T x;
           if(front == -1){
            front++;
        }
    if(front == rear){
        cout<<"Queue is empty";
    }
    else{
        x = Q[front];
        front++;
        return x;
    }
    return x;
}

void Display(){
           if(front == -1){
            front++;
        }
    int temp;
    temp = front;
    int flag = 1;
    while(flag){
        cout<<Q[temp]<<" ";
        if(temp == rear){
            flag = 0;
        }
                temp = (temp+1)%size;
    }
}
};

int main(){
    Queue<int> q1(7);
    q1.enqueue(1);
    q1.enqueue(1);
    q1.enqueue(15);
    //cout<<q1.front;
    //cout<<q1.rear;
    q1.Display();
    return 0;
}