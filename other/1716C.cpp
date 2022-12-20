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


int a[2][200005], n;

void solve() 
{	
	cin >> n;
	for (int i = 0; i <= 1; i++)
	for (int j = 1; j <= n; j++) 
	{
		cin >> a[i][j];
	}
	multiset<int> ss, sss;
	for (int i = 1; i <= n; i++)
	{
		ss.insert(a[0][i] - i);
		sss.insert(a[1][i] - i);
		ss.insert(a[1][i] - (n - i + 1) - n);
		sss.insert(a[0][i] - (n - i + 1) - n);
	}


	int re = 0;
	ss.erase(ss.find(a[0][1] - 1));
	int res = *ss.rbegin() + 1 + 2*n;
	sss.erase(sss.find(a[1][1] - 1));
	ss.erase(ss.find(a[1][1] - (n - 1 + 1) - n));
	sss.erase(sss.find(a[0][1] - (n - 1 + 1) - n));
	if (a[1][1] > re)
	{
		re = a[1][1];
	}
	re ++;
	int w = 0;
	if ((int)sss.size())
	{
		w = *sss.rbegin() + 1 + 1;
	}
	res = min(res, max(re, w) + 2*(n - 1));
	for (int i = 2; i <= n; i++)
	{
		ss.erase(ss.find(a[0][i] - i));
		sss.erase(sss.find(a[1][i] - i));
		ss.erase(ss.find(a[1][i] - (n - i + 1) - n));
		sss.erase(sss.find(a[0][i] - (n - i + 1) - n));
		if (i%2)
		{
			if (a[0][i] > re)
			{
				re = a[0][i];
			}
			if (i != 1) re ++;
			if (a[1][i] > re)
			{
				re = a[1][i];
			}
			re ++;
			w = 0;
			if ((int)sss.size())
			{
				w = *sss.rbegin() + i + 1;
			}
			res = min(res, max(re, w) + 2*(n - i));
		}
		else
		{
			if (a[1][i] > re)
			{
				re = a[1][i];
			}
			re ++;
			if (a[0][i] > re)
			{
				re = a[0][i];
			}
			re ++;
			w = 0;
			if ((int)ss.size())
			{
				w = *ss.rbegin() + i + 1;
			}
			res = min(res, max(re, w) + 2*(n - i));

		}
	}
	cout << res << "\n";
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
