#include<bits/stdc++.h>
using namespace std;
bool a[10007]={0};
int main ()
{
    int i,j,l,m,x,y,ans(0);
    cin>>l>>m;
    fill(a,a+l+1,true); 
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        for(j=x;j<=y;j++)
        a[j]=false;
    }
    for(i=0;i<=l;i++)
    if(a[i]) ans++;
    cout<<ans<<endl;
    return 0;
}