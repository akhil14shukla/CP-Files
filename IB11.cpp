#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

string rec(long A, long B)
{
    long double C = double(A) / double(B);
    int flag = 0;
    if (B < 0)
    {
        flag = 1;
        B = -1 * B;
    }
    long result = A / B;
    if (flag)
    {
        result = -1 * result;
    }

    if (A % B == 0)
    {
        string f = to_string(result);
        return f;
    }
    else
    {
        string f = to_string(result);
        A = abs(A);
        B = abs(B);
        f.append(".");
        long temp = A;
        map<long, long> m;
        string remain = "";
        long rem = temp % B;
        for (int i = 0;; i++)
        {
            if (rem == 0)
            {
                break;
            }
            else
            {
                if (m.find(rem) == m.end())
                {
                    m[(rem)] = i;
                    remain.append(to_string((rem * 10) / B));
                    rem = (rem * 10) % B;
                }
                else
                {
                    remain.insert(m[rem], "(");
                    remain.append(")");
                    break;
                }
            }
        }
        if (abs(A) < abs(B) && C < 0)
        {
            f.insert(0, "-");
        }
        f.append(remain);

        return f;
    }
}

int main()
{
    cout << rec(-1,-2147483648);
    return 0;
}