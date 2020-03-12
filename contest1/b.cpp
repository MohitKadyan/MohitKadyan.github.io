#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vll a(n);
        map<ll,ll> p;
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<m;i++)
        {
            int x;
            cin>>x;
            p[x-1]=1;
        }
        ll swaps=-1;
        while(1)
        {
            swaps=-1;
            for(ll i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1]&&p[i]==1)
                {
                    swap(a[i],a[i+1]);swaps++;
                }
            }
            if(swaps==-1) break;
        }
        ll tmp=-1;
        for(ll i=0;i<n-1;i++)
        {
            if(a[i]>a[i+1]) {tmp=0;break;}
        }
        if(tmp==-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
