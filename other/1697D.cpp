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

int luu[10000];
char s[10000];

void ask1(int id)
{
	cout << "? 1 " << id << endl;
}

void ask2(int l, int r)
{
	cout << "? 2 " << l << " " << r << endl;
}

void erase(int &len, int val)
{
	for (int i = val; i < len; i++) luu[i] = luu[i+1];
	len--;
}

void insert(int &len, int val)
{
	luu[++len] = val;
}


void solve() 
{
	int n;
	int cnt = 0;
	cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		int l = 1, r = cnt;
		while(l <= r)
		{
			int mid = (l + r)/2;
			ask2(luu[mid], i);
			int w; cin >> w;
			if (w == cnt - mid + 1) l = mid + 1; else r = mid - 1;
		}
		if (r > 0)
		{
			s[i] = s[luu[r]];
			erase(cnt, r); insert(cnt, i);
		}
		else
		{
			ask1(i);
			cin >> s[i];
			insert(cnt, i);
		}
	}

	cout << "! "; for (int i = 1; i <= n; i++) cout << s[i];
	cout << endl;
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
