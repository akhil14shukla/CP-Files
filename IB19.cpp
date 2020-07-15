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

// void rec1(TreeNode *A, int B, map<TreeNode *, int> &m, int &flag)
// {
//     if (A == NULL)
//     {
//         return;
//     }
//     if (A->val == B)
//     {
//         m[A] = A->val;
//         flag = 1;
//         return;
//     }
//     m[A] = A->val;
//     if (!flag && A->left!=NULL)
//     {

//         m[A->left] = A->left->val;
//         rec1(A->left, B, m, flag);
//         if (!flag)
//         {
//             m.erase(A->left);
//         }
//     }

//     if (!flag && A->right!=NULL)
//     {
//         m[A->right] = A->right->val;
//         rec1(A->right, B, m, flag);
//         if (!flag)
//         {
//             m.erase(A->right);
//         }
//     }
//     if(!flag){
//         m.erase(A);
//     }
// }

// int rec(TreeNode *A,int B,int C)
// {
//     map<TreeNode*, int> m1,m2;
//     int flag = 0;
//     rec1(A,B,m1,flag);
//     if(flag == 0){
//         return -1;
//     }
//     flag = 0;
//     rec1(A,C,m2,flag);
//     if(flag == 0){
//         return -1;
//     }
//     map<TreeNode*, int>::iterator i;
//     for(i = m1.end();i!=m1.begin();){
//         i--;
//         if(m2.find(i->first)!=m2.end()){
//             return m2[i->first];
//         }
//     }
//     return 0;
// }

// void rec(TreeNode *A)
// {
//     if (A == NULL)
//     {
//         return;
//     }
//     rec(A->left);
//     TreeNode *temp = A->right;
//     if (A->left != NULL)
//     {
//         A->right = A->left;
//         TreeNode *t = A;
//         while (t->right != NULL)
//         {
//             t = t->right;
//         }
//         t->right = temp;
//         A->left = NULL;
//     }
//     rec(A->right);
// }
// vector<int> order(vector<int> &A, vector<int> &B)
// {
//     vector<int> C(A.size());
//     for (int i = 0; i < A.size(); i++)
//     {
//         C[i] = -1;
//     }
//     map<int, int> m;
//     for (int i = 0; i < A.size(); i++)
//     {
//         m[A[i]] = i;
//     }
//     // sort(m.begin(), m.end());
//     map<int, int>::iterator i;
//     for (i = m.begin(); i != m.end(); i++)
//     {
//         int j = B[(i)->second];
//         int k = 0;
//         while (j)
//         {
//             if (C[k] == -1)
//             {
//                 j--;
//             }
//             k++;
//         }
//         if (C[k] == -1){
//             C[k] = i->first;
//         }
//         else{
//             while(C[k]!=-1 && k<A.size()){
//                 k++;
//             }
//             C[k] = i->first;
//         }
//     }
//     return C;
// }

int rec(map<int, vector<int>> m, int n, int &final)
{
    int count = 0;
    for (int i = 0; i < m[n].size(); i++)
    {
        int count1 = rec(m, m[n][i], final);
        
        if (count1 % 2 == 0)
        {
            final++;
            // count = 0;
        }
        else{
            count = count + count1;
        }
        count1 = 0;

        if (n == 1)
        {
            count = 0;
        }
        if (i == m[n].size() - 1)
        {
            return count + 1;
        }
    }

    if (m[n].size() == 0)
        return 1;
}

int solve(int A, vector<vector<int>> &B)
{
    if (A % 2 == 1)
    {
        return -1;
    }
    bool visit[A];
    fill_n(visit,visit + A,false);
    // map<int,int> m(A);
    map<int, vector<int>> m;
    for (int i = 0; i < B.size(); i++)
    {
        m[B[i][0]].push_back(B[i][1]);
    }
    int count = 0;
    int final = 0;
    rec(m, 1, final);
    return final;
}

// TreeNode *ten(TreeNode *A)
// {
//     rec(A);
//     return A;
// }

int main()
{
    // TreeNode A(2);
    // TreeNode t1(3);
    // TreeNode t2(4);
    // TreeNode *t3 = NULL;
    // TreeNode t4(6);
    // TreeNode t5(7);
    // TreeNode t6(8);
    // A.left = &t1;
    // A.right = &t2;
    // t1.left = t3;
    // t1.right = &t4;
    // t2.left = &t5;
    // t2.right = &t6;
    // TreeNode *B = ten(&A);
    // vector<int> A = {5, 3, 2, 6, 1, 4};
    // vector<int> B = {0, 1, 2, 0, 3, 2};
    // vector<int> C = order(A, B);
    // rep(i, C.size())
    // {
    //     cout << C[i] << " ";
    // }
    vector<vector<int>> D = {{1, 2}, {1, 3}, {1, 4}, {3, 5}, {4, 6}};

    vector<vector<int>> E = {{6, 11}, {8, 15}, {5, 6}, {12, 16}, {2, 5}, {2, 13}, {8, 12}, {1, 2}, {2, 4}, {1, 8}, {6, 14}, {3, 10}, {1, 3}, {1, 7}, {3, 9}};
    cout << solve(16, E);
    return 0;
}