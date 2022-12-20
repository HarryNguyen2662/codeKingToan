#include<bits/stdc++.h>
using namespace std;
int dd[200001];
struct kk 
{
    int f;
    int s;
    long long cost;
    int cs;
     bool operator < (kk other) {
	  if (other.f>f)
	 	return true;
	 	else {
	 		if (other.s>s) return true;
		 }
	    return false;
	}
};
struct kv
{
	long long ct;
	int cs;
	 bool operator < (kv other) {
	  if (other.ct>ct)
	 	return true;
	 	return false;}
};
class my
{
  bool reverse;
public:
  my(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const kv& lhs, const kv&rhs) const
  {
    if (reverse) return (lhs.ct>rhs.ct);
    else return (lhs.ct<rhs.ct);
  }
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	long long cst,cost,kq,ssl,ngua;
	int n,m,t,i,l,r,c,tg; priority_queue<kv,vector<kv>,my> q,qq; vector<kk> ldk;
	cin>>n>>m>>t;
	for (i=1;i<=n;i++)
	{
		cin>>l>>r>>c;
	 ldk.push_back({l,1,c,i});	ldk.push_back({r,0,c,i});
    }
     sort(ldk.begin(),ldk.end());
     tg=1; cst=0;
     for (auto k:ldk)
     {
         ngua+=ssl; kq+=(double)cost*(k.f-tg); tg=k.f;
		if (k.s==0)
		{
			if (ssl<m) {
				ssl++; dd[k.cs]=1; cst+=k.cost;
			     q.push({-1*k.cost,k.cs}); 	
			}//	else 
		//	{
			//	while(dd[q.top().cs]==3) q.pop();
//				if (-1*q.top().ct>k.cost)
//				{
//					cst+=q.top().ct+k.cost; 
//					qq.push({-1*q.top().ct,q.top().cs});
//					dd[q.top().cs]=0; q.pop();
//				}
				//else qq.push({k.cost,k.cs});
		//	}
		}
		else 
		{
		    if (dd[k.cs]==0) dd[k.cs]=2;
		    else {
		     cst-=k.cost; dd[i]=3;
			 ssl--;
//			 while (!qq.empty()&&!dd[qq.top().cs]) qq.pop();
//			 if (!qq.empty())
//			 {
//			 	ssl++; cst+=qq.top().ct; dd[qq.top().cs]=1;
//				  qq.pop();
//			 }
			}
		}	
	 }
}
