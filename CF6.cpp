#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (int i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    rep(k, test)
    {
        int n, x, m;
        cin >> n >> x >> m;
        int li = 1, ri = n;
        vector<int> v1(2);
        v1[0] = x;
        v1[1] = x;
        rep(l, m)
        {
            cin >> li >> ri;
            if ((li <= x && ri >= x) || !( li>v1[1] || ri<v1[0]) ) //
            {
                v1[0] = min(v1[0], li);
                v1[1] = max(v1[1], ri);
            }
        }
        int final = v1[1] - v1[0] + 1;
        printf("%d\n", final);
    }
    return 0;
}