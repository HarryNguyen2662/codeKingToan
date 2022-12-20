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

char s[100005], t[100005];
int lu[100005], luu[100005];

void solve() 
{
	int n;
	string dm = "", cl = "";
	int he = 0, hehe = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> s[i];
		if (s[i] != 'b') dm += s[i]; else he++;
	}
	for (int i = 1; i <= n; i++) 
	{
		cin >> t[i];
		if (t[i] != 'b') cl += t[i]; else hehe++;
	}

	if (hehe != he || dm != cl)
	{
		cout << "NO\n"; return;
	}

	int dem = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (t[i] == 'b') dem++;
		if (t[i] != 'b')
		{
			lu[++cnt] = dem; dem = 0;
		}
	}
	dem = 0;
	cnt = 0;
	int haha = 0;

	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'b') dem++;
		if (s[i] == 'a') 
		{
			cnt++;
			if (haha < dem) 
			{
				dem -= haha; haha = 0;
			}
			else
			{
				haha -= dem; dem = 0;
			}
			if (dem > lu[cnt])
			{
				//cout << dem << endl;
				cout << "NO\n"; return;
			}
			else
			{
				haha += lu[cnt] - dem;
				dem = 0;
			}
			//cout << haha << endl;
		}
		if (s[i] == 'c')
		{
			cnt++;
			if (haha <= dem)
			{
				dem -= haha; haha = 0;
			}
			else 
			{
				cout << "NO\n"; return;
			}
			if (dem < lu[cnt])
			{
				cout << "NO\n"; return;
			}
			else
			{
				swap(s[i], s[i - (dem - lu[cnt])]); dem = dem - lu[cnt];
			}
		}
	}

	

	cout << "YES\n";
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
