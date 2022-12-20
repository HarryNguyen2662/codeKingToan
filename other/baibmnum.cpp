#define TASK .....

int n, u, v, pref[limit1e5], a[limit1e5];

void read() {

    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++)  cin >> a[i], pref[i] = pref[i - 1] + a[i];

}



void solve() {

    int result = -INF;
    int l = 1, r = 1;
    multiset<int> s;
    for (int i = u; i <= n; i++) {
        int right = i - u + 1;
        int left = max(1LL, i - v + 1);
        while (l < left) {
            s.erase(s.find(pref[l - 1]));
            l++;
        }
        while (r <= right) {
            s.insert(pref[r - 1]);
            r++;
        }
        maximize(result, pref[i] - *s.begin());
    }
    cout << result << endl;


}


/* Don't coppy 😃 */
signed main() {

    freopen("daycon.inp", "r", stdin);
    freopen("daycon.out", "w", stdout);
    FAST;
    int num_test = 1;
    //cin >> num_test;
    while (num_test--) {
        read();
        solve();
    }

}