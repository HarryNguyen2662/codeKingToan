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

const ll MAX = 3e18 + 9012005;

ll f[100];

void prepare()
{
	f[0] = 1;

	for (int i = 1; i <= 55; i++)
	for(int j = 1; j <= 55; j++)
	{
		if (j*(j + 1)/2 > i) break;

		if (f[i - j*(j + 1)/2] >= MAX/25) f[i] = MAX;
		else f[i] = min(MAX, f[i] + f[i - j*(j + 1)/2]*25);
	}

	f[56] = MAX;
}

void solve() 
{
	int n; ll k;
	cin >> n >> k;


	string res = "";
	ll coststr = 0;
	ll cntlst = 0;
	char lst = 0;

	while(true)
	{
		for (char e = 'a'; e <= 'z'; e++)
		{
			ll cnt = 0;
			
			for (ll i = 1; i + (int)res.size() <= n; i++)
			{
				ll nst;
				if (e == lst) 
				nst = coststr - cntlst*(cntlst + 1)/2 + (cntlst + i)*(cntlst + i + 1)/2;
				else
				nst = coststr + i*(i + 1)/2;	

				if (nst > n) break;
				cnt = min(MAX, cnt + f[min(n - nst, 56ll)]);
				if (cnt == MAX) break;
			}
			if (cnt >= k)
			{
				res += (char)e;
				if (lst == e) 
				{
					coststr -= cntlst*(cntlst + 1)/2;
					cntlst++;
					coststr += cntlst*(cntlst + 1)/2;
				}
				else 
				{
					lst = e;
					cntlst = 1;
					coststr++;
				}
				break;
			}
			else k -= cnt;

		}

		if (k == 1 && coststr == n)
		{
			cout << res << "\n";
			return;
		}
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
    //freopen("conststr.inp","r",stdin); freopen("conststr.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    prepare();

    int testcase = 3;
    //cin >> testcase;
    while(testcase--)
        solve();
}
