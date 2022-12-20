#include<bits/stdc++.h>
using namespace std;
int dp[2][10001];
int main()
{
	freopen("lololoin.txt","r",stdin);
	string st,s;
	int a,b;
	cin >> s >> st;
	a = 0; b = 1;
	for(int i = 0; i < s.size() ;i++)
	{
		for(int j = 0; j < st.size(); j++)
		{
			if (s[i]==st[j]) dp[b][j+1] =dp[a][j]+1;
			else dp[b][j+1]=max(dp[a][j+1],dp[b][j]);
		}
		a=(a==0); b=(b==0);
	}
	cout << dp[a][st.size()];
}