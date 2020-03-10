#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int answer=0,s=0,len;
string str;
int main()
{
    cin>>str;
    len=str.length();
    for(register int i=0;i<len;++i)
    {
        if(str[i]=='M') 
            s++;
        if(str[i]=='F'&&s>0)
            answer=max(answer+1,s);
    }
    printf("%d",answer);
    return 0;
}