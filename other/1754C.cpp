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

int s[200005];

void solve() 
{
	int n;
	int dem = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		if (s[i] == 0) dem++;
	}

	if ((n - dem)%2)
	{
		cout << "-1\n"; return;
	}

	vector<pair<int,int>> ldk;

	if (dem == 0)
	{
		for (int i = 1; i < n; i += 2)
		if (s[i] == s[i + 1])
		{
			ldk.pb({i, i + 1});
		}
		else
		{
			ldk.pb({i, i}); ldk.pb({i + 1, i + 1});
		}
	}
	else
	{
		bool ok = true;
		int st = oo;
		for (int i = 1; i <= n; i++)
		if (s[i] == 0)
		{
			if (st != oo)
			{
				if ((i - st)%2 == 0)
				{
					for (int j = st; j < i; j += 2)
					if (s[j] == s[j + 1])
					{
						ldk.pb({j, j + 1});
					}
					else
					{
						ldk.pb({j, j}); ldk.pb({j + 1, j + 1});
					}
				}
				else
				{
					if (st == 1)
					{
						for (int j = st; j < i - 1; j += 2)
						if (s[j] == s[j + 1])
						{
							ldk.pb({j, j + 1});
						}
						else
						{
							ldk.pb({j, j}); ldk.pb({j + 1, j + 1});
						}
						ldk.pb({i - 1, i - 1});
						if (s[i - 1] == 1) ok = 1 - ok;
					}
					else
					{
						if (ok)
						{
							if (s[st] == 1)
							{
								ldk.pb({st, st});
							}
							else
							{
								ldk.pop_back();
								ldk.pb({st - 1, st});
							}

						}
						else
						{
							if (s[st] == -1)
							{
								ldk.pb({st, st});
							}
							else
							{
								ldk.pop_back();
								ldk.pb({st - 1, st});
							}
						}

						ok = 1 - ok;
						
						for (int j = st + 1; j < i; j += 2)
						if (s[j] == s[j + 1])
						{
							ldk.pb({j, j + 1});
						}
						else
						{
							ldk.pb({j, j}); ldk.pb({j + 1, j + 1});
						}
					}
					
				}
			}
			st = oo;
			ldk.pb({i, i});
		}
		else
		{
			st = min(st, i);
		}
		if (st != oo)
		{
				if ((n - st + 1)%2 == 0)
				{
					for (int j = st; j <= n; j += 2)
					if (s[j] == s[j + 1])
					{
						ldk.pb({j, j + 1});
					}
					else
					{
						ldk.pb({j, j}); ldk.pb({j + 1, j + 1});
					}
				}
				else
				{
					if (ok)
					{
						if (s[st] == 1)
						{
							ldk.pb({st, st});
						}
						else
						{
							ldk.pop_back();
							ldk.pb({st - 1, st});
						}

					}
					else
					{
						if (s[st] == -1)
						{
							ldk.pb({st, st});
						}
						else
						{
							ldk.pop_back();
							ldk.pb({st - 1, st});
						}
					}

					ok = 1 - ok;
					
					for (int j = st + 1; j <= n; j += 2)
					if (s[j] == s[j + 1])
					{
						ldk.pb({j, j + 1});
					}
					else
					{
						ldk.pb({j, j}); ldk.pb({j + 1, j + 1});
					}
				}
		}
	}

	cout << (int)ldk.size() << "\n";
	for (auto v : ldk) cout << v.fi << " " << v.se << "\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
