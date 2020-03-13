// luogu-judger-enable-o2
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
char a[20];
int ans;
int main()
{
//	freopen("title.in","r",stdin);
//	freopen("title.out","w",stdout);
	gets(a);
	for(int i=0;i<strlen(a);i++)
	  if(a[i]!=' '&&a[i]!='\n')
	    ans++;
	printf("%d",ans);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

