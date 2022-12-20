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


void solve() 
{
	ll A, B, C;
	cin >> A >> B >> C;

	A--; C--;

	ll res = 0;

	for (int b = 1; b <= B; b++)
	{
		ll cur = -1;
		ll w = b*b;
		for (int e = 1; e <= b; e++)
		{
			if (e <= A && C >= w/e + 1) 
			{
				res += C - w/e; res %= MOD;
			}
			if (cur == - 1) cur = w/e;
			else 
			{
				ll no = w/e;

				cur = min(A, cur);

				if (cur > no && C >= e)
				{
					res += (cur - no)*(C - e + 1)%MOD; res %= MOD;
				}

				cur = no;
			}
		}

		if (A > w)
		{
			res += (A - w)*C%MOD; res %= MOD;
		}

		// cout << res << endl;
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
