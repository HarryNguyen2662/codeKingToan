#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

map<pair<char, char>, int> dem;

char s[100005], st[100005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> st[i];

	for (int i = 1; i <= n; i++)
	{
		pair<char,char> cur = {s[i], st[n - i + 1]};
		if (cur.fi > cur.se) swap(cur.fi, cur.se);
		dem[cur]++;
	}

	int re = 0, re1 = 0;

	for (char i = 'a'; i <= 'z'; i++)
	for (char j = i; j <= 'z'; j++)
	{
		pair<char,char> id = make_pair(i, j);
		re += dem[id]%2;
		if (i == j) re1 += dem[id]%2;
		dem[id] = 0;
	}	

	if (re > 1 || re1 > 1 || re1 != re) 
	{
		cout << "NO\n"; return;
	}

	cout << "YES\n";

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
