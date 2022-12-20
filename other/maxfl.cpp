#include<bits/stdc++.h>
using namespace std;
vector<int> a[1001];
int f[1001][1001],c[1001][1001],tr[1001];
int n,m,s,t,maxfl
;
void bfs(int u)
{
	queue<int> k; 
	k.push(u);
	while (!k.empty())
	{
		u=k.front(); k.pop();
	for ( auto i:a[u])
	 if (tr[i]==0&&f[u][i]<c[u][i])
	  {
	  	tr[i]=u;
	    k.push(i);
	     }
      }
}
int timduong()
{
	 memset(tr, 0, sizeof(tr));
    tr[s] = -1;
    bfs(s);
    return (tr[t]);
}
void tang()
{
    int d=1e9;
    int v=t;
    while (v!=s){
        int u=tr[v];
        d=min(d,c[u][v]-f[u][v]);
        v=u;
    }
    v=t;
    while (v!=s)
    {
        int u=tr[v];
        f[u][v]+=d;
        f[v][u]-=d;
        v=u;
    }
    maxfl += d;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int x,y,e;
	cin>>n>>m>>s>>t;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>e;
		a[x].push_back(y); a[y].push_back(x); 
		c[x][y]=e;
	}
	 maxfl=0;
	 while (timduong()) tang();
	 cout<<maxfl;
}
