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

int a[3005];

void solve() 
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);

	if (k > a[n - 1])
	{
		cout << "0\n";
		return;
	}

	int re = 3005;

	for (int i = 1; i <= 3000; i++)
	{	
		int ree = 3005;
		int ru  = 0;
		bool kt = true;
		for (int j = 1; j <= n; j++)
		{
			int t = min(k, a[j]/i + (a[j]%i != 0));
			while(t > 1 && a[j]/(t - 1) <= i) t--;
			if (a[j]/t <= i)
			{
				ree = min(ree, a[j]/t);
				ru = max(ru, a[j]/t);
			}
			else 
			{
				kt = false;
				break;
			}
		}
		//if (kt) cout << i - ree << " " << i  << endl;
		//cout << ru << endl;
		if (kt) re = min(re, i - ree);
	}
	
	cout << re << "\n";


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
    cin >> testcase;
    while(testcase--)
        solve();
}
