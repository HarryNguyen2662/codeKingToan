#include<iostream>
#include<queue>

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

const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;


int mid;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
int dist[2005][2005];
bool dd[2005][2005];
int n, m;
pair<int,int> inqe[4000002], iq[4000002];

int readInt () {
	int result = 0;
	char ch;
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	return result;
}


void dfs(int u, int v)
{
	dd[u][v] = true;
	int cnt = 1, cmt = 1;
	iq[cnt] = {u, v};
	while(cmt <= cnt)
	{
		int u = iq[cmt].fi, v = iq[cmt].se;
		cmt++;
		for (int i = 0; i < 4; i++)
		{
			int nu = u + x[i], nv = v + y[i];
			if (nu >= 1 && nu <= n && nv >= 1 && nv <= m && dd[nu][nv] == false && dist[nu][nv] >= mid)
			{
				dd[nu][nv] = true;
				iq[++cnt] = {nu, nv};

			}
		}
	}
}

void solve() 
{
	int cnt = 0;
	pair<int,int> st, ed;
	n = readInt(); m = readInt();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		char s;
		s = getchar();
		if (i > 1 && j == 1) s = getchar();
		dist[i][j] = -1;
		if (s == 'P')
		{
			st = {i, j};
		}
		else if (s == 'C')
		{
			ed = {i, j};
		}
		else if (s == '+')
		{
			dist[i][j] = 0;
			inqe[++cnt] = {i, j};
		}

	}
	int cmt = 1;
	int re = 0;
	while(cmt <= cnt)
	{
		int u = inqe[cmt].fi, v = inqe[cmt].se;
		cmt++;
		for (int i = 0; i < 4; i++)
		{
			int nu = u + x[i], nv = v + y[i];
			if (nu >= 1 && nu <= n && nv >= 1 && nv <= m && dist[nu][nv] == -1)
			{
				
				dist[nu][nv] = dist[u][v] + 1;
				re = max(re, dist[nu][nv]);
				inqe[++cnt] = {nu, nv};

			}
		}
	}
	int l = 0, r = re;
	while(l <= r)
	{
		mid = (l + r)/2;
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) dd[i][j] = false;
		if (dist[st.fi][st.se] >= mid)
		dfs(st.fi, st.se);

		if (dd[ed.fi][ed.se]) l = mid + 1; else r = mid - 1;
	}

	cout << r;
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
