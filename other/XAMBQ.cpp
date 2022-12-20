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
int n, add[105], fen[1505][1505];
long long sum = 0, dp[1505][1505];
void update(int type, int id, int val)
{
	for (; id <= n + 1; id += (id&(-id))) fen[type][id] += val;
}
int get(int type, int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[type][id];
	return res;
}
void emlaLETHIQUYNHKINGhoclop11C1truongthptchuyenLEQUYDON()
{
	//cout << "query: " << endl;
	char type; int x, y;
	cin >> type >> x >> y;
	int l = y, r = y;
	for (int i = x; i <= n; i++)
	{
		if (i != x)
		{
			while(l <= r && l != 1 && dp[i][l-1]+get(i,l-1)  >= (add[type] == 1) + dp[i-1][l] + get(i-1,l) - add[type])
			l++;
		}

		if (l > r) break;
		while(r + 1 <= n && (i == 1 || dp[i][r] + get(i,r)  >= (add[type] == -1) + dp[i-1][r+1] + get(i-1,r+1))) r++;
		
		//cout << i << " " <<  l << " " << r << endl;
		//if (l == 2 && r == 2) cout << dp[5][2] + get(5,2) << " " << dp[i-1][r+1] + get(i-1,r+1) << endl;
		update(i, l, add[type]); update(i, r + 1, -add[type]);
		sum += 1ll*(r - l + 1)*add[type];
	}
	cout << sum << "\n";
}
void solve() 
{
	add['U'] = 1; add['D'] = -1;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) 
			{
				int val;
				cin >> val;
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + val;
				sum += dp[i][j];
			}
	// for (int i = 1; i <= n; i++)
	// {
	// 	for (int j = 1; j <= n; j++) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;
	cout << sum << endl;
	for (int query = 1; query <= n; query++)
		emlaLETHIQUYNHKINGhoclop11C1truongthptchuyenLEQUYDON();
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
