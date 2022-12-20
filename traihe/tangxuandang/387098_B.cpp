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
int n, fen[2000005], s[2000005], a[2000005];

void update(int id)
{
	for (; id <= n + 1; id += (id&(-id))) fen[id] += 1;
}

int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}

long long cal(int x)
{
	vector<int> ldk;
	ldk.pb(0);
	for (int i = 0; i <= n + 1; i++) fen[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		s[i] = s[i-1] + (a[i] <= x);
		ldk.pb(2*s[i] - i);
	}
	sort(ALL(ldk)); ldk.resize(unique(ALL(ldk)) - ldk.begin());
	long long res = 0;
	for (int i = 0; i <= n; i++)
	{
		s[i] = 2*s[i] - i;
		s[i] = lower_bound(ALL(ldk), s[i]) - ldk.begin() + 1;
		res += get(s[i]);
		update(s[i]);
	}
	return res;
}

void solve() 
{
	int x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << cal(x) - cal(x-1);
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
