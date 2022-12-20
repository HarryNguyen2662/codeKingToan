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

char s[4][4];

void solve() 
{
	int demx = 0, demo = 0;

	for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j ++) 
	{
		cin >> s[i][j];
		if (s[i][j] == 'X') demx++; else if (s[i][j] == '0') demo++;
	}

	if (demx - demo > 1 || demx - demo < 0) 
	{
		cout << "invalid";
		return;
	}
	bool tlwon = false, bdwon = false;
		
	for (int i = 1; i <= 3; i++)
	{
		if (s[i][1] == s[i][2] && s[i][2] == s[i][3] && s[i][3] == 'X') tlwon = true;
		if (s[1][i] == s[2][i] && s[2][i] == s[3][i] && s[3][i] == 'X') tlwon = true;		
	} 
	if (s[1][1] == s[2][2] && s[2][2] == s[3][3] && s[3][3] == 'X') tlwon = true;
	if (s[1][3] == s[2][2] && s[2][2] == s[3][1] && s[3][1] == 'X') tlwon = true;

	for (int i = 1; i <= 3; i++)
	{
		if (s[i][1] == s[i][2] && s[i][2] == s[i][3] && s[i][3] == '0') bdwon = true;
		if (s[1][i] == s[2][i] && s[2][i] == s[3][i] && s[3][i] == '0') bdwon = true;		
	} 
	if (s[1][1] == s[2][2] && s[2][2] == s[3][3] && s[3][3] == '0') bdwon = true;
	if (s[1][3] == s[2][2] && s[2][2] == s[3][1] && s[3][1] == '0') bdwon = true;

	if (tlwon && bdwon)
	{
		cout << "invalid"; return;
	}

	if (demx > demo)
	{
		if (tlwon)
		{
			cout << "TL won"; return;
		}
		if (bdwon)
		{
			cout << "invalid"; return;
		}
		if (demx + demo == 9)
		{
			cout << "draw"; return;
		} 
		cout << "BD was making a move"; return;
	}

	if (bdwon)
	{
		cout << "BD won"; return;
	}

	if (tlwon)
	{
		cout << "invalid"; return;
	}
	cout << "TL was making a move";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("caro.inp","r",stdin); freopen("caro.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
