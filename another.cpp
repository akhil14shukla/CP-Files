#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int solve(vector<int> &A)
{
    int i, j;
    long long int max;
    max = 0;
    stack<int> r;
    stack<int> l;
    int m, n;
    j = 0;
    i = 0;
    while (j < A.size())
    {
        if (A[j] < A[i])
        {
            l.push(i);
            j++;
            i = j;
            continue;
        }
        if (i <= 0)
        {
            l.push(0);
            j++;
            i = j - 1;
            continue;
        }
        i--;
    }

    j = 0;
    i = 0;
    while (j < A.size())
    {
        if (A[j] < A[i])
        {
            r.push(i);
            j++;
            i = j;
            continue;
        }
        if (i >= A.size() - 1)
        {
            r.push(0);
            j++;
            i = j + 1;
            continue;
        }
        i++;
    }
    m = r.size();
    for (j = 0; j < m; j++)
    {
        if (max < r.top() * l.top())
        {
            max = r.top() * l.top();
        }
        r.pop();
        l.pop();
    }

    return max % 1000000007;
}

int main()
{
    vector<int> A = {7, 5, 7, 9, 8, 7};
    vector<int> B = {32, 82, 39, 86, 81, 58, 64, 53, 40, 76, 40, 46, 63, 88, 56, 52, 50, 72, 22, 19, 38};
    cout << solve(A) << endl;
    return 0;
}
