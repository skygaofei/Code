//
//  滑雪.cpp
//  刷题专用
//
//  Created by 高飞 on 2018/10/27.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m;
int nex[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int a[105][105];
int book[105][105];
bool inmap(int x,int y)
{
    if(x>=0&&x<=n-1&&y>=0&&y<=m-1)
        return true;
    return false;
}
int dfs(int x,int y)
{
    int tx,ty,d=0,u=0,l=0,r=0;
    if(book[x][y])
        return book[x][y];
    tx=x+nex[0][0];
    ty=y+nex[0][1];
    if(inmap(tx,ty))
        if(a[x][y]>a[tx][ty])
            u=dfs(tx,ty);
    tx=x+nex[1][0];
    ty=y+nex[1][1];
    if(inmap(tx,ty))
        if(a[x][y]>a[tx][ty])
            r=dfs(tx,ty);
    tx=x+nex[2][0];
    ty=y+nex[2][1];
    if(inmap(tx,ty))
        if(a[x][y]>a[tx][ty])
            d=dfs(tx,ty);
    tx=x+nex[3][0];
    ty=y+nex[3][1];
    if(inmap(tx,ty))
        if(a[x][y]>a[tx][ty])
            l=dfs(tx,ty);
    book[x][y]=max(max(u,d),max(l,r))+1;
    return book[x][y];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    int ans=-0x7fffffff;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            ans=max(ans,dfs(i,j));
    cout<<ans;
    return 0;
}
