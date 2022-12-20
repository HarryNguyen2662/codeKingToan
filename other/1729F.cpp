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

int su[200005], d[10], dd[10];

void solve() 
{
	string s;
	cin >> s;
	s = "@" + s;
	int m, k;
	cin >> m >> k;
	int n  = (int)s.size() - 1;

	for (int i = 0; i <= 8; i++) d[i] = dd[i] = 0;

	for (int i = 1; i <= n; i++)
	{
		su[i] = su[i - 1] + (s[i] - '0'); su[i] %= 9;
		
		if (i >= m)
		{
			int w = su[i] - su[i - m] + 18; w %= 9;
			if (d[w] == 0) d[w] = i - m + 1; else if (dd[w] == 0) dd[w] = i - m + 1;
		}
	}

//	cout << d[0] << endl;

	while(k--)
	{
		int l, r, t;
		cin >> l >> r >> t;
		int q = su[r] - su[l-1] + 18; q %= 9;

		pair<int,int> id = {n + 1, n + 1};

		for (int i = 0; i <= 8; i++) for (int j = 0; j <= 8; j++) if ((i*q + j)%9 == t)
		{
			if (d[i])
			{
				if (i != j && d[j]) id = min(id, make_pair(d[i], d[j]));
				else if (i == j && dd[j]) id = min(id, make_pair(d[i], dd[j]));
			}
		}

		if (id.fi == n + 1)
		{
			cout << "-1 -1\n";
			continue;
		}

		cout << id.fi << " " << id.se << "\n";

	}

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
