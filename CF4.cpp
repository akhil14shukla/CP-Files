#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
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
    //use auto instead of data types
    int test;
    cin >> test;
    rep(i, test)
    {
        int n;
        cin >> n;
        int a[2 * n];
        int cs = 0;
        int cb = 0;
        rep(j, 2 * n)
        {
            cin >> a[j];
            if (a[j] == 1)
                cs++;

            if (a[j] == 2)
                cb++;
        }
        int m, o, eter = 0;
        if (cs - cb < 0)
        {
            o = -1;
            m = 1;
            eter = cs - cb;
        }
        if (cb - cs < 0)
        {
            m = -1;
            o = 1;
            eter = cb - cs;
        }
        if (eter != 0)
        {
            mii r;
            mii l;
            l.insert(pii(0,0));
            // r.insert(mp(0, 0));
            // l.pb(mp(0, 0));
            int sum = 0;
            repr(i, n - 1, 0)
            {
                if (a[i] == 1)
                {
                    sum = sum + m;
                }
                else if (a[i] == 2)
                {
                    sum = sum + o;
                }

                if (sum < 0)
                {
                    l.insert(pii(sum, n - i));
                }
            }
            sum = 0;
            int final = 2 * n;
            rep2(i, n, 2 * n - 1)
            {
                if (a[i] == 1)
                {
                    sum = sum + m;
                }
                else if (a[i] == 2)
                {
                    sum = sum + o;
                }

                if (l.count(eter - sum) && sum<0)
                {
                    final = min(final, (int)i - n + 1 + l[eter - sum]);
                }
            }
            if (l.count(eter))
                final = min(final, l[eter]);
            cout << final << el;
        }
        else
        {
            cout << 0 << el;
        }
    }
    return 0;
}
