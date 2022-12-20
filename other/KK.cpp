#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct DATA
{
	long long ha, sta, ed;

	bool operator < (const DATA &other)  const
	{
		return ha < other.ha;
	}
};

long long f[1000005];

void solve() 
{
	long long n, m, k;
	vector<DATA> event;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
	{
		int x, y, w, h;
		cin >> x >> y >> w >> h;	
		int u = x + w, v = y + h;
		event.pb({y, x, u}); event.pb({v + 1, x, u});
	}
	
	sort(ALL(event));

 	long long res = 0;
 	long long mn = oo18;
 	long long mx = -1;

	for (int i = 0; i < (int)event.size(); i++)
	{
		DATA v = event[i];
		for (int j = 0; j <= n; j++)
		{
			if (i > 0 && v.ha - 1 >= event[i-1].ha && f[j])
			{
				mx = max(mx, (v.ha - 1)*(n + 1) + j);
				mn = min(mn, (v.ha - 1)*(n + 1) + j);
			}
			res += (v.ha - event[i-1].ha)*f[j];
			if (j >= v.sta && j <= v.ed) f[j] = 1 - f[j];
			if ( i + 1 < (int)event.size() && v.ha  <= event[i+1].ha - 1 && f[j])
			{
				mx = max(mx, (v.ha)*(n + 1) + j);
				mn = min(mn, (v.ha)*(n + 1) + j);
			}
		}
	}

	cout << res << " " << (mn == oo18 ? -1 : mn) << " " << mx; 
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
