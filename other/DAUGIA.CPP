#include<bits/stdc++.h>
using namespace std;
vector<long long > ldk[10];
bool check(long long u)
{
	for (long long i = 2; i*i<=u;i++) if (u%i ==0) return false;
		return true;
}
int main()
{
	freopen("lololoin.txt","r",stdin);
	long long a,b,r,l,ll,mid,k,u; vector<long long> kk;
	cin >> a >>b;
	ldk[0].push_back(0);
	for (long long i = 0; i<= 9; i++)
	{
		ldk[1].push_back(i);
	}
	kk.push_back(2); kk.push_back(5); kk.push_back(7);
	k = 1; bool kt =false;
	for (long long i = 2; i <=9; i++)
	{
 		k = k*10;
		for (long long j = 0; j <=9; j++)
		{
			for (auto e : ldk[i-2])
			{
				if (e%10 ==0)
				{
					 u = k*j*10+e*10+j;
				}
				else
				{ u = k*j+e*10+j;
			  	if (check(u)) kk.push_back(u);
			  }
				ldk[i].push_back(u); 
				
			}
		}
	}
//	for (auto t :kk) cout << t << endl;
	l = 1; r = kk.size();
	while (l<=r)
	{
		mid = (l+r)/2;
		if (kk[mid-1]>=a) r = mid -1 ; else l = mid +1;
	} 
	ll = 1; r = kk.size();
	while (ll<=r)
	{
		mid = (ll+r)/2;
		if (kk[mid-1]<=b) ll = mid +1 ; else r = mid -1;
	} 
	//for (int i = l -1; i <r; i++) cout << kk[i]<< endl;
	cout << r-l ;
}