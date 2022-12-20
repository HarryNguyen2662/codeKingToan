#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ALL(n) n.begin(), n.end()
#define fi first
#define se second
#define mask(n) (1ll << (n))
#define ck(n, k) (((n) >> (k))&1)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    system("g++ -std=c++11 TCANDY.cpp -o TCANDY.exe");
    system("g++ -std=c++11 testne.cpp -o testne.exe");

    for (int i = 1; i <= 500; i++)
    {
    	int ii = rng()%2500 + 1, jj = rng()%ii + 1; int pp = rng()%1000000+1;
        ofstream out("hellodking.txt");
        out << ii << " " << jj << " " << pp;
        out.close();

        system("TCANDY.exe"); system("testne.exe");
        if (system("fc goodbyedking.txt goodbyedking1.txt") != 0)
        {
            cout << "wrongg\n"; exit(0);
        }
    }

    cout << "dung roi nha";
}

