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

long long a[100005];

void solve() 
{
	int n;
	long long l, r;
	cin >> n >> r >> l;

	n += 2;

	long long sum = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a + 1, a + 1 + n);

	long long res = 0;

	r = sum - r; l = sum - l - 1;


	int id = 0, id1 = 0;

	for (int i = n; i; i--)
	{
		while(id + 1 <= i && a[i] + a[id + 1] <= r) id++;
		
		while(id1 + 1 <= i && a[i] + a[id1 + 1] <= l) id1++;
		
		id = min(id, i - 1); id1 = min(id1, i - 1);
		
		if (id && a[i] + a[id] <= r)
		res += id; 
		
		if (id1 && a[i] + a[id1] <= l)
		res -= id1;
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
