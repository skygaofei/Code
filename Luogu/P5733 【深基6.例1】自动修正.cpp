#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define re register
#define maxn 10000005
using namespace std;
int main()
{
    char s[200];
    scanf("%s",s);
    for(re int i=0;i<strlen(s);++i)
        if(s[i]>='a'&&s[i]<='z')
            s[i]=(char)((int)s[i]-32);
    printf("%s",s);
    return 0;
}
