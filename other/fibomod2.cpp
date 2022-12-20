#include <bits/stdc++.h>
using namespace std;
const long long base=1e9+7;
 
struct MaTran
{
    long long c[2][2];
    MaTran()
    {
        c[0][0]=0;
        c[0][1]=1;
        c[1][0]=1;
        c[1][1]=1;
    }
};
 
long long int nhan(long long int a, long long int b)
{
    long long int ans = 0;
    if (b % 2 == 0)
    {
        ans = nhan(a, b / 2) % base;
        ans = (ans % base + ans % base) % base;
        return ans;
    }
    if (b % 2 == 1)
    {
        ans = nhan(a, b / 2) % base;
        ans = (ans % base + ans % base + a % base) % base;
        return ans;
    }
}

MaTran operator * (MaTran a, MaTran b)
{
    MaTran res;
    for (int i=0; i<=1; i++)
        for (int j=0; j<=1; j++)
        {
            res.c[i][j] = 0;
            for (int k=0; k<=1; k++)
                res.c[i][j] = (res.c[i][j] % base + nhan(a.c[i][k], b.c[k][j]) % base) % base;
        }
    return res;
}
 
MaTran powermod (MaTran a, long long n)
{
    if (n==1)
        return a;
    if (n%2!=0)
        return powermod(a,n-1)*a;
    MaTran tmp = powermod(a,n/2);
    return tmp*tmp;
}
 
int main()
{

    vector<long long int> my_vector;
    my_vector.push_back(0);
    my_vector.push_back(1);
    while (my_vector.size() <= 90)
    {
        int u = my_vector.size();
        my_vector.push_back(my_vector.at(u - 2) + my_vector.at(u - 1));
    }
    for (auto n :my_vector)
    {
    MaTran A,B;
    A = powermod(A,n);
    cout << A.c[0][1]<< endl;
    }
}