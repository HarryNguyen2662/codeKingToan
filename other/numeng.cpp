#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
long long dp[1005][1005][6];
int x[1050], y[1050];
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
    int n;
    cin >> n;
    if (n == 1)
        cout << "one";
    else if (n == 2)
        cout << "two";
    else if ( n == 3)
        cout << "three";
    else if (n == 4)
        cout<< "four";
    else if (n == 5)
        cout << "five";
    else if (n == 6)
        cout <<"six";
    else if (n == 7)
        cout <<"seven";
    else if (n == 8)
        cout <<"eight";
    else if (n == 9)
        cout <<"nine";
    else if (n == 10)
        cout <<"ten";
    else if (n == 11)
        cout << "eleven";
    else if (n == 12)
        cout << "twelve";
    else if ( n == 13)
        cout << "thirdteen";
    else if (n == 14)
        cout<< "fourteen";
    else if (n == 15)
        cout << "fifteen";
    else if (n == 16)
        cout <<"sixteen";
    else if (n == 17)
        cout <<"seventeen";
    else if (n == 18)
        cout <<"eighteen";
    else if (n == 19)
        cout <<"nineteen";
    else
    {
     if (n/10 == 2)
        cout << "twenty";
    else if ( n/10 == 3)
        cout << "thirty";
    else if (n/10 == 4)
        cout<< "forty";
    else if (n/10 == 5)
        cout << "fifty";
    else if (n/10 == 6)
        cout <<"sixty";
    else if (n/10 == 7)
        cout <<"seventy";
    else if (n/10 == 8)
        cout <<"eighty";
    else if (n/10 == 9)
        cout <<"ninety";
    if (n%10 == 1)
        cout << "-one";
    else if (n%10 == 2)
        cout << "-two";
    else if ( n%10 == 3)
        cout << "-three";
    else if (n%10 == 4)
        cout<< "-four";
    else if (n%10 == 5)
        cout << "-five";
    else if (n%10 == 6)
        cout <<"-six";
    else if (n %10== 7)
        cout <<"-seven";
    else if (n%10 == 8)
        cout <<"-eight";
    else if (n %10== 9)
        cout <<"-nine";
    }
}