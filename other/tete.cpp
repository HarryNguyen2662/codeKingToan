#include<bits/stdc++.h>
using namespace  std;
vector<long long> cata[500005],k[1000005];
vector<long long> const MOD = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103, 1000000123, 1000000181};
long long power(long long a, long long b,int i)
{
     if (b == 0) return 1;
     long long y = power(a,b/2,i)%MOD[i];
     if (b%2 == 0) return y*y%MOD[i]; else return y*y%MOD[i]*a%MOD[i];
}
void khoitao()
{
	k[0] = {1,1,1,1,1,1,1,1,1,1};
	for (long long i = 1 ; i <= 1000000 ; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			k[i].push_back(k[i-1][j]*i%MOD[j]);
		}
	}
	cata[0] = {1,1,1,1,1,1,1,1,1,1};
	for (int i = 1; i <= 500000; i++)
	{
		for (int j = 0; j < 10; j++)
		cata[i].push_back( k[2*i][j]*power(k[i+1][j]*k[i][j]%MOD[j],MOD[j]-2,j)%MOD[j]);
	}
}
void check(string s, int n)
{
	for (int j = 0; j < 10; j++)
	{
	 long long d = 1, we=0;
	 for (int i = s.size() - 1; i >= 0 ; i--)
	 {
	 	we = (we + (s[i] - 48) * d % MOD[j])%MOD[j];
	 	d = d*10%MOD[j];
	 }
	 if (we != cata[n][j]) 
	 {

	 	cout <<"NO\n";	
	 	return;
	 }
   }
	 cout <<"YES\n";
}
void solve()
{
	string k; int n;
	cin >> n >> k;
   check(k,n);
}
int main()
{
//freopen("lololoin.txt","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	khoitao();
	while (t--)
		solve();
	//cout<<power(3,MOD-2);
}	
