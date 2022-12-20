#include<bits/stdc++.h>
using namespace std;
int aa[3],n;
bool check[305][305][305];
double dp[305][305][305];
double solve2(int a, int b , int c)
{
	if (check[a][b][c]) return dp[a][b][c];
	check[a][b][c] = 1;
	if (a==0&&b==0&&c==0) return dp[a][b][c];
	int t = a + b + c;
	double cv = double(t);
	double tt = (n - t)/cv;
	if (a!=0) tt+= a*((solve2(a-1,b,c)+1)/cv);
	if (b!=0) tt+= b*((solve2(a+1,b-1,c)+1)/cv);
	if (c!=0) tt+= c*((solve2(a,b+1,c-1)+1)/cv);
	dp[a][b][c] = tt;
	//cout << tt  << endl;
	return tt;
}
void solve()
{
	int x;
	cin >> n;
	for (int i = 0 ; i< n ;i++)
	{
		cin >> x; 
		aa[x-1]++;
	}
	double ans = solve2(aa[0],aa[1],aa[2]);
	cout<<fixed<<setprecision(9);
	cout << ans;
}
int main()
{
 //ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    freopen("lololoin.txt","r",stdin);
	solve();
}