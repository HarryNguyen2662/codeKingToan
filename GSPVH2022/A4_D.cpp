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

int xx[9] = {-2, -1, 1, 2, 2, 1, -1, -2};
int yy[9] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dist[2205][2205];
const int lim = 100;

void solve() 
{
	queue<pair<int,int>> inque;
	
	for (int i = -100; i <= 2100; i++)
	for (int j = -100; j <= 2100; j++) dist[i + lim][j + lim] = oo;
	
	dist[lim][lim] = 0;
	inque.push({0, 0});

	while(!inque.empty())
	{
		int x = inque.front().fi, y = inque.front().se; inque.pop();
		//cout << x << " " << y << endl;
		for (int i = 0; i < 8; i++)
		{
			int newx = x + xx[i], newy = y + yy[i];
			if (newx >= -100 && newx <= 2100 && newy >= -100 && newy <= 2100 && dist[newx + lim][newy + lim] == oo)
			{
				inque.push({newx, newy});
				dist[newx + lim][newy + lim] = dist[x + lim][y + lim] + 1;
			}
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		cout << dist[abs(x-u) + lim][abs(y - v) + lim] << " ";
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
    //freopen("knight.inp","r",stdin); freopen("knight.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
