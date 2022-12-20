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

const long long digit = 1e9;
long long ha[100], haa[100], c[100], res[100], dist[1000005];
int ct = 0;
int a;

void cal(const long long &l, const long long &r)
{
	if (l > r) return;
	long long sohang = (r - l)/a + 1;
	long long tong = r + l;
	if (tong%2 == 0) tong /= 2; else sohang /= 2;
	//cout << sohang << " " << tong << endl;
	int cnt = -1;
	while(sohang)
	{
		ha[++cnt] = sohang%digit;
		sohang /= digit;
	}
	int cmt = -1;
	while(tong)
	{
		haa[++cmt] = tong%digit;
		tong /= digit;
	}
	int ctt = cmt + cnt;
	for (int i = 0; i <= ctt + 3; i++) c[i] = 0;
	for (int i = 0; i <= cnt; i++)
	{
		long long du = 0;
		for (int j = 0; j <= cmt; j++)
		{
			int k = i + j;
			c[k] += ha[i]*haa[j] + du;
			du = c[k]/digit; c[k] %= digit;
		}
		if (du)
		{
			c[i + cmt + 1] += du;
			ctt = max(ctt, i + cmt + 1);
		}
	}
	while(ctt > 0 && c[ctt] == 0) ctt--;
		
	// cout << ctt << endl;
	// for (int i = ctt; i >= 0; i--) cout << c[i] ;
	// 	cout << endl;
	int du = 0;
	ct = max(ct, ctt);
	for (int i = 0; i <= ctt; i++)
	{
		res[i] = (res[i] + c[i] + du);
		du = res[i]/digit;
		res[i] %= digit; 
	}
	int st = min(ct, ctt);
	while(du)
	{
		st++;
		res[st] += du;
		du = res[st]/digit; res[st] %= digit;
	}
	ct = max(ct, st);
}

void solve() 
{
	int b, c;
	cin >> a >> b >> c;

	for (int i = 0 ; i < a; i++) dist[i] = -1;
	dist[1%a] = 1;
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> iq;
	iq.push({1, 1%a});

	while(!iq.empty())
	{
		pair<long long, int> iqq = iq.top(); iq.pop();
		int u = iqq.se; long long len = iqq.fi;
		if (len != dist[u]) continue;
		int v = (u + b)%a;
		if (dist[v] == -1 || dist[v] > len + b)
		{
			dist[v] = len  + b;
			iq.push({dist[v], v});
		}

		v = (u + c)%a;
		if (dist[v] == -1 || dist[v] > len + c)
		{
			dist[v] = len  + c;
			iq.push({dist[v], v});
		}
	}
	int dem = 0;
	long long l, r;
	cin >> l >> r;
	for (int i = 0; i < a; i++)
	if (dist[i] != -1)
	{
		dem++;
		long long le = l + (i - l%a);
		if (le < l) le += a;
		le = max(le, dist[i]);
		long long re = r + (i - r%a);
		if (re > r) re -= a;
		cal(le, re);
		//cout << i << " " << dist[i] << " " << le << " " << re << endl;
	}
	cout << res[ct];
	ct--;
	while(ct >= 0)
	{
			long long w = digit/10;
			while(w)
			{
				cout << res[ct]/w;
				res[ct] %= w;
				w /= 10;
			}
		ct--;
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
   //freopen("lift.inp","r",stdin); freopen("lift.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
