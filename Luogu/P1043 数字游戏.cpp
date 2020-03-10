#include<cstdio>
#include<algorithm>
#include<cstring>
#define oo 2147483647
using namespace std;
int anther_array_usd_to_dp[101][101][11],a_array_used_to_dp[101][101][11];
int a_wonderful_n,a_wonderful_m;
int Are_You_Ok[101];
int I_am_a_Mifan(int magic)
{
    return ((magic%10)+10)%10;
}
int main()
{
    scanf("%d %d",&a_wonderful_n,&a_wonderful_m);
    for (int i=1;i<=a_wonderful_n;i++)
    {
        scanf("%d",&Are_You_Ok[i]);
        Are_You_Ok[i+a_wonderful_n]=Are_You_Ok[i];
    }
    for (int i=1;i<=2*a_wonderful_n;i++)
        Are_You_Ok[i]+=Are_You_Ok[i-1];
    for (int l=1;l<=2*a_wonderful_n;l++)
        for (int r=l;r<=2*a_wonderful_n;r++)
            anther_array_usd_to_dp[l][r][1]=a_array_used_to_dp[l][r][1]=I_am_a_Mifan(Are_You_Ok[r]-Are_You_Ok[l-1]);
    for (int wonderful_huaji=2;wonderful_huaji<=a_wonderful_m;wonderful_huaji++)
        for (int huaji=1;huaji<=2*a_wonderful_n;huaji++)
            for (int magic_huaji=huaji+wonderful_huaji-1;magic_huaji<=2*a_wonderful_n;magic_huaji++)
                a_array_used_to_dp[huaji][magic_huaji][wonderful_huaji]=oo;
    for (int i=2;i<=a_wonderful_m;i++)
        for (int l=1;l<=2*a_wonderful_n;l++)
            for (int r=l+i-1;r<=2*a_wonderful_n;r++)
            {
                for (int k=l+i-2;k<r;k++)
                {
                    a_array_used_to_dp[l][r][i]=min (a_array_used_to_dp[l][r][i],a_array_used_to_dp[l][k][i-1]*I_am_a_Mifan(Are_You_Ok[r]-Are_You_Ok[k]));
                    anther_array_usd_to_dp[l][r][i]=max (anther_array_usd_to_dp[l][r][i],anther_array_usd_to_dp[l][k][i-1]*I_am_a_Mifan(Are_You_Ok[r]-Are_You_Ok[k]));
                }
            }
    int maxium=0,minnnnn=oo;
    for (int i=1;i<=a_wonderful_n;i++)
    {
        maxium=max(maxium,anther_array_usd_to_dp[i][i+a_wonderful_n-1][a_wonderful_m]);
        minnnnn=min(minnnnn,a_array_used_to_dp[i][i+a_wonderful_n-1][a_wonderful_m]);
    }
    printf("%d\n%d",minnnnn,maxium);
    return 0;
}
