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
int dem[35];
void solve1(string &s)
{
	int w = 0;
	dem[w]++;
	long long res = 0;
	int t = 1;
	for (int i = 0; i < (int)s.size(); i ++)
	{
		w = (w + (s[i] - '0')*t%33 )%33; 
		res += dem[w];
		dem[w]++; 
		t = t*10%33;
	}
	cout << res;
}
void solve2(string &s)
{
	int w = 0;
	int dai = -1;
	for (int i = 0; i < 33; i++) dem[i] = -2;
	dem[0] = -1;
	int l = -2, r = -2;
	int t = 1;
	for (int i = 0; i < (int)s.size(); i++)
	{
		w = (w + (s[i] - '0')*t%33 )%33; 
		//cout << w << endl;
		if (dem[w] == -2)
		{
			dem[w] = i;
		}
		else
		{
			dai = max(dai, i - dem[w]);
			if (dai == i - dem[w] )
			{
				l = dem[w]+1; r = i;
			}
		}
		t = t*10%33;
	}
	w = 0;
	t = 1;
	for (int i = 1; i < 33; i++) dem[i] = -2; 
	for (int i = 0; i < (int)s.size(); i++)
	{
		w = (w + (s[i] - '0')*t%33 )%33; 
		if (dem[w] == -2)
		{
			dem[w] = i;
		}
		else if (i - dem[w] == dai)
		{	
			for (int j = 1; j <= dai; j++)
			if (s[r - j + 1] != s[i - j + 1])
			{
				if (s[r-j+1] < s[i - j + 1]) r = i, l = dem[w]+1;
				break;
			}
		}
		t = t*10%33;
	}
	if (l == -2)
	{
		cout << -1;
		return;
	}

	for (int i = r; i >= l; i--) cout << s[i];
}
void solve() 
{
	string s;
	cin >> s;
	reverse(ALL(s));
	int type;
	cin >> type;
	if (type == 1) solve1(s); else solve2(s); 
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
