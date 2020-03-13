//
//  main.cpp
//  em..
//
//  Created by 高飞 on 2018/10/3.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define maxn 100005
using namespace std;
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
int s,n,m,dis[maxn],w[maxn];
vector<int> son[maxn],v[maxn];
void Set(int prt,int to,int d)
{
    son[prt].push_back(to),v[prt].push_back(d);
}
struct Node
{
    int x,dis;
    bool operator < (const Node &a)const
    {
        return dis>a.dis;
    }
};priority_queue<Node> q;
int vis[maxn],tim=0;
void Dijkstra(int S)
{
    for(int i=1;i<=n;i++)
        dis[i]=2147483647;
    dis[S]=0,tim++,q.push((Node){S,0});
    while(!q.empty())
    {
        Node prt=q.top();q.pop();
        int rt=prt.x;
        if(vis[rt]==tim)
            continue;
        vis[rt]=tim;
        for(int i=0;i<son[rt].size();i++)
        {
            int to=son[rt][i];
            if(dis[to]>dis[rt]+v[rt][i])
                dis[to]=dis[rt]+v[rt][i],q.push((Node){to,dis[to]});
        }
    }
}
int main()
{
    read(n),read(m),read(s);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        read(x),read(y),read(z);
        Set(x,y,z);
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)
        printf("%d ",dis[i]);
    return 0;
}
