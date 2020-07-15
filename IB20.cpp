#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

// int c[2000][2000];
// int rec(string A, string B, int i, int j)
// {
//     if (i >= A.size() || j >= B.size())
//     {
//         c[i][j] = 0;
//         return 0;
//     }
//     if (A[i] == B[j])
//     {
//         if (c[i][j] == -1)
//         {
//             c[i][j] = 1 + rec(A, B, i + 1, j + 1);
//         }
//         return c[i][j];
//     }
//     else
//     {
//         if (c[i + 1][j] == -1)
//         {
//             c[i + 1][j] = rec(A, B, i + 1, j);
//         }
//         if (c[i][j + 1] == -1)
//         {
//             c[i][j + 1] = rec(A, B, i, j + 1);
//         }
//         return max(c[i + 1][j], c[i][j + 1]);
//     }
// }
int rec(string A, string B, int i, int j, vector<vector<bool>> &v, vector<vector<bool>> &v1)
{
    if (i > A.size() || j > B.size())
    {
        return false;
    }
    if (i == A.size() && j <= B.size())
    {
        v[i][j] = false;
        v1[i][j] = true;
        while (B[j] == '*' && j <= B.size())
        {
            v[i][j] = false;
            v1[i][j] = true;
            j++;
        }
    }
    if (i <= A.size() && j == B.size())
    {
        v[i][j] = false;
        v1[i][j] = true;
        while (A[i] == '*' && i <= A.size())
        {
            v[i][j] = false;
            v1[i][j] = true;
            i++;
        }
    }
    if (i == A.size() && j == B.size())
    {
        return true;
    }
    if (v1[i][j])
    {
        return v[i][j];
    }
    if (A[i] == B[j] || A[i] == '?' || B[j] == '?')
    {
        // rec(A,B,i+1,j+1,v);
        return rec(A, B, i + 1, j + 1, v,v1);
    }
    if (A[i] == '*' || B[j] == '*')
    {
        v[i + 1][j] = rec(A, B, i + 1, j, v,v1);
        v1[i+1][j] = true;
        if (v[i + 1][j] == false)
        {
            v[i][j + 1] = rec(A, B, i, j + 1, v,v1);
            v1[i][j+1] = true;
            if (v[i][j + 1] == false){
                v[i + 1][j + 1] = rec(A, B, i + 1, j + 1, v,v1);
                v1[i+1][j+1] = true;
            }
        }
        return v[i][j + 1] || v[i + 1][j] || v[i + 1][j + 1];
    }

    v[i][j] = false;
    v1[i][j] = true;
    return false;
}
int solve(const string A, const string B)
{
    int n = A.size(), m = B.size();
    int flag = 1;
    vector<vector<bool>> v(n + 4, vector<bool>(m + 4, true));
    vector<vector<bool>> v1(n + 4, vector<bool>(m + 4, false));
    int i = 0, j = 0;
    int t = rec(A, B, 0, 0, v,v1);
    return t;
}

int main()
{
    string A = "bacb";
    string B = "b**************************************************************";
    cout << solve(A, B)<<endl;
    cout << time;
    return 0;
}
