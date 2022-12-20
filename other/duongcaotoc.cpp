#include<bits/stdc++.h>
using namespace std;
int main()
{
	double n,v,v1,s; int q;
	cin>>n>>v>>v1; v=abs(v-v1);
	cin>>q;
	while(q--)
	{
		cin>>s;
		s=n-sqrt(s); s=sqrt(2*s*s);
		cout << std::setprecision(10);	
		cout<<s/v<<"\n";
	}
}
