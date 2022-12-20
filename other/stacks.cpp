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
int n;
int len[100], cu[100];
int inq[44][1048580], inst[44][1048580];

void xuly(int id, int l, int r)
{
	if (l > r || id > 2*n + 1) return;
	int key = (l + r)/2;

	if (id%2)
	{
		if (id == 2*n + 1) return;
		while(cu[id] <= len[id])
		{
			int cur = inq[id][cu[id]]; cu[id]++;
			if (cur <= key)
			{
				cout << id << " " << id + 1 << " ";
				len[id + 2]++; inq[id + 2][len[id + 2]] = cur;
			}
			else
			{
				cout << id << " ";
				len[id + 1]++; inst[id + 1][len[id + 1]] = cur;
			}
		}
		xuly(id + 2, l, key); xuly(id + 1, key + 1, r);
		return;
	}
	while(len[id])
	{
		int cur = inst[id][len[id]]; len[id]--;
		cout << id << " ";
		len[id+1]++; inq[id + 1][len[id + 1]] = cur;
	}
	xuly(id + 1, l, r);
}


void solve() 
{

	cin >> n;
	
	for (int i = 1; i <= 2*n + 1; i += 2) cu[i] = 1;
	
	for (int i = 1; i <= mask(n); i++)
	{
		int u;
		cin >> u;
		len[1]++; inq[1][len[1]] = u;
	}

	xuly(1, 1, mask(n));
	
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
