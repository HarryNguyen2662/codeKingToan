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
int st[4000005];
void update(int id, int l, int r, int cs, int val)
{
	if (l > cs || r < cs) return;
	if (l == r)
	{
		//cout << cs << " " << id << endl;
		st[id] += val;
		return;
	}
	int mid = (l + r)/2;
	update(id*2, l, mid, cs, val); update(id*2 + 1, mid + 1, r, cs, val);
	st[id] = st[id*2] + st[id*2+1];
}
int getsum(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return 0;
	if (u <= l && r <= v)
	{
		//cout << id << endl;
		return st[id];
	}
	int mid = (l + r)/2;
	return getsum(id*2, l, mid, u, v) + getsum(id*2+1, mid + 1, r, u, v);
}
long long sum[1000005], su[1000005];
void solve() 
{
	int n, m, q;
	cin >> n >> m >> q;
	//cout << n << endl;
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		sum[l]++; sum[r]--;
		
	}
	for (int i = 1; i <= n; i++) sum[i] += sum[i-1];
	while(q--)
	{
		int t;
		cin >> t;
		int l = 1, r;
		int res = 0, sl1 = 0, sl2 = 0;
		ffor (int i = 1; i <= t; i++)
		{
			cin >> r;
			int t1 = sum[l-1] , t2 = sum[r] - sum[n], t3 = sum[r] - sum[l-1]; 
 			int val = sum[r-1] - (t1+t2 - t3)/2 + su[r];
		}
		res += (sum[n] - sum[l] + su[n] - su[l]);
		cout << m - res << "\n";
	}
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("QUARANTINE.inp","r",stdin); freopen("QUARANTINE.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
