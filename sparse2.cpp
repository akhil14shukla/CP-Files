#include <iostream>

using namespace std;

class Elements
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
private:
    int m;
    int n;
    int num;
    Elements *ele;
public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Elements[this->num];
    }
    ~Sparse()
    {
        delete [] ele;
    }
    void read()
    {
        cout<<"Enter non-zero elements: "<<endl;
        for(int l = 0; l<this->num; l++)
        {
            cin>>ele[l].i>>ele[l].j>>ele[l].x;
        }
    }

    void display()
    {
        for (int k = 0; k<this->num; k++)
        {
            cout<<ele[k].i<<" "<<ele[k].j<<" "<<ele[k].x<<endl;
        }
    }
};

int main(){
Sparse ma1(4,4,4);
ma1.read();
ma1.display();

}
