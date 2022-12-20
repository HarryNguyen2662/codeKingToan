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

double step = 200;
double kc = (double)1/step;

pair<double, double> a[55], b[55];

int n, t;

struct point
{
	double x, y;

} p[55];
double len(const point &e)
{
	return e.x*e.x + e.y*e.y;
}

point operator -(const point &u, const point &v)
{
	return {u.x - v.x, u.y - v.y};
}

double operator *(const point &u, const point &v)
{
	return u.x*v.y - u.y*v.x;
}

bool cmp(const point &u, const point &v)
{
	long long w = (u - p[1])*(v - p[1]);

	if (w == 0) return len(u - p[1]) < len(v - p[1]);
	return w > 0;
}


double cal(double cur)
{

	for (int i = 1; i <= n; i++)
	{
		p[i].x = a[i].fi*cur + a[i].se;
		p[i].y = b[i].fi*cur + b[i].se;
	
		if (p[i].y < p[1].y)
		{
			swap(p[i], p[1]);
		}

	}
	//cout << p[1].y << endl;

	sort(p + 2, p + 1 + n, cmp);
	int cnt = 2;
	for (int i = 3; i <= n; i++)
	{
		while(cnt >= 2 && (p[cnt] - p[cnt-1])*(p[i] - p[cnt]) <= 0) cnt--;
		p[++cnt] = p[i];
	}
	//cout << cnt << endl;
	if (cnt <= 2)
	{
		return 0;
	}
	double res = 0;
	p[cnt + 1] = p[1];
	for (int i = 1; i <= cnt; i++) res += p[i]*p[i+1];

	return abs(res)/2;

}

void solve() 
{
	cin >> n >> t;

	if (t >= 6000)
	{
		step = 35;
	}
	else if (t >= 3000)
	{
		step = 85;
	}
	else if (t > 600)
	{
		step = 125;
	}
	else if (t > 300)
	{
		step = 321;
	}
	else if (t <= 300)
	{
		step = 704;
	}
	kc = 1/step;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi >> a[i].se >> b[i].fi >> b[i].se;
	}
	//cout << step*kc << endl;
	double res = 0;

	for (double i = 0; i < t; i++)
	{
		for (double j = 1; j <= step; j++)
		{	
			res += kc*cal(i + j*kc);
		}
	}
	cout << fixed << setp(9) << res;
}	

int main() 
{   
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
