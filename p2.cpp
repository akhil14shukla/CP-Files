#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, temp;
    int i, j;
    cin >> n;
    int A[n][n];
    int count = 0;
    int check = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> temp;
            A[i][j] = temp;
        }
    }

    if (A[n - 1][n - 1] == -1)
    {
        cout << 0;
    }
    else
    {
        int count = 0;
        int check = 0;
        i = 0;
        j = 0;
        while ((i != n - 1 && j != n - 1) && check == 0)
        {
            if (A[i + 1][j] == A[i][j + 1] && A[i + 1][j] == -1)
            {
                check = 0;
                break;
            }
            if (j + 1 <= n - 1 && A[i][j + 1] != -1)
            {
                if (j == n - 2 && A[i + 1][j + 1] != -1)
                {
                    if (A[i][j + 1] == 1)
                    {
                        count++;
                    }
                    j++;
                }
                else if (j != n - 2)
                {
                    if (A[i][j + 1] == 1)
                    {
                        count++;
                    }
                    j++;
                }
            }
            if (i + 1 <= n - 1 && A[i + 1][j] != -1)
            {
                if (i == n - 2 && A[i + 1][j + 1] != -1)
                {
                    if (A[i + 1][j] == 1)
                    {
                        count++;
                    }
                    i++;
                }
                else if (i != n - 2)
                {
                    if (A[i + 1][j] == 1)
                    {
                        count++;
                    }
                    i++;
                }
            }
            if (i == n - 1 && j == n - 1)
            {
                check = 1;
            }
        }

        cout << count;
    }

    return 0;
}