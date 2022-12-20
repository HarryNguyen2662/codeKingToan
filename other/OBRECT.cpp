#include<bits/stdc++.h>
using namespace std;
int x[1005],y[1005],docao[1005][1005];
int main()
{
	freopen("lololoin.txt","r",stdin);
	stack<int> s,s1;
	int n,m,ans=0,z;
	cin >> n >> m;
	for (int i = 1; i<= n; i++)
		for(int j = 1; j<=m; j++)
		{
			cin>>z;
			
				docao[i][j]=docao[i-1][j]+1;
		}
	for(int i = 1; i<= n; i++)
		{
			for(int j = 1;j <= m; j++)
			{
				while (!s.empty()&&docao[i][s.top()]>=docao[i][j]) s.pop();
				if (s.empty()) x[j]=0; else x[j]=s.top(); s.push(j);
			//	cout<< docao[i][j]<<" ";
			}
			for(int j= m; j; j--)
			{
					while (!s1.empty()&&docao[i][s1.top()]>=docao[i][j]) s1.pop();
				if (s1.empty()) y[j]=m+1; else y[j]=s1.top(); s1.push(j); 
			}
			int kq=0,k;
			for (int j=1;j<=n; j++)
			{
				k=docao[i][j]*(y[j]-x[j]);
				kq=max(kq,k);
				x[j]=0; y[j]=0;
			}
			ans = max(ans,kq);
			while(!s.empty()) s.pop();
			while(!s1.empty()) s1.pop();
			cout<<endl;
		}
		cout<< ans;
}