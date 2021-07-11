//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

//author: _mayor
#include <bits/stdc++.h>

using namespace std;

// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    return !root ? " null" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string a)
{
    istringstream b(a);
    return build(b);
}

TreeNode *build(istringstream &b)
{
    string s;
    b >> s;
    if (s == "null")
        return NULL;

    TreeNode *node = new TreeNode(stoi(s));
    node->left = build(b);
    node->right = build(b);
    return node;
}

int main()
{
    //init object and call the methods serialize() and deserialize
}
