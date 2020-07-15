#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

int rec(const string &A, const string &B, int i, int j, vector<vector<bool>> &v, vector<vector<bool>> &v1)
{
    if (i == A.size() && j < B.size() || i < A.size() && j == B.size())
    {
        v[i][j] = false;
        v1[i][j] = true;
        if (j == B.size() - 1 && B[j] == '*')
        {
            return true;
        }
        return false;
    }
    if (i == A.size() && j == B.size())
    {
        v[i][j] = true;
        v1[i][j] = true;
        return true;
    }
    // if (v1[i][j])
    // {
    //     return v[i][j];
    // }
    bool m1 = false;
    if (B[j + 1] == '*')
    {
        m1 = rec(A, B, i, j + 2, v, v1);
        v[i][j + 2] = m1;
        v1[i][j + 2] = true;
        if(m1){
            return m1;
        }
    }
    if (A[i] == B[j] || A[i] == '.' || B[j] == '.')
    {
        v[i][j] = true;
        v1[i][j] = true;
        v[i + 1][j + 1] = rec(A, B, i + 1, j + 1, v, v1);
        v1[i + 1][j + 1] = true;
        return m1 || v[i + 1][j + 1];
    }

    if (B[j] == '*')
    {
        int k = 0;
        bool m = false;
        v[i - 1][j + 1] = rec(A, B, i - 1, j + 1, v, v1);
        v1[i - 1][j + 1] = true;
        m = m || v[i - 1][j + 1];
        while (!m && (A[i + k] == B[j - 1] || B[j - 1] == '.') && k <= A.size() - i)
        {
            v[i + k][j] = 1;
            v1[i + k][j] = 1;

            v[i + k + 1][j + 1] = rec(A, B, i + k + 1, j + 1, v, v1);
            v1[i + k + 1][j + 1] = true;
            m = m || v[i + k + 1][j + 1];
            k++;
        }
        return m;
    }
    return false;
}

int solve(const string A, const string B)
{
    int n = A.size(), m = B.size();
    int flag = 1;
    vector<vector<bool>> v(n + 4, vector<bool>(m + 4, false));
    vector<vector<bool>> v1(n + 4, vector<bool>(m + 4, false));
    int i = 0, j = 0;
    int t = rec(A, B, 0, 0, v, v1);
    return t;
}

int main()
{
    // string A = "baaaaaabaaaabaaaaababababbaab";
    // string B = "..a*aa*a.aba*a*bab*";
    string A = "ac";
    string B = "ab*c";
    cout << solve(A, B) << endl;
    // cout << time;
    return 0;
}