#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<ctime>
#include<queue>
#include<sstream>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
int fa[20010], n, m, p, f1, f2;
int find(int x)
{
    /*if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];*/
    return fa[x]=(fa[x]==x)?x:find(fa[x]);
}
void merge(int a, int b)
{
    int t1, t2;
    t1 = find(a);
    t2 = find(b);
    if (t1 != t2)
        fa[t2] = t1;
    return;
}
bool judge(int a, int b)
{
    int t1, t2;
    t1 = find(a);
    t2 = find(b);
    if (t1 == t2)
        return true;
    return false;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
            merge(x, y);
        else if (z == 2)
        {
            if (judge(x, y))
                cout << "Y"<<endl;
            else
                cout << "N"<<endl;
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
