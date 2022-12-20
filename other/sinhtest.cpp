#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ALL(n) n.begin(), n.end()
#define fi first
#define se second
#define mask(n) (1ll << (n))
#define ck(n, k) (((n) >> (k))&1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int b[6];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    system("g++ -std=c++11 MUABANCO.cpp -o MUABANCO.exe");
    system("g++ -std=c++11 testmay.cpp -o testmay.exe");

    long long oo = 1e9;

    b[1] = 1; b[2] = oo; b[3] = 6; b[4] = 10; b[5] = oo/2;

    for (int ii = 1; ii <= 1000; ii++)
    {
        ofstream out("hellodking.txt");
            
        int n = rng()%10 + 1, k = rng()%n + 1;

        out << n << " " << k << "\n";

        for (int i = 1; i <= n; i++)
        {
            out << b[rng()%5 + 1] << " ";
        }
        
        out.close();

        system("MUABANCO.exe");
        system("testmay.exe");

        if (system("fc goodbyedking.txt goodbyedking1.txt") != 0)
        {
            cout << "wrongg\n"; exit(0);
        }

        cout << "Accepted\n";
    }

    cout << "XIN CHUC MUNG LE DAI KING DA DUNG ROI NHA";
}

