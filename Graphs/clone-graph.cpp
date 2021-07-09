//https://leetcode.com/problems/clone-graph/

//author: _mayor
#include <bits/stdc++.h>
using namespace std;

unordered_map<Node *, Node *> mp;
Node *cloneGraph(Node *node)
{
    if (!node)
        return node;
    if (mp.find(node) != mp.end())
        return mp[node];

    Node *clone = new Node(node->val);
    mp[node] = clone;
    for (Node *nei : node->neighbors)
    {
        clone->neighbors.push_back(cloneGraph(nei));
    }
    return clone;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cloneGraph()
    return 0;
}