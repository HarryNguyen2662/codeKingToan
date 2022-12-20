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

ll gcd(ll x, ll y)
{
	if (y == 0) return x;

	return gcd(y, x%y);
}

void solve() 
{
	ll k; string s, st;
	cin >> k >> s >> st;
	bool ok = true;
	ll tu1 = 0, tu2 = 0, tu3 = 0, mau1 = 1, mau2 = 1;


	if (st == "0")
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '.') 
			{
				ok = false;
				continue;
			}

			if (ok)
			{
				tu1 = tu1*k + (s[i] - '0');
			}
			else
			{
				tu2 = tu2*k + (s[i] - '0');
				mau1 = mau1*k;
			}
		}
		
		if (tu2 == 0)
		{
			cout << tu1 << " 1\n"; return;
		}

		ll w = gcd(tu2, mau1); 

		tu2 /= w; mau1 /=w;

		cout << tu1*mau1 + tu2 << " " << mau1 << "\n";
		return;
	}

	s += st;


	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.') 
		{
			ok = false;
			continue;
		}

		if (ok)
		{
			tu1 = tu1*k + (s[i] - '0');
		}
		else
		{
			tu2 = tu2*k + (s[i] - '0');
			if (i < (int)s.size() - (int)st.size())
			{
				tu3 = tu3*k + (s[i] - '0');
				mau1 = mau1*k;
			} else mau2 = mau2*k;
		}
	}

	mau2--; mau1 *= mau2;

	tu2 -= tu3;


	if (tu2 == 0)
	{
		cout << tu1 << " 1\n"; return;
	}


	ll w = gcd(tu2, mau1); 

	tu2 /= w; mau1 /=w;

	cout << tu1*mau1 + tu2 << " " << mau1 << "\n";
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
