//
//  CF1027D Mouse Hunt.cpp
//  7.21集训
//
//  Created by skygao on 2019/7/21.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#define maxn 200005
#define re register
using namespace std;
int n;
int c[maxn],a[maxn];
int vis[maxn];
int pos,tim;
stack<int> st;
bool flag;
inline void dfs(int x)
{
    if(!a[x])
        return;
    tim++;
    if(tim>vis[x]&&vis[x]!=0)
    {
        flag=true;
        pos=x;
        a[x]=0;
        vis[x]=0;
        return ;
    }
    st.push(x);
    vis[x]=tim;
    dfs(a[x]);
    vis[x]=a[x]=0;
}
int main()
{
    int anss=0,ans;
    scanf("%d",&n);
    for(re int i=1;i<=n;++i)
        scanf("%d",&c[i]);
    for(re int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(re int i=1;i<=n;++i)
    {
        flag=false;
        dfs(i);
        if(flag)
        {
            ans=0x7fffffff;
            if(!st.empty())
            {
                while(!st.empty()&&st.top()!=pos)
                {
                    ans=min(ans,c[st.top()]);
                    st.pop();
                }
                if(!st.empty())
                    ans=min(ans,c[st.top()]);
                anss+=ans;
            }
        }
        while(!st.empty())
            st.pop();
    }
    printf("%d",anss);
    return 0;
}
