#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[501][501];
int dp[501][501];
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
int answer;


int solve(int x,int y)
{
	if(x==n-1 && y==m-1)
	{
		return 1;
	}
	
	if(dp[x][y]!=-1) return dp[x][y];
		
	dp[x][y]=0;
	
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0 && ny>=0 && nx<n && ny<m)
		{
			if(arr[nx][ny]<arr[x][y])
			{
				dp[x][y]+=solve(nx,ny);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);
	int tmp;
	memset(dp,-1,sizeof(dp));
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>tmp;
			arr[i][j]=tmp;
		}
	}
	
	
	
	cout<<solve(0,0);	
	
	return 0;
}
