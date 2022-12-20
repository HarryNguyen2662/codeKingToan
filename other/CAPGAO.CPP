#include<bits/stdc++.h>
using namespace std;
long long a[21];
void solve()
{
	int n ,m, l,r,mid;
	long long x,sum; vector<long long > ldk;
	cin  >> n >> m;
	for (int i = 0; i< n ;i++)
		cin >> a[i];
	bitset<20> s;
	for (int i = 0 ; i < 1<<n; i++)
	{
		s = i;
		sum = 0;
		for (int j = 0 ; j < n; j++)
			if (s[j]==1)
			{
				sum+=a[j];
			}
		ldk.push_back(sum);
	}
	sort(ldk.begin(),ldk.end());
	for (int i = 0; i < m ; i++)
	{
		cin >> x; 
		l = 1; r = ldk.size();
		bool kt = false;
		while (l <= r)
		{
			mid = (l+r)/2;
			if (ldk[mid-1] == x)
			{
				kt = true; 
			    break;
			}
			else if (ldk[mid-1]>x) r = mid -1; 
			else l = mid +1;
		}
		cout << kt ;
	}
}
int main()
{
	freopen("CAPGAO.INP","r",stdin);
	freopen("CAPGAO.OUT","w",stdout);
	solve();
}