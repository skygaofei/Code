//
//  main.cpp
//  滑动窗口
//
//  Created by 高飞 on 2018/12/22.
//  Copyright © 2018 高飞. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <deque>
#define maxn 1000005
using namespace std;
int a[maxn],Min[maxn],Max[maxn];
int n,k;
void getmin(){
    deque<int> q;
    q.push_back(1);
    Min[1]=a[1];
    for(register int i=2;i<=n;++i){
        while(!q.empty()&&(a[i]<a[q.back()]))
            q.pop_back();
        q.push_back(i);
        while(!q.empty()&&(q.front()<i-k+1))
            q.pop_front();
        Min[i]=a[q.front()];
    }
}
void getmax(){
    deque<int> q;
    q.push_back(1);
    Max[1]=a[1];
    for(register int i=2;i<=n;++i){
        while((!q.empty())&&(a[i]>a[q.back()]))
            q.pop_back();
        q.push_back(i);
        while((!q.empty())&&(q.front()<i-k+1))
            q.pop_front();
        Max[i]=a[q.front()];
    }
}
int main() {
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    getmin(),getmax();
    for(register int i=k;i<=n;++i)
        printf("%d ",Min[i]);
    printf("\n");
    for(register int i=k;i<=n;++i)
        printf("%d ",Max[i]);
    return 0;
}
