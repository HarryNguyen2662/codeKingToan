#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s; int k,i,kt;
	cin>>s;
	 k=s.size()-1; kt=(k%2==0); k=k/2+1;
	for (i=1;i<s.size();i++) if (s[i]=='1') 
	{
	   kt=0; break; }
	   cout<<k-kt;
}
