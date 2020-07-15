#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int t, test;
    cin >> t;
    for (test = 0; test < t; test++)
    { // n rows and m columns
        int n, i;
        cin >> n;
        int a[n];
        int b[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int j, final = 1;
        int k, l;
        for (i = 0; i < n; i++)
        {
            k = l = i;
            for (j = i; j < n; j++)
            {
                if (a[j] < a[k])
                {
                    if (b[j] == b[k])
                    {
                        final = 0;
                        continue;
                    }
                    else
                    {
                        l = j;
                        k = j;
                        final = 1;
                    }
                }
            }
            if(!final){
                break;
            }
            swap(a[i], a[l]);
            swap(b[i], b[l]);
        }
        // for (i = 0; i < n - 1; i++)
        // {
            // if (a[i] > a[i + 1])
            // {
                // final = 0;
                // break;
            // }
        // }
        if (final)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}