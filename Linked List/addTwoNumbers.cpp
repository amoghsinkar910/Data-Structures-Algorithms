//author: _mayor
#include <bits/stdc++.h>   

#define for0(i, n) for (long long  i = 0; i < n; i++) 
#define for1(i, n) for (long long  i = 1; i <= n; i++) 
#define forc(i, l, r) for (long long  i = l; i <= r; ++i) 
#define forr0(i, n) for (long long  i = n - 1; i >= 0; i--) 
#define forr1(i, n) for (long long  i = n; i >= 1; i--) 

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *res = l1, *last = NULL;
    int c = 0, keep, sum;
    while (l1 != NULL && l2 != NULL)
    {
        sum = (l1->val + l2->val + c);
        if (sum >= 10)
        {
            keep = sum % 10;
            l1->val = keep;
            c = sum / 10;
        }
        else
        {
            keep = sum;
            l1->val = keep;
            c = 0;
        }
        last = l1;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1 != NULL)
    {
        sum = (l1->val + c);
        if (sum >= 10)
        {
            keep = sum % 10;
            l1->val = keep;
            c = sum / 10;
        }
        else
        {
            keep = sum;
            l1->val = keep;
            c = 0;
        }
        last = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        last->next = l2;
    }
    while (l2 != NULL)
    {
        sum = (l2->val + c);
        if (sum >= 10)
        {
            keep = sum % 10;
            l2->val = keep;
            c = sum / 10;
        }
        else
        {
            keep = sum;
            l2->val = keep;
            c = 0;
        }
        last = l2;
        l2 = l2->next;
    }

    if (last != NULL && c)
    {
        last->next = new ListNode(c);
    }
    return res;
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //init LL and call addTwoNumbers function
    
    return 0;
}