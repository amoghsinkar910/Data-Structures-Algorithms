#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    if(str.length() == 0 || str[0] == 'N')
        return NULL;
        
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        vector <int> res = bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

void helper(Node* root,int d,int lev,map<int,pair<int,int>> &mp)
{
    if(root==NULL) return;
    if(lev >= mp[d].second){
        mp[d] = {root->data,lev};
    }
    helper(root->left,d-1,lev+1,mp);
    helper(root->right,d+1,lev+1,mp);
}

vector <int> bottomView(Node *root)
{
    if(root==NULL) return {};
    vector<int> ans;
    map<int,pair<int,int>> mp;
    helper(root,0,0,mp);
    
    for(auto it:mp)
    {
        ans.push_back(it.second.first);
    }
    return ans;
}

