#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
void dijkstra()
{
	for (int i = 1; i <= n; i++) dd[i] = oo;
	dd[1] = 0;
	priority_queue<cap, vector<cap>, greater<cap> > q;
	q.push({0, 1});
	while (!q.empty())
	{
		int u = q.top().s;
		int du = q.top().f;
		q.pop();
		if (dd[u]!=du) continue;
		for (auto e : a[u])
		{
			int v = e.f;
			int de = e.s;
			if(dd[v] > dd[u] + de)
			{
				dd[v] = dd[u] + de;
				q.push({dd[v], v});
			}
		}
	} 
}
int main()