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

int a[100005][log +2], lg[100005];
ll su[100005], sum[100005], so[100005], csu[100005], csum[100005], cso[100005];

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i][0];
		sum[i] = sum[i-1] + a[i][0];
		so[i] = so[i-1]^a[i][0];
		su[i] = su[i-1] + 1ll*a[i][0]*a[i][0];
		csum[i] = csum[i - 1] + i;
		cso[i] = cso[i-1]^i;
		csu[i] = csu[i-1] + 1ll*i*i;
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i) + 1; j++)
		a[j][i] = min(a[j][i-1], a[j + mask(i-1)][i-1]);

	auto getmin = [&](const int &l, const int &r)
	{
		int k = lg[r - l + 1];

		return min(a[l][k], a[r - mask(k) + 1][k]);
	};

	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int cl = getmin(l, r), cr = cl + r - l;
		l--; cl--;

 		if (sum[r] - sum[l] == csum[cr] - csum[cl]  
			&& (so[r]^so[l]) == (cso[cr]^cso[cl])
				&& su[r] - su[l] == csu[cr] - csu[cl]) 
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
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
