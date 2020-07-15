#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i, temp;
    int sumt = 0;
    cin >> n;
    vector<int> A;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == 0)
        {
            A.push_back(-1);
            sumt = sumt - 1;
        }
        else
        {
            A.push_back(1);
            sumt = sumt + 1;
        }
    }
    int j, k;
    j = 0;
    k = A.size() - 1;
    int sum1 = 0;
    int sum2 = sumt;
    while (sum1 <= sum2 && j <= n - 1)
    {
        sum1 = sum1 + A[j];
        sum2 = sum2 - A[j];
        j++;
    }
    if (j == n - 1 && sum1<sum2)
    {
        cout << 0;
    }
    else
    {
        cout << j;
    }
    return 0;
}