#include<bits/stdc++.h>
using namespace  std;
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};
int n,m;
int d[105][105],dd[105][105],a[105][105],ans = 0,dem;
void dfs(int i, int j)
{
    dd[i][j] = dem; bool kt = false;   
    d[i][j] = 0;
    for (int e=0 ;e<4; e++)
    {
    	int x = i +xx[e], y = j +yy[e];
    	if (1<=x&&x<=n&&y>=1&&y<=m&&a[i][j]<a[x][y])
    	{
    		kt = true;
    		if (dd[x][y]!=dem) 
    			{
   				dfs(x,y); 	
    			}  
    			 d[i][j] = max(d[i][j],d[x][y]+1);
    	} 
    }
    if (!kt) d[i][j] = 1;
     ans = max(ans,d[i][j]);
}
int main()
{
	freopen("DUONGHAM.inp","r",stdin);
    freopen("DUONGHAM.inp","w",stdout);
	// ios_base::sync_with_stdio(0);
	// cin.tie(0); cout.tie(0)
	cin >> n >> m; 
	dem = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j<= m; j++)
			cin >> a[i][j];
	for (int i = 1; i<=n; i++)
		for (int j =1; j<=m;j++)
		{
			dem ++;
			dfs(i,j);
            dd[i][j] = 0;
           //  if (i == 1&&j ==1) cout << ans<<endl;
		} 
	cout <<ans;
}