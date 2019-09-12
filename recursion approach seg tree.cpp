#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll MAX = 1e5+3;
const ll MAX1 =1e6+1;
ll segtree[MAX1];
ll n,q,a[MAX];


void build(ll node,ll start,ll end)
{
    if(start==end)
    {
        segtree[node]=a[start];
        return ;
    }
    ll mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    segtree[node]=min(segtree[2*node],segtree[2*node+1]);
    
}

void update(ll node,ll start,ll end,ll ind,ll val)
{
    if(start==end)
    {
        segtree[node]=val;
        a[ind]=val;
        return ;
    }
    ll mid=(start+end)/2;
    if(start<=ind && mid>=ind)
        update(2*node,start,mid,ind,val);
    else update(2*node+1,mid+1,end,ind,val);
    segtree[node]=min(segtree[2*node],segtree[2*node+1]);
    
}

ll query(ll node,ll start,ll end,ll l,ll r)
{
    if(start>r || end<l)
        return 1e9;
    
    else if(l<=start && end<=r)
    {
        return segtree[node];   
    }
    
    ll mid=(start+end)/2;
    ll p1=query(2*node,start,mid,l,r);
    ll p2=query(2*node+1,mid+1,end,l,r);
    return min(p1,p2);
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
   
    build(1,1,n);
    
    while(q--)
    {
        char ch;
        ll x,y;
        cin>>ch>>x>>y;
        if(ch=='q')
        {
            cout<<query(1,1,n,x,y)<<endl;
        }
        else if(ch=='u')
        {
            update(1,1,n,x,y);
        }
    }
   
}
