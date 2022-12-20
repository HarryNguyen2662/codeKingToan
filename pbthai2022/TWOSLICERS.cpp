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


long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	if (a == 0) return b;
	return gcd(b, a%b);
}
struct pso
{
	long long tu, mau;

	pso (long long _tu = 0, long long _mau = 1)
	{
		tu = _tu; mau = _mau;
	}

	pso operator - (const pso &other)
	{
		pso res;
		res.mau = mau;
		res.tu = tu - other.tu;
		return res;
	}

	bool operator < (const pso &other) const
	{
		return tu < other.tu;
	}


};

pso ldk[10005];

void solve() 
{
	int a, b;
	cin >> a >> b;

	// if (a == b)
	// {
	// 	cout << "0 / 1";
	// 	return;
	// }
	int ab = a*b;

	pso res(2*ab, 2*ab);
	
	for (int i = 0; i <= 2*ab; i++)
	{
		int cnt = 0;
		for (int j = 0; j <= a; j++) ldk[++cnt] = pso(j*2*b, 2*ab);
		for (int j = 0; j <= b; j++) 
		{
			ldk[++cnt] = pso(j*2*a + i%(2*b), 2*ab);
		}
		sort(ldk + 1, ldk + 1 + cnt);
		pso mn(2*ab, 2*ab); pso mx(0, 2*ab);
		bool kt = true;
		for (int j = 2; j <= cnt; j++)
		{
			if (ldk[j].tu == ldk[j-1].tu)
			{
				kt = false;
				 break;
			}
			mn = min(mn, ldk[j] - ldk[j-1]);
			mx = max(mx, ldk[j] - ldk[j-1]);
		}
		if (!kt) continue;
		res = min(res, mx - mn);
		
	}
	//cout << res.tu << " " << res.mau << endl;
	long long w = gcd(res.tu, res.mau);
	//cout << w << endl;
	if (w > 0) 
	{
		res.tu /= w; res.mau /= w;
	}
	cout << res.tu << " / " << res.mau;
}

int main() 
{  
	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
