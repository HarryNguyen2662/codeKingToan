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
int dist[2000005];
bool use[2000005];
void solve() 
{
	int n, x, y, z, st = 0, ed = 0;
	cin >> n >> x >> y >> z;
	for (int i = 1 ; i <= n ; i++)
	{
		bool kt;
		cin >> kt;
		if (kt) st += mask(i-1);
	}
	for (int i = 1 ; i <= n ; i++)
	{
		bool kt;
		cin >> kt;
		//cout << kt << endl;
		if (kt) ed += mask(i-1);
	}
	//cout << ed << endl;
	for (int i = 0; i < mask(n); i++) dist[i] = oo;
	dist[st] = 0;
	//cout << mask(n) << endl;
	for (int i = 0; i < mask(n); i ++)
	{
		int v = -1;
		for (int j = 0; j < mask(n); j++)
		if (!use[j] && (v == -1 || dist[j] < dist[v])) v = j;
		
		if (dist[v] == oo) break;
		use[v] = true;
		for (int j = 0; j < n; j++) if (ck(v, j))
		{
			int u = v - mask(j);
			// cout << u << endl;
			if (dist[u] > dist[v] + x)
			{
				dist[u] = dist[v] + x;
			}
		}
		else
		{
			int u = v + mask(j);
			//cout << u << endl;
			if (dist[u] > dist[v] + y)
			{
				dist[u] = dist[v] + y;
			}
		}
		for (int j = 0; j < n; j++)
			for (int jj = j + 1; jj < n; jj++)
				if (ck(v, j) != ck(v, jj))
				{
					int u = v^mask(j)^mask(jj);
					if (dist[u] > dist[v] + z*(jj - j))
					{
						dist[u] = dist[v] + z*(jj -j);
					}
				}
	}
	cout << dist[ed];
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
