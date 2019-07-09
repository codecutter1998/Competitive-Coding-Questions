/*

author:Rohit Kulkarni

complexity : O(E)
*/


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll MAX=1e2+5;
const ll INF=1e15+2;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);

ll n;
vector<ll>graph[MAX];
ll dfsNumber[MAX],cnt,low[MAX];
int vis[MAX],art_pt[MAX],child_cnt,root;



void dfs(ll v,ll p)
{
    low[v]=dfsNumber[v]=cnt;cnt++;
    vis[v]=1;
    for(auto child : graph[v])
    {
        if(child == p)
            continue;
            
        if(vis[child])
        {
            low[v]=min(low[v],dfsNumber[child]);
        }
        else
        {
            if(v==root)
                child_cnt++;
            
            dfs(child,v);
            
            if(v!=root && low[child]>=dfsNumber[v])
                art_pt[v]=1;
            
            low[v]=min(low[v],low[child]);    
        }
    }
}

int main()
{
    faster;
    ll c_cnt=0;
    
    while(1)
    {
        c_cnt++;
        cin>>n;
        if(!n)break;
        if(c_cnt>1)
            cout<<endl;
        memset(vis,0,sizeof(vis));
        memset(art_pt,0,sizeof(art_pt));
        memset(dfsNumber,0,sizeof(dfsNumber));
        memset(low,0,sizeof(low));
        
        for(int i=0;i<=n;i++)
            graph[i].clear();
            
        map<string,ll>mp;
        map<ll,string>rmp;
        
        for(int i=1;i<=n;i++)
        {
            string s;
            cin>>s;
            mp[s]=i;
            rmp[i]=s;
        }
        
        ll m;
        cin>>m;
        
        for(int i=1;i<=m;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            ll u=mp[s1],v=mp[s2];
            graph[u].pb(v);
            graph[v].pb(u);
        }
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                root=i;
                child_cnt=0;
                dfs(i,0);
                
                if(child_cnt>1)
                    art_pt[root]=1;
            }
        }
        multiset<string>ss;
        ll cnt1=0;
        for(int i=1;i<=n;i++)
        {
            if(art_pt[i])
            {
                cnt1++;
                ss.insert(rmp[i]);
            }
        }
        
        cout<<"City map #"<<c_cnt<<": "<<cnt1<<" camera(s) found\n";
        for(auto s1:ss)
            cout<<s1<<endl;
    }
}