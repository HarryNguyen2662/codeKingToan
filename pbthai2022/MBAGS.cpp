#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
const ld TIME_LIMIT = .65;
int n, m, wei[505], luu[10], cs[505];
vector<int> ldk[10];
string create_gnome()
{
	string res = "";
	for (int i = 0; i < n; i++)
	{
		int w = rng()%m + 1;
		res += (char)(w + '0');
	}
	return res;
}

struct DATA
{
	string chromosome;
	int fitness;

	DATA()
	{
		chromosome = "";
		fitness = 0;
	}
	DATA(const string &s)
	{
		chromosome = s;
		for (int i = 0; i < n; i++) luu[s[i]-'0'] += wei[cs[i]];
		int re = 0; 
		for (int i = 1; i <= m; i++)
		{
			re = max(re, luu[i]); luu[i] = 0;
		}
		fitness = re;

	}

	bool operator < (const DATA &other) const
	{
		return fitness < other.fitness;
	}
};

string match(const DATA &a, const DATA &b)
{
	string res = "";
	for (int i = 0; i < n; i++)
	{
		double tt = rng()%101; tt /= 100;
		if (tt < 0.475)
		{
			res += a.chromosome[i];
		}
		else if (tt < 0.950)
		{
			res += b.chromosome[i];
		}
		else
		{
			int w = rng()%m + 1;
			res += (char)(w + '0');
		}
	}
	return res;
}

void solve() 
{
	vector<DATA> population, new_gen;
	int pop_size = 70;
	int RE = 2*oo + 5;
	string RES = "";
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> wei[i];
		cs[i] = i;
	}
	
	for (int adu = 0; adu < 2; adu++)
	{
		random_shuffle(cs, cs + n);
		for (int i = 0; i < pop_size; i++)
		{
			string gnome = create_gnome();
			population.pb(DATA(gnome));
		}
		 auto START_TIME = clock();
		while (ld(clock() - START_TIME) / (ld)CLOCKS_PER_SEC < TIME_LIMIT)
		{
			sort(ALL(population));

			if (population[0].fitness < RE)
			{
				RE = population[0].fitness;
				RES = population[0].chromosome;
			}

			int len = 10*pop_size/100;
			for (int i = 0; i < len; i++) new_gen.pb(population[i]);

			len = pop_size - len;
			for (int i = 0; i < len; i++)
			{
				int id = rng()%40, id1 = rng()%40;
				new_gen.pb(DATA(match(population[id], population[id1])));
			}
			population = new_gen; new_gen.clear();
		}
		population.clear();
	}
	for (int i = 0; i < n; i++)
	{
		ldk[RES[i] - '0'].pb(cs[i]);
	}

	for (int i = 1; i <= m; i++)
	{
		cout << (int)ldk[i].size() << " ";
		for (auto v : ldk[i]) cout << v << " ";
		cout << "\n";
	}
}

int main() 
{   
   	#ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
