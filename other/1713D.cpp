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

int cot[1000005];

void ask(int x, int y)
{
	cout << "? " << cot[x] << " " << cot[y] << endl;
}

void solve() 
{
	int n;
	cin >> n;

	for (int i = 1; i <= mask(n); i++)
	{
		cot[i] = i;
	}

	while(n >= 2)
	{
		int cnt = 0;
		for (int i = 1; i <= mask(n); i += 4)
		{
			int ss;
			ask(i, i + 2);
			cin >> ss;
			if (ss == 1)
			{
				ask(i, i + 3);
				cin >> ss;
				if (ss == 1) cot[++cnt] = cot[i]; else cot[++cnt] = cot[i + 3];
			}
			else if (ss == 2)
			{
				ask(i + 1, i + 2);
				cin >> ss;
				if (ss == 1) cot[++cnt] = cot[i + 1]; else cot[++cnt] = cot[i + 2];
			}
			else
			{
				ask(i + 1, i + 3);
				cin >> ss;
				if (ss == 1) cot[++cnt] = cot[i + 1]; else cot[++cnt] = cot[i + 3];
			}
		}
		n -= 2;
	}

	if (n == 1)
	{
		ask(1, 2);
		int ss;
		cin >> ss;
		if (ss == 2) cot[1] = cot[2];
	}

	cout << "! " << cot[1] << endl;
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
    while(testcase--)
        solve();
}
