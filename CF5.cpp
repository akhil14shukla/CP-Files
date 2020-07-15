#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <string>
#include <map>
#include <stack>
#define pb push_back
#define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define mii map<int, int>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpii vector<pair<int, int>>
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

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void fastscan(int &number)
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
    rep(k, test)
    {
        int m, n, i, j;
        int final1 = 0;
        cin >> m >> n;
        int C = min(m, n);
        if (m <= n)
        {
            i = m;
            j = n;
        }
        else
        {
            i = n;
            j = m;
        }
        if (m != 0 && n != 0)
        {
            if (2 *i <= j)
            {
                final1 = i;
                printf("%d\n", final1);
            }
            else
            {
                final1 = j - i;
                ll leftA = 2 * i - j; // of A
                ll leftB = 2 * i - j; // of B
                if (leftA >= 3 && leftB >= 3)
                {
                    int k = leftA / 3;
                    leftA = leftA - 3 * k;
                    leftB = leftB - 3 * k;
                    final1 = final1 + 2 * k;
                }
                if ((leftA >= 1 && leftB > 1) || (leftA > 1 && leftB >= 1))
                {
                    final1 = final1 + 1;
                }
                printf("%d\n", final1);
            }
        }
        else
        {
            printf("%d\n", final1);
        }
    }

    return 0;
}