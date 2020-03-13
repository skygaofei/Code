// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int sum=0;
    sum+=a/5;
    sum+=b/10*3;
    sum+=c/2;
    cout<<sum;
    return 0;
}