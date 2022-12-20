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
vector<pair<int,int>> a[10005];
pair<int,int> c[1005];
int re[1005];
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> c[i].fi >> c[i].se;
		//cout << c[i].fi << " " << c[i].se << endl;
		a[c[i].fi].pb({c[i].se, i});
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	for (int i = 1; i <= n; i++)
	{
		for (auto v : a[i]) pq.push(v);
		a[i].clear();
		while(!pq.empty() && pq.top().fi < i) pq.pop();
		//cout << pq.top().se << endl;
		re[pq.top().se] = i; pq.pop();
	}
	for (int i = 1; i <= n; i++)
	{
		cout << c[i].fi << " " << c[i].se << " " << re[i] << "\n";
	}
//	cout << endl;
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
    cin >> testcase;
    while(testcase--)
        solve();
}
