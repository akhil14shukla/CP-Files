#include <bits/stdc++.h>
using namespace std;
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




int check(int a[],ll n){
    ll f = 1;
    for(int j = 0;j<10;j++){
        f = f*a[j];
        if(f>= n){
            return 1;
        }
    }
    return 0;
}


void solve()
{
    ll n;
    cin >> n;
    string s = "codeforces";
    int i = 0;
    int a[10]={1,1,1,1,1,1,1,1,1,1};
    while(1){
        if(check(a,n)){
            break;
        }
        if(i>9)i = 0;

        a[i]++;
        i++;
    }
    for(int j = 0;j<10;j++){
        rep(i,a[j])
        cout<<s[j];
    }
    cout<<endl;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}