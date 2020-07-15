#include <stdio.h>
using namespace std;

struct Elements(){
int i;
int j;
int x;
}

struct Sparse(){
int m;
int n;
int num;
struct Elements *e;
}

void Create( struct Sparse *ma){
cout<<"Enter the size of Matrix: "<<endl;
cin>>ma->m>>ma->n;
cout<<"Enter the number of non-zero entries: "<<endl;
cin>>ma->num;
ma->e = new struct Elements[num];
}
