#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ALL(n) n.begin(), n.end()
#define fi first
#define se second
#define mask(n) (1ll << (n))
#define ck(n, k) (((n) >> (k))&1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

long long a[10005], b[10005];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    system("g++ -std=c++11 C2XOR.cpp -o C2XOR.exe");    
    system("g++ -std=c++11 testmay.cpp -o testmay.exe");

    int oo = 1000000000;
    for (int ii = 1; ii <= 1000; ii++)
    {
        ofstream out("hellodking.txt");
            
        int n = 100;
        out << n << "\n";

        for (int i = 1; i <= n; i++)
        {
            out << rng()%1005 + 1 << " ";
        }

        out.close();

       system("C2XOR.exe"); system("testmay.exe");
        if (system("fc goodbyedking.txt goodbyedking1.txt") != 0)
        {
            cout << "wrongg\n"; exit(0);
        }
    }

    cout << "dung roi nha";
}

