#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define maxn 1005
#define re register
using namespace std;
char s[maxn];
int boy,girl; 
int main()
{
    scanf("%s",s);
    for(re int i=0;i<=strlen(s)-3;++i)
    {
        if(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y')
			boy++;
        if(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l')
			girl++;
    }
    printf("%d\n%d",boy,girl);
    return 0;
}