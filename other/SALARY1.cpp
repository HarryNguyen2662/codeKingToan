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
vector<int> a[100005];
long long w[100005], fen[200005];
int cnt = 0, in[100005], out[100005];
void dfs(int u)
{
	in[u] = ++cnt;
	for (auto v : a[u])
	{
		dfs(v);
	}
	out[u] = ++cnt;
}


void update(int id, int val)
{
	for (; id <= cnt; id += (id&(-id))) fen[id] += val;
}
long long get(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}
void solve() 
{
	int n, m;
	int cha;
	cin >> n >> m;
	cin >> w[1];
	for (int i = 2; i <= n; i++)
	{
		
		cin  >> w[i] >> cha;
			//cout << cha << endl;
		a[cha].pb(i);
	}
	dfs(1);
	for (int j = 1; j <= m; j++)
	{
		char type; int u;
		cin >> type >> u;
		//cout << type << " " << u << endl;
		if (type == 'p')
		{
			int val;
			cin >> val;
			//cout << val << endl;
			if (in[u]+1 <= out[u]-1)
			{
				update(in[u]+1, val); 
				update(out[u], -val);
			}
		}
		else
		{
		 	cout <<  w[u] + get(in[u]) << "\n";
		}
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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
