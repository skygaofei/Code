#include<bits/stdc++.h>
using namespace std;
int f[25][25][25];
int w(long a,long b,long c)
{
    if(a<=0||b<=0||c<=0)
    {
        return 1;
    }
    if(a>20||b>20||c>20)
    {
        return w(20,20,20);
    }
    if(f[a][b][c]>0)
        return f[a][b][c];
    else if(a<b&&b<c)
    {
        f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        return f[a][b][c];
    }
    else
    {
        f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
        return f[a][b][c];
    }
}
int main()
{
    //freopen("function.in","r",stdin);
    //freopen("function.out","w",stdout);
    long long a,b,c;
    while(true)
    {
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)
            return 0;
        else
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<endl;
    }
    //fclose(stdin);
    //fclose(stdout);
     return 0;
}
