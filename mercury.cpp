#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool valid(ll x,ll y,ll h,ll w)
{
    if(x>=0&&x<h&&y>=0&&y<w) return true;
    return false;
}
void spread(vector<vector<ll> > mat,ll h,ll w,ll x,ll y,ll p,ll &cnt,map <pair<ll,ll>,bool> &dp,vector<pair<ll,ll>> pans)
{
    if(mat[x][y]<p)
    {
        cnt++;dp[{x,y}]=true;pans.push_back({x,y});
        if(valid(x-1,y,h,w)&&dp[{x-1,y}]==false)
        {
            spread(mat,h,w,x-1,y,p,cnt,dp,pans);
        }
        if(valid(x+1,y,h,w)&&dp[{x+1,y}]==false)
        {
            spread(mat,h,w,x+1,y,p,cnt,dp,pans);
        }
        if(valid(x,y-1,h,w)&&dp[{x,y-1}]==false)
        {
            spread(mat,h,w,x,y-1,p,cnt,dp,pans);
        }
        if(valid(x,y+1,h,w)&&dp[{x,y+1}]==false)
        {
            spread(mat,h,w,x,y+1,p,cnt,dp,pans);
        }
    }
    else return;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll h,w,q;
        cin>>h>>w>>q;
        vector<vector<ll> > mat(h,vector<ll>(w));
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)
            {
                cin>>mat[i][j];
            }
        }
        ll same=mat[0][0],tmp=1;
        for(ll i=0;i<h;i++)
        {
            for(ll j=0;j<w;j++)
            {
                if(mat[i][j]!=same){tmp=-1;break;}
            }
            if(tmp==-1) break;
        }
        vector<pair<ll,ll> > starting;
        vector<ll> power;
        ll st1=0,st2=0,subtask2=1,pidx=-1,maxipower=0;
        for(ll i=0;i<q;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            if(i==0){st1=x;st2=y;}
            if(z>maxipower){maxipower=z;pidx=i;}
            if(x!=st1||y!=st2){subtask2=-1;}
            starting.push_back({x-1,y-1});
            power.push_back(z);
        }
        if(subtask2==1)
        {
            map <pair<ll,ll>,bool> dp;
            ll x=starting[pidx].first,y=starting[pidx].second;
            ll p=power[pidx];
            ll lcnt=0;
            vector<pair<ll,ll>> possibleans;
            spread(mat,h,w,x,y,p,lcnt,dp,possibleans);
            for(ll i=0;i<q;i++)
            {
                ll cnt=0;
                if(i==pidx) cnt=lcnt;
                else{
                for(ll j=0;j<possibleans.size();j++)
                {
                    ll x=possibleans[j].first,y=possibleans[j].second;
                    if(mat[x][y]<power[i]) cnt++;
                }}
                cout<<cnt<<endl;
            }
        }
        else
        {
            ll cnt=0;
            vector<pair<ll,ll>> pans;
            for(ll i=0;i<q;i++)
            {
                map <pair<ll,ll>,bool> dp;
                ll cnt=0;
                ll x,y,p;
                x=starting[i].first;
                y=starting[i].second;
                p=power[i];
                if(tmp==1)
                {
                    if(same<p) cout<<h*w<<endl;
                    else cout<<"0"<<endl;
                    continue;
                }
                if(mat[x][y]>=p){cnt=0;}
                else
                {
                    spread(mat,h,w,x,y,p,cnt,dp,pans);
                }
                cout<<cnt<<endl;
            }
        }
    }
	return 0;
}

