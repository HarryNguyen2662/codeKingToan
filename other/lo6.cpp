//私の人生は桜のようです。 花が咲くと最も美しくなりますが、すぐに色あせます。
//しかし、最も重要なことは、それが常にすべての人に愛され、記憶されているということです。
//I'm too tired of playing, eating, sleeping and relaxing.
//I will train for my last schoolyear and make this year become the best year of my school life.
#include <bits/stdc++.h>
#define fi first
#define se second
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORD(i, a, b) for(int i = (a); i > (b); --i)
#define REPD(i, a, b) for(int i = (a); i >=(b); --i)
#define TR(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define endl '\n'
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ins insert
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define unmap unordered_map
#define pq priority_queue
#define minEle min_element
#define maxEle max_element
#define lb lower_bound //first pos >= val
#define ub upper_bound // first pos > val
#define bp __builtin_popcount
#define debug(a) cout << a << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
typedef pair <int, pii> pip;
typedef pair <ll, ld> pld;
typedef pair <ll, pll> pllp;
typedef pair <pll, ll> ppll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <pll> vpll;
typedef vector <pii> vpii;
typedef map <int, int> mii;
typedef map <ll, ll> mll;
typedef string BigNum;

const ll maxN = 1e18;
const ll minN = -1e18;
const int INF = 2e9;
const ll MOD = 1e9 + 7;
const ll MOD1 = 998244353;
const int baseHash = 331;
const int bigNumLength = 5000;
const ld PI = acos(-1);

//Remember limit for IT, etc..., and +1 in limit of any array
const ll limit = 2e5 + 5;
const ll limit1 = 1e6 + 5;
const ll limit2 = 1e3 + 5;
//If TLE let's use int instead of ll because it's as slow as your WPM :)))

/*----IMPORTANT THINGS----*/
pii dir[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
//right down left up rightdown leftdown rightup leftup
pii NON = {-1, -1};
/*------------------------*/

#define PROB "problem"

int n;
int a[limit];

void solveProblem() {
    int cntNeg = 0, cntZero = 0, maxNeg = -1e9 - 5, pos = 0, posZero = 0;
    
    REP(i, 1, n) {
        if (a[i] < 0) ++cntNeg;
        else if (a[i] == 0) ++cntZero, posZero = i;

        if (a[i] < 0) {
            if (maxNeg < a[i]) {
                maxNeg = a[i];
                pos = i;
            }
        }
    }

    if (cntNeg % 2 == 1) {
        int ans = 1;
        REP(i, 1, n) {
            if (i == pos) continue;
            ans = 1LL * ans * a[i] % MOD;
        }

        cout << ans << endl;
        return;
    }

    if (cntZero > 1) cout << 0 << endl;
    else {
        if (cntZero == 0) {
            int ans = 1;
            REP(i, 1, n) {
                ans = 1LL * ans * a[i] % MOD;
            }

            cout << ans << endl;
        }

        else {
            int ans = 1;
            REP(i, 1, n) {
                if (i == posZero) continue;
                ans = 1LL * ans * a[i] % MOD;
            }

            cout << ans << endl;
        }
    }
}

void fastInput() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // if (fopen(PROB".inp", "r")) {
    //     freopen(PROB".inp", "r", stdin);
    //     freopen(PROB".out", "w", stdout);
    // }
}

void readInput() {
    cin >> n;
    REP(i, 1, n) cin >> a[i];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    fastInput();
    readInput();
    solveProblem();
}