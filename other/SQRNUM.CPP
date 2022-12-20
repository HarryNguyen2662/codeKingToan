#include<bits/stdc++.h>
using namespace std;
int kt[1000005];
bool check[1000005];
int main()
{
	freopen("SQRNUM.INP","r",stdin);
	freopen("SQRNUM.OUT","w",stdout);
	//freopen("lololoin.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	 cin.tie(0); cout.tie(0);
		vector<int> ldk,ans;
	for (int i = 2; i<= 1000; i++)
		if (!kt[i])
		{
			ldk.push_back(i);
			for (int j = i*i; j<= 1000; j+=i) kt[j] = 1;
		}
	int t,x;
	int dem;
	cin >> t;
	dem=0;
	while(t--)
	{
		cin >> x;
		for (auto u: ldk)
		{
			if (u*u>x) break;
			if (x%u==0)
			{
				while(x%u==0)
				{
				kt[u]++;
				x=x/u;
				}
				if (kt[u]%2) dem++; else if (dem) dem--;
			}
		}
		if (x>1)
		{
			kt[x]++;
			if (kt[x]%2) dem++; else if (dem) dem--;
		}
		if (dem) cout <<"NO"<<"\n"; else cout <<"YES" <<"\n";
	}
}