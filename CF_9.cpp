#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
#define pb push_back
#define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<int, int>>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fir first
#define sec second
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
#define fs fastscan
#define tlower(A) transform(A.begin(), A.end(), A.begin(), ::tolower)
#define tupper(A) transform(A.begin(), A.end(), A.begin(), ::toupper)
#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
#define N 100000
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>(n);
    int a[n];
    bitset<N> c;
    rep(i, n)
    {
        cin>>(a[i]);
        c[a[i]] = 1;
    }
    deque<int> min1;
    int flag = 0;
    rep(i, n+1)
    {
        if (c[i] == 0)
        {
            min1.push_back(i);
            flag = 1;
        }
    }
        rep(i, n)
            min1.pb(n + 1+i);
    
    int b[n];
    rep(i, n)
    {
        b[i] = min1[0];
        min1.pop_front();
        c[b[i]] = 1;
        c[a[i]] = 0;
        if (i < n - 1)
            c[a[i + 1]] = 1;
        if(c[a[i]] == 0){
            // min1.pop_front();
            min1.push_front(a[i]);
        }
        cout << b[i] << " ";
    }
    return 0;
}