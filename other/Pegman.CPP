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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
char s[105][105];
int r[105], l[105], u[105], d[105];
bool check[105][105];
void solve() 
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	{
		cin >> s[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		l[i] = r[i] = 0;
		for (int j = 1; j <= m; j++) if (s[i][j] != '.') 
		{
			l[i] = j;
			break;
		}
		
		for (int j = m; j; j--) if (s[i][j] != '.') 
		{
			r[i] = j;	
			break;
		}
	}
	for (int j = 1; j <= m; j++)
	{
		u[j] = d[j] = 0;
		for (int i = 1; i <= n; i++) if (s[i][j] != '.') 
		{
			u[j] = i;
			break;
		}
		
		for (int i = n; i; i--) if (s[i][j] != '.') 
		{
			d[j] = i;	
			break;
		}	
	}
	int res = 0;
	for (int i = 1; i <= n; i++) 
	if (l[i])
	{
		if (l[i] == r[i])
		{
			if (s[i][l[i]] == '<' || s[i][l[i]] == '>')
			{
				if (u[l[i]] != i)
				{
					res++; 
				}
				else if (d[l[i]] != i)
				{
				 	res++; 
				}
				else 
				{
					cout << "IMPOSSIBLE\n";
					return;
				}
			}
		}
		else 
		{
			if (s[i][l[i]] == '<') res++;
			if (s[i][r[i]] == '>') res++;
		}
	}
	for (int i = 1; i <= m; i++)
	if (u[i])
	{
		if (u[i] == d[i])
		{
			//cout << "hello" << endl;
			if (s[u[i]][i] == '^' || s[u[i]][i] == 'v')
			{
				if (r[u[i]] != i) res++;
				else if (l[u[i]] != i) res++;
				else 
				{
					cout << "IMPOSSIBLE\n";
					return;
				}
			}
		}
		else
		{
			if (s[u[i]][i] == '^') res++;
			if (s[d[i]][i] == 'v') res++;
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
    for (int i = 1; i <= testcase; i++)
    {
    	cout << "Case #" << i << ": ";
        solve();
    }
}
