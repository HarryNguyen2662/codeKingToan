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
void add(int &x, const int &y)
{
	x += y;
	if (x >= MOD) x -= MOD;
}
struct BIT
{
	vector<int> fen;
	int len;
	
	BIT(const int &n)
	{
		fen.assign(n + 5, 0);
		len = n;
	}

	void update(int id, const int &val)
	{
		for (; id <= len; id += (id&(-id))) add(fen[id], val);
	}

	int getsum(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) add(res, fen[id]);
		return res;
	}

};
int a[500005], sl[500005];
void solve() 
{
	int n;
	vector<int> diffval;
	n = ReadInt();
	
	for (int i = 1; i <= n; i++) a[i] = ReadInt(), diffval.pb(a[i]);
	
	sort(ALL(diffval)); diffval.resize(unique(ALL(diffval)) - diffval.begin());
	//cout << n << endl;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diffval), a[i]) - diffval.begin() + 1;
		sl[i] = 1ll * i * (n - i + 1)%MOD;
		//cout << sl[i] << endl;
	}
	
	BIT ldk = BIT(n), qa = BIT(n);
	
	for (int i = 1; i <= n; i++)
	{
		int su = ldk.getsum(a[i]);
		//cout << su << endl;
		ldk.update(a[i], i);
		add(sl[i], (int)(1ll*(n - i + 1)*su%MOD));
	}
	
	for (int i = n; i; i--)
	{
		int su = qa.getsum(a[i]);
		//cout << su << endl;
		qa.update(a[i], n - i + 1);
		add(sl[i], (int)(1ll*i*su%MOD));
	}
	
	int res = 0;
	
	for (int i = 1; i <= n; i++)
	{
		//cout << sl[i] << endl;
		add(res, (int)(1ll*sl[i]*diffval[a[i]-1]%MOD));
	}
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
