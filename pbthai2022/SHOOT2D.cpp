#include<iostream>
#include<set>
#include<vector>
#include <algorithm>  

using namespace std;

#define fi first
#define se second
#define pb push_back

#define ALL(v) v.begin(), v.end()

set<pair<int,int>> sg[2][1600005];
pair<int, int> point, lu[200005];
int cnt = 0;
struct hehe
{
	int type, x, y;
} query[200005];

void update(bool ty, int id, int l, int r, int u, pair<int,int> val, bool ti = 0)
{
	if (ti) sg[ty][id].erase(val);
	else
	sg[ty][id].insert(val);
	if (l == r)
	{
		return;
	}
	int mid = (l + r)/2;
	if (u <= mid)
	update(ty, id * 2, l, mid, u, val, ti); 
	else
	update(ty, id * 2 + 1, mid + 1, r, u, val, ti);
}

int u, v;
int get(bool ty, int id, int l, int r)
{
	if (r < u || l > v) return -1;
	if (u <= l && r <= v)
	{
		pair<int,int> memay = {point.fi, 0};
		if (ty == 1)
		{
			auto vv =sg[ty][id].upper_bound(memay);
			if (vv == sg[ty][id].begin()) return -1;
			vv--;
			for (; ; vv--)
			{
				int v = (*vv).se;
				if (1ll*query[v].y*query[v].y > 1ll*(query[v].y - point.se)*(query[v].y - point.se) + 1ll*(query[v].x - point.fi)*(query[v].x - point.fi))
				{
					return v;
				}
				if (vv == sg[ty][id].begin()) break;
			}
		}
		else
		{
			for (auto vv = sg[ty][id].lower_bound(memay); vv != sg[ty][id].end(); vv++)
			{
				int v = (*vv).se;
				if (1ll*query[v].y*query[v].y > 1ll*(query[v].y - point.se)*(query[v].y - point.se) + 1ll*(query[v].x - point.fi)*(query[v].x - point.fi))
				{
					return v;
				}
			}
		}
		return -1;
	}
	int mid = (l + r)/2;
	int luu = get(ty, id*2, l, mid);
	if (luu != -1) return luu;
	return	get(ty, id * 2 + 1, mid + 1, r);
	
}

void solve() 
{
	int q;
	vector<long long> diff;
	int ahi = -1e9, ahu = 1e9;
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &query[i].type, &query[i].x, &query[i].y);
		if (query[i].type == 2)
		{
			ahi = max(ahi, query[i].x);
			ahu = min(ahu, query[i].x);
			diff.pb(query[i].x);
		}
	}
	for (int i = 1; i <= q; i++)
	if (query[i].type == 1)
	{
		if (query[i].x >= ahu) diff.pb(query[i].x - query[i].y);
		if (query[i].x <= ahi) diff.pb(query[i].x + query[i].y);
	}
//	cout << ahi << " " << ahu << endl;
	sort(ALL(diff)); diff.resize(unique(ALL(diff)) - diff.begin());
	//for (auto v : diff) cout << v << " "; cout << endl;
	int n = (int)diff.size();

	for (int i = 1; i <= q; i++)
	if (query[i].type == 1)
	{
		lu[i] = {lower_bound(ALL(diff), query[i].x - query[i].y) - diff.begin() + 1,
		lower_bound(ALL(diff), query[i].x + query[i].y) - diff.begin() + 1};
		pair<int,int> memay = {query[i].x, i};
		if (query[i].x >= ahu)
		update(0, 1, 1, n, lu[i].fi, memay);
		if (query[i].x <= ahi)
		update(1, 1, 1, n, lu[i].se, memay);	
	}
	else
	{
		int id = lower_bound(ALL(diff), query[i].x) - diff.begin() + 1;
		point = {query[i].x, query[i].y};
		int luu = -1;
		u = 1; v = id - 1;
		if (id > 1) luu = get(0, 1, 1, n);
		
		u = id + 1; v = n;
		if (luu == -1 && id < n) luu = get(1, 1, 1, n);
		

		if (luu != -1)
		{
			pair<int,int> memay = {query[luu].x, luu};
			if (query[luu].x >= ahu)
			update(0, 1, 1, n, lu[luu].fi, memay, 1);
			if (query[luu].x <= ahi)
			update(1, 1, 1, n, lu[luu].se, memay, 1);
		}
		cout << luu << "\n";
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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
