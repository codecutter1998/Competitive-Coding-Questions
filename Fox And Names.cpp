/*

https://codeforces.com/problemset/problem/510/C

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

ll n,flg;
vector<ll>graph[28],order,order1;
ll indegree[28],cnt;

void topo()
{
    while(order.size())
    {
        ll v=order[0];
        order.erase(order.begin());
        order1.pb(v);cnt++;
        
        for(auto child : graph[v])
        {
            indegree[child]--;
            if(!indegree[child])
                order.pb(child);
        }
    }
}

int main()
{
    cin>>n;
    
    string s[n];
    
    for(int i=0;i<n;i++)
        cin>>s[i];
        
    for(int i=0;i<n-1;i++)
    {
        ll len1=s[i].length();
        
        for(int j=i+1;j<n;j++)
        {
            ll k,len2=s[j].length();
            ll len=min(len2,len1);
            
            for(k=0;k<len;k++)
            {
                if(s[i][k]!=s[j][k])
                    break;
            }
            if(k<len)
            {    
                graph[s[i][k]-'a'+1].pb(s[j][k]-'a'+1);
                indegree[s[j][k]-'a'+1]++;
            }
            else
            {
                if(len1>len2)
                {
                    cout<<"Impossible\n";
                    return 0;
                }
            }
        }
    }
    
    for(int i=1;i<=26;i++)
        if(!indegree[i])
            order.pb(i);
            
    topo();
    
    if(cnt!=26)
        cout<<"Impossible\n";
    else
    {
        for(auto c: order1)
            cout<<(char)(c+96);
        cout<<endl;    
    }        
    
    
}
