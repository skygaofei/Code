// luogu-judger-enable-o2
//
//  main.cpp
//  单词方阵
//
//  Created by 高飞 on 2018/5/26.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int AWonderfulVariables;
char AAmazingMap[101][101],AAlsoAmazingMap[101][101],AScaryArray[8]={' ','y','i','z','h','o','n','g'};
bool ATerribleFlag;
void AFunnyFunction(int AGoodX,int AGoodY)
{
    if(AGoodX-6>=1&&AGoodY+6<=AWonderfulVariables)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX-i+1][AGoodY+i-1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX-i+1][AGoodY+i-1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodY+6<=AWonderfulVariables)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX][AGoodY+i-1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX][AGoodY+i-1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodX+6<=AWonderfulVariables&&AGoodY+6<=AWonderfulVariables)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX+i-1][AGoodY+i-1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX+i-1][AGoodY+i-1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodX+6<=AWonderfulVariables)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX+i-1][AGoodY]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX+i-1][AGoodY]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodX+6<=AWonderfulVariables&&AGoodY-6>=1)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX+i-1][AGoodY-i+1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX+i-1][AGoodY-i+1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodY-6>=1)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX][AGoodY-i+1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX][AGoodY-i+1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodX-6>=1&&AGoodY-6>=1)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX-i+1][AGoodY-i+1]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX+i-1][AGoodY-i+1]=AScaryArray[i];
        ATerribleFlag=0;
    }
    if(AGoodX-6>=1)
    {
        for(int i=1;i<=7;i++)
            if(AAmazingMap[AGoodX-i+1][AGoodY]!=AScaryArray[i])
                ATerribleFlag=1;
        if(ATerribleFlag==0)
            for(int i=1;i<=7;i++)
                AAlsoAmazingMap[AGoodX-i+1][AGoodY]=AScaryArray[i];
        ATerribleFlag=0;
    }
}
int main(){
    cin>>AWonderfulVariables;
    for(int i=1;i<=AWonderfulVariables;i++)
        for(int j=1;j<=AWonderfulVariables;j++)
            AAlsoAmazingMap[i][j]='*';
    for(int i=1;i<=AWonderfulVariables;i++)
        scanf("%s",AAmazingMap[i]+1);
    for(int i=1;i<=AWonderfulVariables;i++)
        for(int j=1;j<=AWonderfulVariables;j++)
            AFunnyFunction(i,j);
    for(int i=1;i<=AWonderfulVariables;i++)
    {
        for(int j=1;j<=AWonderfulVariables;j++)
            cout<<AAlsoAmazingMap[i][j];
        cout<<endl;
    }
    return 0;
}
