#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
pair<long long ,long long > cost[1000050], costt[1000050];
int c[100050];
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n,luu,x,luu1;
    cin >> t;
    while (t--)
    {
    	bool kt = false;
    	cin >> n;
    	int j = 1;
    	luu = 0;
    	while (j+1 <= n)
    	{
    		cout <<"? 2 "<<j<<" "<<j+1<<" 1"<<endl;
    		cin >> x;
    		if (x == 1) 
    		{
    			luu = j;
    			c[luu] = 1;
    			break;
    		}
    		else if (x==2)
    		{
    			if (j+1==n) 
    			{
    				luu = j+1; break;
    			}
    			else
    			{
    				cout <<"? 2 "<<j+1<<" "<<j+2<<" 1"<<endl;
    				cin >> x;
    				if (x==1)
    				{
    					luu = j+1; break;
    				}
    			}
    		}
    		j+=2;
    	}
    	if (luu ==0 ) luu = n;
    	c[luu] = 1;
    	for (int i = luu -1; i; i --)
    	{
    		cout <<"? 1 "<<luu<<" "<<i<<" "<<n-1<<endl;
    		cin >> x;
    		c[i] = x;
    	}
    	for (int i = luu +1; i<=n; i ++)
    	{
    		cout <<"? 1 "<<luu<<" "<<i<<" "<<n-1<<endl;
    		cin >> x;
    		c[i] = x;
    	}
    	cout << "! ";
    	for (int i = 1; i<= n; i++) cout << c[i]<<" ";
    	cout <<endl;
    	cout.flush();
    }
}
