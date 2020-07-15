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



void solve(){
    ll n;
    cin>>n;
    int a[2*n];
    rep(i,2*n){
        cin>>a[i];
    }
    vector<int> o;
    vector<int> e;
    rep2(i,0,2*n-1){
        if(a[i]%2== 0){
            e.pb(i+1);
        }
        else{
            o.pb(i+1);
        }
    }
    n = n-1;
    while(n>0 && (e.size()>=2 || o.size()>=2)){
        if(e.size()>=2){
            cout<<e[e.size()-2]<<" "<<e[e.size()-1]<<el;;
            e.pop_back();
            e.pop_back();
            n--;
        }
        else if(o.size()>=2){
            cout<<o[o.size()-2]<<" "<<o[o.size()-1]<<el;;
            o.pop_back();
            o.pop_back();
            n--;
        }
    }
    while(n>0){
        cout<<e[e.size()-1]<<" "<<o[o.size()-1]<<el;;
            e.pop_back();
            o.pop_back();
            n--;
    }
}

int main(){

    int test;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}