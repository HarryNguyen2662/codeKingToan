#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],dd[1000001]; 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,kq=0,i,u,v,j;
    cin>>n>>m; 
      for (i=1;i<=n;i++)
      for (j=1;j<=m;j++)
       cin>>a[i][j];
       for (i=1;i<=(n+1)/2;i++)
       {
	        u=n-i+1;
        for (j=1;j<=(m+1)/2;j++)
         {
         	 v=m-j+1; int dem=1; dd[a[i][j]]++;
            if(j!=v) 
			{
			  dem++; dd[a[i][v]]++;  }
         	if(i!=u) 
			 {
			 dem++;  dd[a[u][j]]++;  }
       		if(i!=u&&j!=v) 
			  {
			   dem++;  dd[a[u][v]]++;}
       		kq+=(dem-max({dd[a[i][j]],dd[a[u][j]],dd[a[i][v]],dd[a[u][v]]}));
       		dd[a[i][j]]=dd[a[u][j]]=dd[a[i][v]]=dd[a[u][v]]=0;
		 }}
	 cout<<kq;
}
