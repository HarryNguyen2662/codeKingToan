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

struct point
{
	long long x, y;

	point(long long _x = 0, long long _y = 0)
	{
		x = _x; y = _y;
	}
} a[1000005], ww;

int lu[1000005];

point operator -(const point &u, const point &v)
{
	return {u.x - v.x, u.y - v.y};
}

long long operator *(const point &u, const point &v)
{
	return u.x*v.y - v.x*u.y;
}

	
void solve() 
{
	int n;
	cin >> n;
	a[1] = {1, 0}; n++;
	for (int i = 2; i <= n; i++)
	{
		a[i].x = i;
		cin >> a[i].y;
		a[i].y += a[i-1].y;
	}
	

	int cnt = 1; lu[cnt] = 1; lu[++cnt] = 2;
	for (int i = 3; i <= n; i++)
	{
		while(cnt >= 2 && (a[lu[cnt]] - a[lu[cnt-1]])*(a[i] - a[lu[cnt]]) <= 0) cnt--;
		lu[++cnt] = i;
	}
	
	long long res = 0;
	for (int i = 1; i < cnt; i++)
	if (lu[i] + 1 < lu[i + 1])
	{
		long long re = a[lu[i+1]]*a[lu[i]];
		for (int j = lu[i]; j < lu[i + 1]; j++)
		{
			re += a[j]*a[j + 1];
		}
		if (re < 0) re = -re;
		res += re;
	}

	cout << res/2 << "." << (res%2)*5;
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
