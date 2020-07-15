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
TreeNode *swap(TreeNode *A)
{
    if (A == NULL)
    {
        return NULL;    
    }
    swap(A->left);
    TreeNode *temp = A->right;
    A->right = A->left;
    A->left = temp;
    swap(A->left);
    return A;
}

 int rec(TreeNode* A, TreeNode* root){
    if(A==NULL){
        return 0;
    }
    int x = rec(A->left,root);
    int y = rec(A->right,root);
    if(A==root && A->left == NULL){
        return 1+y;
    }
    else if(A == root && A->right == NULL){
        return 1+x;
    }
    return x<y?1+x:1+y;
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
    int B = rec(&A,&A);
    return 0;
}
