#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e9; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
stack<int> st;
queue<int> qu;
string res="";
int a[20006];
void QS(int n, int l, int r)
{
    if (n == 1) return;
    int mid = (l + r)/2;
    for (int i = 1; i <= n; i++)
    {
        qu.push(st.top()); st.pop();
        res += 'C';
    }
    for (int i = 1; i <= n; i++)
    {
        if (qu.front())
    }
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i; i--) st.push(a[i]);
    //cout <<st.size()<<endl;
    MS(n, true);
    // cout << st.size() << endl;
    // while(!st.empty()) 
    // {
    //     cout << st.top()<<endl;
    //     st.pop();
    // }
    cout << res;    
}