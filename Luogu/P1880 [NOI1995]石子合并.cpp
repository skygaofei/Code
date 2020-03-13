#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 110
#define INF 999999999
using namespace std;
int dp[MAXN][MAXN][2];
int n,a[MAXN],maxx,minn;
int cost(int i ,int j)
{
    int ans=0;
    while(i<=j)
        ans+=a[i++];
    return ans;
}
void work()
{
    int l,i,j,k,c;
    for(i=1;i<=n;i++)
        dp[i][i][0]=dp[i][i][1]=0;
    for(l=2;l<=n;l++)
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            dp[i][j][0]=INF;
            dp[i][j][1]=-INF;
            c=cost(i,j);
            for(k=i; k<j; k++)
            {
                if(dp[i][k][0]+dp[k+1][j][0]+c<dp[i][j][0])
                    dp[i][j][0] = dp[i][k][0]+dp[k+1][j][0]+c;
                if(dp[i][k][1]+dp[k+1][j][1]+c>dp[i][j][1])
                    dp[i][j][1] = dp[i][k][1]+dp[k+1][j][1]+c;
            }
        }
    minn=min(minn,dp[1][n][0]);
    maxx=max(maxx,dp[1][n][1]);
}
int main()
{
    maxx=-INF;
    minn=INF;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    work();
    for(int i=2;i<=n;i++)
    {
        int last=a[1];
        for(int k=1;k<=n-1;k++)
            a[k]=a[k+1];
        a[n]=last;
        work();
    }
    cout<<minn<<endl<<maxx;
    return 0;
}