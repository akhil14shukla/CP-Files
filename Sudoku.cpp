#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int check(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C)
{
    int flag = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (A[i][j] > 1)
            {
                flag = 1;
                return 0;
            }
            if (B[i][j] > 1)
            {
                flag = 1;

                return 0;
            }
            if (C[i][j] > 1)
            {
                flag = 1;
                return 0;
            }
        }
    }
    return 1;
}

int recur(vector<vector<int>> &A, vector<vector<int>> &A1, vector<vector<int>> &B, vector<vector<int>> &C /*, int i1, int j1*/)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (A[i][j] == 0)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (A1[i][k] == 0)
                    {
                        A[i][j] = k + 1;
                        A1[i][k]++;
                        B[j][k]++;
                        C[3 * (i / 3) + j / 3][k]++;
                        if (check(A1, B, C))
                        {
                            int c = recur(A, A1, B, C);
                            if (c == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                A[i][j] = 0;
                                A1[i][k]--;
                                B[j][k]--;
                                C[3 * (i / 3) + j / 3][k]--;
                                continue;
                            }
                        }
                        else
                        {
                            A[i][j] = 0;
                            A1[i][k]--;
                            B[j][k]--;
                            C[3 * (i / 3) + j / 3][k]--;
                            /*free(&A);
                            free(&A1);
                            free(&B);
                            free(&C);*/
                            continue;
                        }
                    }
                }
                if (A[i][j] == 0)
                    return 0;
            }
        }
    }
    return 1;
}

vector<vector<int>> Sudoku(vector<vector<int>> &A)
{
    vector<vector<int>> A1 = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> B = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> C = {{0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (A[i][j] <= 9 && A[i][j] >= 1)
            {
                A1[i][A[i][j] - 1]++;
                B[j][A[i][j] - 1]++;
                C[3 * (i / 3) + j / 3][A[i][j] - 1]++;
            }
        }
    }
    recur(A, A1, B, C);
    return A;
}

int main()
{
    vector<vector<int>> A = {{0, 0, 9, 7, 0, 0, 0, 0, 3}, {0, 0, 4, 5, 0, 0, 0, 9, 0}, {1, 5, 0, 0, 9, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 8, 0, 0, 6, 1}, {0, 0, 2, 0, 0, 0, 8, 0, 0}, {0, 6, 0, 2, 0, 4, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 7, 0, 0}, {7, 9, 0, 0, 0, 0, 0, 5, 0}};
    /*vector<vector<int>> B =*/Sudoku(A);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}