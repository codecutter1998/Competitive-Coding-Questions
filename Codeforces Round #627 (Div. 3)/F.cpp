#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define repA(i, a, n) for (ll i = a; i <= (n); ++i)
#define repD(i, a, n) for (ll i = a; i >= (n); --i)
#define trav(a, x) for (auto const &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define bpc(a) __builtin_popcount(a)
#define ff first
#define ss second
#define mk0(a) memset(a, 0, sizeof(a))
#define mk_1(a) memset(a, -1, sizeof(a))
#define ar array

const ll MAX = 2e5 + 5;
const ll MAX1 = 1e2 + 5;
const ll INF = 1e15 + 2;
const ll MOD = 998244353;

#define pb push_back
#define faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(0);
#define pi pair<ll, ll>
#define map1 unordered_map

inline ll nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
    ll ret = 0;
    bool f = 0;
    char ch = nc();
    while (ch > '9' || ch < '0')
        f ^= ch == '-', ch = nc();
    while (ch <= '9' && ch >= '0')
        ret = ret * 10 + ch - '0', ch = nc();
    return f ? -ret : ret;
}

ll power(ll base, ll ind, ll mod)
{
    ll res = 1;
    while (ind)
    {
        if (ind & 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        ind >>= 1;
    }
    return res;
}

ll inv(ll den, ll mod) { return power(den, mod - 2, mod); }


vector<ll>g[MAX];
ll col[MAX],n;
ll diff[MAX],maxdiff[MAX];


pair<ll,ll> dfs(ll rt=1,ll p=0)
{
    pair<ll,ll> sen = make_pair(-INF,INF);
    
    trav(child,g[rt])
    {
        if(child!=p)
        {
            pair<ll,ll> pp = dfs(child,rt);
            if(rt==1 and child==3)
            {
                cout<<pp.ff<<" "<<pp.ss<<"gg";
            }
            sen.ff=max(sen.ff,pp.ff);
            sen.ss=min(sen.ss,pp.ss);

        }
    }

    (sen.ff=-INF)?(col[rt]==1)?(sen.ff=1,sen.ss=0):(sen.ff=0,sen.ss=1):(col[rt]==1)?(sen.ff++):(sen.ss++);
    if(rt==1)cout<<sen.ff<<" "<<sen.ss<<" dddd";
    diff[rt]=sen.ff-sen.ss;
    return sen;
}

void dfs1(ll rt=1,ll p=0,ll mx=-INF)
{
    maxdiff[rt]=max(diff[rt],mx);
    mx=max(mx,maxdiff[rt]);

    rep(i,sz(g[rt]))
    {
        if(g[rt][i]!=p)
            dfs1(g[rt][i],rt,mx);
    }
}

void init()
{
    for(int i=1;i<=n;++i)
        maxdiff[i]=-INF;
}

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin>>n;
    rep1(i,n)
        cin>>col[i];
    init();
    rep(i,n-1)
    {
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }    
    dfs();
    //dfs1();
    rep1(i,n)cout<<diff[i]<<" ";
    cout<<"\n";
    rep1(i,n)
        cout<<maxdiff[i]<<" ";
}