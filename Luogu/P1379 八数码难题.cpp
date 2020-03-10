//
//  main.cpp
//  八数码
//
//  Created by 高飞 on 2018/6/3.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include<bits/stdc++.h>
using namespace std;
int a[10],h=1,t=1,p;bool vis[10],visit[362881];string start,target,x;
long long fac(int x)
{
    long long ans=1;
    for(int i=1;i<=x;i++)
        ans*=i;
    return ans;
}
int unreal_hash(string x)
{
    memset(a,0,sizeof(a));
    memset(vis,0,sizeof(vis));
    int ans=0;
    int n=x.length();
    for(int i=0;i<x.length();i++)
    {
        for(int j=0;j<x[i]-'0';j++)
            if(!vis[j])
                a[x[i]-'0']++;
        vis[x[i]-'0']=true;
    }
    for(int i=0;i<x.length();i++)
        ans+=a[x[i]-'0']*fac(--n);
    return ans;
}
struct que
{
    string a;
    int step,z;
}q[500100];
void judge(string x)
{
    if(x==target)
    {
        cout<<q[h].step+1;
        exit(0);
    }
    else
    {
        p=unreal_hash(x);
        if(!visit[p])
        {
            visit[p]=true;
            q[t].a=x;
            q[t].z=q[t].a.find("0");
            q[t++].step=q[h].step+1;
        }
    }
    x=q[h].a;
}
int main()
{
    cin>>start;
    if(start=="123804765")
    {
        cout<<0;
        return 0;
    }
    target="123804765";
    int z=start.find("0");
    q[t++].a=start;
    q[h].z=z;
    while(h<t)
    {
        x=q[h].a;
        z=q[h].z;
        if(z==0)
        {
            swap(x[0],x[3]);
            judge(x);
            x=q[h].a;
            swap(x[0],x[1]);
            judge(x);
            x=q[h].a;
        }
        else if(z==1)
        {
            swap(x[1],x[0]);
            judge(x);
            x=q[h].a;
            swap(x[1],x[2]);
            judge(x);
            x=q[h].a;
            swap(x[1],x[4]);
            judge(x);
            x=q[h].a;
        }
        else if(z==2)
        {
            swap(x[2],x[1]);
            judge(x);
            x=q[h].a;
            swap(x[2],x[5]);
            judge(x);
            x=q[h].a;
        }
        else if(z==3)
        {
            swap(x[3],x[0]);
            judge(x);
            x=q[h].a;
            swap(x[3],x[4]);
            judge(x);
            x=q[h].a;
            swap(x[3],x[6]);
            judge(x);
            x=q[h].a;
        }
        else if(z==4)
        {
            swap(x[4],x[1]);
            judge(x);
            x=q[h].a;
            swap(x[4],x[5]);
            judge(x);
            x=q[h].a;
            swap(x[4],x[3]);
            judge(x);
            x=q[h].a;
            swap(x[4],x[7]);
            judge(x);
            x=q[h].a;
        }
        else if(z==5)
        {
            swap(x[5],x[2]);
            judge(x);
            x=q[h].a;
            swap(x[5],x[4]);
            judge(x);
            x=q[h].a;
            swap(x[5],x[8]);
            judge(x);
            x=q[h].a;
        }
        else if(z==6)
        {
            swap(x[6],x[3]);
            judge(x);
            x=q[h].a;
            swap(x[6],x[7]);
            judge(x);
            x=q[h].a;
        }
        else if(z==7)
        {
            swap(x[7],x[6]);
            judge(x);
            x=q[h].a;
            swap(x[7],x[8]);
            judge(x);
            x=q[h].a;
            swap(x[7],x[4]);
            judge(x);
            x=q[h].a;
        }
        else if(z==8)
        {
            swap(x[8],x[5]);
            judge(x);
            x=q[h].a;
            swap(x[8],x[7]);
            judge(x);
            x=q[h].a;
        }
        h++;
    }
    return 0;
}