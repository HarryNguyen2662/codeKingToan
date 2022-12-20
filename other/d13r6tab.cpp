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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int thaotac1(int val, int id, int len)
{
	for (int i = id - 1; i < (len-1)*len + id; i += len)
	{
		if (ck(val, i) && !ck(val, i + 1)) 
		{
			val -= mask(i); val += mask(i+1);
		}
		else if (!ck(val, i) && ck(val, i + 1))
		{
			val += mask(i); val -= mask(i+1);
		}
	}
	return val;
}
int thaotac2(int val, int id, int len)
{
	for (int i = (id-1)*len; i < id*len ; i++)
	{
		if (ck(val, i)) val -= mask(i); else val += mask(i);
	}
	return val;
}
int n;
pair<int,int> trace[1200005];
bool kq[1200005];
void bfs(int st)
{
	queue<int> qe; qe.push(st);
	trace[st] = {-1, 0};
	while(!qe.empty())
	{
		int st = qe.front(); qe.pop();
		if (kq[st])
		{
			vector<pair<int,int>> ldk;
			while(trace[st].fi != -1)
			{
				ldk.pb(trace[st]);
				if (trace[st].fi == 1) st = thaotac1(st, trace[st].se, n);
				else st = thaotac2(st, trace[st].se, n);
			}
			cout << (int)ldk.size() << "\n";
			reverse(ALL(ldk)); for (auto v : ldk) cout << v.fi << " " << v.se << "\n";
			exit(0);
		}
		for (int i = 1; i < n; i++)
		{
			int nst = thaotac1(st, i, n);
			if (trace[nst].fi == 0)
			{
				trace[nst] = {1, i};
				qe.push(nst);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			int nst = thaotac2(st, i, n);
			if (trace[nst].fi == 0)
			{
				trace[nst] = {2, i};
				qe.push(nst);
			}
		}
	}
}
void solve()
{
	cin >> n;
	if (n >= 5)
	{
		cout << -1;
		return;
	}
	int st = 0, ed = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		bool kt;
		cin >> kt;
		if (kt) st += mask((i-1)*n + j - 1);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		bool kt;
		cin >> kt;
		if (kt) ed += mask((i-1)*n + j - 1);
	}
	kq[ed] = true;
	for (int i = 0; i < n*n; i++) if (ck(ed, i))
	{
		kq[ed - mask(i)] = true;
	}
	else kq[ed + mask(i)] = true;
	bfs(st);
	cout << -1;
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
