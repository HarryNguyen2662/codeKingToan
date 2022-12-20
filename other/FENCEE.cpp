#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 9
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
int lg[1005], mx[1005][log + 5], sum[1005][1005], h[1005][log+5], n, m;
char s[1005][1005];
int getmn(int l, int r)
{
	int k = lg[r - l + 1];
	return max(h[l][k], h[r - mask(k) + 1][k]);
}
int getmin(int l, int r)
{
	int k = lg[r - l + 1];
	return min(mx[l][k], mx[r - mask(k) + 1][k]);
}
int getres(int l, int r, int u, int v)
{
	return sum[u][v] - sum[u][r-1] - sum[l-1][v] + sum[l-1][r-1];
}
int findleft(int id)
{
	int l = 1, r = id;
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (getmin(mid, id) >= h[id][0]) r = mid - 1; else l = mid + 1;
	}
	// r = id;
	// id = l;
	//cout << l << " ";
	// while(l <= r)
	// {
	// 	int mid = (l + r)/2;
	// 	if (getmn(id, mid) > 0) r = mid - 1; else l = mid + 1;
	// }
	//cout << l << endl;
	return l;
}
int findright(int id)
{
	int l = id, r = m;
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (getmin(id, mid) >= h[id][0]) l = mid + 1; else r = mid - 1;
	}
	//cout << r << " hi " << id << endl;
	// l = id;
	// id = r;
	// while (l <= r)
	// {
	// 	int mid = (l + r)/2;
	// 	if (getmn(mid, id) > 0) l = mid + 1; else r = mid - 1;
	// }
	return r;
}
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			{
				cin >> s[i][j];
				sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
				if (s[i][j] == '$') sum[i][j] ++;
			}
	int l = 0, r = 0, ll = 0, rr = 0;
	int res = -1;
	for (int i = 1; i <= 1000; i++)
	{
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (h[j][0] == 0 && s[i][j] == '$') h[j][0] = 1;
			else if (h[j][0] > 0)
			{
				if (s[i][j] == '*') h[j][0] = 0; else h[j][0]++;
			}
			//cout << h[j][0] << " ";
			if (s[i][j] == '*') mx[j][0] = 0; else mx[j][0]++;

		}
		//cout << endl;
		//if (i == 1) cout << h[1][0] << endl;
		//if (i == 3) cout << mx[6][0] << endl;
		for (int e = 1; e <= log ; e++)
		for (int j = 1; j <= m - mask(e) + 1; j++)
		{
			h[j][e] = max(h[j][e-1], h[j + mask(e - 1)][e-1]);
		 	mx[j][e] = min(mx[j][e-1], mx[j + mask(e-1)][e-1]);
		}
		for (int j =  1; j <= m; j++)
		if (h[j][0] > 0)
		{
			int L = findleft(j), R = findright(j);
			while(getres(i - h[j][0]+1, L, i, L) == 0) L++;
			while(getres(i - h[j][0]+1, R, i, R) == 0) R--;
			int val = getres(i - h[j][0] + 1, L, i, R);
			if (val > res)
			{
				res = val;
				l = i - h[j][0] + 1; r = L; ll = i; rr = R;
			}
			else if (val == res && (h[j][0] + R - L + 1) < (ll - l + rr - r + 2))
			{
				l = i - h[j][0] + 1; r = L; ll = i; rr = R;
			}
		}
	}
	//cout << res << endl;
	while(getres(l, r, ll, r) == 0) r++;
	while(getres(l, rr, ll, rr) == 0) rr--;
	//while(getres())
	cout << l << " " << r << " " << ll << " " << rr;
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
