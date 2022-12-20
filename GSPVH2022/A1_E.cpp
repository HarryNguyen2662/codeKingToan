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


string s, mo[26];
int dp[1000005][2], tv[1000005][2];
bool minimize(int &x, const int &y)
{
	if (x > y)
	{
		x = y;
		return true;
	}
	return false;
}
int cost(int id, int ty)
{
	int res = 0;
	for (int i = 0; i < (int)mo[ty].size(); i++) res += (s[id+i] != mo[ty][i]);
	return res;
}
void solve() 
{
	mo[0] = ".-"; mo[1] = "-..."; mo[2] = "-.-."; mo[3] = "-.."; mo[4] = "."; mo[5] = "..-.";
	mo[6] = "--."; mo[7] = "...."; mo[8] = ".."; mo[9] = ".---"; mo[10] = "-.-"; mo[11] = ".-..";
	mo[12] ="--"; mo[13] = "-."; mo[14] = "---"; mo[15] = ".--."; mo[16] = "--.-"; mo[17] = ".-.";
	mo[18] = "..."; mo[19] = "-"; mo[20] = "..-"; mo[21] = "...-"; mo[22] = ".--"; mo[23] = "-..-";
	mo[24] = "-.--"; mo[25] = "--..";	
	cin >> s;
	int n = (int)s.size();
	s = "#" + s;
	for (int i = 0; i <= n; i++) 
	{
		dp[i][1] = dp[i][0] = oo;
		tv[i][1] = tv[i][0] = -1;
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < 2; j++)
	if (dp[i][j] < oo)
	{
		//cout << i << " " << j << endl;
		if (j == 0)
		{
			for (int e = 0; e < 26; e++) if (i + (int)mo[e].size() <= n) 
				if (minimize(dp[i + (int)mo[e].size()][1], dp[i][j] + cost(i+1, e)))
				tv[i+(int)mo[e].size()][1] = e;
		}
		else
		{
			if (minimize(dp[i+1][0], dp[i][j] + (s[i+1] != '|'))) tv[i+1][0] = 0;
			if (i + 2 <= n && minimize(dp[i+2][0], dp[i][j] + (s[i+2] != '|') + (s[i+1] != '|')))
			tv[i+2][0] = 1;
		}
	}
	cout << dp[n][1] << "\n";
	int id = 1;
	vector<string> ldk;
	while(n)
	{
		if (!id)
		{
			ldk.pb("|");
			if (tv[n][0]) ldk.pb("|"), n --;
			n--;
		}
		else
		{
			ldk.pb(mo[tv[n][1]]); n -= (int)mo[tv[n][1]].size();
		}
		id = 1 - id;
	}
	reverse(ALL(ldk));
	for (auto v : ldk) cout << v;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("morse.inp","r",stdin); freopen("morse.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
