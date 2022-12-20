#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main()
{
	long long n,t,l,r,ans,res,ok = 0;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = 0;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 2; i <= n; i++) {
			if(abs(a[i] - a[i - 1]) == 1 && ok == 0) ok = i - 1;
            if(abs(a[i] - a[i - 1]) == 1 && ok > 0) ans = max(ans, i - ok + 1);
            if(abs(a[i] - a[i - 1]) != 1) ok = 0;
		}
		cout << ((ans > n / 2) ? "Yes" : "No") << endl;
	}
}
