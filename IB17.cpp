#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

//   Definition for binary tree
struct TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> der(TreeNode *A)
{
    stack<TreeNode *> s1, s2;
    vector<vector<int>> final;
    vector<int> temp;
    int flag = 0;
    if (A != NULL)
    {
        temp.push_back(A->val);
        final.push_back(temp);
        if (A->left != NULL)
            s2.push(A->left);
        if (A->right != NULL)
            s2.push(A->right);
        flag = 1;
    }
    temp.clear();
    TreeNode *root = A;
    while (!s1.empty() || !s2.empty())
    {
        TreeNode *A1;
        if (flag == 0)
        {
            A1 = s1.top();
            if (s1.size() != 0)
                s1.pop();
            temp.push_back(A1->val);
            if (A1->left != NULL)
                s2.push(A1->left);
            if (A1->right != NULL)
                s2.push(A1->right);
        }
        else
        {
            A1 = s2.top();
            if (s2.size() != 0)
                s2.pop();
            temp.push_back(A1->val);
            if (A1->right != NULL)
                s1.push(A1->right);
            if (A1->left != NULL)
                s1.push(A1->left);
        }

        if (temp.size() != 0 && flag == 0 && s1.size()==0)
        {
            final.push_back(temp);
            temp.clear();
            flag = !flag;
        }
                if (temp.size() != 0 && flag == 1 && s2.size()==0)
        {
            final.push_back(temp);
            temp.clear();
            flag = !flag;
        }
    }
    return final;
}

int main()
{
    TreeNode A(2);
    TreeNode t1(3);
    TreeNode t2(4);
    TreeNode t3(5);
    TreeNode t4(6);
    TreeNode t5(7);
    TreeNode t6(8);
    A.left = &t1;
    A.right = &t2;
    t1.left = &t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    vector<vector<int>> B = der(&A);
    return 0;
}