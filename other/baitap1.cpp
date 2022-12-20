#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
string s;     int kq=0,chiso=1;
	cin>>s;
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
             if (z[i]<=i) {
        if (z[i]>kq) {
        	kq=z[i]; chiso=i+1;
		} 	
 }
          }   
  cout<<kq<<"\n"; cout<<chiso;	
}
