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

char s[100005];
int dem[2];

void solve() 
{
	int n;
	int hehe = 0;
	int re = 0;
	dem[0] = dem[1] = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		dem[s[i] - '0']++;
	}

	for (int i = 1; i <= n; i++)
	if (hehe == 0)
	{
		dem[s[i] - '0']--;
		if (s[i] == '1' && dem[0])
		{
			hehe = 1 - hehe;
			re++;
		}
	}
	else
	{
		dem[s[i] - '0']--;
		if (s[i] == '0' && dem[1])
		{
			hehe = 1 - hehe;
			re++;
		}
	}

	cout << re << "\n";
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
