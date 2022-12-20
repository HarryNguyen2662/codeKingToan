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

int x0, y0;
const int lim = 1e6;

int cal(int a, int b)
{
	if (b == 0)
	{
		x0 = 1; y0 = 0;
		return a;
	}
	int val = cal(b, a%b);
	int t = x0; x0 = y0; y0 = t - a/b*y0;
	return val; 
}

vector<pair<int,int>> ldk[lim + 5];
int luu[lim + 5];

void solve() 
{
	string s;
	int X, res = 2*oo;
	
	cin >> s;
	cin >> X;
	X++;

	for (int i = 0; i <= X; i++)
	{
		ldk[i].clear(); luu[i] = 2*oo;
	}

	int n = (int)s.size(); //reverse(ALL(s));
	int _n = n/2;
	for (int i = 0; i < mask(_n); i++)
	if (ck(i, 0))
	{
		int cost = 0;
		int c0 = 1, c1 = 0;
		for (int j = 0; j < _n; j++)
		{
			if (s[j] - '0' != ck(i, j)) cost++;
			if (ck(i, j)) c1 += c0; else c0 += c1;
		}
		if (c0 <= X)
		{
			luu[c0] = min(luu[c0], cost);
		}
		if (c0 <= X && c1 <= X) ldk[c0].pb({c1, cost});
	}

	for (int i = 0; i <= X; i++) if ((int)ldk[i].size())
	{
		sort(ALL(ldk[i]));
	}

	int __n = n - _n;
	for (int i = 0; i < mask(__n); i++)
	if (!ck(i,__n - 1))
	{
		int cost = 0;
		int c0 = 1, c1 = 0;
		int c01 = 1, c10 = 0;
		for (int j = 0; j < __n; j++)
		{
			if (s[j + _n] - '0' != ck(i, j)) cost++;
			if (ck(i, j))
			{ 
				c1 += c0; 
				c01 += c10;
			}
			else
			{ 
				c0 += c1;
				c10 += c01;
			}
		}
		
		if (c0 > X) continue;

		if (c10 == 0)
		{
			if (X%c0 == 0)
			{
				int _x = X/c0;
				if (luu[_x] < 2*oo) res = min(res, cost + luu[_x]);
			}
			continue;
		}
		//cout << c0 << " " << c10 << endl;

		// can c0 va c10, x = ad + cd => (d, -c) * (a, b)
		int t = cal(c0%c10, -c10);
		int xx = X%c10;
		//cout << c0%10 << " " << -c10 << endl;
		if (xx%t) continue;
		int u;
		if (t > 0)
		{
			u = floor((long double)xx*x0/c10);
		}
		else
		{
			u = ceil((long double)xx*x0/c10);
		}
		 //cout << xx << " " << x0 << " " << y0 << endl;
		 //u = 2;
		// int _x = xx/t*x0 - c10/t*u; if (_x > X) break;
		 //cout << -(3 - xx*x0)/c10 << endl;
		//cout << _x << endl;
		for (; ; u += (t > 0 ? -1 : 1))
		{

		 	int _x = xx/t*x0 - c10/t*u; if (_x > X) break;
			pair<int,int> _y = {(X - _x*c0)/c10, 0}; if (_y.fi < 0) break;
			if ((int)ldk[_x].size() == 0) continue;
			
			int id = lower_bound(ALL(ldk[_x]), _y) - ldk[_x].begin();			
			if (id < (int)ldk[_x].size() && ldk[_x][id].fi == _y.fi) 
			{
				//cout << i << " " << cost << " " << ldk[_x][id].se << endl;
				res = min(res, ldk[_x][id].se + cost);
			}
		}
	}
	cout << ((res == 2*oo) ? -1 : res) << "\n";
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
   	cin >> testcase;
    while(testcase--)
        solve();
}
