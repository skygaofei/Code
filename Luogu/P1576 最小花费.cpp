//
//  main.cpp
//  最小花费
//
//  Created by 高飞 on 2018/8/6.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int n,m,A,B;
struct node
{
    int num;
    double dis;
};
vector<node> son[2005];
struct Node
{
    int num;double dis;
    bool operator < (const Node &a)const
    {
        return a.dis>dis;
    }
}temp;priority_queue<Node> q;
bool vis[2005];
double dis[2005];
void Dijkstra()
{
    temp.num=A;
    temp.dis=1;
    q.push(temp);
    
    while(!q.empty())
    {
        Node prt=q.top();q.pop();
        int rt=prt.num;
        if(vis[rt])
            continue;
        vis[rt]=true;
        for(int i=0;i<son[rt].size();i++)
        {
            int to=son[rt][i].num;
            double temp_num=son[rt][i].dis;
            if((!vis[to])&&(dis[to]<dis[rt]*temp_num))
            {
                dis[to]=dis[rt]*temp_num;
                temp.num=to;
                temp.dis=dis[to];
                q.push(temp);
            }
        }
    }
}
int main()
{
    node tmp;
    scanf("%d%d",&n,&m);
    memset(dis,-0x3f,sizeof(dis));
    int x,y;
    double z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%lf",&x,&y,&z);
        tmp.num=y;
        tmp.dis=1-z/100;
        son[x].push_back(tmp);
        tmp.num=x;
        son[y].push_back(tmp);
    }
    scanf("%d%d",&A,&B);
    dis[A]=1;
    Dijkstra();
    printf("%.8lf",100/dis[B]);
    return 0;
}
