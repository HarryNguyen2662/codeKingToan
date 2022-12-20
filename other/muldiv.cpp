#include<bits/stdc++.h>
using namespace  std;
int dem[200005];
long long const MOD = 1e9+7;
long long power(long long a, long long b)
{
     if (b == 0) return 1;
     long long y = power(a,b/2)%MOD;
     if (b%2 == 0) return y*y%MOD; else return y*y%MOD*a%MOD;
}
void solve()
{
	long long ans = 1,t,u,n,x,k=1,e;
	vector<int> ldk;
	cin >> n;
	for (int i = 1; i <= n; i++)
		{
		 cin >> x;
		 if (dem[x] == 0) ldk.push_back(x); 
		  dem[x]++;
		}
	for (auto x:ldk)
	{
		t = dem[x]; u = t*(t+1)/2;
		 e = power(x,u);
		ans = power(ans,t+1)*power(e,k)%MOD;
		k = k*(t+1)%(MOD-1);
	}
	cout << ans;
}
int main()
{
	//freopen("lololoin.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	//cout<<power(3,MOD-2);
}	