#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
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

#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
using namespace std;

int check(int n)
{
    int count = 0;
    int temp = n;
    for (int i = 2; i <= temp / 2 && n > 1; i++)
    {
        if (n % i == 0)
        {
            count++;
            n = n / i;
            i--;
        }
        if (count > 2)
        {
            return 1;
        }
    }
    if (count == 2)
    {
        return 2;
    }
    return 0;
}

void solve(ll n, int a, int f)
{
    int check1 = check(n);
    if (n == 1)
    {
        if (a == 1)
        {
            cout << "FastestFinger" << el;
            return;
        }
        else
        {
            cout << "Ashishgup" << el;
            return;
        }
    }
    if (n == 2)
    {
        if (a == 0)
        {
            cout << "FastestFinger" << el;
            return;
        }
        else
        {
            cout << "Ashishgup" << el;
            return;
        }
    }
    int flag = 0;
    ll store = 1;
    if (n % 2 == 0)
    {
        for (ll i = 32; i >= 1; i--)
        {
            long temp = n % long(pow(2, i));
            if (n == long(pow(2, i)))
            {
                flag = 0;
                break;
            }
            if(temp == 0 && long(pow(2, i)) == 2){
                flag = 2;
                break;
            }
            if (temp == 0 && long(pow(2, i)) != 2)
            {
                flag = 1;
                store = long(pow(2, i));
                break;
            }
        }
        if (flag == 0)
        {
            if (a == 1)
            {
                cout << "FastestFinger" << el;
                return;
            }
            else
            {
                cout << "Ashishgup" << el;
                return;
            }
        }
        /*else if (flag == 1)
        {
            if (a == 0)
            {
                cout << "FastestFinger" << el;
                return;
            }
            else
            {
                cout << "Ashishgup" << el;
                return;
            }
        }*/
        if (check1 == 2)
        {
            if (a == 1)
            {
                cout << "FastestFinger" << el;
                return;
            }
            else
            {
                cout << "Ashishgup" << el;
                return;
            }
        }
        if (check1 == 1)
        {
            if (a == 0)
            {
                cout << "FastestFinger" << el;
                return;
            }
            else
            {
                cout << "Ashishgup" << el;
                return;
            }
        }
    }
    else
    {
        if (a == 0)
        {
            cout << "FastestFinger" << el;
            return;
        }
        else
        {
            cout << "Ashishgup" << el;
            return;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        solve(n, 1, 0);
    }
    return 0;
}