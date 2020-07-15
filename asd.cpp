#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int solve(vector<int> &A, int B, int C) // C is the number for comparison and B is the number of digtis
{
    string s = to_string(C);
    int count = 0;

    if (A.size() == 0)
    {
        return 0;
    }
    int i;
    if (s.size() < B)
    {
        return 0;
    }
    if (B < s.size() && B != 1)
    {
        if (A[0] == 0)
        {
            return int((A.size() - 1) * pow(A.size(), B - 1));
        }
        else
        {
            return int(pow(A.size(), B));
        }
    }
    if (B == s.size())
    {
        int first = C;
        int D[s.size()];
        for (i = B - 1; i >= 0; i--)
        {
            D[B - 1 - i] = first / int(pow(10, i));
            first = first % int(pow(10, i));
        }
        int k;
        for (k = B - 1; k >= 0; k--)
        {
            first = D[B - 1 - k];
            int fact = int(pow(A.size(), k));
            if (k == B - 1 && A[0] == 0 && B > 1)
            {
                i = 1;
            }
            else
            {
                i = 0;
            }
            for (; i < A.size(); i++)
            {
                if (A[i] < first)
                {
                    count = count + fact;
                }
                if (A[i] == first)
                {
                    break;
                }
            }
            if (A[i] != first)
            {
                break;
            }
        }
        return count;
    }
}
int f(int A, int B)
{
    int c = A + B - 2;
    int i;
    long long fact_sum = 1;
    long long factA = 1, factB = 1;
    if (A == 0 && B == 0)
    {
        return 0;
    }
    if (c < 0)
    {
        return 1;
    }
    if (c == 0)
    {
        return 2;
    }
    for (i = 1; i <= c; i++)
    {
        fact_sum = fact_sum * i;
    }
    for (i = 1; i <= A - 1; i++)
    {
        factA = factA * i;
    }
    for (i = 1; i <= B - 1; i++)
    {
        factB = factB * i;
    }
    return fact_sum / (factA * factB);
}

int main()
{
    vector<int> a = {0, 1, 2, 5};
    cout << f(100,1);
    return 0;
}