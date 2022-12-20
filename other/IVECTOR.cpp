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
int n, t[100005], re[100005], fen[100005], feen[100005], sg[400005];
void update(int id)
{
	for (; id; id -= (id&(-id))) fen[id]++;
}
int get(int id)
{
	int res = 0;
	for (; id <= n; id += (id&(-id))) res += fen[id];
	return res;
}
void update1(int id, int l, int r, int k)
{
	if (l > k || r < k) return;
	if (l == r)
	{
		sg[id] = 1;
		return;
	}
	int mid = (l + r)/2;
	if (mid >= k) update1(id*2, l, mid, k); else update1(id*2 + 1, mid + 1, r, k);
	sg[id] = sg[id*2] + sg[id*2+1];
}
int get1(int id, int l, int r, int val)
{
	if (l == r) return l;
	int mid = (l + r)/2;
	if (mid - l + 1 - sg[id*2] >= val) return get1(id*2, l , mid, val);
	return get1(id*2 + 1, mid + 1, r, val - (mid - l + 1 - sg[id*2])); 
}
void solve() 
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int val;
		cin >> val;
		re[val] = get(val);
		update(val);
	}
	for (int i = 1; i < n; i++) cout << re[i] << " "; cout << re[n] << "\n";
	for (int i = 1; i <= n; i++) 
	{
		int val;
		cin >> val;
		val = get1(1, 1, n, val + 1);
		//cout << re[i] << endl;
		update1(1, 1, n, val);
		re[val] = i;
	}
	for (int i = 1; i < n; i++) cout << re[i] << " "; cout << re[n];
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("IVECTOR.inp","r",stdin); freopen("IVECTOR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
