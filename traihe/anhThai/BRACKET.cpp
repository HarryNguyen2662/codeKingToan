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


int dp[10005][20005];
int mn[20005], mw[20005];
char s[1000005];
void solve() 
{
	//cout << "lo" << endl;
	int n;
	cin >> n;
	int cnt  = 0;
	int dem = 0, mnn = oo;
	//a[0] = 1;
	mw[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i]; //cout << s[i] << " ";
		if (s[i] == '?') 	
		{
			//cout << dem << endl;
			mn[cnt] = mnn; mnn = oo;
			cnt++;
			mw[cnt] = mw[cnt-1] + dem; dem = 0;
		}
		else
		{
			if (s[i] == '(') dem++; else dem--;
			mnn = min(mnn, dem);
		}
	}
	mn[cnt] = dem;
	//cout << dem << endl;
	
	dp[0][cnt] = 1; 
	for (int i = 0; i < cnt; i++)
	for (int j = 0; j <= 2*cnt; j++)
	if (dp[i][j] && j - cnt + mw[i] + mn[i] >= 0)
	{
		if (j - cnt + mw[i+1] + 1 > 0 )
		dp[i+1][j + 1] = (dp[i+1][j+1] + dp[i][j])%MOD;
		if (j - cnt + mw[i+1] - 1 >= 0 && j - 1 >= 0)
		dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j])%MOD;
	}
	//cout << 1 - cnt + mw[0] + mn[0] - 1 << endl; 
	//cout << dp[1][3] << " " << dp[1][1] << endl;
	if (s[n] == '?')
	{
		//w - cnt + mw[cnt] = 0
		int w = cnt - mw[cnt];
		if (w >= 0 && w <= 2*cnt)
		cout << dp[cnt][w];
		else cout << 0;
	}
	else
	{
		if (dem > 0)
		{
			cout << 0;
		}
		else
		{
			//-dem = w - cnt + mw[cnt]
			int w = cnt - dem - mw[cnt];
			//cout << cnt << " " << dem << " " << mw[cnt] << endl;
			if (w >= 0 && w <= 2*cnt && -dem + mn[cnt] >= 0)
			{
				cout << dp[cnt][w];
			}
			else cout << 0;
		}
	}
	//cout << "hello";
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
