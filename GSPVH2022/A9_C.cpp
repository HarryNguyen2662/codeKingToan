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

int dem[100003];

void solve() 
{
	string s, st;
	cin >> s >> st;
	int n = (int)s.size(), m = (int)st.size();

	if (n > m)
	{
		cout << "NO\n"; return;
	}
	dem[0] = 0;
	for (int i = 0; i < m; i++) 
	{
		if (i > 0) dem[i] = dem[i-1];
		if (st[i] == 'B') dem[i]++;
	}

	for (int i = 0; i <= m - n; i++)
	{
		bool kt = true;
		for (int j = 0; j < n; j++) if (s[j] != st[j + i])
		{
			kt = false; break;
		}
		if (kt)
		{
			if (i == 0 && dem[m - 1] - dem[i + n - 1] == 0)
			{
				cout << "YES\n"; return;
			}
			if (i > 0 && st[0] == 'B' && dem[i - 1] == dem[m - 1] - dem[i + n - 1])
			{
				cout << "YES\n"; return;
			}
		}
		kt = true;
		for (int j = 0; j < n; j++) if (s[n - j - 1] != st[j + i])
		{
			kt = false; break;
		}
		if (kt && i > 0 && st[0] == 'B' && dem[i - 1] - 1 == dem[m - 1] - dem[i + n - 1])
		{
			//cout << i << endl;
			cout << "YES\n"; return;
		}
	}

	cout << "NO\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("abba.inp","r",stdin); freopen("abba.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 3;
    //cin >> testcase;
    while(testcase--)
        solve();
}
