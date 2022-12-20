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
struct DATA
{
	int lx, ly, rx, ry, ti;
};
vector<pair<int,pair<int,int>>> a[1005];
DATA c[1005];
int dist[1005][4005];
int getdist(int x, int y, int i)
{
	if ((y == c[i].ry || y == c[i].ly) && c[i].lx <= x && x <= c[i].rx)
	{

		if (y == c[i].ly) return x - c[i].lx;
		else return 2*c[i].rx - x - c[i].lx + c[i].ry - c[i].ly;
	}
	if ((x == c[i].rx || x == c[i].lx) && c[i].ly <= y && y <= c[i].ry)
	{
		//cout << x <<" " << y << " "<< i << " " << c[i].ly << " " << c[i].ry << endl;
		if (x == c[i].lx) return 2*c[i].ry - y + 2*(c[i].rx - c[i].lx) - c[i].ly;
		else return y - c[i].ly + c[i].rx - c[i].lx;
	}
	return -1;
}
void match(int i, int j)
{
	if (getdist(c[i].rx, c[i].ly, j) != -1) a[i].pb({j, {c[i].rx, c[i].ly} }), a[j].pb({i, {c[i].rx, c[i].ly} });
	if (getdist(c[j].lx, c[j].ly, i) != -1) a[i].pb({j,{c[j].lx, c[j].ly}}), a[j].pb({i,{c[j].lx, c[j].ly}});
	if (getdist(c[i].rx, c[i].ry, j) != -1) a[i].pb({j,{c[i].rx, c[i].ry}}), a[j].pb({i,{c[i].rx, c[i].ry}});
	if (getdist(c[j].lx, c[j].ry, i) != -1) a[i].pb({j,{c[j].lx, c[j].ry}}), a[j].pb({i,{c[j].lx, c[j].ry}});
	if (getdist(c[i].rx, c[i].ry, j) != -1) a[i].pb({j,{c[i].rx, c[i].ry}}), a[j].pb({i,{c[i].rx, c[i].ry}});
	if (getdist(c[j].rx, c[j].ly, i) != -1) a[i].pb({j, {c[j].rx, c[j].ly}}), a[j].pb({i, {c[j].rx, c[j].ly}});
	if (getdist(c[i].lx, c[i].ry, j) != -1) a[i].pb({j,{c[i].lx, c[i].ry}}), a[j].pb({i,{c[i].lx, c[i].ry}});
	if (getdist(c[j].lx, c[j].ly, i) != -1) a[i].pb({j,{c[j].lx, c[j].ly}}), a[j].pb({i,{c[j].lx, c[j].ly}});
}
int add(int dich, int xuatphat, int i)
{
	int addd = dich - xuatphat;
	if(addd < 0) addd += 2*(c[i].rx - c[i].lx) + 2*(c[i].ry - c[i].ly);
	return addd;
}
void solve() 
{
	int n, m, stx, sty, edx, edy;
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	cin >> n >> m >> stx >> sty >> edx >> edy;
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) for (int j = 0; j <= 2*(m+n); j++) dist[i][j] = 2*oo;
	for (int i = 1; i <= q; i++)
	{
		cin >> c[i].lx >> c[i].ly >> c[i].rx >> c[i].ry >> c[i].ti;
		//cout << c[i].lx << " " << c[i].ly << endl;
		int cur = getdist(stx, sty, i);
		if (cur != -1)
		{
			dist[i][cur] = add(cur, c[i].ti, i);
			pq.push({dist[i][cur], {i, cur}});
		}
	}
	for (int i = 1; i <= q; i++)
	{
		if (c[i].lx == c[i].ly && c[i].lx == c[i].rx && c[i].lx == c[i].ry) continue;
		for (int j = i + 1; j <= q; j++)
		{
			if (c[j].lx == c[j].ly && c[j].lx == c[j].rx && c[j].lx == c[j].ry) continue;
			match(i, j);
		}
	}
	while(!pq.empty())
	{
		int dai = pq.top().fi;
		pair<int,int> it = pq.top().se;
		pq.pop();
		if (dai != dist[it.fi][it.se]) continue;
		//cout << it.fi << " " << it.se << " " << dai << endl;
		for (auto v : a[it.fi])
		{
			int tt = getdist(v.se.fi, v.se.se, it.fi);
			//cout << tt << endl;
			int add1 = dai + add(tt, it.se, it.fi) + 1;
			int tnt = getdist(v.se.fi, v.se.se, v.fi);
			int vt = (c[v.fi].ti + add1)%(2*(c[v.fi].rx - c[v.fi].lx + c[v.fi].ry - c[v.fi].ly));
			//cout <<"! " << v.fi << " " << tnt << " " << vt << " " <<add1 << endl;
			add1 += add(tnt, vt, v.fi);
			if (dist[v.fi][tnt] > add1)
			{
				dist[v.fi][tnt] = add1;
				pq.push({add1, {v.fi, tnt}});
			}
		}
	}
	int res = 2*oo;
	for (int i = 1; i <= q; i++)
	{
		int cur = getdist(edx, edy, i);
		if (cur == -1) continue;
		//cout << i << endl;
		for (int j = 0; j < 2*(c[i].rx - c[i].lx + c[i].ry - c[i].ly); j++)
		if (dist[i][j] != 2*oo)
		{
			//cout << j << endl;
			res = min(res, dist[i][j] + add(cur, j, i));
		}
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