// luogu-judger-enable-o2
//
//  main.cpp
//  USACO Stall Reservations
//
//  Created by 高飞 on 2018/8/8.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define maxn 50005
using namespace std;
int n,visit[maxn],counter=0;
struct Cow
{
    int start,end,index;
}cow[maxn];
struct Num
{
    int x;
    bool operator < (const Num &a) const
    {
        return cow[x].end>cow[a.x].end;
    }
};
bool cmp(Cow a,Cow b)
{
    return a.start<b.start;
}
priority_queue<Num,vector<Num> > q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&cow[i].start,&cow[i].end);
        cow[i].index=i;
    }
    sort(cow+1,cow+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        Num k;
        k.x=i;
        if(!q.empty())
        {
            Num p=q.top();
            if(cow[p.x].end>=cow[i].start)
            {
                counter++;
                q.push(k);
                visit[cow[i].index]=counter;
            }
            else
            {
                q.pop();
                q.push(k);
                visit[cow[i].index]=visit[cow[p.x].index];
            }
        }
        else
        {
            q.push(k);
            counter++;
            visit[cow[i].index]=counter;
        }
    }
    printf("%d\n",counter);
    for(int i=1;i<=n;i++)
        printf("%d\n",visit[i]);
    return 0;
}
