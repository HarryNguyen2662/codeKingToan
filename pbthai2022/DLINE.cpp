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

struct DATA 
{
	ll a, b, c;

	DATA(ll _a = 0, ll _b = 0, ll _c = 0)
	{
		a = _a; b = _b; c = _c;
	}
};

pair<ll, ll> p[100005];

ll gcd(ll u, ll v)
{
	if (v == 0) return u;

	return gcd(v, u%v);
}

DATA getline(int i, int j)
{
	ll bb = p[j].fi - p[i].fi,aa = p[i].se - p[j].se;
	ll cc = -(aa*p[i].fi + bb*p[i].se);
	ll w = gcd(aa, bb); w = gcd(w, cc);
	aa /= w; bb /= w; cc /= w;
	if (aa < 0) 
	{
		aa = -aa; bb = -bb; cc = -cc;
	}

	return DATA(aa, bb, cc);
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i].fi >> p[i].se;
	}

	for (int i = 1; i <= 100; i++)
	{
		int id = rng()%n + 1, id1 = rng()%n + 1;
		while(id1 == id)
		{
			id1 = rng()%n + 1;
		}

		DATA dline = getline(id, id1);

		int dem = 0;
		for (int j = 1; j <= n; j++)
		if (dline.a*p[j].fi + dline.b*p[j].se + dline.c == 0) dem++;

		if (dem > n/2)
		{
			cout << dline.a << " " << dline.b << " " << dline.c; return;
		}
	}

	cout << "0 0 0";
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
