#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        if(b>a)
        {
            if((b-a)%2==0){ans=2;}
            else ans=1;
        }
        else if(b<a)
        {
            if((a-b)%2==0){ans=1;}
            else ans=2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
