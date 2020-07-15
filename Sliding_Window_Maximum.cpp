#include <bits/stdc++.h>
#include <stack>
using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B)
{
    deque<int> d;
    vector<int> f;
    d.push_back(0);
    int i = 0;
    for (i = 0; i < B && i < A.size(); i++)
    {
        while(!d.empty() && d.front()<=i-B){
            d.pop_front();
        }
        if(A[i]<A[d.front()]){
            d.push_back(i);
        }
        else if(A[i]>A[d.back()]){
            while(!d.empty() && A[i]>A[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
    }
    // i++;
    f.push_back(A[d.front()]);
    for(;i<=A.size()-1;i++){
        while(!d.empty() && d.front()<=i-B){
            d.pop_front();
        }
        if(A[i]<A[d.front()]){
            d.push_back(i);
        }
        else if(A[i]>A[d.back()]){
            while(!d.empty() && A[i]>A[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }
        f.push_back(A[d.front()]);
    }
    return f;
}

int main()
{
    vector<int> A = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> B = slidingMaximum(A, 3);
    for(int i = 0; i<B.size();i++){
        cout<<B[i]<<" ";
    }
    return 0;
}
