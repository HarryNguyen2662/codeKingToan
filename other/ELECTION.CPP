#include<bits/stdc++.h>
using namespace std;
#define st first
#define nd second
pair<int,int> a[1005];
int dp[100005];
int main()
{
//	freopen("lololoin.txt","r",stdin);
     freopen("ELECTION.INP","r",stdin);
     freopen("ELECTION.OUT","w",stdout);
	int n,sum;
	vector<int> ans,ldk;
   	cin >> n;
   	for (int i =1; i<=n; i++) 
   		{
   			cin >> a[i].st;
   			a[i].nd= i;
   			sum+=a[i].st;
   		}
   	sort(a+1,a+n+1);
   	ldk.push_back(0);
   	for (int i= n; i ; i--)
   	{
   		int e = ldk.size();
   		for(int j = 0; j < e; j++)
   		{
   			if (2*(ldk[j]+a[i].st)<=sum) ldk.push_back(a[i].st+ldk[j]);
   			if(!dp[ldk[j]+a[i].st]) dp[ldk[j]+a[i].st] = i;
   		}
   	}
   	for (int i = sum; i; i--)
   	{
   		if(dp[i])
   		{
   			int j = i;
   			while(dp[j])
   			{
   				ans.push_back(a[dp[j]].nd);
   				j = j-a[dp[j]].st;
   			}
   			cout << ans.size()<< endl;
   			for (auto v :ans)  cout << v<<" ";
   			break;
   		}
   	}
}
