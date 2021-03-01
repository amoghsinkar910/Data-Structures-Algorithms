//author: _mayor

//Time: O(nlogn) 
//using the merge sort technique to sort LL by splitting the array
//into two halves and mergin them again in sorted order
//Divide and conquer

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

const ll N = 1e5 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//sort and merge two parts => conquer
ListNode *merge(ListNode *l, ListNode *r)
{
    if (l == NULL)
        return r;
    if (r == NULL)
        return l;

    if (l->val < r->val)
    {
        l->next = merge(l->next, r);
        return l;
    }
    else
    {
        r->next = merge(l, r->next);
        return r;
    }
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    //middle of LL
    ListNode *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;

    //split into two halves => divide
    return merge(sortList(head), sortList(mid));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll i, j, k, n, cnt = 0;
        //call sortList()
    }

    return 0;
}