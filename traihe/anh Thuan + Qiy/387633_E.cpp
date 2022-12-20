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

long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

long long a[300005], sg[1300005];
void build(int id, int l, int r)
{
	if (l == r)
	{
		sg[id] = a[l];
		return;
	}
	int mid = (l + r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	sg[id] = gcd(sg[id*2], sg[id*2+1]);
}

long long get(int id, int l, int r, int u, int v)
{
	if (u > r || l > v) return 0;
	if (u <= l && r <= v)
	{
		return sg[id];
	}
	int mid = (l + r)/2;
	return gcd(get(id*2, l, mid, u, v), get(id*2+1, mid + 1, r, u, v));
}

void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i < n; i++)
	{
		a[i] = a[i] - a[i+1];
	}
	n--;
	build(1, 1, n);
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		r--;
		cout << abs(get(1, 1, n, l, r)) << "\n";
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
