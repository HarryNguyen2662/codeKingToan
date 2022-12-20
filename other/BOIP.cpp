#include<bits/stdc++.h>
using namespace std;
void input()
{
    cin >> n >> p;
    for (int i = 0 ; i < n; i++)
     cin >> a[i];
}
bool check(long long a)
{
	if (a >= MAX/p) return false; else return true;
}
void xuly()
{
	sort(a, a + n );
	dem = 0;
	for ( int i = 1; i < n; i++)
	 if (a[i] == a[i-1]) dem++;
	 else 
	 {
	 	b[m] = make_pair(a[i-1], dem + 1);
	 	dem = 0; m ++;
	 }
	 if (dem) b[m] = make_pair (a[n-1], dem + 1); m ++;
}
void xuly1()
{
	for ( int i = 0 ; i < m; i++)
	 if ( dd[i] == 0)
	{
		ldk[nn].push_back (b[i].second);
		k = b[i].first;
		mid = i +1 ;
		while (1)
		{
			if (!check(k)) break; else k = k*p;
			l = mid +1; r = m; kt = false;
			while (l <= r)
			{
				mid = (l + r)/2;
				if (b[mid-1].first == k) {
					 kt = true; break; 
				} else if (b[mid-1] < k) l = mid + 1; else r = mid -1; 
			}
			if (!kt) break; else {
				ldk[nn].push_back(b[mid-1].second);
				dd[mid-1] = 1;
			}
		}
		nn ++;
	}
}
void xuly2()
{
	long long ans = 0;
	for (int i = 0; i <= nn; i++)
	{
		dp[0][0] = 0; dp[0][1] = ldk[i][0];
		for (int j = 1; j < ldk.size(); j++)
		 {
		  dp[j][0] = max (dp[j-1][1], dp[j-1][0]);
		  dp[j][1] = max (dp[j-1][1], dp[j-1][0] + ldk[i][j]);
	    }
	    ans += max (dp[ldk.size()-1][1], dp[ldk.size()-1][0];
	}
	cout << ans;
}
void answer()
{
	input();
	xuly();
	if ( p == 1) cout << m; 
	else {
		xuly1();
		xuly2();
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
