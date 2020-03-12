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
        string s;
        cin>>s;
        vll p(m);
        for(ll i=0;i<m;i++) cin>>p[i];
        map<char,ll> mp;
        map<char,ll> fcnt;
        map<ll,ll> error;
        for(ll i=0;i<m;i++)
        {
            error[p[i]-1]+=1;
        }
        ll comp=0;
        for(ll i=n-1;i>=0;i--)
        {
            comp+=error[i];
            fcnt[s[i]]+=comp+1;
        }
        for(char c='a';c<='z';c++)
        {
            cout<<fcnt[c]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

