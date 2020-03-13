#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[4]={0,1,1};
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i;i++)
    {
    	f[2]=f[0];f[0]=f[1];f[1]=(f[1]+f[2])%n;
    	if(f[0]%n==0&&f[1]%n==1)
    		break;
	}
	printf("%d",i);
    return 0;
}