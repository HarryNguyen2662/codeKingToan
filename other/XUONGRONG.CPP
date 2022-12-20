#include<bits/stdc++.h>
using namespace  std;
vector<int> a[1005];
int dd[1005],xet[1005];
bool kt;
void dfs(int z,int u,int danhdau, int e)
{
 	 dd[u] = danhdau;
  	for (auto v:a[u])
  	{
  		//cout << v<<endl;
  		if (dd[v]!=danhdau)
  		{
           dfs(z,v,danhdau,e+1);
           xet[u] = max(xet[u],xet[v]);
  		}
  		else if (v == z&&e>2) 
  		{
  			kt = true; ;
  			xet[u] =1;
  		}
  	}
}
int main()
{
	freopen("XUONGRONG.INP","r",stdin);
	freopen("XUONGRONG.OUT","w",stdout);
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0)
	int n,m,u,v,ans=0;
	cin >> n >> m;
	for (int i = 1; i<= m;i++)
	{
		cin>> u >>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i<=n; i++)
	if (xet[i]==0)
	{
		kt =false;
		dfs(i,i,i,1);
		if (kt) 
			{
				ans ++;
			}
	}

	// for (int i = 1; i<= n ;i++) if (xet[i]) cout << i << endl;
	 cout << ans;
}