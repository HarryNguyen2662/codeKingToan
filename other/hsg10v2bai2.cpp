#include<bits/stdc++.h>
using namespace std;
map<int,int > dem;
int a[1000005];
int main()
{
    freopen("yeunhi.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int dem1=0,x,y,n,l,luu; long long ans=0; set<long long> s,ss;
    cin  >> n >> x >> y; 
    for (int i = 1; i<= n; i++) 
        cin >>a[i];
    for (int i = 1 ; i<= n ;i++)
    {
        if(dem[a[i]]==0)
        {
            dem1++;
            s.insert(a[i]);
        }
        dem[a[i]]++;
        if (dem1==x)
        {
            luu=i; break;
        }
    }
    if (dem1<x)
    {
        cout << 0; 
        return 0;
    }
    l=1;
    if (y==1)
    {
        ans = 2*(*s.begin()) + *s.rbegin();
        for (int i = luu+1; i<=n ;i++)
        {
            if (dem[a[i]]==0)
            {
            s.insert(a[i]);
            while(true)
            {
                dem[a[l]]--; l++;
                if(dem[a[l-1]]==0)
                {
                     s.erase(s.find(a[l-1]));
                     break;
                }
            }
            ans= max(ans,  2*(*s.begin()) + *s.rbegin());
        }
        dem[a[i]]++;
        }
    }
    else if (y==x)
      {
        ans = 2*(*s.rbegin()) + *s.begin();
        for (int i = luu+1; i<=n ;i++)
        {
            if (dem[a[i]]==0)
        {
            s.insert(a[i]);
            while(true)
            {
                dem[a[l]]--; l++;
                if(dem[a[l-1]]==0)
                {
                     s.erase(s.find(a[l-1]));
                     break;
                }
            }
            ans= max(ans,  2*(*s.rbegin()) + *s.begin());
        }
        dem[a[i]]++;
        }
    }
    else
     {
        for (int i = y+1; i <= x ; i++)
        {
            ss.insert(*s.rbegin());
            s.erase(*s.rbegin());
        }
        ans = *s.begin() + *s.rbegin() + *ss.rbegin();
        for (int i = luu+1; i<=n ;i++)
        {
            if (dem[a[i]]==0)
            {
                while(true)
                {
                    dem[a[l]]--; l++;
                   if(dem[a[l-1]]==0)
                   {
                        if (s.find(a[l-1])!=s.end())
                        {
                            s.erase(s.find(a[l-1]));
                            ss.insert(a[i]);
                            s.insert(*ss.begin());
                             ss.erase(*ss.begin());
                      } 
                     else
                     {
                            ss.erase(ss.find(a[l-1]));
                            s.insert(a[i]);
                            ss.insert(*s.rbegin());
                         s.erase(*s.rbegin());   
                       }
                     break;
                    
                }
            }
                ans= max(ans,  *s.begin() + *s.rbegin() + *ss.rbegin());

            }
            dem[a[i]]++;
        }
    }   
    cout << ans;
}