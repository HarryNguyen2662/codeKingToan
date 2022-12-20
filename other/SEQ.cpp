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

int a[300005], fen[300005], n, k, dp[300005];
void update(int id, int len)
{
	for (; id <= n; id += (id&(-id))) fen[id] = max(fen[id], len);
}
int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res = max(res, fen[id]);
	return res;
}
void solve1(int st)
{
	int len = dp[st];
	vector<int> ans;
	ans.pb(st);
	int w = st; len--; //st = a[st];
	for(int i = w - 1; i; i--) if (dp[i] == len)
	{
		if (a[i] < a[st]) 
		{
			ans.pb(i); st = i; len--;
		}
	}
	while(k--)
	{
		cout << ans.back() << " ";
		ans.pop_back();
	}

}
void solve2()
{
	int luu = 0;
	for (int i = 1; i <= n; i++) fen[i] = 0;
	for (int i = n; i; i--)
	{
		dp[i] = get(a[i]) + 1;
		update(a[i], dp[i]);
		//cout << dp[i] << endl;
		if (dp[i] > dp[luu]) 
		{ 
			luu = i;
		}
	}
	int len = dp[luu];
	cout << luu << " ";
	k--;
	int w = luu; len--; //luu = a[luu];
	for(int i = w + 1; i <= n; i++) if (dp[i] == len)
	{
		//cout << i << endl;
		if (a[i] < a[luu]) 
		{
			//cout << i << endl;
			luu = i; len--;
			if (k) 
				{
					cout << luu << " "; 
					k--;
				}
				else return;
		}
	}

}
void solve() 
{
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int luu = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = get(a[i]) + 1;
		update(a[i], dp[i]);
		if (dp[i] > dp[luu]) luu = i;
	}
	if (k <= dp[luu]) solve1(luu);
	else solve2();

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
    //cin >> testcase;
    while(testcase--)
        solve();
}
