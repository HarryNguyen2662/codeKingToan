#include<bits/stdc++.h>

using namespace std;

#define int long long
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

bool ok[2000005];
int l[2000005], r[2000005];

void solve() 
{	
	int n, k;
	vector<pair<int,int>> event; set<pair<int,int>> can;
	cin >> n >> k;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		event.pb({l[i], i}); event.pb({r[i] + 1, -i});
	}

	sort(ALL(event));
	int st = 0; int dem = 0;
	for (auto v : event)
	if (v.se > 0)
	{
		if (dem >= k)
		{
			can.insert(v);
			dem++;
		}
		else if (dem == k - 1)
		{
			st = v.fi;
			ok[v.se] = true;
			dem++;
		}
		else
		{
			ok[v.se] = true;
		 	dem++;
		}
	}
	else
	{
		if (ok[-v.se])
		{
			if (dem >= k)
			res = max(res, v.fi - st - 1);
			ok[-v.se] = false;
			dem--;
			if ((int)can.size())
			{
				auto t = can.begin(); 
				ok[(*t).se] = true;
				st = (*t).fi; can.erase(*t);
			}
		}
		else
		{
			if (can.find({l[-v.se], -v.se}) != can.end())
			can.erase({l[-v.se], -v.se});
			dem--;
		}
	}

	cout << res;
}

signed main() 
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
