#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

template<typename _T> inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template<typename _T, typename... args> void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define _upgrade ios_base::sync_with_stdio(0);
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

int main()
{
    _upgrade
    
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif    
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
            
        if(*max_element(all(v)) == *min_element(all(v)))
        {
            cout << 1 << "\n";
            for(int i = 0; i < n; i++)
                cout << 1 << " ";
            cout << "\n";
        }
        else if(n % 2 == 0)
        {
            cout << 2 << "\n";
            for(int i = 0; i < n; i++)
                cout << (i % 2) + 1 << " ";
            cout << "\n";
        }
        else
        {
            int id = -1;
            for(int i = 0; i < n; i++)
                if(v[i] == v[(i + 1) % n]) id = i; 
            
            if(id != -1)
            {
                cout << 2 << "\n";
                int c = 1;
                for(int i = 0; i < n; i++)
                {
                    cout << c << " ";
                    if(i != id)
                        c = 3 - c;
                }
                cout << "\n";
            }
            else
            {
                cout << 3 << "\n";
                cout << 3 << " ";
                for(int i = 1; i < n; i++)
                    cout << (i % 2) + 1 << " ";
                cout << "\n";
            }
        }
    }

	return 0;
}