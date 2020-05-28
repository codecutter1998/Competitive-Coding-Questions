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

const ll MAX = 2e3 + 5;
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

ll n, h, l, r;
ll a[MAX];
ll dp[MAX][MAX];

void init()
{
    mk_1(dp);
}

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    cin >> n >> h >> l >> r;

    rep1(i, n)
            cin >>
        a[i];
    
    init();
    dp[0][0] = 0;
    ll max_val = 0;
    for (int ind = 1; ind <= n; ++ind)
    {
        //a[ind] %= h;
        for (int hh = 0; hh < h; ++hh)
        {
            ll v1 = (hh - a[ind] + h*h) % h;
            ll v2 = (hh - a[ind] + 1 + h*h) % h;
            if (dp[ind - 1][v1] != -1)
                dp[ind][hh] = max(dp[ind][hh], dp[ind - 1][v1]+(hh >= l and hh <= r)),max_val=max(max_val,dp[ind][hh]);
            if (dp[ind - 1][v2] != -1)
                dp[ind][hh] = max(dp[ind][hh], dp[ind - 1][v2]+(hh >= l and hh <= r)),max_val=max(max_val,dp[ind][hh]);
        }
    }
    
    cout << max_val;
}