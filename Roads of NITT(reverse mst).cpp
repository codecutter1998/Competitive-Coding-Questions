/*
author:codecutter1998

complexity : O(nlogn)

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll MAX=2e4+5;
const ll INF=1e15+2;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);
ll parent[MAX],size[MAX];
stack<ll>st,res1;
int mark[MAX];
vector<pair<ll,ll>>edges;

ll getPar(ll v)
{
    if(v!=parent[v])
        parent[v]=getPar(parent[v]);
    
    return parent[v];    
}

void doUnion(ll x,ll y)
{
    if(size[x]>size[y])
    {
        parent[y]=x;
        size[x]+=size[y];
    }
    else 
    {
        parent[x]=y;
        size[y]+=size[x];
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        //clean
        memset(parent,0,sizeof(parent));
        memset(size,0,sizeof(size));
        memset(mark,0,sizeof(mark));
        while(!st.empty())
            st.pop();
        while(!res1.empty())
            res1.pop();    
        edges.clear();
        
        edges.pb({0,0});
        ll n;
        cin>>n;
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            ll a,b;
            cin>>a>>b;
            edges.pb({a,b});
        }
        
        ll q;
        cin>>q;
        while(q--)
        {
            char ch;
            cin>>ch;
            if(ch=='R')
            {
                ll val;
                cin>>val;
                st.push(val);
                mark[val]=1;
            }
            else 
            {
                st.push(0);
            }
        }
        
        ll conPair=0;
        
        for(int i=1;i<=n;i++)
        {
            if(!mark[i])
            {
                auto it=edges[i];
                ll a1=getPar(it.first);
                ll a2=getPar(it.second);
                
                if(a1!=a2)
                {
                    conPair+=size[a1]*size[a2];
                    doUnion(a1,a2);
                }
            }
        }
        
        ll notConn=((n*(n-1))/2)-conPair;
        
        while(!st.empty())
        {
            ll val=st.top();
            st.pop();
            if(val==0)
                res1.push(notConn);
            else
            {
                auto it=edges[val];
                ll a1=getPar(it.first);
                ll a2=getPar(it.second);
                
                if(a1!=a2)
                {
                    notConn-=size[a1]*size[a2];
                    doUnion(a1,a2);
                }
            }
        }
        
        while(!res1.empty())
        {
            cout<<res1.top()<<endl;
            res1.pop();
        }
        if(t)
            cout<<"\n";
        
    }
}