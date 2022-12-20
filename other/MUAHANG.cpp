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
bool dd[2000005];
int c[1005], s[1005];
void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i] >> s[i];
	//cout << s[1] << endl;
	vector<int> ldk;
	ldk.pb(0); dd[0] = true;
	for (int i = 0; i < n; i++)
	{
		int len = (int)ldk.size();
		for (int j = 0; j < len; j++)
		{
			for (int e = 1; e <= s[i+1]; e++) if (dd[ldk[j] + e*c[i+1]] == false)
			{
				dd[ldk[j] + e*c[i+1]] = true;
				ldk.pb(ldk[j] + e*c[i+1]);
			}            
		}
	}
        sort(ALL(ldk));
    for (int i = 1; i < (int)ldk.size(); i++) cout << ldk[i] << "\n";
}	

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("MUAHANG.inp","r",stdin); freopen("MUAHANG.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
