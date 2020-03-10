#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[11];
    int zs=0,mod,c[11]={0},jianhao[14]={0};
    for(int i=1,j=1;i<=10,j<=13;i++,j++)
    {
        cin>>a[i];
        if (a[i]=='-'){
        jianhao[j]=1;i--;}
}
    for(int i=1;i<=10;i++)
    {
        c[i]=a[i]-48; 
        if(a[i]=='X')c[i]-=30; 
        }
    for(int i=1;i<=9;i++)
    {zs+=c[i]*i;} 
    mod=zs%11; 
    if(mod==c[10])cout<<"Right"<<endl; 
    else 
    {
        for(int i=1,j=1;i<=9,j<=13;i++,j++)
        {if(jianhao[j]==1)cout<<'-',j++; 
        if (i!=10)cout<<c[i]; 
        }
        if(mod==10)cout<<'X'; //打印识别码 
        else cout<<mod;
        }
}