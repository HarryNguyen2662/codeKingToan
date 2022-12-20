#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

ll w[100005], c[100005], mn[100005][log + 4];
int lg[100005];

ll getmn(int l, int r)
{
	int k = lg[r - l + 1];
	return min(mn[l][k], mn[r - mask(k) + 1][k]);
}

bool check(int i, int j, ll val)
{
	if (i > j) return true;

	int l = i, r = j;
	ll sum = w[j] - w[i-1];

	while(l <= r)
	{
		int mid = (l + r)/2;
		if (getmn(mid, j) + sum <= val) l = mid + 1; else r = mid - 1;
	} 


	if (r >= i && getmn(r, j) + sum <= val) return (check(i, r - 1, val)&&check(r + 1, j, val));
	else return false;

}

void trace(int i, int j, ll val)
{
	if (i > j) return;
	int l = i, r = j;
	ll sum = w[j] - w[i-1];

	while(l <= r)
	{
		int mid = (l + r)/2;
		if(getmn(mid, j) + sum <= val) l = mid + 1; else r = mid - 1;
	}
	cout << r << " ";
	trace(i, r - 1, val); trace(r + 1, j, val);
}


void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		mn[i][0] = c[i] - w[i]; w[i] += w[i-1];

		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i) + 1; j++)
	mn[j][i] = min(mn[j][i - 1], mn[j + mask(i - 1)][i - 1]);

	ll l = 0, r = oo15;

	while(l <= r)
	{
		ll mid = (l + r)/2;

		if (check(1, n, mid)) r = mid - 1; else l = mid + 1;
	}



	cout << l << "\n";

	trace(1, n, l);

}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("QBST.inp","r",stdin); freopen("QBST.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
