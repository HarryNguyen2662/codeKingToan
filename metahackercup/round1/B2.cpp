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

long long a[500005], b[500005], su[500005], su1[500005];

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}

 	sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + n);

 	long long totalx = 0, totaly = 0;

 	for (int i = 1; i <= n; i++)
 	{
 		totalx = (totalx + a[i]*a[i])%MOD;
 		totaly = (totaly + b[i]*b[i])%MOD;

 		su[i] = (su[i - 1] + a[i])%MOD;
 		su1[i] = (su1[i - 1] + b[i])%MOD;
 	}

 	int q;
 	long long sum  = 0;

 	cin >> q;
 	while(q--)
 	{
 		long long x, y;
 		cin >> x >> y;

 		long long l = 1, r = n;
 		while(l <= r)
 		{
 			long long mid = (l + r)/2;
 			if (a[mid] <= x) l = mid + 1; else r = mid - 1;
 		}

 		sum = ((sum + totalx + 1ll*n*x%MOD*x%MOD -2ll*su[r]%MOD*x%MOD - 2ll*(su[n] - su[r])%MOD*x%MOD)%MOD + MOD)%MOD;
 		
 		l = 1; r = n;

 		while(l <= r)
 		{
 			long long mid = (l + r)/2;
 			if (b[mid] <= y) l = mid + 1; else r = mid - 1;
 		}

  		sum = ((sum + totaly + 1ll*n*y%MOD*y%MOD -2ll*su1[r]%MOD*y%MOD - 2ll*(su1[n] - su1[r])%MOD*y%MOD)%MOD + MOD)%MOD;

 	}

 	cout << sum << "\n";
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
    int dem = 0;
    
    cin >> testcase;
    while(testcase--)
    {
    	dem++;

    	cout << "Case #" << dem << ": "; 
        solve();
    }
}
