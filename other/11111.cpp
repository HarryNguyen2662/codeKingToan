#include<bits/stdc++.h>
using namespace std;
int f[1005],n,ss,t;
//vector<pair<int,int> > a[1005];
////priority_queue<pair<int,int> > s;
//void input()
//{
//	int x, y ,z,m;
//	cin >> n >> m >> ss >>t;
//	for (int i = 0; i <  m; i++)
//	{
//		cin >> x >>y >> z;
//		a[x].push_back({z,y});
//		a[y].push_back({z,x});
//	}
//}
//void solve()
//{
//
//	for (int i = 1; i <= n; i++)
//		f[i] = 1e7;
//	f[ss] = 0;
//	s.push({0,ss});
//	while (s.size())
//	{
//		int u = s.top().second;
//		int giatri = s.top().first;
//		if (giatri==f[u]) continue;
//		for (int i = 0; i< a[u].size(); i++)
//		{
//			int d1 = a[u][i].second, d2 = a[u][i].first;
//			if (f[d1] > min(giatri,d2))
//			{
//				f[d1] = min(giatri,d2);
//				s.push({f[d1],d1});
//			}
//		} 
//	}
//	cout << f[t];
//}
int main()
{
  //freopen("lololoin.txt","r",stdin);
 // input();
 // solve();
}
