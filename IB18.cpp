#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#include "Trie.h"
using namespace std;

//   Definition for binary tree
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// struct TreeLinkNode
// {
//     TreeLinkNode *left;
//     TreeLinkNode *right;
//     TreeLinkNode *next;
// };

TreeLinkNode *rec(TreeLinkNode *A)
{
    queue<TreeLinkNode *> q1, q2;
    A->next = NULL;
    int flag = 0;
    if (A != NULL)
    {
        if (A->left != NULL)
            q1.push(A->left);
        if (A->right != NULL)
            q1.push(A->right);
        flag = 0;
    }
    while (!q1.empty() || !q2.empty())
    {
        TreeLinkNode *temp;
        if (flag == 0 && q1.size() != 0)
        {
            temp = q1.front();
            q1.pop();
            if (temp != NULL && q1.size() != 0)
            {
                temp->next = q1.front();
            }
            else if (temp != NULL && q1.size() == 0)
            {
                temp->next = NULL;
            }
            if (temp != NULL) 
            {
                if (temp->left != NULL)
                    q2.push(temp->left);
                if (temp->right != NULL)
                    q2.push(temp->right);
            }
            if (q1.empty())
            {
                flag = !flag;
            }
        }
        if (flag == 1 && q2.size() != 0)
        {
            temp = q2.front();
            q2.pop();
            if (temp != NULL && q2.size() != 0)
            {
                temp->next = q2.front();
            }
            else if (temp != NULL && q2.size() == 0)
            {
                temp->next = NULL;
            }
            if (temp != NULL)
            {
                if (temp->left != NULL)
                    q1.push(temp->left);
                if (temp->right != NULL)
                    q1.push(temp->right);
            }
            if (q2.empty())
            {
                flag = !flag;
            }
        }
    }
    return A;
}

int main()
{
    TreeLinkNode  A(2);
    TreeLinkNode  t1(3);
    TreeLinkNode  t2(4);
    TreeLinkNode  *t3 = NULL;
    TreeLinkNode  t4(6);
    TreeLinkNode  t5(7);
    TreeLinkNode  t6(8);
    A.left = &t1;
    A.right = &t2;
    t1.left = t3;
    t1.right = &t4;
    t2.left = &t5;
    t2.right = &t6;
    struct TreeNode *B = rec(&A);
    return 0;
}