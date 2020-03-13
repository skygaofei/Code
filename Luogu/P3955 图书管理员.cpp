// luogu-judger-enable-o2
#include<iostream>
using namespace std;
long long Pow(long long x,long long y)
{
    long long sum=x;
    for(long long i=2;i<=y;i++)
        sum*=x;
    return sum;
}
struct reader
{
    int l;
    int num;
}read[1010];
int book[1010];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>book[i];
    for(int i=1;i<=q;i++)
        cin>>read[i].l>>read[i].num;
    for(int i=1;i<=q;i++)
    {
        int ans=999999999;
        for(int j=1;j<=n;j++)
        {
            if(book[j]%Pow(10,read[i].l)==read[i].num)
                if(ans>book[j])
                    ans=book[j];
        }
        if(ans!=999999999)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}