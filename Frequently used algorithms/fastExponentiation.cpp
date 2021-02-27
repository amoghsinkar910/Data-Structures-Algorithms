#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fastPower(ll base,ll pow)
{
    ll ans=1;
    while(pow>0)
    {
        if(pow&1)
            ans = ans*base;
        base = base*base;
        pow = pow/2;
    }
    return ans;
}

int main()
{
    ll n,p; //n^p
    cin>>n>>p;
    cout<<fastPower(n,p)<<endl;
    return 0;
}

