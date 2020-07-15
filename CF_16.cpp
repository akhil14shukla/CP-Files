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


void solve(){
    ll n;
    cin>>n;
    vl v1(n);
    vector<pair<int,int>> p1(n);
    rep(i,n){
        cin>>v1[i];
        p1[i] = {v1[i],i};
    }
    sort(p1.begin(),p1.end());
    
}

int main(){
    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}