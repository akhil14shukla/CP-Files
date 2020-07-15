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

    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        string s1;
        cin >> s1;
        vi v1;
        // v1.pb(0);
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1')
            {
                v1.pb(i);
            }
        }
        // v1.pb(s1.size() - 1);
        int temp;
        int final = 0;
        if (v1.size())
        {
            if (s1[0] == '0')
                final = final + (v1[0] - 0) / (k + 1);
            if (s1[n - 1] == '0')
                final = final + (n - 1 - v1[v1.size() - 1]) / (k + 1);
        }
        else
        {
            final++;
            final = final + (n-1) / ( k + 1);

        }
        if (v1.size() > 1)
            rep(i, v1.size() - 1)
            {
                final = final + (v1[i + 1] - v1[i] - 1) / (2 * k + 1);
            }
        cout << final << el;
    }
}