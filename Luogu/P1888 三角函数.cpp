// luogu-judger-enable-o2
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[4];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    for(int i=1;i<=a[i];i++)
    {
        if(a[1]%i==0&&a[3]%i==0)
        {
            a[1]/=i;
            a[3]/=i;
        }
    }
    cout<<a[1]<<'/'<<a[3];
    return 0;
}