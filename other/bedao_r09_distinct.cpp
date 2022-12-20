#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using piv = pair<int, vi>;

const int P = 100;
const int M = 200;
const int oo = 1e9;

string str[M + 5];
int cnt[P + 5][2] , pre[P + 5][P + 5];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 0; i < p; i++) cnt[i][0] = cnt[i][1] = 0;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < p; j++)
            if (s[j] == '1')
                cnt[j][1]++;
            else cnt[j][0]++;
    }

    for (int i = 1; i <= m; i++) cin >> str[i];

    string s1 = "";
    int ans1 = 0;

    for (int i = 0; i < p; i++)
    if (cnt[i][0] < cnt[i][1]) {
        s1 += '1';
        ans1 += cnt[i][0];
    } else {
        s1 += '0';
        ans1 += cnt[i][1];
    }

    bool flag = true;

    for (int i = 1; i <= m; i++)
    if (s1 == str[i]) {
        flag = false;
        break;
    }

    if (flag) {
        cout << ans1 << '\n';
        return;
    }

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
    if (i != j) {
        for (int k = 0; k < p; k++)
        if (str[i][k] != str[j][k]) {
            pre[i][j] = k;
            break;
        }
    }

    int res = oo;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < p; j++) {
            bool ok = true;

            for (int k = 1; k <= m; k++)
                if (k != i && pre[i][k] >= j && ((str[i][j] - '0') ^ 1) == (str[k][j] - '0')) {
                    ok = false;
                    break;
                }

            if (ok) {
                int ans = 0;

                for (int k = 0; k < p; k++) {
                    if (k < j) {
                        ans += cnt[k][(str[i][k] - '0') ^ 1];
                    }
                    else if (k == j) {
                        ans += cnt[k][str[i][k] - '0'];
                    }
                    else {
                        ans += min(cnt[k][0], cnt[k][1]);
                    }
                }

                //cout << i << ' ' << j << ' ' << ans << '\n';
                res = min(res, ans);
                break;
            }
        }
    }

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;

    while (t--) solve();
    return 0;
}