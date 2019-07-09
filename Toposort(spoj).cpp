/*
https://www.spoj.com/problems/TOPOSORT/

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
const ll MAX=1e4+5;
const ll INF=1e15+2;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pi pair<ll,ll>

ll n,m,c_cnt;
vector<ll>graph[MAX],order;
ll indegree[MAX];
ll cnt;
set<ll>nodes;

void topo()
{
    while(!nodes.empty())
    {
        ll v=*nodes.begin();
        nodes.erase(nodes.begin());
        order.pb(v);cnt++;
        
        for(auto child : graph[v])
        {
            indegree[child]--;
            if(!indegree[child])
                nodes.insert(child);
        }
        
    }
}

int main()
{
    cin>>n>>m;
    
    for(int i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        graph[x].pb(y);
        indegree[y]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(!indegree[i])
            nodes.insert(i);
    }
    
    topo();
    
    if(cnt!=n)
        cout<<"Sandro fails.\n";
    else 
    {
        for(int i=0;i<order.size();i++)
            cout<<order[i]<<" ";
            
    }
}


