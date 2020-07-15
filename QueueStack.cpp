#include<iostream>
#include "StackH.h"
using namespace std;

template <typename T>
class QueueStack{
    private:
    Stack<int> s1();
    Stack<int> s2();
    public:
    void Insert(T x){
        s1.push(x);
    }
    T Delete(){
        T x;
        if(!s2.isEmpty()){
            while(!s1.isEmpty()){
            s2.push(s1.pop());
            }
            x = s2.pop();
        }
        else{
            x = s2.pop();
        }
        return x;
    }
    void Display(){
        
    }
};

int main(){
    QueueStack<int> qs1;
    qs1.Insert(25);
    return 0;
}