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
 long long BASE= 256;
long long HSMOD[4] ={(long long)1e9 + 7, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
long long pw[NMOD + 2 ][200005];
void preparepw()
{
    for (int i = 0; i < NMOD; i++)
    {
    	//cout << "debug: " << i << "\n";
        pw[i][0] = 1;
        for (int j = 1; j <= 200003; j++) {
        	pw[i][j] = pw[i][j-1]*BASE % HSMOD[i];
        }
    }

	//cout << "DEBUG : " << pw[1][8] << " " << BASE << " " << pw[1][8] * BASE % (1000000000 + 5277) << " " << pw[1][9] << " " << HSMOD[1] << endl;
} 
struct HSS
{   
    int len;
    vector<long long> ps[NMOD];
    HS (string s)
    {
        int n = s.size(); len = n;
        for (int i = 0 ; i < NMOD; i ++) 
            {
                ps[i].resize(n + 1);
                ps[i][0] = 0;
                for (int j = 1; j <= n; j++) ps[i][j] = (ps[i][j-1] +1ll*s[j-1]*pw[i][j]%HSMOD[i])%HSMOD[i];
            }
    } 
    int qy(int l, int r, int type)
    {
    	l++; r++;
        return (ps[type][r] - ps[type][l-1] + HSMOD[type])%HSMOD[type]*pw[type][len-r]%HSMOD[type];
    }
};
HSS qa;
int n, k;
string st[60];
bool check(int len)
{
	vector<pair<int,int>> ldk;
	int sl = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<pair<int,int>> w;
		int dai = (int)st[i].size();
		for (int j = 0; j < dai - len + 1; j++)
		{	
			//for (int e  = j; e <= j + len - 1; e++) cout << st[i][e];
			w.pb({qa.qy(j + sl, sl + j + len - 1, 0), qa.qy(j + sl, sl + j + len - 1, 1)});
			//cout << endl;
		}
		if (!w.empty())
		{
			sort(w.begin(), w.end());
			ldk.pb(w[0]);
			for (int i = 1; i < (int)w.size(); i++) if (w[i] != w[i-1]) ldk.pb(w[i]);
		}
		sl += dai;
	}
	sort(ldk.begin(), ldk.end());
	//for (auto v : ldk) cout << v.fi << " " << v.se << endl;
	int dem = 1;
	if (dem >= k) return true;
	for (int i = 1; i < (int)ldk.size(); i++)
	{
		if (ldk[i] != ldk[i-1])
		{
			dem = 1;
		} 	else dem++;
		if (dem >= k) return true;
	}
	return false;

}
void WRITEANS(int len)
{
	vector<pair<int,int>> ldk;
	int sl = 0;
	for (int i = 1; i <= n; i++)
	{
		vector<pair<int,int>> w;
		int dai = (int)st[i].size();
		for (int j = 0; j < dai - len + 1; j++)
		{	
			w.pb({qa.qy(j + sl, sl + j + len - 1, 0), qa.qy(j + sl, sl + j + len - 1, 1)});
		}
		if (!w.empty())
		{
			sort(w.begin(), w.end());
			ldk.pb(w[0]);
			//out <<(int)w.size() << endl;
			for (int i = 1; i < (int)w.size(); i++) if (w[i] != w[i-1]) ldk.pb(w[i]);
		}
		sl += dai;
	}
	sort(ldk.begin(), ldk.end());
	
	int dem = 1;
	pair<int,int> re;
	for (int i = 1; i < (int)ldk.size(); i++)
	{
		if (ldk[i] != ldk[i-1])
		{
			dem = 1;
		} 	else dem++;
		if (dem >= k)
		{
			re = ldk[i];
			break;
		}
	}
	sl = 0;
	for (int i = 1; i <= n; i++)
	{
		int dai = (int)st[i].size();
		for (int j = 0; j < dai - len + 1; j++)
		if (re.fi == qa.qy(j + sl, j + sl + len - 1, 0) && re.se == qa.qy(j + sl, j + sl + len - 1, 1))
		{	
			for (int e = j; e <= j + len - 1; e++) cout << st[i][e];
				return;
		}
		sl += dai;
	}
}
void solve() 
{
	string s = "";
	cin >> n >> k;
	int l = 1, r = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> st[i];
		r = max(r, (int)st[i].size());
		s += st[i];
	}
	if (k == 1)
	{
		for (int i = 1; i <= n; i++) if((int)st[i].size() == r)
		{
			cout << st[i];
			return;
		}
	}
	preparepw();
	qa.HS(s);
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (check(mid)) l = mid + 1; else r = mid - 1;
	}
	//cout << r << endl;
	WRITEANS(r);
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("thuyvan.inp","r",stdin); freopen("thuyvan.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
