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
        string start;
        cin >> start;
        cout << start[0];
        if (start.size() > 2)
            rep2(i, 1, start.size() - 3)
            {
                cout << start[i];
                i++;
            }
        cout << start[start.size() - 1] << el;
    }

    return 0;
}