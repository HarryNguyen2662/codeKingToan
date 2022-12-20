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

};

point operator -(const point &u, const point &v)
{
	return {u.x - v.x, u.y - v.y};
}

long long operator *(const point &u, const point &v)
{
	return u.x*v.y - u.y*v.x;
}

long long gcd(long long u, long long v)
{
	if (v == 0) return u;
	return gcd(v, u%v);
}

point a[100005];

void solve() 
{
	int n;
	cin >> n;
 	n++; a[1] = {1, 0};
	for (int i = 2; i <= n; i++)
	{
		a[i].x = i - 1;
		cin >> a[i].y;
	}
	int cnt = 2;
	for (int i = 3; i <= n; i++)
	{
		while(cnt >= 2 && (a[cnt] - a[cnt-1])*(a[i] - a[cnt]) >= 0) cnt--;
		a[++cnt] = a[i];
	}
	int m; point e;
	cin >> m;
	while(m--)
	{
		long long x; cin >> x; e = point(0, x);

		int l = 1, r = cnt - 1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if ((a[mid] - e)*(a[mid + 1] - e) < 0) r = mid - 1; else l = mid + 1;
		}
		e = a[l] - e;
		long long g = gcd(e.x, e.y);
		cout << e.x/g << " " << e.y/g << "\n"; 
	}
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
