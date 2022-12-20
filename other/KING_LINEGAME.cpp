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

const int oo = 1e9 + 11062004;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
pair<long long, long long> a[100005];
void solve() 
{
	int n, p;
	cin >> n;
	//cout << n << endl;
	cin >> p;
	//cout << p << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
	}
	if (n == 1)
	{
		cout << "possible\n";
		return;
	}
	p = p * n;
	int sl = 20;
	while(sl--)
	{
		int x = rng()%n + 1;
		vector<pair<pair<int,int>,int>> ldk;
		int dem = 0;
		for (int i = 1; i <= n; i++)
		if (a[i] == a[x]) dem++;
		else
		{
			int at = a[i].se - a[x].se, am = a[i].fi - a[x].fi;
			int b;
			if (am == 0) ldk.pb({{a[i].fi, oo}, 0});
			else if (at == 0) ldk.pb({{0, 0}, a[i].se});
			else 
			{	
				int t = __gcd(at, am);
				at /= t; am /= t;
				if (am < 0)
				{
					am = -am;
					at = -at;
				} 
				b = a[x].se - a[x].fi*at/am;
				ldk.pb({{am, at}, b});
			}
		}
		sort(ALL(ldk));
		int de = dem + 1;
		for (int i = 1; i < (int)ldk.size(); i++)
		if (ldk[i] == ldk[i-1]) de++;
		else
		{
			if (de*100 >= p)
			{ 
				cout << "possible\n";
				return;
			}
			de = dem + 1;
		}
		if (de*100 >= p)
		{
			//cout << x  << " " << y << endl; 
			cout << "possible\n";
			return;
		}
	}
	cout << "impossible\n";
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
