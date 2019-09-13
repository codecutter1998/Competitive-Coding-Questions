//https://codeforces.com/contest/706/problem/D

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i, n)    for(ll i = 0; i < (n); ++i)
#define rep1(i, n)    for(ll i = 1; i <= (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define first ff
#define second ss 

const ll MAX=3e3+5;
const ll MAX1=1e2+5;
const ll INF=1e15+2;
const ll MOD=1e9+7;

#define pb push_back
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
#define pi pair<ll,ll>
#define map1 unordered_map

struct trie
{
    trie *bit[2];
    ll cnt;
};

trie *head;

void insert(ll x)
{
    trie *root = head;
    
    repD(i,30,0)
    {
        ll val = (x>>i)&1;
        if(root->bit[val]==NULL)
            root->bit[val] = new trie();
        root = root->bit[val];
        root->cnt++;
    }
}

void remove(ll x)
{
    trie *root = head;
    
    repD(i,30,0)
    {
        ll val = (x>>i)&1;
        root = root->bit[val];
        root->cnt--;
    }
}


ll maxxor(ll x)
{
    ll ans=0;
    trie *root = head;
    insert(0);
    
    repD(i,30,0)
    {
        ll val = (x>>i)&1;
        
        if(root->bit[val^1] && root->bit[val^1]->cnt>0)
        {
            ans+=(1<<i);
            root = root->bit[!val];
        }
        else
            root = root->bit[val];
    }
    return ans;
}

int main()
{
    faster;
    
    head = new trie();
    ll q;
    cin>>q;
    
    while(q--)
    {
        char ch;
        ll v;
        cin>>ch>>v;
        
        if(ch == '+')
        {
            insert(v);
        }
        else if(ch == '-')
        {
            remove(v);
        }
        else
        {
            cout<<maxxor(v)<<endl;
        }
    }
    
    
}
