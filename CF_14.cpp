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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Selection(int A[], int n)
{
    int i, j;
    int k, l;
    for (i = 0; i < n; i++)
    {
        k = l = i;
        for (j = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                l = j;
                k = j;
            }
        }
        swap(A[i], A[l]);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int a[n];
        rep(i, n)
        {
            cin >> a[i];
        }
        int final = 0;
        int flag = 1;
        int count1 = 0, count0 = 0;
        int j = 0;
        bitset<N> b;
        while (j <= n / 2 && flag)
        {
            int temp = 0;
            if (b[j] == 0)
            {

                rep2(i, j, n - 1)
                {
                    if (a[j] > a[i] && b[i] == 0)
                    {
                        temp++;
                        b[i] = 1;
                        flag = 0;
                    }
                }
                if (!flag)
                    count0 = temp + j;
            }
            j++;
        }
        j = n-1;
        flag = 1;
        while (j >= n / 2 && flag)
        {
            int temp = 0;
            if (b[j] == 0)
            {
                repr(i, j-1,0)
                {
                    if (a[j] < a[i] && b[i] == 0)
                    {
                        temp++;
                        b[i] = 1;
                        flag = 0;
                    }
                }
                if (!flag)
                    count1 = temp + n-1 - j;
            }
            j--;
        }
        cout << count1 + count0 << el;
    }
    return 0;
}