#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
}

int main () {
    int i,n;
    int temp1;
    struct Node* head = new struct Node;
    cin>>n;
    head->data = -1;
    for (i = 0;i<n; i++){
        cin>>temp1;
        while(temp1%10 != 0){
        struct Node* temp = new struct Node;
        }
    }
    return 0;
}