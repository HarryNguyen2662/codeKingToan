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
int f[2005][2005],  a[100005], n, dem[100005], re[100005];
bool ktt[100005];	
vector<int> ldk[100005];
void sub1()
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (a[i] == a[j]) f[i][j] = f[i-1][j-1] + 1;
		else f[i][j] = 0;
	}
	int dai = 0;
	pair<int,int> res = {0, 0};
	for (int i = n; i; i--)
	{
		int w = oo, d = 0;
		for (int j = 1; j <= n; j++) if (f[i][j] > 0)
		{
			w = min(w, f[i][j]);
			d++;
		}
		if (d > dai)
		{
			dai = d;
			res = {i - w + 1, i};
		}
		else if (d == dai && i - w + 1 > res.fi)
		{
			res = {i - w + 1, i};
		}
	}
	//cout << f[4][4] << " " << f[4][2] << endl;
	cout << res.fi << " " << res.se << endl;
	return;
}

bool cmp(const vector<int> &x, const vector<int> &y)
{
	return x[0] < y[0];
}
void sub2()
{
	vector<int> diffval;
	for (int i = 1; i <= n; i++) diffval.pb(a[i]);
	sort(ALL(diffval)); diffval.resize(unique(ALL(diffval)) - diffval.begin());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(ALL(diffval), a[i]) - diffval.begin();
		dem[a[i]]++;
	}
	int dai = 0;
	int cnt = 0;
	pair<int,int> res = {0, 0};
	for (int i = 1; i <= n; i++) dai = max(dai, dem[a[i]]);
	for (int i = 1; i <= n; i++) 
	{
		if (dem[a[i]] == dai) 
		{
			ldk[a[i]].pb(i);
			res.se =  i;
			res.fi = i;
		}
		if (dem[a[i]] == dai)
		{
			if (ktt[a[i]] == false)
			{
				re[++cnt] = a[i];
				ktt[a[i]] = true;
			}
		}
		//cout << dem[a[i]] << endl;
	}
	//cout << cnt << endl;
	//for (int i = 1; i <= cnt; i++) cout << re[i] << endl;
	if (cnt == 1)
	{
		cout << res.fi << " " << res.se << endl ;
		return;
	}
	dai = 1;
	int ree = 1;
	for (int i = 2; i <= cnt; i++)
	if (ldk[re[i]][0] - 1 == ldk[re[i-1]][0])
	{
		bool kt = true;
		for (int j = 1; j < (int)ldk[re[i]].size(); j++) if (ldk[re[i]][j] - 1 != ldk[re[i-1]][j])
		{
			kt = false;
			break;
		}
		if (kt)
		{
			dai++;
			if (dai > ree)
			{
				ree = dai;
				res = {ldk[re[i]].back() - dai + 1, ldk[re[i]].back()};
			}
			else if (dai == ree && ldk[re[i]].back() - dai + 1 > res.fi)
			{
				res = {ldk[re[i]].back() - dai + 1, ldk[re[i]].back()};
			}
		}
		else dai = 1;
	}
	else dai = 1;
	cout << res.fi << " " << res.se << endl;
}

void solve() 
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	//if (n <= 2000) sub1();
	//sub1();
	sub2();
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
