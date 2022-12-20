#include<bits/stdc++.h>
using namespace std;
bool check[105][105];
int dp[105][105];
int a[105],n;
long long solve(int i, int j)
{
	int x,y;
	if (i<=0) x = i +n; else x = i;
	if (j >n) y = j -n; else  y =j;
	if (check[x][y]) return dp[x][y];
	check[x][y] = 1;
	if (x==y) return dp[x][y] = a[x]%2;
	return dp[x][y] = max (a[x]%2-solve(i-1,j),a[y]%2-solve(i,j+1));
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	int ans = 0 ;
	cin >> n;
	for (int i = 1; i <=n; i++) 
		cin >> a[i];
	for (int i = 1; i <=n; i++)
	{
		memset(check,0,sizeof check);
		memset(dp,0,sizeof dp);
		if (solve(i-1,i+1)-a[i]%2<0) ans ++;
	}
	cout << ans;
}