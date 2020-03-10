//
//  CF510C Fox And Names.cpp
//  7.21集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define maxn 105
#define re register
using namespace std;
char s[maxn][maxn];
queue<char> q;
vector<char> son[maxn+300];
int in[maxn+300];
void addedge(char x,char y)
{
    son[x].push_back(y);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%s",s[i]);
    for(re int i=1;i<n;++i)
    {
        bool flag=false;
        for(re int k=0;k<min(strlen(s[i]),strlen(s[i+1]));++k)
        {
            if(s[i][k]==s[i+1][k])
                continue;
            flag=true;
            addedge(s[i][k],s[i+1][k]);
            in[s[i+1][k]]++;
            break;
        }
        if(flag==0&&strlen(s[i+1])<strlen(s[i]))
        {
            printf("Impossible");
            return 0;
        }
    }
    for(re char i='a';i<='z';++i)
        if(in[i]==0)
            q.push(i);
    vector<char> ans;
    while(!q.empty())
    {
        int prt=q.front();q.pop();
        for(re int i=0;i<son[prt].size();++i)
        {
            int rt=son[prt][i];
            in[rt]--;
            if(in[rt]==0)
                q.push(rt);
        }
        ans.push_back(prt);
    }
    if(ans.size()!=26)
    {
        printf("Impossible");
        return 0;
    }
    for(re int i=0;i<ans.size();++i)
        printf("%c",ans[i]);
    return 0;
}
