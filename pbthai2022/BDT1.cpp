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

long double k[100005], c[100005], luu[100005]; 

void solve() 
{
	int n;

	long double sum = 0, su = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		su += (long double)1/k[i];
	}


	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		sum += k[i]*c[i];
	}

	long double ans = sum*su;



	if (ans < 0)
	{
		cout << "-1\n"; return;
	}

	ans = sqrt(ans);

	long double X = sum/su;

	if (X < 0)
	{
		cout << "-1\n"; return;
	}

	for (int i = 1; i <= n; i++)
	{
		luu[i] = X/(k[i]*k[i]) - c[i];
		if (luu[i] + c[i] < 0) 
		{
			cout << "-1\n"; return;
		}
	}

	cout << fixed << setp(3);

	cout << ans << "\n"; for (int i = 1; i <= n; i++) cout << luu[i] << " ";
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
