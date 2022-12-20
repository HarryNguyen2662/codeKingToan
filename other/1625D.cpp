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
int a[300005], n , k, trace[300005], dp[300005], id[300005];
bool kt[100];
struct Trie
{
	int cnt;
	struct Node
	{
		int child[2];
		int pass;
		Node()
		{
			child[0] = child[1] = pass = 0;
		}
	};
	vector<Node> dk;
	Trie()
	{
		dk.resize(1000005);
		cnt = 1;
	}
	void insert(const int &e)
	{
		int p = 1;
		if (dp[e] > dp[dk[p].pass])
		{
			dk[p].pass = e;
		}
		for (int i = 29; i >= 0; i--)
		{
			bool x = ck(a[e], i);
			if (dk[p].child[x] == 0) dk[p].child[x] = ++cnt;
			p = dk[p].child[x];
			if (dp[e] > dp[dk[p].pass])
			{	
				dk[p].pass = e;
			}
		}
	}
	void find(const int &e)
	{
		int p = 1;
		for (int i = 29; i >= 0; i--)
		{
			bool x = ck(a[e], i);
			if (kt[i])
			{
				
				if (dk[p].child[1-x] == 0) return;
				//cout << e << " " << i << " " << dk[p].child[1-x] << endl;
				p = dk[p].child[1-x];
			}
			else
			{
				if (dk[p].child[1-x] != 0)
				{
					int pp = dk[p].child[1-x];
					if (dp[trace[e]] < dp[dk[pp].pass])
					{
						trace[e] = dk[pp].pass;
					}
				}
				if (dk[p].child[x] == -1) return;
				p = dk[p].child[x];
			}
		}
		if (dp[trace[e]] < dp[dk[p].pass])
		{
			trace[e] = dk[p].pass;
		}
	}
};
void solve() 
{
	Trie ldk;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id+ 1, id + 1 + n, [](const int &x, const int&y)
		{
			return a[x] < a[y];
		});
	//for (int i = 1; i <= n; i++) cout << id[i] << " "; cout << endl;
	for (int i = 0 ; i <= 29; i++) kt[i] = ck(k, i);
	dp[0] = -1;
	dp[id[1]] = 1;
	ldk.insert(id[1]);
	for (int i = 2; i <= n; i++) 
	{
		ldk.find(id[i]);
		if (trace[id[i]] == 0) dp[id[i]] = 1; else dp[id[i]] = dp[trace[id[i]]] + 1;
		//cout << id[i] << " " << trace[id[i]] << endl;
		ldk.insert(id[i]);
	}
	int res = 0;
	int idd = -1;
	for (int i = 1; i <= n; i++)
	if (dp[id[i]] > res)
	{
		res = dp[id[i]];
		idd = id[i];
	}
	if (res <= 1)
	{
		cout << -1;
		return;
	}
	cout << res << "\n";
	while(idd != 0)
	{
		cout << idd << " ";
		idd = trace[idd];
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
