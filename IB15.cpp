#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

vector<string> rec(vector<string> A)
{
    struct TrieNode *root = getNode();
    vector<string> f;
    for (int i = 0; i < A.size(); i++)
        insert(root, A[i]);
    for (int i = 0; i < A.size(); i++)
    {
        int p = 0;
        string t1 = "";
        struct TrieNode *temp = root->children[A[i][0] - 'a'];
        while (temp != NULL)
        {
            if(temp->count==1){
                t1.push_back(A[i][p]);
                break;
            }
            t1.push_back(A[i][p]);
            p++;
            temp = temp->children[A[i][p] - 'a'];
        }
        f.push_back(t1);
    }
    return f;
}

int main()
{
    vector<string> A = {"zebra", "dog", "duck", "dove"};
    vector<string> B = rec(A);
    rep(i, B.size())
    {
        cout << B[i] << " ";
    }
    return 0;
}