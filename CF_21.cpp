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
#define N 10000
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string v;
    cin >> v;
    int j = 0;
    //    cout<<v[1];
    while (j < v.size() - 1)
    {
        if (v[j] == '1' && v[j + 1] == '0')
        {
            if (j + 2 <= v.size() - 1 && j - 1 >= 0)
            {
                if (v[j + 2] == '1' && v[j - 1] == '1')
                {
                    v.erase(v.begin() + j);
                    if (j != 0)
                        j--;
                }
                else if (v[j + 2] == '0')
                {
                    v.erase(v.begin() + j + 1);
                    if (j != 0)
                        j--;
                }
            }
            else if (j == 0)
            {
                if (j + 3 <= v.size() - 1 && v[j + 3] == '0')
                {
                    v.erase(v.begin() + j + 1);
                    if (j != 0)
                        j--;
                }
                else{
                    v.erase(v.begin() + j);
                    if (j != 0)
                        j--;
                }
            }

        }
        j++;
    }
    rep(i, v.size())
    {
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    stack<int> s;
    s.pu
    while (t--)
    {
        solve();
    }
    return 0;
}