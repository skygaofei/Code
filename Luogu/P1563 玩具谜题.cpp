#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n,m,x,y;
bool way[100005];
string name[100005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>way[i]>>name[i];
    }
    int s=0;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if(!x)
        {
            if(!way[s])
                s=(s+n-y)%(n);
            else
                s=(s+y)%(n);
        }
        else
        {
            if(!way[s])
                s=(s+y)%(n);
            else
                s=(s+n-y)%(n);
        }
    }
    cout<<name[s];
    return 0;
}
