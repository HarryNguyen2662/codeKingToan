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
vector<int> p[100005], mx[100005];
int luu[100005];
void solve() 
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) luu[i] = 0;
	p[0].assign(n + 2, 0);
	for (int i = 1; i <= m; i++)
	{
		p[i].assign(n + 2, 0);
		for (int j = 1; j <= n; j++) 
		{
			cin >> p[i][j];
			//cout << p[i][j] << " ";
			if (p[i][j] > p[luu[j]][j])
			{
				luu[j] = i;
			}
		}
		//cout << endl;
	}
	int res = oo + 1;
	vector<int> ldk;
	for (int i = 1; i <= n; i++) 
	{
		res = min(res, p[luu[i]][i]); ldk.pb(luu[i]);
	}	
	sort(ALL(ldk)); ldk.resize(unique(ALL(ldk)) - ldk.begin());
	int sl = (int)ldk.size();
	if (sl < n)
	{
		cout << res << "\n";
		return;
	}
	//cout << sl << endl;
	for (int i = 1; i <= n; i++)
	{
		mx[i].assign(n + 2, 0);
		mx[i][i] = p[luu[i]][i];
	 	for (int j = i + 1; j <= n; j++) mx[i][j] = min(mx[i][j-1], p[luu[j]][j]);
	}
	int resres = 0;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
	for (int e = 1; e <= m; e++)  
	resres = 
max(resres, min({p[e][j], p[e][i], (i == 1 ? oo : mx[1][i-1]), (i + 1 == j ? oo : mx[i+1][j-1]), (j == n ? oo : mx[j + 1][n])}));
	cout << resres << "\n";	 
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
