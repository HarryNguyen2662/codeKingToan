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

struct DATA
{
	int lx, uy, aa, bb;
};

DATA iq[10000003];
int f[1005], cs[1005];
int s[1005][1005];
int ok[1001][1001][3][3];

bool cango(int x, int y, int a, int b)
{
	return (s[x + a - 1][y + b - 1] - s[x - 1][y + b - 1] - s[x + a - 1][y - 1] + s[x - 1][y - 1] == 0);
}


void solve() 
{
	int a, b, c, n, m, x, y, z, t;
	cin >> n >> m >> x >> y >> z >> t;
	x++; y++; z++; t++;
	int sum = 5;
	a = 1; b = 1; c = 3;

	cs[0] = 1; cs[1] = 3;
	f[1] = 0; f[3] = 1;  
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
	{
		char xe;
		cin >> xe;
		s[i][j] = xe - '0';
		s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	}

	ok[x][y][f[a]][f[b]] = -2;
	int cnt = 0, cmt = 1;	
	iq[++cnt] = {x, y, f[a], f[b]};
	while(cmt <= cnt)
	{
		x = iq[cmt].lx;
		y = iq[cmt].uy;
		a = cs[iq[cmt].aa];
		b = cs[iq[cmt].bb];
		c = sum - a - b;
		cmt++;
	//	cout << x << " " << y << " " << a << " " << b << " " << c << " " << ok[x][y][f[a]][f[b]] << endl;

		swap(b, c);
		int xx = x, yy = y - b;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = 3;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		yy = y + c;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			

			ok[xx][yy][f[a]][f[b]] = 1;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		swap(b, c);

		swap(a, c);
		xx = x - a; yy = y;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			ok[xx][yy][f[a]][f[b]] = 4;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		xx = x + c;
		if (xx >= 1 && xx <= n - a + 1 && yy >= 1 && yy <= m - b + 1 && cango(xx, yy, a, b) && ok[xx][yy][f[a]][f[b]] == 0)
		{
			
			ok[xx][yy][f[a]][f[b]] = 2;
			iq[++cnt] = {xx, yy, f[a], f[b]};
		}
		swap(a, c);

	}
	if (ok[z][t][0][0] == 0)
	{
		cout << -1;
		return;
	}
	//cout << f[1] << " " << f[3] << endl;
	//cout << ok[4][3][f[1]][f[3]] << endl;
	vector<int> ldk;
	int te = 0, tee = 0;
	//cout << ok[z][t][0][0] << endl;
	int de = 0;
	while(ok[z][t][te][tee] != -2)
	{
		de++;
		ldk.pb(ok[z][t][te][tee] - 1);
		a = cs[te]; b = cs[tee]; c = sum - a - b;
		int adu = ok[z][t][te][tee];
		//cout << adu << " " << z << " " << t << " " << a << " " << b << " " << c << endl;
		if (adu == 3)
		{
			t += b; swap(b, c);
			tee = f[b];
		}
		else if (adu == 1)
		{
			t -= c; swap(b, c);
			tee = f[b];
		}
		else if (adu == 4)
		{
			z += a; swap(a, c);
			te = f[a];
		}
		else
		{
			z -= c; swap(a, c);
			te = f[a];
		}
	}

	cout << (int)ldk.size() << "\n";
	reverse(ALL(ldk));
	for (auto v : ldk) cout << v << " ";
}

int main() 
{   
   	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
