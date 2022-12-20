#include <bits/stdc++.h>
using namespace std;
long long dd[2000000];
int check[10];
int main()
{
	freopen("RELATIVE.INP","r",stdin);
	freopen("RELATIVE.OUT","w",stdout);
	int n,sum;
	long long ans = 0;
	string s;
	cin >> n;
	for (int i = 1; i<= n; i++)
	{
		cin >> s;
		sum=0;
		for(int j =0 ; j< s.size();j ++)
			if(!check[s[j]-48]) {
				sum = sum+ (1<<(s[j]-48));
				check[s[j]-48]=1;
			}
		for(int j =0 ;j <=9; j++) check[j]=0;
		dd[sum] ++;
		//cout << sum<<" "<<dd[sum]<<endl;
	}
	for (int i = 1; i< 1024; i++)
		if (dd[i])	
		{
			ans=ans+dd[i]*(dd[i]-1)/2;
			for (int j = i+1; j < 1024; j++)
				if ((dd[j])&&((i&j)>0))
					{
						//cout << i <<" "<<j << endl;
						ans=ans+dd[i]*dd[j];
					}
		}
	cout << ans;
}