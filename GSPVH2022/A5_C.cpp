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

int dem[13], dem1[13];

bool ok()
{
	for (int i = 0; i <= 9; i++)
	{

		if (((dem[i] > 0) ^ (dem1[i] > 0))) 
		{
			return false;
		}
	}
	return true;
}

void solve() 
{
	string s, st;
	cin >> s >> st;
	int n = (int)s.size(), nn = (int)st.size();
	s = "@" + s; st = "@" + st;
	for (int i = 1; i <= n; i++) dem[s[i] - '0']++;
	for (int j = 1; j <= nn; j++) dem1[st[j] - '0']++;

	if (ok()) 
	{
		cout << "friends";
		return;
	}

	for (int i = 1; i < n; i++)
	{
		int x = s[i] - '0', y = s[i + 1] - '0';
		dem[x]--; dem[y]--;
		if ((i != 1 || x != 1) && x >= 1 && y < 9)
		{
			dem[x-1]++; dem[y+1]++;
			if (ok())
			{
				cout << "almost friends"; return;
			}
			 dem[x-1]--; dem[y+1]--;
		}

		if (x < 9 && y >= 1)
		{
			dem[x+1]++; dem[y-1]++;
			if (ok())
			{
				cout << "almost friends"; return;
			}
			dem[x+1]--; dem[y-1]--;
		}
		dem[x]++; dem[y]++;
	}

	for (int i = 1; i < nn; i++)
	{
		int x = st[i] - '0', y = st[i + 1] - '0';
		dem1[x]--; dem1[y]--;
		if ((i != 1 || x != 1) && x >= 1 && y < 9)
		{
			dem1[x-1]++; dem1[y+1]++;
			if (ok())
			{
				cout << "almost friends"; return;
			}
			 dem1[x-1]--; dem1[y+1]--;
		}

		if (x < 9 && y >= 1)
		{
			dem1[x+1]++; dem1[y-1]++;
			if (ok())
			{
				cout << "almost friends"; return;
			}
			dem1[x+1]--; dem1[y-1]--;
		}
		dem1[x]++; dem1[y]++;
	}
	cout << "nothing";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("digits.inp","r",stdin); freopen("digits.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
