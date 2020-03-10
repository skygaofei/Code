//
//  CF1B Spreadsheets.cpp
//  Algorithm
//
//  Created by skygao on 2019/10/10.
//  Copyright © 2019 skygao. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define re register
using namespace std;
int n,k;
bool flag;
string s;
int r,c,p;
int tmp[10];
inline int _pow(int a,int b)
{
    if(b==0)
        return 1;
    int res=a;
    for(re int i=1;i<b;++i)
        res*=a;
    return res;
}
inline bool check(string x)
{
    bool flag=false;
    for(re int i=0;i<x.length()-1;i++)
        if(isdigit(x[i])&&!isdigit(x[i+1]))
            flag=true;
    return flag;
}
int main()
{
    scanf("%d",&n);
    for(re int t=1;t<=n;++t)
    {
        cin>>s;
        flag=check(s);
        if(!flag)
        {
            k=r=c=p=0;
            while(!isdigit(s[k])) k++;
            k--;
            for(re int i=k;i>=0;--i)
                c+=(_pow(26,p)*(s[i]-'A'+1)),p++;
            k++;
            while(k<s.length())
                r=r*10+s[k++]-'0';
            printf("R%dC%d\n",r,c);
        }
        else
        {
            k=r=c=0;
            k=1;
            while(isdigit(s[k]))
                r=r*10+s[k++]-'0';
            k++;
            while(isdigit(s[k])&&k<s.length())
                c=c*10+s[k++]-'0';
            k=0;
            while(c!=0)
            {
                k++;
                if(c%26!=0)
                    tmp[k]=c%26,c/=26;
                else
                    tmp[k]=26,c=c/26-1;
            }
            for(re int i=k;i>=1;--i)
                printf("%c",tmp[i]+'A'-1);
            printf("%d\n",r);
        }
    }
    return 0;
}
