// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int dp[13][13][13][13],map[13][13],n,tempx,tempy,tempz;
int main()
{
	scanf("%d%d%d%d",&n,&tempx,&tempy,&tempz);
	while(tempx!=0||tempy!=0||tempz!=0)
	{
		map[tempx][tempy]=tempz;
		scanf("%d%d%d",&tempx,&tempy,&tempz);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				for(int p=1;p<=n;p++)
				{
					dp[i][j][k][p]=max(max(dp[i-1][j][k-1][p],dp[i-1][j][k][p-1]),max(dp[i][j-1][k-1][p],dp[i][j-1][k][p-1]))+map[i][j]+map[k][p];
					if(i==k&&p==j)
						dp[i][j][k][p]-=map[i][j];
				}
	printf("%d",dp[n][n][n][n]);
	return 0;
}