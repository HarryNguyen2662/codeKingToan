#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    int n,k;
    long long ans=0;
    deque<int> UN;
    cin >> n >> k;
    for (int i =1 ;i <= n; i++)
    {
        cin>> a[i];
        while(!UN.empty()&&a[UN.back()]>a[i]) UN.pop_back();
        UN.push_back(i);
        if (UN.front()<=i-k) UN.pop_front();
        ans+=a[UN.front()]*2;
    }  
    cout<<ans;
}
