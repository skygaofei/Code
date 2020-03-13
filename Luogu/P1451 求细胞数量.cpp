#include<bits/stdc++.h>
using namespace std;  
const int next[4][2]={{1,0},{0,1},{-1,0},{0,-1}};    
int m,n,sum=0;  
bool a[100][100];  
void in()  
{  
    string s;
    cin>>m>>n;
    for(int i=1;i<=m;++i)  
    {  
        cin>>s;
        for(int j=0;j<n;j++)
         	if(s[j]=='0')
		  		a[i][j+1]=0;
          	else
		  		a[i][j+1]=1;
    }
}
void BFS(int sx,int sy)  
{  
    queue<int> x,y;
    int tx,ty;
    sum++;
    x.push(sx);
    y.push(sy);
    a[sx][sy]=0;
    while(!x.empty())
    {
        for(int k=0;k<4;k++)
        {
            tx=x.front()+next[k][0];
            ty=y.front()+next[k][1];
            if(tx>0&&tx<=m&&ty>0&&ty<=n&&a[tx][ty])
            {
                x.push(tx);
                y.push(ty);
                a[tx][ty]=false;
            }
        }
        x.pop();
        y.pop();
    }
}
int main()
{
    in();
    for(int i=1;i<=m;i++)
      	for(int j=1;j<=n;j++)
			{
		  		if(a[i][j])
					BFS(i,j);
			}
    cout<<sum;  
    return 0;  
}

