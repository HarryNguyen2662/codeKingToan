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

long long a[200005], mn[200005][log+5], mx[200005][log+5];
int lg[200005];
long long getmx(int l, int r)
{
	int k = lg[r - l + 1];
	return max(mx[l][k], mx[r - mask(k) + 1][k]);
}
long long getmn(int l, int r)
{
	int k = lg[r - l + 1];
	return min(mn[l][k], mn[r - mask(k) + 1][k]);
}

int l[200005], r[200005];
void solve() 
{
	stack<int> st;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
		if (!st.empty())  l[i] = st.top(); else l[i] = 0;
		st.push(i);
		mx[i][0] = mx[i-1][0] + a[i];
		mn[i][0] = mx[i][0];
	}
	while(!st.empty()) st.pop();
	for (int i = n; i; i--)
	{
		while (!st.empty() && a[st.top()] <= a[i]) st.pop();
		if (!st.empty())  r[i] = st.top(); else r[i] = n + 1;
		st.push(i);
	}
	for (int i = 1; i <= log; i++) for (int j = 0; j <= n - mask(i) + 1; j++)
	{
		mx[j][i] = max(mx[j][i-1], mx[j + mask(i-1)][i-1]);
		mn[j][i] = min(mn[j][i-1], mn[j + mask(i-1)][i-1]);
	}

	for (int i = 1; i <= n; i++)
	if (getmx(i, r[i] - 1) - getmn(l[i], i - 1) > a[i])
	{
		cout << "NO\n";
		return;
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
    for (int i = 1; i <= 200000; i++)
    {
    	lg[i] = lg[i-1];
    	while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
    }
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
