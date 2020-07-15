#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int rec(int B, vector<int> A)
{
    if (A.size() == 0)
    {
        return 0;
    }
    map<int, int> s;
    for (int i = 0; i < A.size(); i++)
    {
        s[A[i]]++;
    }
    long result = 0;
    while (B--)
    {
        result = (result + s.rbegin()->first) % (1000000007);
        long temp = s.rbegin()->first;
        s[s.rbegin()->first]--;
        if (s[s.rbegin()->first] == 0)
        {
            s.erase(s.rbegin()->first);
        }
        s[temp-1]++;
    }
    return result % (1000000007);
}

int main()
{
    vector<int> B = {1,4};
    cout << rec(2, B);
    return 0;
}