#include <bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int left, int right)
{
    return left + abs(int(rd())) % (right - left + 1);
}

char randChar()
{
    int t = randInt(1, 3);
    switch (t)
    {
    case 1:
        return char('a' + randInt(0, 25));
    case 2:
        return char('A' + randInt(0, 25));
    case 3:
        return char('0' + randInt(0, 9));
    }
}

string genString(int n)
{
    string resuft;
    for (int i = 1; i <= n; i++)
    {
        resuft.push_back(randChar());
    }
    return resuft;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("script.txt", "w", stdout);
    for (int i = 2; i <= 20; i++)
    {
        string script = "gen " + genString(20) + " > ";
        cout << script << i << "\n";
    }
    return 0;
}
