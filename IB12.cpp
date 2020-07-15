#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

vector<int> rec(string A, vector<string> B)
{
    vector<int> final;
    unordered_map<string, int> m;
    for (int i = 0; i < B.size(); i++)
    {
        m[B[i]]++;
    }
    unordered_map<string, int> m2;
    for (int i = 0; i < B.size(); i++)
    {
        m2[B[i]] = 0;
    }
    int n = B[0].size();
    int i = 0;
    int limit = A.size() - n;
    for (; i <= limit; i++)
    {
        int j = 0;
        if (m.find(A.substr(i, n)) != m.end())
        {
            int l = i;
            while (m.find(A.substr(l, n)) != m.end() && m[A.substr(l, n)] > m2[A.substr(l, n)])
            {
                j++;
                m2[A.substr(l, n)]++;
                l = l + n;
            }
            if (j == B.size())
            {
                final.push_back(i);
            }
            for (int k = 0; k < B.size(); k++)
            {
                m2[B[k]] = 0;
            }
        }
    }
    return final;
}

int main()
{

    string A = "cacabbabcbccbccbbbcccabaaacaaccbbaccca";
    vector<string> B = {"c", "c", "b", "a", "c" };
    vector<int> C = rec(A, B);
    rep(i, C.size())
    {
        cout << C[i] << endl;
    }
}