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
#define ar array

const ll MAX = 1e3 + 5;
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

ar<ll,2> a[MAX][MAX];
char dir[MAX][MAX];
int vis[MAX][MAX];
ll n;

int connect(ll i,ll j,ll d,ll s,char d1,char d2)
{
    if(a[d][s][0]==-1)
    {
        dir[i][j]=d1;
        if(vis[d][s]==0)
            dir[d][s]=d2;
        vis[d][s]=vis[i][j]=1;
    }
    else
        return 0;
}

void dfs(ll i,ll j,char d)
{
    if(vis[i][j])return ;
    vis[i][j]=1;
    dir[i][j]=d;
    if(a[i][j][0]==a[i+1][j][0] and a[i][j][1]==a[i+1][j][1])
        dfs(i+1,j,d);
    if(a[i][j][0]==a[i-1][j][0] and a[i][j][1]==a[i-1][j][1])
        dfs(i-1,j,d);
    if(a[i][j][0]==a[i][j+1][0] and a[i][j][1]==a[i][j+1][1])
        dfs(i,j+1,d);
    if(a[i][j][0]==a[i][j-1][0] and a[i][j][1]==a[i][j-1][1])    
        dfs(i,j-1,d);
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
    {
        rep1(j,n)
        {
            cin>>a[i][j][0]>>a[i][j][1];
        }
    }

    rep1(i,n)
    {
        rep1(j,n)
        {
            if(a[i][j][0]==-1)
            {
                int res = vis[i][j];
                if(!res)res=connect(i,j,i+1,j,'D','U');
                if(!res)res=connect(i,j,i-1,j,'U','D');
                if(!res)res=connect(i,j,i,j+1,'R','L');
                if(!res)res=connect(i,j,i,j-1,'L','R');
                if(!res) 
                {
                    cout<<"INVALID\n";
                    return 0;
                }
            }
            else if(a[i][j][0]==i and a[i][j][1]==j)
            {
                
                dfs(i,j,'X');
            }
        }
    }
    rep1(i,n)
    {
        rep1(j,n)
        {
            if(!vis[i][j])
            {
                cout<<"INVALID\n";
                return 0;
            }
        }
    }
    rep1(i,n)
    {
        rep1(j,n)
        {
            cout<<dir[i][j];
        }
        cout<<"\n";
    }

}