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
bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    if (a.first != b.first)
        return (a.first > b.first);
    else
        return (a.second > b.second);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--)
    {
        string s1;
        cin >> s1;
        int n;
        cin >> n;
        char f[n];
        vector<pair<int, int>> a(n);
        rep(i, n)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), sortinrev);
        sort(s1.begin(), s1.end());
        string s2 = s1;

        // int count0 = 0;
        char final[n];
        rep(j, n)
        {
            int count1 = 0;
            int count0 = 0;
            // count0 = count(a.begin(), a.end(), 0); // counting zeros
            repr(i, a.size() - 1, 0)
            {
                if (a[i].first == 0)
                {
                    count0++;
                }
                else
                {
                    break;
                }
            }
            while (true)
            {
                count1 = count(s2.begin(), s2.end(), s2[s2.size() - 1]);
                if (count1 == count0)
                {
                    break;
                }
                else
                {
                    s2.pop_back();
                }
            }
            if (a.size() > 0)
            {
                while (count0--)
                {
                    final[a[a.size() - 1].second] = s2[s2.size() - 1];
                    int temp = a[a.size() - 1].second;
                    a.pop_back();
                    s2.pop_back();

                    rep(i, a.size())
                    {
                        a[i].first = a[i].first - abs(temp - a[i].second);
                    }
                }
                sort(a.begin(), a.end(), sortinrev);
            }
        }
        rep(i, n)
        {
            cout << final[i];
        }
        cout << el;
    }
    return 0;
}