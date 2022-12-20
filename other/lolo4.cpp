#include<bits/stdc++.h>
using namespace std;
vector<int > pos;
long long m;
long long dp[20][130][4000][2];
bool kt[175];
void check()
{
	for (int a = 2; a <= 170; a++)
	{
		kt[a] = 1;
		for (int i = 2; i*i <= a; i++)
			if (a%i==0)
			{
				kt[a]=0;
				break;
			}
	}
}
void trans(long long a)
{
	pos.clear();
	while (a)
	{
		pos.push_back(a%10);
		a= a/ 10;
	}
}
long long solve1(long long a)
{
	trans(a);
	int n = pos.size();
	memset(dp,0,sizeof dp);
	// for (int i = 0; i <= pos[0]; i++)
	// {
	// 	int tot = (pos[0]==i);
	// 	dp[1][i][i%m][tot] ++;
	// }
	for (int l = 1; l < n; l++)
		for (int sum = 0 ; sum <= 120; sum++)
			for (int du= 0 ; du < m; du++)
				for (int gh = 0 ; gh<= 1; gh ++)
				 if (!gh)
				 {
				 	for (int k = 0 ; k <= 9; k++)
				 		dp[l+1][sum+k][(du*10+k)%m][0]+= dp[l][sum][du][0];
				 }
				 else
				 {
				 	for (int k = 0 ; k <= pos[l]; k++)
				 	{
				 		int tot = (pos[l]==k);
				 		dp[l+1][sum+k][(du*10+k)%m][tot]+= dp[l][sum][du][1];
				 	}
				 }
		long long ans = 0;
		for (long long i = 0; i<= 120; i++)
		  if (kt[i]&&dp[n][i][0][0])
		  {
		  //	cout << i << " " <<dp[n][i][0][0]<< endl;
		  	ans+=dp[n][i][0][0];
		  //	if (dp[n][i][0]) cout << i << endl;
		  }
		 //  int kk = 0;
		 //  for (int du = 0; du < m ; du++)
		 //  {	kk+=dp[n][11][du][0];
		 //  	cout << dp[n][11][du][0] <<endl;
		 //  }
		 // cout << kk << endl;
	return ans;
}
void solve()
{
	long long l,r;
	cin >> l >> r >> m;
	cout << solve1(r)-solve1(l-1);
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	check();
	//solve();
}