#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
	deque<int> s,ss;
	int n,k,kq=0,i,l;
	cin>>n>>k;l=0;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		while (!s.empty()&&a[s.back()]>=a[i]) s.pop_back();
		s.push_back(i); 
		while (!ss.empty()&&a[ss.back()]<=a[i]) ss.pop_back();
		ss.push_back(i); 
		if (a[ss.front()]-a[s.front()]>k)
		{
			if (ss.front()>s.front())
			{
				while(a[ss.front()]-a[s.front()]>k) 
				{
					l=s.front()+1;
					s.pop_front();
				}
			}
			else
			{
				while(a[ss.front()]-a[s.front()]>k) 
				{
					l=ss.front()+1;
					ss.pop_front();
				}	
			}
		}
		kq=max(kq,i-l+1);
	}
	cout<<kq;
}