//
//  main.cpp
//  robot
//
//  Created by 高飞 on 2018/10/2.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#define maxn 55
using namespace std;
struct que
{
    int x,y,dir;
}q[10005];
int n,m,ans_time[maxn][maxn][4],sx,sy,tx,ty,l,r;
int _map[maxn][maxn];
bool vis[maxn][maxn][4];
int turnleft(int x)
{
    return (x-1+4)%4;
}
int turnright(int x)
{
    return (x+1)%4;
}
int gox[4]={0,1,0,-1};
int goy[4]={1,0,-1,0};
bool judge(int x,int y)
{
    if(x>=n||y>=m||x<=0||y<=0)
        return false;
    else
        return !(_map[x][y]|_map[x+1][y]|_map[x][y+1]|_map[x+1][y+1]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&_map[i][j]);
    char dir1[2];
    scanf("%d%d%d%d%s",&sx,&sy,&tx,&ty,dir1);
    l=0;r=0;
    q[++r].x=sx;
    q[r].y=sy;
    if(dir1[0]=='E')
        q[r].dir=0;
    else if(dir1[0]=='S')
        q[r].dir=1;
    else if(dir1[0]=='W')
        q[r].dir=2;
    else
        q[r].dir=3;
    vis[sx][sy][q[1].dir]=1;
    while(l<r)
    {
        int x=q[++l].x,y=q[l].y,dir=q[l].dir;
        int t=turnleft(dir);
        if(!vis[x][y][t])
        {
            vis[x][y][t]=true;
            ans_time[x][y][t]=ans_time[x][y][dir]+1;
            q[++r].x=x;
            q[r].y=y;
            q[r].dir=t;
        }
        t=turnright(dir);
        if(!vis[x][y][t])
        {
            vis[x][y][t]=true;
            ans_time[x][y][t]=ans_time[x][y][dir]+1;
            q[++r].x=x;
            q[r].y=y;
            q[r].dir=t;
        }
        for(int i=1;i<=3;i++)
        {
            int px=x+gox[dir]*i;
            int py=y+goy[dir]*i;
            if(judge(px,py))
            {
                if(!vis[px][py][dir])
                {
                    vis[px][py][dir]=true;
                    ans_time[px][py][dir]=ans_time[x][y][dir]+1;
                    q[++r].x=px;
                    q[r].y=py;
                    q[r].dir=dir;
                }
            }
            else
                break;
        }
    }
    int finans=0x3f3f3f3f;
    for(int i=0;i<=3;i++)
        if(vis[tx][ty][i])
            finans=min(finans,ans_time[tx][ty][i]);
    if(finans==0x3f3f3f3f)
        printf("-1");
    else
        printf("%d",finans);
    return 0;
}
