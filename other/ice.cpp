
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

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
bool dis[5001][5001];
int dist[5001][5001];
pair<int,int> inqe[25000002];

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


void solve() 
{
	int cnt = 0;
	int n;
 	n = readInt();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
		{
			char x;
			x = getchar();
			if (x != '0' && x != '1') x = getchar();
			dis[i][j] = true;
			dist[i][j] = -1;
			if (x == '0')
			{
				dist[i][j] = dis[i][j] = 0;
				inqe[++cnt] = {i, j};
			}
		}

	int res = 0;
	int cmt = 1;
	while(cmt <= cnt)
	{
		int u = inqe[cmt].fi, v = inqe[cmt].se;
		cmt++;
		//cout << u << " " << v << endl;
		for (int i = 0; i < 4; i++)
		{
			int nu = u + x[i], nv = v + y[i];
			if (nu >= 1 && nu <= n && nv >= 1 && nv <= n && dist[nu][nv] == -1)
			{
				if (dis[nu][nv])
				{
					dis[nu][nv] = false;
				}
				else 
				{
					dist[nu][nv] = dist[u][v] + 1;
					res = max(res, dist[nu][nv]);
					inqe[++cnt] = {nu, nv};
				}
			}
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
