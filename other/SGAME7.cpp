#include<bits/stdc++.h>
using namespace std;
vector<int> ldk;
long long dp[19][200];
int k;
void biendoi(long long a)
{
	ldk.clear();
	while(a)
	{
		ldk.push_back(a%10);
		a/=10;
	}
}
long long solve(int i,int gh, int sum)
{	
	if(i==-1) return (sum==k);
	if(dp[i][sum]!=-1&&!gh) return dp[i][sum];
	int h = (gh) ? ldk[i]: 9;
	long long ans = 0;
	for(int j = 0; j<=h; j++)
	{
		int newgh= (j==ldk[i]) ? gh : 0;
		ans+=solve(i-1,newgh,sum+j);
	}
	if (!gh) dp[i][sum] = ans;
	return ans;
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	long long a,b;
	cin>> a >> b >> k;
	biendoi(a-1);
	memset(dp,-1,sizeof dp);
	long long ans1 = solve(ldk.size()-1,1,0);
	//cout << ans1<<endl; 
	biendoi(b);
	memset(dp,-1,sizeof dp);
	long long ans2 = solve(ldk.size()-1,1,0); 
	cout<<ans2-ans1<<"\n";
	//cout<<sum1<<endl;
	long long m=1;
	long long ans3=0;
	long long kk=k;
	while(k)
	{
		long long tt = min(k,9);
		k=k-tt;
		ans3+=m*tt;
		m*=10;
	}
	if(ans3>=a) cout << ans3 ;
	else
	{
		ans3=0;
		biendoi(a);
		for(int i = ldk.size()-1; i>= 0; i--)
		{
			if(ans3+ldk[i]+9*i<kk) break;
			ans3+=ldk[i];
			cout<<ldk[i];
		}
		kk=kk-ans3;
		if(kk%9!=0) cout << kk%9;
		for(int i=0; i<kk/9; i++) cout << 9;
	}
}