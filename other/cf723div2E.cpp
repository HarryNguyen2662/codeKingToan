#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int n;
long long fw[100500];
int dem[1000];
pair<int,char> c[4];
vector<int> ldk[1000];
void uptree(int id, int vl)
{
    for (; id < n; id = (id | (id+1)))
        fw[id] +=vl;
}
int sum(int id)
{
    int res = 0;
    for (; id >= 0;  id = (id & (id+1)) - 1)
        res += fw[id];
    return res;
}
long long solve(string s, string st)
{
    long long res =0 ;
    dem['N'] = dem['T'] = dem['O'] = dem['A'] = 0;
    for (int i = 0; i < n; i++)
       {  fw[i] = 0;}
    for (int i = 0; i < n; i++)
    {
        int x = ldk[st[i]][dem[st[i]]]; dem[st[i]]++;
        res += x + sum(x) - i;
       uptree(0,1); uptree(x+1,-1);
    }
    return res;
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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        n = s.size();
        for (int i = 0; i < n; i++)
        {
            ldk[s[i]].pb(i); 
        }   
        c[0] = {ldk['A'].size(), 'A'}; c[1] = {ldk['N'].size(),'N'}; c[2] = {ldk['T'].size(),'T'}; 
        c[3] = {ldk['O'].size(),'O'};
        sort(c,c+4);
        string res="";
        long long re = 0;
        do
        {
            string st;
            for (int i =0; i <4; i++)
                for (int j = 0; j < c[i].f;j++) st+=c[i].s;
            long long ree = solve(s,st);
            if (re <=ree){ res =st; re = ree; }
        }
        while (next_permutation(c,c+4));
        cout << res<<endl;
        ldk['N'].clear(); ldk['T'].clear(); ldk['O'].clear(); ldk['A'].clear();
    }
} 