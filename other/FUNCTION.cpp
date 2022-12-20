#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long power(long long a, long long b)
{
	if (b==0) return 1;
	long long y = power(a,b/2);
	if (b%2==0) return y*y%MOD; else return y*y%MOD*a%MOD;
}
int main()
{
	//freopen("lololoin.txt","r",stdin);
	freopen("FUNCTION.INP","r",stdin);
	freopen("FUNCTION.OUT","w",stdout);
	long long A,B,n,x;
	cin >> A >> B >> n >> x;	
	if (A==1) cout << (power(A,n)*x%MOD + (n)%MOD*B%MOD)%MOD;
	else
		cout << (power(A,n)*x%MOD + (power(A,n)-1)*power(A-1,MOD-2)%MOD*B%MOD)%MOD;
}