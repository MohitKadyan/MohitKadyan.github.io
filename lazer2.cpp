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
#define x second
#define y first
#define MAX 1000000
typedef pair<int,int >point;
struct event 
{
    point p1,p2;
    ll type;
    event() {};
    event(point p1,point p2, ll type) : p1(p1), p2(p2),type(type) {};
};
ll n,e;
event events[MAX];
bool compare(event a, event b) 
{ 
    return a.p1.x<b.p1.x; 
}
set<point >s;
void hv_intersection(ll x1,ll x2,ll &cnt)
{
    for (ll i=0;i<e;++i)
        {
                event c = events[i];
                //cout<<c.p1.x<<" "<<c.p1.y<<" "<<c.p2.x<<" "<<c.p2.y<<" "<<endl;
                if (c.type==0) s.insert(c.p1);
                else if (c.type==1) s.erase(c.p2);
                else
                {
                        for (typeof(s.begin()) it=s.lower_bound(make_pair(c.p1.y,-1));it!=s.end() && it->y<=c.p2.y; it++)
                                {cnt++;printf("%d, %d\n", events[i].p1.x, it->y);}
                }
        }
}/*
int main () 
{
    scanf("%d", &n);
    int p1x,p1y,p2x,p2y;
        for (int i=0;i<n;++i) 
        {
                scanf("%d %d %d %d", &p1x, &p1y,&p2x, &p2y);
        if(p1x==p2x)             
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else                   
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            events[e++]=event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
        }
    sort(events, events+e,compare);
    hv_intersection();
    return 0;
}*/
int main()
{
    io
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vll a(n+1);
        f(i,0,n)
        {
            cin>>a[i+1];
        }
        int p1x,p1y,p2x,p2y;
        for (int i=0;i<n-1;++i) 
        {
            p1x=i+1;p1y=a[i+1];p2x=i+1;p2y=a[i+2];
        if(p1x==p2x)             
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),2);
        }
        else                   
        {
            events[e++]=event(make_pair(p1y,p1x),make_pair(p2y,p2x),0);
            events[e++]=event(make_pair(p2y,p2x),make_pair(p1y,p1x),1);
        }
        }
        while(q--)
        {
            ll x1,x2,y;
            cin>>x1>>x2>>y;
            //p1x=x1,p1y=y,p2x=x2,p2y=y
            events[e++]=event(make_pair(y,x1),make_pair(y,x2),0);
            events[e++]=event(make_pair(y,x2),make_pair(y,x1),1);
            ll cnt=0;
            sort(events, events+e,compare);
            hv_intersection(x1,x2-1,cnt);
            cout<<cnt<<endl;
        }
    }
    return 0;
}