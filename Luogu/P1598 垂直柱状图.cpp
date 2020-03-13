#include<stdio.h>
#include<string.h>
int main()
{
    char a[4][100];//最后一个测试点异常，数组开大点就过了 
    int i, j, t, letter[26]={0}, max, len;
    memset(a, 0, sizeof(char)*300);
    for(i=0; i<4; i++)//读取4行字符 
        gets(a[i]);
    //统计各大写字母出现的次数到letter数组中 
    for(i=0; i<4; i++)
    {
        len = strlen(a[i]);
        for(j=0; j<len; j++)
            if(a[i][j]>='A' &&a[i][j]<='Z')
            {
                t=a[i][j]-'A'; 
                letter[t]++;
            }    
    }
    //字母中最高的出现次数（即找出柱状图的峰顶） 
    max = 0;
    for(i=0; i<26; i++)
        if(max<letter[i]) max=letter[i];
    //打印柱状图，根据max确定整个图的最高行数 
    for(j=max; j>=1; j--)
    {
        for(i=0; i<26; i++)
        {
            if(letter[i]>=j) 
                printf("* ");//1个星+1个空格 
            else
                printf("  ");//2个空格 
        }
        printf("\n");
    }
    for(i=0; i<26; i++)//打印底部的26个字母
        printf("%c ", 'A'+i);
    return 0;
}