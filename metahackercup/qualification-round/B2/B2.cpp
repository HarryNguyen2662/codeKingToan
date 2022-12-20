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

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

char s[3005][3005];
bool dd[3005][3005];
int de[3005][3005], b[3005][3005];

void solve() 
{
	queue<pair<int,int>> iq;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
		{
			cin >> s[i][j];
		}

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		dd[i][j] = false;
		b[i][j] = 2;
		de[i][j] = 0;
		for (int e = 0; e < 4; e++)
		{
			int ni = i + x[e], nj = j + y[e];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= m)
			{
				if (s[ni][nj] == '^') b[i][j]--;
				else de[i][j]++;
			}
		}
		//cout << de[i][j] << " " << b[i][j] << endl;
		if (s[i][j] == '#' || de[i][j] < b[i][j]) 
		{
			iq.push({i, j});
			dd[i][j] = true;
		}
	}

	while(!iq.empty())
	{
		int i = iq.front().fi, j = iq.front().se; iq.pop();
		//cout << i << " " << j << " " << de[i][j] << " " << b[i][j] << endl;
		if (s[i][j] == '^')
		{
			cout << "Impossible\n";
			return;
		}
		for (int e = 0; e < 4; e++)
		{
			int ni = i + x[e], nj = j + y[e];
			if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && !dd[ni][nj])
			{
				de[ni][nj]--;
				if (de[ni][nj] < b[ni][nj])
				{
					dd[ni][nj] = true;
					iq.push({ni, nj});
				}
			}
			
		}
	}
	
	cout << "Possible\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << ((dd[i][j] == 1) ? s[i][j] : '^');
		}
		cout << "\n";
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    int dem = 0;
    while(testcase--)
    {
    	dem++;
    	cout << "Case #" << dem << ": ";
        solve();

    }
}
