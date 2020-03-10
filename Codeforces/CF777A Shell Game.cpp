#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int i,j,k,m,n;
int a[51][51]={
{0,1,2},
{1,0,2},
{1,2,0},
{2,1,0},
{2,0,1},
{0,2,1},
{0,1,2}};
int main()
{
    scanf("%d%d",&n,&m);
    n=n%6;
    printf("%d",a[n][m]);
    return 0;
}