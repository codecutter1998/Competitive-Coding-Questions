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

int main()
{
    faster;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    ll n = sz(s);
    s = "%" + s;
    ll op[n + 2], cl[n + 2];
    mk0(op);
    mk0(cl);
    rep1(i, n)
    {
        if (s[i] == '(')
            op[i] = 1 + op[i - 1];
        else
            op[i] = op[i - 1];
    }
    for (int i = n; i >= 1; --i)
    {
        if (s[i] == ')')
            cl[i] = 1 + cl[i + 1];
        else
            cl[i] = cl[i + 1];
    }
    ll ind, max_val = 0;
    for (int i = 1; i < n; ++i)
    {
        //cout<<op[i]<<" "<<cl[i+1]<<"\n";
        ll mn = min(op[i], cl[i + 1]);
        if (max_val < mn)
        {
            ind = i;
            max_val = mn;
        }
    }
    if(max_val==0)
    {
        cout<<"0\n";
        return 0;
    }
    cout << "1\n";
    cout << 2 * max_val << "\n";
    int cnt = 0;
    for (int i = 1; i <= ind; ++i)
    {
        if (s[i] == '(')
            cout << i << " ", cnt++;
        if (cnt == max_val)
            break;
    }
    cnt = 0;
    stack<ll> st;
    for (int i = n; i > ind; --i)
    {
        if (s[i] == ')')
            st.push(i),cnt++;
        if (cnt == max_val)
            break;
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout << "\n";
}