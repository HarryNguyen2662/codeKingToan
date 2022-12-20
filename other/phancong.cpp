#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int f[1002][1002],c[1002][1002],tr[1002];
vector<int> a[1002];
vector<pair<int,int> > qq;int n,m,s,t,maxfl;
void bfs(int u)
{
	queue<int> k; 
	k.push(u);
	while (!k.empty())
	{
		u=k.front(); k.pop();
	for ( auto i:a[u])
	 if ( tr[i]==0&&f[u][i]<c[u][i])
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
    return tr[t];
}
void tang()
{
   int v=t; 
    while (v!=s)
    {
        int u=tr[v];  
        f[u][v]++;
        f[v][u]--;
        v=u;
    }
    maxfl ++;
}
bool check(int u)
{
	 memset(f, 0, sizeof(f));
	for (auto e:a[s] ) c[s][e]=u;
    maxfl=0; 
    while (timduong()) tang();
     return maxfl==m;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>m>>n;
	 for (int i=1;i<=m;i++)
	  {
	     c[i][0]=1;
	     a[i].push_back(0);
	     a[0].push_back(i);
	  }
	for (int i=1;i<=n;i++)
	 {
	 	while (1)
	 	{
	 		int x;
	 		cin>>x;
	 		if(x==0) break;	 		
	 	    c[m+i][x]=1;
	 	    a[i+m].push_back(x);
	 	    a[x].push_back(i + m);
		 }
	 }
	 int l,r,mid;
	 l=1;r=500; s=1001; t=0;
	  for (int i=1;i<=n;i++) {
	  	 a[s].push_back(i+m);
	  	 a[i + m].push_back(s);
	  }
	 while (l<=r)
	 {
	 	mid=(l+r)/2; 
	 	 if (check(mid)) r=mid-1; else l=mid+1;
	 }
	 if (!check(l)) cout<<"NO";
	 else
	 {
	 	cout<<"YES"<<"\n";
	 	cout<<l<<"\n";
	 	for (int i=1;i<=n;i++)
	 	{
	 		for (auto v:a[i+m]) if (f[i+m][v]&&v!=1001) cout<<v<<" "; 
			  cout<<"0"<<"\n"; 
		 }	 	
	 }
}
