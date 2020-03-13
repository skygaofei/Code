//
//  对称二叉树.cpp
//  algorithm
//
//  Created by 高飞 on 2018/11/24.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#define mem(a,b) memset(a,b,sizeof(a));
#define maxn 1000005
#define re register
using namespace std;
int n,cnt;
int node[maxn][2], val[maxn];
bool book[100][100];
int ans = -0x7fffffff;
queue<int> root;
bool flag;
void dfs(int x, int y)
{
    if (!flag)
        return;
    if(book[x][y])
        return ;
    if (val[x] != val[y])
    {
        book[x][y]=flag = false;
        return;
    }
    cnt += 2;
    if (node[x][0] != -1)
    {
        if (node[y][1] != -1)
            dfs(node[x][0], node[y][1]);
        else
        {
            book[x][y]=flag = false;
            return;
        }
    }
    else if (node[y][1] != -1)
    {
        book[x][y]=flag = false;
        return;
    }
    if (node[x][1] != -1)
    {
        if (node[y][0] != -1)
            dfs(node[x][1], node[y][0]);
        else
        {
            book[x][y]=flag = false;
            return;
        }
    }
    else if (node[y][0] != -1)
    {
        book[x][y]=flag = false;
        return;
    }
    book[x][y]=true;
}
bool judge(int root)
{
    cnt = 1, flag = true;
    if (node[root][0] == -1 && node[root][1] == -1)
        return true;
    if (node[root][0] != -1 && node[root][1] != -1)
    {
        dfs(node[root][0], node[root][1]);
        return flag;
    }
    else
        return false;
}
int main()
{
    scanf("%d",&n);
    for (re int i = 1; i <= n; i++)
        scanf("%d",&val[i]);
    bool Full = true;
    for (re int i = 1; i <= n; i++)
    {
        scanf("%d%d",&node[i][0],&node[i][1]);
        if (node[i][0] == -1 || node[i][1] == -1)
            Full = false;
    }
    if (Full)
    {
        printf("%d",cnt);
        return 0;
    }
    root.push(1);
    while (!root.empty())
    {
        if (judge(root.front()))
        {
            if (cnt > ans)
                ans = cnt;
        }
        if (node[root.front()][0] != -1)
            root.push(node[root.front()][0]);
        if (node[root.front()][1] != -1)
            root.push(node[root.front()][1]);
        root.pop();
    }
    printf("%d",ans);
    return 0;
}
