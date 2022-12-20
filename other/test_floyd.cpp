#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int dd[115][115],t[115][115];
int n; 
void floyd()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 1; k <= n; k++)
				if (dd[j][k] > dd[j][i] + dd[k][i])
				{
					dd[j][k] = dd[i][k] + dd[i][j];
					t[j][k] = t[j][i];
				}
}
int main ()
{
	freopen("yeunhi.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m,k,u,v,loai,w;
	vector<int> ldk;
	cin >> n >> m >> k;
	for (int i = 1; i<= n; i++)
		for (int j = 1; j<= n; j++)
		{
			if (i==j) dd[i][j] = 0; else dd[i][j] = 1e9;
		}
	for (int i = 1;  i<= m; i++)
	{
		cin >> u >> v>>w;
		dd[u][v] = dd[v][u] = w;
		t[u][v] = v;
		t[v][u] = u; 
	}
	floyd();
	while(k--)
	{
		cin >> loai >> u >> v;
		if (loai)
		{
			while(u!=v)
			{
				ldk.push_back(u);
				u = t[u][v];
			}
			cout << (int)ldk.size() + 1 <<" ";
			for (auto q : ldk) cout << q <<" ";
				cout << v<<endl;
			ldk.clear();
		}
		else
		{
			cout << dd[u][v] << endl;
		}
	}
}