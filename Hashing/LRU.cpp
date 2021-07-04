//https://leetcode.com/problems/lru-cache/

//author: _mayor
#include <bits/stdc++.h>

#define for0(i, n) for (long long i = 0; i < n; i++)
#define for1(i, n) for (long long i = 1; i <= n; i++)
#define forc(i, l, r) for (long long i = l; i <= r; ++i)
#define forr0(i, n) for (long long i = n - 1; i >= 0; i--)
#define forr1(i, n) for (long long i = n; i >= 1; i--)

#define pb push_back
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef long long int lli;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

//DLL and map implementation
class node
{
public:
    int val;
    int key;
    node *prev;
    node *next;
    node(int k, int v)
    {
        key = k;
        val = v;
    }
};
node *head = new node(-1, -1);
node *tail = new node(-1, -1);
int cap;
unordered_map<int, node *> mp; //key->node

//adds node just after head so that the most recently used
//node is always just after the head node
void add(node *newnode)
{
    node *x = head->next; //last updated node
    //adding newnode just after head
    //and then updating the next, prev links
    newnode->next = x;
    newnode->prev = head;
    head->next = newnode;
    x->prev = newnode;
}

void del(node *delnode)
{
    node *delprev = delnode->prev;
    node *delnext = delnode->next;
    delprev->next = delnext;
    delnext->prev = delprev;
}

LRUCache(int capacity)
{
    cap = capacity;
    head->next = tail;
    tail->prev = head;
}

//if value already present then erase it from map
//delete the node and add after head
//update the new address of the node in map
int get(int key)
{
    if (mp.find(key) != mp.end())
    {
        node *cur = mp[key];
        int ans = cur->val;
        mp.erase(key);
        del(cur);
        add(cur);
        mp[key] = head->next;
        return ans;
    }
    return -1;
}

//if node already exists then delete the node
//then if capacity is alredy full then delete the node just before tail
//i.e the LRU node
//add node after head with value and update address of the node in map
void put(int key, int value)
{
    if (mp.find(key) != mp.end())
    {
        node *exist_node = mp[key];
        mp.erase(key);
        del(exist_node);
    }
    if (mp.size() == cap)
    {
        mp.erase(tail->prev->key);
        del(tail->prev);
    }
    add(new node(key, value));
    mp[key] = head->next;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}