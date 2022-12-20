#include<bits/stdc++.h>
using namespace std;
const long long N=3*1e6;
int pri[N+5],sov[N+5];
void khoitao()
{
    pri[1]=1;
    for(long long i=2;i<=sqrt(N);i++)
        if(pri[i]==0)
        for(long long j=i*i;j<=N;j=j+i)
        pri[j]=1;
}
long long solve(long long n)
{
    long long sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main()
{freopen("lololoin.txt","r",stdin);
	//
     freopen("SPRIME.inp","r",stdin);
     freopen("SPRIME.out","w",stdout);
    int t,l,r;
    khoitao();
    for(int i=2;i <=N; i++)
    {
        sov[i]=sov[i-1];
        if(pri[i]==0)
        {
            if(solve(i)%5==0)
            {
                sov[i]++;
            }
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        cout<<sov[r]-sov[l-1]<<endl;
    }
}