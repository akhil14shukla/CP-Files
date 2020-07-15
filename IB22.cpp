#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

int main2(vector<int> A)
{
    int a[A.size()];
    for (int i = 0; i < A.size(); i++)
    {
        a[i] = 1;
    }
    int max = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j] && (a[i]) < (a[j] + 1))
            {
                a[i] = a[j] + 1;
            }
        }
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

// int rec(string A, int i, int *store, vector<bool> &check){
//     if(i == A.size()){
//         return 1;
//     }
//     if(i>A.size()){
//         return 0;
//     }
//     if(check[i]){
//         return store[i];
//     }
//         if(A[i] == '0'){
//             store[i] = 0;
//             check[i] = true;
//         return 0;
//     }
//     if(A[i]-'0' == 2 && A[i+1]-'0'<=6 && A[i+1]-'0'!=0){
//         store[i+1] = rec(A,i+1,store,check);
//         check[i+1] = true;
//         store[i+2] = rec(A,i+2,store,check);
//         check[i+2] = true;
//         return store[i+1] + store[i+2];
//     }
//     if(A[i] - '0'==1 && A[i+1]-'0'!=0){
//         store[i+1] = rec(A,i+1,store,check);
//         check[i+1] = true;
//         store[i+2] = rec(A,i+2,store,check);
//         check[i+2] = true;
//         return store[i+1] + store[i+2];
//     }
//     if(A[i] - '0'==1 && A[i+1]-'0'==0){
//         store[i+2] = rec(A,i+2,store,check);
//         check[i+2] = true;
//         return store[i+2];
//     }
//     if(A[i] - '0'==2 && A[i+1]-'0'==0){
//         store[i+2] = rec(A,i+2,store,check);
//         check[i+2] = true;
//         return store[i+2];
//     }
//     if(A[i]-'0'>2){
//         store[i+1] = rec(A,i+1,store,check);
//         check[i+1] = true;
//         return store[i+1];
//     }
// }
// //875361268549483279131     //12
// int numDecodings(string A) {
//     int store[A.size()+2];
//     vector<bool> check(A.size()+2,false);
//     int m =  rec(A,0,store,check);
//     return m;
// }

int rec(vector<int> &A, int i, unordered_map<int, int> &m, vector<bool> &check)
{
    if (i == A.size() - 1)
    {
        return 0;
    }
    if (i != A.size() - 1 && A[i] == 0)
    {
        return 1e9;
    }
    if (m.find(i) != m.end())
    {
        return m[i];
    }
    int k = A[i];
    int min = 1e8;
    for (int j = 1; j <= k && i + j < A.size(); j++)
    {
        int k = 0;
        k = 1 + rec(A, i + j, m, check);
        if (min > k)
        {
            check[A.size() - 1] = false;
            min = k;
        }
    }
    m[i] = min;
    return min;
}
int jump(vector<int> &A)
{
    unordered_map<int, int> m;
    vector<bool> check(A.size(), false);
    check[0] = true;
    int final = rec(A, 0, m, check);
    if (final < 1e8)
    {
        return final;
    }
    return -1;
}

int solve(const vector<int> &A, int B)
{
    vector<vector<int>> dp(B + 1, vector<int>(A.size(), 0));
    // for(int i = 0;i<B+1;i++){
    //     for(int j = 0;j<A.size();j++){
    //         dp[i][j] = 0;
    //     }
    // }
    if (B > 0)
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[1][i] = max(dp[1][i], max(A[i] - A[j], dp[1][j]));
            }
        }
    for (int j = 0; j < B; j++)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int k = 0; k < i; k++)
            {
                dp[j + 1][i] = max(dp[j + 1][i], max(A[i] - A[k + 1] + dp[j][k], dp[j][k]));
            }
            dp[j + 1][i] = max(dp[j + 1][i], dp[j][i]);
        }
    }
    int l = 0;
    return dp[B][A.size() - 1];
}

int Obstacles(vector<vector<int>> &A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A[0].size(), 0));
    int i = 0, j = 0;
    if (A[0][0] != 1)
        dp[0][0] = 1;
    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < A[0].size(); j++)
        {
            if (A[i][j] != 1)
            {
                if (i > 0 && j > 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
                else if (i == 0 && j != 0)
                {
                    dp[i][j] = dp[i][j - 1];
                }
                else if (j == 0 && j != 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[A.size() - 1][A[0].size() - 1];
}

int Area(vector<int> &A)
{
    stack<int> q;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (q.empty())
        {
            q.push(i);
            if (ans < A[i])
            {
                ans = A[i];
            }
            continue;
        }
        if (A[q.top()] <= A[i])
        {
            q.push(i);
            if (ans < A[i])
            {
                ans = A[i];
            }
        }
        else
        {
            while (!q.empty() && A[q.top()] > A[i])
            {
                int k = i;
                int height = A[q.top()];
                q.pop();
                int l = 0;
                if (!q.empty())
                    l = q.top();
                if (q.size() != 0)
                {
                    if (ans < height * (i - l - 1))
                    {
                        ans = height * (i - l - 1);
                    }
                }
                else
                {
                    if (ans < height * (i - l))
                    {
                        ans = height * (i - l);
                    }
                }
            }
            q.push(i);
        }
    }
    int k = 0;
    if (!q.empty())
    {
        k = q.top();
    }
    while (!q.empty())
    {
        int height = A[q.top()];
        q.pop();
        int l = 0;
        if (q.size() != 0)
        {
            l = q.top();
        }
        if (q.size() != 0)
        {
            if (ans < height * (k - l))
            {
                ans = height * (k - l);
            }
        }
        else if (q.size() == 0)
        {
            if (ans < height * (k - l + 1))
            {
                ans = height * (k - l + 1);
            }
        }
    }
    return ans;
}

int main()
{
    // vector<int> A = { 19230, 13765, 6863, 3840, 8367, 15603, 16327, 15140, 5582, 12937, 9472, 14190, 9541, 4126, 2757, 400, 19685, 15908, 4929, 18136, 16050, 6622, 13439, 265, 5846, 3188, 8756, 4960, 18781, 11139, 5152, 12314};
    // cout<<main2(A);
    // string A = "4612";
    vector<int> B = {47, 69, 67, 97, 86, 34, 98, 16, 65, 95, 66, 69, 18, 1, 99, 56, 35, 9, 48, 72, 49, 47, 1, 72, 87, 52, 13, 23, 95, 55, 21, 92, 36, 88, 48, 39, 84, 16, 15, 65, 7, 58, 2, 21, 54, 2, 71, 92, 96, 100, 28, 31, 24, 10, 94, 5, 81, 80, 43, 35, 67, 33, 39, 81, 69, 12, 66, 87, 86, 11, 49, 94, 38, 44, 72, 44, 18, 97, 23, 11, 30, 72, 51, 61, 56, 41, 30, 71, 12, 44, 81, 43, 43, 27};
    cout << Area(B);
    return 0;
}