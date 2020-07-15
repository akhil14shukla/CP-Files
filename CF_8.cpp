#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
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
using namespace std;

void fastscan(int &number) //much faster way of input, only integers
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n];
        rep(i, n)
        {
            cin >> a[i];
        }
        vi final;
        final.pb(a[0]);
        rep2(j,1,n-2){
            if((a[j]>=a[j-1] && a[j]>=a[j+1] )|| (a[j]<=a[j-1] && a[j]<=a[j+1])){
                final.pb(a[j]);
            }
        }
        final.pb(a[n-1]);
        cout<<final.size()<<el;
        rep(j,final.size()){
            cout<<final[j]<<" ";
        }
        cout<<el;
    }
    return 0;
}