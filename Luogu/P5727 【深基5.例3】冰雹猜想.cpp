#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#define re register
#define maxn 10000005
using namespace std;
int main()
{
    vector<int> ans;
    int n;
    scanf("%d",&n);
    while(n!=1)
    {
        ans.push_back(n);
        if(n%2)
            n=n*3+1;
        else
            n>>=1;
    }
    printf("1");
    for(re int i=ans.size()-1;i>=0;--i)
        printf(" %d",ans[i]);
    return 0;
}
