#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
    int n, test,temp;
    cin >> n;
    vector<pair<int, int>> v1;
    vector<pair<int, int>> v2;
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        v1.push_back(make_pair(temp,i));
    }
    int c[n];
    int hash[n];
    for (i = 0; i < n; i++)
    {
        hash[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        v2.push_back(make_pair(temp,i));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (j = 0; j < n; j++)
    {
        c[j] = v1[j].second - v2[j].second;
        if (c[j] < 0)
        {
            c[j] = c[j] + n;
        }
        hash[c[j]]++;
    }
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (hash[i] > max)
        {
            max = hash[i];
        }
    }
    cout << max << endl;

    return 0;
}