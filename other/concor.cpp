#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000001;
#define f first
#define s second
int check[2005];
struct Kingtapyeu
{
    long long x,y,r;
    long long m;
} rada[2005];
pair<long long, long long> tram[2005];
int main ()
{
   // freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long double kc,kc11,kc22,kc3;
    long long kg,ans=0, xx,yy,rr,d,a,b,c,cc,kc1,kc2;
    int s,n;
    cin >> s >> n >> d;
    for (int i = 1; i<= s; i++)
    {
        cin >> xx>>yy>>rr>>kg;
        rada[i]={xx,yy,rr,kg};
    }
    for(int i = 1; i<= n; i++)
    {
        cin >> tram[i].f >> tram[i].s;
    }
    tram[0] = {0,0};
    for (int i = 1; i <= n; i++)
    {
        a = tram[i-1].s-tram[i].s; b = tram[i].f-tram[i-1].f;
        //cout << a<<" "<< b << endl;
        c = -(a*tram[i].f + b*tram[i].s);
          kc3 = (long double)sqrt((tram[i].f-tram[i-1].f)*(tram[i].f-tram[i-1].f) + (tram[i].s-tram[i-1].s)*(tram[i].s-tram[i-1].s)); 
        for (int  j = 1; j <= s; j++)
        {
           if ( check[j]) continue;
           cc = (a*rada[j].x+b*rada[j].y+c)*(a*rada[j].x+b*rada[j].y+c);
           kc = (long double)cc/(a*a+b*b);
           kc1 = (rada[j].x-tram[i].f)*(rada[j].x-tram[i].f) + (rada[j].y-tram[i].s)*(rada[j].y-tram[i].s); 
           kc2 = (rada[j].x-tram[i-1].f)*(rada[j].x-tram[i-1].f) + (rada[j].y-tram[i-1].s)*(rada[j].y-tram[i-1].s);
           kc11 =  (long double)sqrt(kc1-kc);
           kc22= (long double)sqrt(kc2-kc);
           //cout << kc11 <<" "<<kc22<<endl;
           if(kc11+kc22 <=kc3+EPS&&kc11+kc22>=kc3-EPS)
           {
                if (cc <= (rada[j].r+d)*(rada[j].r+d)*(a*a+b*b))
                {
                  //  cout <<"lo "<<i<<" "<<j << endl;
                    check[j] =1 ;
                    ans+=rada[j].m;
                }
           }
           else if (min(kc1,kc2) <= (rada[j].r+d)*(rada[j].r+d))
           {
            //cout << min(kc1,kc2)<<endl; cout <<i<<" "<<j << endl;
          //  cout <<i<<" "<<j << endl;
            check[j] = 1;
            ans +=rada[j].m;
           } 
        }
    }
        a = tram[0].s-tram[n].s; b = tram[n].f-tram[0].f;
        //cout << a<<" "<< b << endl;
        c = -(a*tram[n].f + b*tram[n].s);
          kc3 = (long double)sqrt((tram[n].f-tram[0].f)*(tram[n].f-tram[0].f) + (tram[n].s-tram[0].s)*(tram[n].s-tram[0].s)); 
        for (int  j = 1; j <= s; j++)
        {
           if (check[j]) continue;
           cc = (a*rada[j].x+b*rada[j].y+c)*(a*rada[j].x+b*rada[j].y+c);
           kc = (long double)cc/(a*a+b*b);
           kc1 = (rada[j].x-tram[n].f)*(rada[j].x-tram[n].f) + (rada[j].y-tram[n].s)*(rada[j].y-tram[n].s); 
           kc2 = (rada[j].x-tram[0].f)*(rada[j].x-tram[0].f) + (rada[j].y-tram[0].s)*(rada[j].y-tram[0].s);
           kc11 =  (long double)sqrt(kc1-kc);
           kc22= (long double)sqrt(kc2-kc);
           if(kc11+kc22 <=kc3+EPS&&kc11+kc22>=kc3-EPS)
           {
                if (cc <= (rada[j].r+d)*(rada[j].r+d)*(a*a+b*b))
                {
                   //cout <<"lo "<<0<<" "<<j << endl;
                    check[j] =1 ;
                    ans+=rada[j].m;
                }
           }
           else if (min(kc1,kc2) < (rada[j].r+d)*(rada[j].r+d))
           {
            check[j] = 1;
             ans +=rada[j].m;
           } 
        }
    cout << ans;
}