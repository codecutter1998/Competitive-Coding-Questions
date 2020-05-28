#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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

const ll MAX = 203;
const ll MASK = (1 << 30) + 1;
const ll MAX1 = 200000 + 5;
const ll INF = 1e18;
const ll MOD = 998244353;

vector<ll> occ[MAX];
vector<ll> v;
ll a[MAX1], n;
ll ans = 0;

void go1()
{
    ll l = 0, r = sz(v) - 1, x = 0, s = 0;
    for (ll a : v)
        s += a;
    ans = max(s, ans);
    while (1)
    {
        ++x;
        bool bl = 0, br = 0;
        while (l <= r && !bl)
        {
            if (!v[l])
                bl = 1;
            else
                --s;
            ++l;
        }
        while (l <= r && !br)
        {
            if (!v[r])
                br = 1;
            else
                --s;
            --r;
        }

        if (!bl || !br)
            break;

        ans = max(2 * x + s, ans);
    }
}

void solve()
{
    ans = 0;
    rep(i, n)
        occ[a[i] - 1]
            .pb(i);
    rep(i, MAX)
        occ[i]
            .pb(n);

    rep(x, MAX)
    {
        if (sz(occ[x]) == 1)
            continue;
        rep(y, MAX)
        {
            if (x == y)
            {
                ans = max(ans, sz(occ[x]) - 1);
                continue;
            }
            v.clear();
            for (int i = 0, j = 0; i < sz(occ[x]) - 1 or j < sz(occ[y]) - 1;)
            {
                if (occ[x][i] < occ[y][j])
                    v.pb(0), i++;
                else
                    v.pb(1), j++;
            }

            go1();
        }
    }
}

void pre()
{
    rep(i, MAX)
        occ[i]
            .clear();
}

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t;
    cin >> t;
    rep(_, t)
    {
        cin >> n;
        pre();
        rep(i, n) cin >> a[i];
        solve();
        v.clear();
       cout << ans << "\n";
    }
}