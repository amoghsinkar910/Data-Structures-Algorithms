//https://leetcode.com/problems/binary-tree-right-side-view/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

void rec(TreeNode *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (ans.size() < level)
        ans.push_back(root->val);
    rec(root->right, level + 1, ans);
    rec(root->left, level + 1, ans);
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> ans;
    rec(root, 1, ans);
    return ans;
}

int main()
{
    //rightSideView(root)
    return 0;
}