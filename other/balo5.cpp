#include<bits/stdc++.h>
using namespace std;
long long w[40],v[40];
struct  ledaiking
{
	long long f,s;
	int t;
	bool operator < (ledaiking other)
	{
		return f < other.f;
	}
};
int main()
{
	freopen("lololoin.txt","r",stdin);
	int n,luu1,luu2,l,r,mid,nn; long long L,R,ans=0,sum,giatri,NL,NR;
	vector<ledaiking>ldk,ldh,kk; deque<ledaiking> dd;
	cin >> n >> L>>R;
	nn=n-n/2;
	for (int i = 0; i< n ;i ++)
	cin >> w[i] >> v[i];
	bitset<18> st,stt;
	for (int i =0; i< 1<< (n/2); i++)
	{
		st = i; sum =0; giatri = 0; 
		for (int j =0; j <(n/2); j++)
			if(st[j]==1) sum+=w[j], giatri+=v[j];
		ldk.push_back({sum,giatri,i});
	}
	for (int i =0; i< 1<< nn; i++)
	{
		st = i; sum =0; giatri = 0; 
		for (int j =0; j <nn; j++)
			if(st[j]==1) sum+=w[j+n/2], giatri+=v[j+n/2];
		ldh.push_back({sum,giatri,i});
	}
	sort(ldh.begin(),ldh.end());
	sort(ldk.begin(),ldk.end());
	 l = -1;
	for(int i = ldk.size()-1; i>=0; i--)
	{
		NL=L-ldk[i].f; NR=R-ldk[i].f;
	//	cout <<NL <<endl<<NR<<endl;
		//cout<<ldh[l+1].f<<" "<<NR <<endl;
		while(l+1<ldh.size()-1&&ldh[l+1].f<=NR)
		{
			l++;// cout<<l<<endl;
			while(!dd.empty()&&dd.back().s<ldh[l].s) dd.pop_back();
			dd.push_back(ldh[l]);
		}
		if(!dd.empty())
		{
			while(!dd.empty()&&dd.front().f<NL)dd.pop_front();
			if(!dd.empty()&&(ldk[i].s+dd.front().s>ans))
			{
				ans = ldk[i].s+dd.front().s;
		//		cout<<luu1<<" "<<luu2<<endl; 
				luu1=ldk[i].t; luu2 = dd.front().t;
			}
		}
	}
	st=luu1; stt=luu2;
	//cout << luu1 << endl<<luu2<<endl;
	cout << st.count()+stt.count()<<endl;
	for (int i = 0; i<n/2; i++) if (st[i]) cout << i+1<<" ";
	for (int i = 0; i<nn; i++) if (stt[i]) cout << i+1+n/2<<" ";
}