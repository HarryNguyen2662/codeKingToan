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
int a[200005], fen[200005];
void update(int id, int val)
{
	for (; id <= 200000; id += (id&(-id))) fen[id] += val;
}
int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}
void solve() 
{
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i, (a[i] >= x));
	}
	int m;
	cin >> m;
	int id = 0;
	while(m--)
	{
		int type, u;
		cin >> type;
		if (type == 1)
		{
			n++;
			cin >> a[n];
			update(n, (a[n] >= x));
		}
		else if (type == 2)
		{
			id++;
			if (a[id] >= x)
			update(id, -1);
		}
		else
		{
			cin >> u;
			cout << get(u + id) << "\n";
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
