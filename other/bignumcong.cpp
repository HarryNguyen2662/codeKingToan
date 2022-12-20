#include<bits/stdc++.h>
using namespace std;
string f[505];
string congbignum(string s1, string s2)
{
	string s3;
	long long int nho = 0;
	long long int poiter = s2.size() - 1;
	for (int i = s1.size() - 1; i >= 0; i--)
	{
		if (poiter >= 0)
		{
			long long int value = s1[i] - 48 + s2[poiter] - 48 + nho;
			s3.push_back(value % 10 + 48);
			nho = value / 10;
			poiter--;
		}
		else
		{
			long long int value = s1[i] - 48 + nho;
			s3.push_back(value % 10 + 48);
			nho = value / 10;
		}
	}
	while (nho != 0)
	{
		s3.push_back(nho % 10 + 48);
		nho /= 10;
	}
	string s4;
	for (int i = s3.size() - 1; i >= 0; i--)
	{
		s4.push_back(s3[i]);
	}
	return s4;
}
void khoitao()
{
	f[1]="1"; f[2]="1";
	for (int i = 3; i <= 500; i++)
		f[i]=congbignum(f[i-1],f[i-2]);
}
void solve()
{
	int k;
    cin >> k;
    cout << f[k] << "\n";
}
int main()
{
	freopen("testthuin.txt","r",stdin);
	 freopen("testthuout.txt","w",stdout);
	 //cout << congbignum("5","90");
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	 khoitao();
	 int t;
	  cin >> t;
	  while (t--) solve();
}