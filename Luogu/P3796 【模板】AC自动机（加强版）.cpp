//
//  P3796 【模板】AC自动机（加强版）.cpp
//  Algorithm
//
//  Created by SkyGao on 2020/3/10.
//  Copyright © 2020 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#define maxn 200005
#define re register
using namespace std;
int n;
int trie[maxn][26],cntt,maxx;
int fail[maxn],sum[maxn];
int book[maxn],que[maxn],h;
string c[155];
vector<int> pp;
inline int insert(string s)
{
    int pos=0;
    for(re int i=0;i<s.length();++i)
    {
        if(trie[pos][s[i]-'a']==0)
            trie[pos][s[i]-'a']=++cntt;
        pos=trie[pos][s[i]-'a'];
    }
    return pos;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
        if(n==0)
            return 0;
        memset(trie,0,sizeof(trie));
        memset(fail,0,sizeof(fail));
        memset(sum,0,sizeof(sum));
        memset(book,0,sizeof(book));
        h=cntt=maxx=0;pp.clear();
        for(re int i=0;i<n;++i)
        {
            cin>>c[i];
            book[i]=insert(c[i]);
        }
        que[h++]=0;
        for(re int i=0;i<h;++i)
        {
            int u=que[i];
            for(re int j=0;j<26;++j)
            {
                if(trie[u][j])
                {
                    fail[trie[u][j]]=u?trie[fail[u]][j]:0;
                    que[h++]=trie[u][j];
                }
                else
                    trie[u][j]=trie[fail[u]][j];
            }
        }
        cin>>c[n];
        for(re int p=0,i=0;c[n][i];++i)
            p=trie[p][c[n][i]-'a'],sum[p]++;
        for(re int i=cntt;i>0;--i)
            sum[fail[que[i]]]+=sum[que[i]];
        for(re int i=0;i<n;++i)
        {
            if(sum[book[i]]>maxx)
                maxx=sum[book[i]],pp.clear(),pp.push_back(i);
            else if(sum[book[i]]==maxx)
                pp.push_back(i);
        }
        cout<<maxx<<endl;
        for(re int i=0;i<pp.size();++i)
            cout<<c[pp[i]]<<endl;
    }
    return 0;
}
