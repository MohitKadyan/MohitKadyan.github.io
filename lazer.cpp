#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define fi first
#define se second
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mib map<int,bool>
#define mlb map<ll,bool>
#define f(i,k,n) for(int i=k;i<n;i++)
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
	io
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,q,ymin=inf,ymax=0;
		cin>>n>>q;
		vll a(n+1);
		f(i,0,n)
		{
			cin>>a[i+1];
			if(ymin>a[i+1]) ymin=a[i+1];
			if(ymax<a[i+1]) ymax=a[i+1];
		}
		while(q--)
		{
			ll x1,x2,y;
			cin>>x1>>x2>>y;
			if(y<ymin||y>ymax){cout<<"0"<<endl;continue;}
			ll cnt=0;
			f(i,x1,x2)
			{
				if((y>=a[i]&&y<=a[i+1])||(y<=a[i]&&y>=a[i+1])) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}