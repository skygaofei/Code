#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,s;
    scanf("%d",&t);
    while(t--)
    {
        s=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
           scanf("%d",&x),s^=x;
        if(s)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}