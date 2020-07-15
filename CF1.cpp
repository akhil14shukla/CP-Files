#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int rsum(int a[], int n)
{
    int sm;
    int rsum1 = 0;
    for (sm = 0; sm < n; sm++)
    {
        rsum1 = rsum1 + a[sm];
    }
    return rsum1;
}
int main()
{

    int t, test;
    cin >> t;
    for (test = 0; test < t; test++)
    { // n rows and m columns
        int m, n, i, j;
        cin >> n;
        cin >> m;
        int row[n];
        int col[m];
        int a[n][m];
        for (i = 0; i < n; i++)
        {
            row[i] = 0;
        }
        for (i = 0; i < m; i++)
        {
            col[i] = 0;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 1)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        int ash = 0;
        int viv = 1;
        int control_row = 0;
        int control_col = 0;
        while (control_row != -1 && control_col != -1)
        {
            control_row = -1;
            control_col = -1;
            for (i = 0; i < n; i++)
            {
                if (row[i] == 0)
                {
                    control_row = i;
                }
            }
            for (i = 0; i < m; i++)
            {
                if (col[i] == 0)
                {
                    control_col = i;
                }
            }
            if (control_row == -1 || control_col == -1)
            {
                if (ash == 1)
                {
                    cout << "Ashish" << endl;
                    break;
                }
                else
                {
                    cout << "Vivek" << endl;
                    break;
                }
            }
            a[control_row][control_col] = 1;
            if (ash == 0)
            {
                ash = 1;
                row[control_row] = 1;
                col[control_col] = 1;
                viv = 0;
            }
            else
            {
                ash = 0;
                row[control_row] = 1;
                col[control_col] = 1;
                viv = 1;
            }
        }
    }
    return 0;
}