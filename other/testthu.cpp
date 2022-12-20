//huydichepcode
#include<bits/stdc++.h>

typedef long long ll;
typedef float fl;

using namespace std;

const int BASE = 20060529;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5 ;
ll N[MAX], dp[MAX][105];
int main()
{
  #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
  cout.tie(NULL);
//  freopen("input.txt","r", stdin);
//  freopen("output.txt","w", stdout);
  ll n, m ;
  cin >> n >> m;
  for(ll i =1 ; i <= n ; i ++){
    cin >> N[i] ;
  }
  if (N[1] !=0 ) dp[1][N[1]] = 1;
  else {
    for(ll i = 1; i<= m ; i ++) dp[1][i] = 1;
  }
  for(ll i = 2; i <= n ; i ++){
    if(N[i] != 0) {
      dp[i][N[i]] = dp[i - 1][N[i] - 1] + dp[i - 1][N[i]] + dp[i - 1][N[i] + 1];
    }
    else{
      for(ll j = 1; j <= m ; j ++ ){
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1];
      }
    }
  }
  ll res = 0;
  for(ll i = 1; i<= m ; i ++) res += dp[n][i];
  cout << res;
  return 0;
}
