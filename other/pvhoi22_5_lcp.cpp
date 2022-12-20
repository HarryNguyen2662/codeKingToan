#include<bits/stdc++.h>

using namespace std;

#define NMOD 2
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
int n, k, cmt[5005];
long long dp[5005][5005], cost[5005][5005];
string s[5005];
bool cmp(const string &x, const string &y)
{
	if (x[0] == y[0])
	{
		return (int)x.size() > (int)y.size();
	}
	else return x < y;
}
void sub1()
{
	sort(s + 1, s + 1 + n, cmp);
	int cnt = 1; cmt[1] = 1;
	cost[1][1] = 0;
	int mx = 1;
	for (int i = 2; i <= n; i++)
	if (s[i][0] != s[i-1][0])
	{
		cnt++; cmt[cnt] = 1;
		cost[cnt][1] = 0;
	}
	else
	{
		++cmt[cnt];
		cost[cnt][cmt[cnt]] = cost[cnt][cmt[cnt]-1] + (long long)s[i].size()*1ll*(cmt[cnt]-1);
	}
	//cout<< cmt[1] << " " << cmt[2] << endl;
	for (int i = 0; i <= cnt; i++) for (int j = 0; j <= k; j++) dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < cnt; i++)
		for (int j = 0; j <= k; j++)
		if (dp[i][j] != -1)
		{
			//cout << i << " " << j << endl;
			for (int e = 0; e <= cmt[i+1]; e++)
			if (j  + e <= k)
			{
				//if (i + 1 == cnt && j + e == k) cout << j << " " << dp[i][j] + cost[2][3] << endl;
				dp[i+1][j + e] = max(dp[i+1][j+e], dp[i][j] + cost[i+1][e]);
			}
		}
	//cout << dp[1][2] << endl;
	cout << dp[cnt][k];
	return;
}

const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
const long long BASE = 256;
const int MAXN = 4000005;
long long pw[NMOD][MAXN + 5];
void preparepw()
{
    for (int i = 0; i < NMOD; i ++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= MAXN; j++) pw[i][j] = pw[i][j-1]* BASE % HSMOD[i];
    }
}
int mx = 0;
struct HSS
{   
    int len;
    vector<long long> ps[NMOD];
    void HS (string ss)
    {
        int n = (int)ss.size(); len = n;
        for (int i = 0 ; i < NMOD; i ++) 
            {
                ps[i].resize(n + 1);
                ps[i][0] = 0;
                for (int j = 1; j <= n; j++) ps[i][j] = (ps[i][j-1] +1ll*ss[j-1]*pw[i][j]%HSMOD[i])%HSMOD[i];
            }
    } 
    int qy(int l, int r, int type)
    {
        return (ps[type][r] - ps[type][l-1] + HSMOD[type])%HSMOD[type]*pw[type][mx-r]%HSMOD[type];
    }
};
HSS ldk[5005];
int cal(int i, int j)
{
	int l = 1, r = min((int)s[i].size(), (int)s[j].size());
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (ldk[i].qy(1, mid, 0) == ldk[j].qy(1, mid, 0) 
			&& ldk[i].qy(1, mid, 1) == ldk[j].qy(1, mid, 1)) l = mid + 1; else r = mid - 1;
	}
	return r;
}
void sub3()
{
	sort(s + 1, s + 1 + n);
	preparepw();
	for (int i = 1; i <= n; i++) ldk[i].HS(s[i]), mx = max(mx, (int)s[i].size());
	long long res = 0;
	for (int i = 1; i < n; i++) cost[i][i+1] = cal(i, i + 1);
	for (int i = 1; i <= n - 2; i++)
		res = max(res, cost[i][i+1] + cost[i+1][i+2] + cal(i, i + 2));
	cout << res;
	return;
 }
void sub4()
{
	preparepw();
	for (int i = 1; i <= n; i++) ldk[i].HS(s[i]), mx = max(mx, (int)s[i].size());
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			cost[i][j] = cost[j][i] = cal(i, j);
	long long res = 0;
	for (int i = 1; i < mask(n); i++)
	if (getbit(i) == k)
	{
		long long cur = 0;
		for (int j = 0; j < n; j++) if (ck(i,j))
		for (int e = j + 1; e < n; e++) if (ck(i, e))
			cur += cost[j+1][e+1];
		res = max(res, cur);
	}
	cout << res;
	return;
}

struct Trie
{
	long long kq;
	struct Node
	{
		Node *child[26];
		int pass;
		Node()
		{
			for (int i = 0; i < 26; i++) child[i] = NULL;
			pass = 0;
		}
	};
	Node *root;
	Trie()
	{
		root = new Node();
		kq = 0;
	}

	void insert(const string &xx)
	{
		Node *p = root;
		for (int i = 0; i < (int)xx.size(); i++)
		{
			int x = xx[i] - 'a';
			if (p -> child[x] == NULL) p -> child[x] = new Node();
			p = p -> child[x];
			kq += p -> pass;
			p -> pass++;
		}
	}

};

void sub2()
{
	Trie qa;
	for (int i = 1; i <= n; i++)
	{
		qa.insert(s[i]);
	}
	cout << qa.kq;
}


void solve() 
{
	
	bool oksub1 = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for (int j = 1; j < (int)s[i].size(); j++) if (s[i][j] != s[i][j-1])
		{
			oksub1 = false; break;
		}
	}
	if (k == 1)
	{
		cout << 0;
		return;
	}
	if (oksub1) sub1();
	else if (k == n) sub2();
	else if (n <= 20) sub4();
	else if (k == 3) sub3();
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
