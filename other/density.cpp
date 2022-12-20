#include<bits/stdc++.h>
using namespace std;
void solve()
{
	long long a,b,k,t,t1,m,m1,ans =0,x,y;
	cin >> a >> b >> k;
	t = cbrt(a); if (t*t*t!=a) t ++;
	t1 = cbrt(b);
	cout << t << " "<<t1<<endl;
	for (long long i = t; i <= t1; i++)
	{
		m = max(i*i*i-k,a);
		m1 = min(i*i*i+k,b);
		//cout << m << " "<< m1<<endl;
		x = sqrt(m) ;
		cout << " test " << i << " m = " << m <<" x =  " << x <<" " <<x*x << endl;
		 if (x!=0&&x*x==m)
		{
			x--;
			//cout <<" ne " << x << endl;
		}
		y = sqrt(m1);
		//cout << "ans1 = " << y-x<<endl;
		ans += (y-x); 
	}
	cout << ans;
}
int main()
{	    
	 freopen("lololoin.txt","r",stdin);

	// freopen("density.inp","r",stdin);
	//  freopen("density.out","w",stdout);
	solve();
}