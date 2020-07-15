#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

vector<int> rec(vector<int> A, int B)
{
    if(A.size()<B){
        return {};
    }
    unordered_map<int, int> m;
    vector<int> f;
    for(int i = 0;i<B;i++){
        m[A[i]]++;
    }
    f.push_back(m.size());
    for (int i = B; i < A.size(); i++)
    {
        m[A[i-B]]--;
        if(m[A[i-B]] == 0){
            m.erase(A[i-B]);
        }
        m[A[i]]++;
        f.push_back(m.size());
    }
    return f;
}

int main()
{
    vector<int> A = {1, 2, 1, 3, 4, 3};
    int B = 1;
    vector<int> C = rec(A,B); 
    rep(i, C.size())
    {
        cout << C[i] << " ";
    }

    return 0;
}