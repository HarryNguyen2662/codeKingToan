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
vector<int> id;
long long cal(long long val, int i)
{
	if (val == 0) return 0;
	if (i == -1) return 1;
	return val/mask(id[i]+1)*cal(mask(id[i]), i - 1) + cal(min(mask(id[i]), val%mask(id[i]+1)), i - 1);
}
void solve() 
{
	int n, m, q;
	cin >> n >> m >> q;
	while(q--)
	{
		long long x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		id.clear();
		for (int i = 0; i <= 29; i++) if (ck(x1, i)) id.pb(i);
		//cout << id.size() << endl;
		long long res = cal(y2 + 1, (int)id.size() - 1);
		res -= cal(y1, (int)id.size() - 1);
		if (y1 > 0 && ((x1 & (y1-1) ) == 0) && ((x1 & y1) == 0)) res++;
		id.clear();
		for (int i = 0; i <= 29; i++) if (ck(y1, i)) id.pb(i);
		res += cal(x2 + 1, (int)id.size() - 1);
		res -= cal(x1, (int)id.size() - 1);
		if (x1 > 0 && (y1 & (x1-1) ) == 0 && (y1 & x1) == 0) res++;
		if ((x1&y1) == 0) res--;
		cout << res << "\n"; 
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
