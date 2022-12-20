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

int a[10004];

void solve() 
{
	int n;
	cin >> n;
	int w = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (w == 0) w = a[i]; else w = __gcd(w, a[i]);
	}

	if (w == 1)
	{
		cout << "0\n"; return;
	}

	int re = n;

	int cur = 0;
	for (int i = n; i <= n - i + 1 < re; i--)
	{
		int ww = __gcd(a[i], i); ww = __gcd(ww, w);
		if (ww == 1)
		{
			re = min(re, n - i + 1);
			break;
		}
		else
		{
			cur += n - i + 1;
			for (int j = i - 1; j <= cur + n - j + 1 < re; j--)
			{
				int www = __gcd(a[j], j); www = __gcd(www, ww);
				if (www == 1)
				{
					re = min(re, cur + n - j + 1);
					break;
				}
				else
				{
					cur += n - j + 1;
					for (int e = j - 1; cur + n - e + 1 < re; e--)
					{
						int wwww = __gcd(a[e], e); wwww = __gcd(wwww, www);
						if (wwww == 1)
						{
							re = min(re, cur + n - e + 1);
							break;
						}
						else
						{
							cur += n - e + 1;
							for (int ee = j - 1; cur + n - ee + 1 < re; ee--)
							{
								int wwwww = __gcd(a[ee], ee); wwwww = __gcd(wwwww, wwww);
								if (wwwww == 1)
								{
									re = min(re, cur + n - ee + 1);
									break;
								}
								else
								{
									cur += (n - ee + 1);
									for (int eee = j - 1; cur + n - eee + 1 < re; eee--)
									{
										int wwwwww = __gcd(a[eee], eee); wwwwww = __gcd(wwwwww, wwwww);
										if (wwwwww == 1)
										{
											re = min(re, cur + n - eee + 1);
											break;
										}
									}
									cur -= (n - ee + 1);
								}
							}
							cur -= (n - e + 1);
						}
					}
					cur -= (n - j + 1);

				}
			}

			cur -= (n - i + 1);
		}
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
