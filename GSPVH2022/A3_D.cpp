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


long long dem[100005];
int f[100005], in[100005], out[100005];
const int lim = 100000;

void solve() 
{
	int n, r, m;
	cin >> n >> r >> m;

	f[1] = 1;
	for (int i = 2; i <= m + 1; i++)
	{
		int x;
		cin >> x;
		f[i] = ((f[i-1] + x)%n + n)%n; if (f[i] == 0) f[i] = n;
	}
	int w = f[m + 1] - f[1];
	int st = 1, buoc = 0;
	for (int i = 1; i <= n; i++)
	if (in[i] == 0)
	{
		st = i;
		while(out[st] == 0)
		{
			buoc++;
			if (in[st] == 0) in[st] = buoc; else out[st] = buoc;
			st = (st + w)%n; if (st == 0) st = n;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		st = f[i];
		int ww = r/(out[st] - in[st]);
		if (ww)
		{
			dem[in[st]] += ww; dem[out[st]] -= ww;
		}
		ww = r%(out[st] - in[st]);
		if (ww)
		{
			dem[in[st]] += 1; dem[in[st] + ww] -= 1;
		}
	}
	r = r%n; w = w%n;
	w = (1 + 1ll*r*w%n)%n;
	if (w == 0) w = n;
	//cout << w << endl;
	dem[in[w]]++; dem[in[w]+1] --;
	for (int i = 1; i <= buoc; i++) dem[i] += dem[i-1];
	for (int i = 1; i <= n; i++)
	{
		cout << dem[in[i]] + dem[out[i]]  << " ";
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
    //freopen("jog.inp","r",stdin); freopen("jog.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
