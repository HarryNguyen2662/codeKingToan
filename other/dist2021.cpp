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

int n;

long long k;

pair<int,int> a[100005];

int na[100005], fen[100005], cnt = 0;

vector<int> diffval;
void update(int id, int val)
{
	for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}

int get(int id)
{
	int re = 0;
	for (; id; id -= (id&(-id))) re += fen[id];
	return re;
}
bool check(long long val)
{

	for (int i = 1; i <= cnt; i++) fen[i] = 0;
	
	long long re = 0;

	int l = 1;
	update(na[1], 1);

	for (int i = 2; i <= n; i++)
	{
		while(l < i && a[i].fi - a[l].fi > val) 
		{
			update(na[l], -1);
			l++;
		}
		int l = lower_bound(ALL(diffval), a[i].se - val) - diffval.begin() + 1;
		int r = upper_bound(ALL(diffval), a[i].se + val) - diffval.begin();

		if (l <= r)
		{
			re += (get(r) - get(l-1));
		}

		if (re >= k) return true;

		update(na[i], 1);
	}

	return false;
}

void solve() 
{
	
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		diffval.pb(a[i].se);
	}

	sort(a + 1, a + n + 1);
	
	sort(ALL(diffval));
	
	diffval.resize(unique(ALL(diffval)) - diffval.begin());
	
	cnt = (int)diffval.size();
	
	for (int i = 1; i <= n; i++)
	{
		na[i] = lower_bound(ALL(diffval), a[i].se) - diffval.begin() + 1;
	}
	
	long long l = 0, r = 2*oo;
	
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) r = mid - 1; else l = mid + 1;
	}

	cout << l;
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
