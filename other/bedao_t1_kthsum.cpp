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

int n;
long long k;
const int lim = 100002;
int fen[100005], su[100005];
long long sum[100005]; 
void update(int id)
{
	for (; id <= lim; id += (id&(-id))) fen[id] += 1;
}
int get(int id)
{
	int res = 0; 
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}
vector<long long> diff;
int id0;
bool check(long long x)
{
	long long dem = 0;
	for (int i = 1; i <= lim; i++) fen[i] = 0;
	update(id0); 
	for (int i = 1; i <= n; i++)
	{
		long long val = sum[i] - x;
		
		int id = upper_bound(ALL(diff), val) - diff.begin(); // - 1 + 1
	//	if (x == 6) cout << get(id) << " " << val << endl;
		dem += get(id);
		update(su[i]);

	}
	//if (x <= 6) cout << x << " " << dem << endl;
	return dem >= k;
}

void solve() 
{
	cin >> n >> k;
	long long l = -1ll*1e14, r = (long long)1e14;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		sum[i] = sum[i-1] + x;
		diff.pb(sum[i]);
	}
	diff.pb(0);
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	id0 = lower_bound(ALL(diff), 0) - diff.begin() + 1;// cout << id0 << endl;
	for (int i = 1; i <= n; i++)
	{
		su[i] = lower_bound(ALL(diff), sum[i]) - diff.begin() + 1;   
	}
	while(l <= r)
	{
		long long mid = (l + r)/2;
		if (check(mid)) l = mid + 1; else r = mid - 1;
	}
	cout << r;
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
