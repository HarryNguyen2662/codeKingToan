#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<iostream>
#include<math.h>

using namespace std;


int a[100005], mx[350][100005], be[350], cnt[350];
bool ok[100005];
int readInt () {

	int result = 0;
	char ch;

	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}

		return result;
}

void solve() 
{
	int n, k;
	// n = readInt(); k = readInt();
	cin >> n >> k;

	int sz = 330;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	a[n] = -1e9;

	int bl = (n - 1)/sz;

	for (int i = 0; i <= bl; i++)
	{
		int l =  i*sz, r =min(n - 1, (i + 1)*sz -1);
		for (int j = 0; j < k; j++) mx[i][j] = n;
		for (int j = l; j <= r; j++)
		{
			if (a[mx[i][j%k]] < a[j]) mx[i][j%k] = j;
		}

		be[i] = mx[i][0];
	}

	for (int i = 1; i <= n; i++)
	{
		int re = 0;
		for (int j = 0; j <= bl; j++)
		{
			//cout << i << " " << be[re] << endl;
			if (a[be[re]] < a[be[j]]) re = j; 
		}

		// cout << re<< endl;
		cout << a[be[re]] << " ";
		//cout << a[re] << " ";


		for (int j = re + 1; j <= bl; j++)
		{
			cnt[j]++; if (cnt[j] >= k) cnt[j] -= k;
			 be[j] = mx[j][cnt[j]];
		}

		int l = re*sz, r = min(n - 1, (re + 1)*sz - 1);
		int c = 0;

		for(int j = l; j <= r; j++)
		if (ok[j] == false)
		{
			int w = (j - c)%k;
			mx[re][w] = n;
		} else c++;
		
		ok[be[re]] = true; c = 0;
	 	
	 	for(int j = l; j <= r; j++)
		if (ok[j] == false)
		{
			int w = (j - c)%k;
			if (a[mx[re][w]] < a[j]) mx[re][w] = j;
		} else c++;

	 	be[re] = mx[re][cnt[re]];
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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}