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

long long su[150005];
int a[150005];

void solve() 
{
	int n, m;
	cin >> n >> m;
	int l, r;
	cin >> l >> r;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	int res = 0;
	sort(a + 1, a + 1 + m);
	if (l < a[1]) res = a[1] - l;
	for (int i = 1; i < m; i++)
	if (a[i + 1] > a[i] + 1)
	{
		int w = max(l, a[i] + 1);
		int ww = min(a[i+1] - 1, r);
		if (w )
		if (w <= ww)
		{
			int mid = (a[i] + a[i + 1])/2;
			for (int e = -2; e <= 2; e++)
			if (mid + e >= w && mid + e <= ww)
			{
				res = max(res, min(mid + e - a[i], a[i + 1] - (mid + e)));
			}
			res = max(res, min(w - a[i], a[i + 1] - w));
			res = max(res, min(ww - a[i], a[i + 1] - ww));
		}

	}
	if (r > a[m]) res = max(res, r - a[m]);
	cout << res << " ";
}

int main() 
{   
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
   // freopen("cauluong.inp","r",stdin); freopen("cauluong.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase >> testcase;
    while(testcase--)
        solve();
}
