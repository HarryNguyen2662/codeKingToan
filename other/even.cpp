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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
pair<int,int> a[100005];
long long luu[200005];
void solve() 
{
	int n;
	vector<int> diffval;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		a[i].se++;
		diffval.pb(a[i].fi); diffval.pb(a[i].se);
	}
	sort(ALL(diffval)); diffval.resize(unique(ALL(diffval)) - diffval.begin());
	for (int i = 0; i < (int)diffval.size(); i++) luu[i] = rng()%oo18 + 1;
	long long res = 0;
	long long x = 0;
	vector<long long> ldk;
	ldk.pb(0);
	for (int i = 1; i <= n; i++)
	{	
		int id1 = lower_bound(ALL(diffval), a[i].fi) - diffval.begin();
		int id2 = lower_bound(ALL(diffval), a[i].se) - diffval.begin();
		x ^= luu[id1]; x ^= luu[id2];
	//	cout << luu[id1] << " " << luu[id2] << endl;
		ldk.pb(x);
	}
	//cout << x << endl;
	sort(ALL(ldk));
	int dem = 1;
	for (int i = 1; i < (int)ldk.size(); i++)
	if (ldk[i] == ldk[i-1])
	{
		dem++;
	}
	else
	{
		res += 1ll*dem*(dem-1)/2;
		dem = 1;
	}
	res += 1ll*dem*(dem-1)/2;
	cout << res;
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
