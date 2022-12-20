#include<bits/stdc++.h>
using namespace std;
int n,dd[50005];
vector<int> ds[100005];
struct edge {
    int u, v, w;
};

vector<edge> edges;
bool cmp(const edge &a, const edge &b) {
    return a.w < b.w;
}
#define N 50005
int cha[N], hang[N];
int find(int u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}
bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v]=u;
    return true;
}

int find() {
    sort(edges.begin(), edges.end(), cmp);
    for (int i=1; i<=n; i++) {
        cha[i] = i;
        hang[i] = 0;
    }
	long long mst_weight = 0;
    for (edge &e: edges) {
        if (join(e.u, e.v)) {
            mst_weight += e.w;
        }
    }
    cout << mst_weight;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int i,j,z,m,goc,ssl; bool kt=false;
	cin>>n;
	for (i=1;i<=n;i++) 
	{
		cin>>m;
		if (m==0) kt=true;
		 ds[0].push_back(i);
		for (j=1;j*j<=m;j++)
		if (m%j==0)
		{
			ds[j].push_back(i);
			if (j*j==m) continue;
			ds[m/j].push_back(i);
		}
	}
	int w=(kt==false);
	for (i=1e5;i>=w;i--)
	  if (ds[i].size()>=2)
	  {
	  	goc=ds[i][0]; 
		  for (j=1;j<ds[i].size();j++)
		   {
		   	edges.push_back({goc,ds[i][j],123456-i});
		   }
	  }
	  find();
 } 
