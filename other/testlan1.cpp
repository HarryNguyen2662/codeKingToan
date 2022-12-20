#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define setp setprecision
#define mask(i) (1ll << (i))
#define getbit1(x) __builtin_popcount(x)
#define hoanvi next_permutation
void zfunction()
{
    string s = "ereiereidkkee";
    int n = (int)s.size();
    vector<int> p(n+1);
    p[0] = n;
    for (int i = 1, l = 0, r =0; i < (int)s.size(); i++)
    {
        if (i <= r) p[i] = min(r - i + 1, p[i-l]);
        while (i + p[i] < (int)s.size() && s[p[i]] == s[i + p[i]]) p[i]++;
        if (i + p[i] - 1 > r)
        {
            l = i; r = i + p[i] - 1;
        }
    }
    for (int i = 0; i < (int)s.size(); i++) cout << p[i] <<" ";
}
void manacher()
{
    string s = "ereikee";
    int n = (int)s.size();
    vector<int> b(2*n+5);
    b[0] = '!'; b[1] = '#';
    int cnt = 1;
    for (int i = 0; i < (int)s.size(); i++)
    {
        cnt++; b[cnt] = s[i];
        cnt++; b[cnt] = '#';
    }
    b[cnt+1] = '@';
    vector<int> p(2*n+5);
    int C = 1, R = 1;
    for (int i = 2; i < cnt; i++)
    {
        int w = 2*C - i;
        p[i] = (R > i) ? min(R - i , p[w]) : 0;
        while(b[i-1-p[i]] == b[i + 1 + p[i]]) p[i]++;
        if (i + p[i] > R)
        {
            C = i; R = i + p[i];
        }
        cout << p[i] <<" ";
    }
}
int main()
{
    manacher();
}
