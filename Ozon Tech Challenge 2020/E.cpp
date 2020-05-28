#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define repA(i, a, n) for (ll i = a; i <= (n); ++i)
#define repD(i, a, n) for (ll i = a; i >= (n); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()
#define bpc(a) __builtin_popcount(a)
#define ff first
#define ss second
#define mk0(a) memset(a, 0, sizeof(a))
#define mk_1(a) memset(a, -1, sizeof(a))

const ll MAX = 1e5 + 5;
const ll MAX1 = 1e2 + 5;
const ll INF = 1e15 + 2;
const ll MOD = 1e9 + 7;

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


//lca
ll p[MAX][20];
vector<ll>g[MAX];
ll lvl[MAX];


void dfs(ll rt,ll pa)
{
    lvl[rt]=1+lvl[pa];
    p[rt][0]=pa;

    for(int i=0;i<sz(g[rt]);++i)
    {
        if(g[rt][i]!=pa)
        {
            dfs(g[rt][i],rt);
        }
    }
}
void input()
{
    for(int i=0;i<MAX;++i)
    {
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    lvl[0]=-1;
}

ll lca(ll u,ll v)
{
    if(lvl[u]<lvl[v])
        swap(u,v);
    ll lg=0;
    for(;(1<<lg)<=lvl[u];lg++);
    lg--;

    for(int i=lg;i>=0;--i)
    {
        if(lvl[u]-(1<<i)>=lvl[v])
            u=p[u][i];
    }
    if(u==v)return u;
    for(int i=lg;i>=0;--i)
    {
        if(p[u][i]!=-1 and p[u][i]!=p[v][i])
            u=p[u][i],v=p[v][i];
    }
    return p[u][0];
}
void solve()
{
    mk_1(p);
    input();
    dfs(1,0);
    for(int i=0;i<20;++i)
    {
        for(int j=1;j<=MAX;++j)
        {
            if(p[j][i-1]!=-1)
                p[j][i]=p[p[j][i-1]][i-1];
        }
    }

}

//set union

ll par[MAX],sz[MAX];

ll getPar(ll u)
{
    if(u==par[u])return u;
    return par[u]=getPar(par[u]);
}

void init()
{
    rep(i,MAX)par[i]=i,sz[i]=1;
}

void merge(ll u,ll v)
{
    ll p1=getPar(u),p2=getPar(v);
    if(p1==p2)return ;

    if(sz[p1]>sz[p2])
        swap(p1,p2);
    par[p1]=p2;
    sz[p2]+=sz[p1];
    sz[p1]=0;    
}

void solve1()
{
    init();

}

int main()
{
    faster;
    #ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
}    