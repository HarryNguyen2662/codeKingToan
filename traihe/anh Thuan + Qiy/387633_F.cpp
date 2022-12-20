#include<bits/stdc++.h>
using namespace std;
#define log 18
#define mask(n) (1ll << (n))
#define fi first
#define se second

pair<int,int> a[300005];
int lg[300005], cs[300005], mx[300005][log + 2];

void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> mx[i][0];
		lg[i] = lg[i-1];
		while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
	}

	for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i) + 1; j++)
	mx[j][i] = max(mx[j][i-1], mx[j + mask(i - 1)][i-1]);

	for (int i = 1; i <= m ;i++)
	{
		cs[i] = i;
		cin >> a[i].fi >> a[i].se;
	}
	
	sort(cs + 1, cs + 1 + m, [](const int &x, const int &y)
	{
		auto getmax = [&](const int &l ,const int &r)
		{
			int k = lg[r - l + 1];
			return max(mx[l][k], mx[r - mask(k) + 1][k]);
		};

		if (a[x] == a[y]) return x < y;
		pair<int,int> mxx = {max(a[x].fi, a[y].fi),  min(a[x].se, a[y].se)};
		if (mxx == a[x] || mxx == a[y])
		{
			return mxx == a[x];
		}
		if (mxx.fi <= mxx.se)
		{
			if (a[x].fi == mxx.fi) 
			{
				return getmax(mxx.se + 1, a[x].se) < getmax(a[y].fi, mxx.fi - 1); 
			}
			else
			{
				return getmax(a[x].fi, mxx.fi - 1) < getmax(mxx.se + 1, a[y].se); 
			}	
		}
		return getmax(a[x].fi, a[x].se) < getmax(a[y].fi, a[y].se);
	});
	for (int i = 1; i <= m; i++) cout << cs[i] << " ";

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

	solve();
}