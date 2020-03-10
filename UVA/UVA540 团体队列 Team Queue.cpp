#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#define maxn 1005
#define re register
using namespace std;
queue<int> q[maxn];
unordered_map<int, int> v;
int t;
void solution() 
{
    int n, num;
    v.clear();
    for (re int i = 0; i < maxn; ++i)
        while (!q[i].empty())
            q[i].pop();
    for (re int i = 1; i <= t; ++i)
    {
        scanf("%d", &n);
        for (re int j = 1; j <= n; ++j)
        {
            scanf("%d", &num);
            v[num] = i;
        }
    }
    string s; 
    while (cin >> s && s != "STOP") 
    {
        if (s == "ENQUEUE") 
        {
            scanf("%d", &num);
            q[v[num]].push(num);
            if (q[v[num]].size() == 1) 
                q[0].push(v[num]);
        }
        else if (s == "DEQUEUE") 
        {
            num = q[q[0].front()].front(); 
            q[q[0].front()].pop();
            printf("%d\n", num);
            if (q[v[num]].empty()&&!q[0].empty()) 
                q[0].pop();
        }
    }
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    int s = 0;
    while (cin >> t)
    {
        if (t == 0)
            return 0;
        printf("Scenario #%d\n", ++s), solution(), printf("\n");
    }
    return 0;
}