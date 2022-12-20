#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int d[10000005];
string longDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
  
    if (ans.length() == 0)
        return "0";
    return ans;
}
void solve(int n,int j,int k)
{
    string s="";
    for (int i = 1;i <= n; i++) s +=(char)(j+48);
    cout << longDivision(s,k);
}
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
    bool kt = false;
    int n;
    cin >> n;
    for (int i = 1; i<= 1e7; i++)
        d[i] = (d[i-1]*10+1)%n;
    for (int i = 1; i<= 1e7; i++)
      {  for (int j = 1; j <= 9; j++)
            if (d[i]*j%n==0)
            {
                kt = true;
                solve(i,j,n);
                break;
            }
            if(kt) break;
        }
    if (!kt) cout << -1;
}