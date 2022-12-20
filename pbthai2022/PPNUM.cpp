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

int prime[100005];
bool ok[100005];


void solve() 
{
	int n;
	vector<int> ldk;
	cin >> n;
	for (int i = 1; i <= n; i++) prime[i] = i;

	for (int i = 2; i <= n; i++) if (prime[i] == i)
	for (int j = 2*i; j <= n; j+= i) prime[j] = i;

	for (int i = 1; i <= n; i++)
	{
		if (prime[i] != 1 && i/prime[i] != 1 && i/prime[i] != prime[i] && prime[i/prime[i]] == i/prime[i]) 
		{
			ldk.pb(i);
		}
	}

	int res = 0;

	if (n <= 300)
	{
		for (int i = 1; i <= min(n, 300); i++)
		{ 
			bool kt = false; 
			for (int j = 0; j < (int)ldk.size(); j++)
			{
				if (ldk[j] > i) break;
				for (int e = j +1; e < (int)ldk.size(); e++)
				{
					if (ldk[j] + ldk[e] > i) break;
					for (int ee = e + 1; ee < (int)ldk.size(); ee++)
					{
						if (ldk[j] + ldk[e] + ldk[ee] > i) break;
						if (ldk[j] + ldk[e] + ldk[ee] == i) 
						{
							kt = true;
							break;
						}
					}
					if(kt) break;
				}
				if (kt) break;
			}
			
			if (kt) res++;
		}
		cout << res; return;

	}
	for (int i = 1; i <= 300; i++)
		{ 
			bool kt = false; 
			for (int j = 0; j < (int)ldk.size(); j++)
			{
				if (ldk[j] > i) break;
				for (int e = j +1; e < (int)ldk.size(); e++)
				{
					if (ldk[j] + ldk[e] > i) break;
					for (int ee = e + 1; ee < (int)ldk.size(); ee++)
					{
						if (ldk[j] + ldk[e] + ldk[ee] > i) break;
						if (ldk[j] + ldk[e] + ldk[ee] == i) 
						{
							kt = true;
							break;
						}
					}
					if(kt) break;
				}
				if (kt) break;
			}
			
			if (kt) res++;
		}
	cout << res + n - 300;
	
	
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
