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
int val[1000005], val1[1000005], sl[1000005], sl1[1000005], a[1005], b[1005], c[1005], d[1005];
void solve() 
{
	vector<int> ldk, qa;
	int n, L;
	cin >> n >> L;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i]; 
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> d[i];
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) ldk.pb(a[i] + b[j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) qa.pb(c[i] + d[j]);
	

	sort(ALL(ldk)); sort(ALL(qa));
	
	int cnt = 1;
	int dem = 1;
	val[cnt] = ldk[0];
	for (int i = 1; i < (int)ldk.size(); i++)
	if (ldk[i] != ldk[i-1])
	{
		sl[cnt] = dem; dem = 1;
		cnt++; val[cnt] = ldk[i];
	} else dem++;
	sl[cnt] = dem;
	
	int cmt = 1;
	dem = 1;
	val1[cmt] = qa[0];
	for (int i = 1; i < (int)qa.size(); i++)
	if (qa[i] != qa[i-1])
	{
		sl1[cmt] = dem; dem = 1;
		cmt++; val1[cmt] = qa[i];
	} else dem++;
	sl1[cmt] = dem;

//	cout << sl[cnt] << " " << cmt << endl;

	long long res = 0;
	for (int i = 1; i <= cnt; i++)
	{
		while(cmt > 1 && val[i] + val1[cmt] > L) cmt--;
		//cout << cmt << endl;
		if (val[i] + val1[cmt] == L) res = res + 1ll*sl[i]*sl1[cmt];
	}
	cout << res;
}

int main() 
{   
    freopen("CHONDAY.inp","r",stdin); freopen("CHONDAY.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
