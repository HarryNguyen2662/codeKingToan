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
const long long BASE = 11062004;
void solve() 
{
	string s, t;
	cin >> s;
	cin >> t;
	
	long long fact = 1;
	long long hashT = 0;
	for (int i = 0; i < (int)t.size(); i++)
	{

		fact = fact*BASE%MOD;
		hashT = (hashT*BASE%MOD + t[i] - 'a' + 1)%MOD;
	}
	//cout << hashT << endl;
	vector<long long> ldk;
	vector<char> res;
	ldk.pb(0);
	//cout << (int)s.size() << endl;
	for (int i = 0; i < (int)s.size(); i++)
	{
		ldk.pb((ldk.back()*BASE%MOD + s[i] - 'a' + 1)%MOD);
		res.pb(s[i]);
		//if (i == 3) cout << ldk.back() << endl;
		if ((int)ldk.size() - 1 >= (int)t.size())
		{
			//cout << i << endl;
			long long w = (ldk.back() - ldk[(int)ldk.size() - (int)t.size() - 1]*fact%MOD + MOD)%MOD;
			//cout << w << endl;
			if (w == hashT)
			{
				for (int e = 1; e <= (int)t.size(); e++)
				{
				 	ldk.pop_back(); res.pop_back();
				}
			}
		}
	}
	//cout << ldk[4] << endl;
	for (auto v : res) cout << v;
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
