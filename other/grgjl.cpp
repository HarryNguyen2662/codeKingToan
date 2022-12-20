#include <bits/stdc++.h>
#include <queue>
using namespace std;

int n,m,x1,x2,y1,y2,ans;
int move1[8]={2, 1, -1 -2, -2, -1, 1, 2};
int move2[8]={1, 2, 2, 1, -1, -2, -2, -1};
int danhdau[2001][2001];
queue <int>a;
queue <int>b;
queue <int>dem;

bool kt(int x, int y)
{
	return x > 0 && y > 0 && x <= n && y <= m;
}

void BFS(int x, int y)
{
	a.push(x);
	b.push(y);
	dem.push(0);
	danhdau[x][y]=-1;
	while (!a.empty() || !b.empty() || dem.empty())
	{
		int a1=a.front();
		int b1=b.front();
		int ans=dem.front();
		a.pop();
		b.pop();
		dem.pop();
		for (int i=0; i<8; i++)
		{
			int nexta= a1+ move1[i];
			int nextb= b1+ move2[i];
			if (kt(nexta, nextb) && (danhdau[nexta][nextb]==0)) 
				{
					danhdau[nexta][nextb]=-1;
					a.push(nexta);
					b.push(nextb);
					dem.push(ans+1);
					if (nexta==x2 && nextb==y2)
					{
						cout<<dem.front();
						return;
					}
				}
		}
	}
	cout <<"-1";
	return;
}

int main()
{
	freopen("lololoin.txt", "r", stdin);
	cin >>n >>m;
	cin >>x1 >>y1;
	cin >>x2 >>y2;
	BFS(x1,y1);
}