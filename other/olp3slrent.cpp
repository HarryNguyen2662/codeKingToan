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
const long long oo12 = 1e12, oo18 = 1e18+3, oooo = 922372036854775807;

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
int nn;
pair<long long, int> fen[300005];
pair<long long, long long> a[100005];
int cs[100005];
void update(int id, pair<long long,int> val)
{
	for (; id <= nn + 5; id += (id&(-id))) fen[id] = max(fen[id], val);
}
pair<long long, int> get(int id)
{
	pair<long long, int> res = {-oo12, -oo};
	for (; id; id -= (id&(-id))) res = max(res, fen[id]);
	return res;
}
bool cmp(const int &x, const int &y)
{
	return a[x] < a[y];
}
void solve() 
{
	int n;
	vector<long long> diff;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se;
		cs[i] = i;
		diff.pb(a[i].se);
	}
	sort(cs + 1, cs + 1 + n, cmp);
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	nn = (int)diff.size();
	for (int i = 1; i <= nn; i++) fen[i] = {-oo12, -oo};
	long long res = oo12;
	pair<int, int> cs1 = {oo, oo};
	for (int e = 1; e <= n; e++)
	{
		int i = cs[e];
		//cout << i << endl;
		int x = lower_bound(ALL(diff), a[i].se) - diff.begin() + 1;
		//cout << x << endl;
		pair<long long,int> j = get(x);
		//cout << j.fi << " " << j.se << endl;
		if (j.fi != -oo12)
		{
			if (a[i].fi + a[i].se - j.fi < res)
			{
				res = a[i].fi + a[i].se - j.fi;
				cs1.fi = -j.se; cs1.se = i;
			}
			else if (res == a[i].fi + a[i].se - j.fi)
			{
				if (cs1.fi > -j.se) 
				{
					cs1.fi = -j.se; cs1.se = i;
				}
				else if (cs1.fi == -j.se && cs1.se > i) cs1.se = i;
			}
		}
		update(x, {a[i].fi + a[i].se, -i});
	}
	if (cs1.fi == oo)
	{
		cout << "-1";
		return;
	}
	cout << res << "\n";
	cout << cs1.fi << " " << cs1.se;
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
