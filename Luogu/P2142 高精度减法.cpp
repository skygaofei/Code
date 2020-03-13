#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std; 
const int maxn = 10010; 
int len1, len2; 
int a[maxn], b[maxn]; 
string s1, s2; 
void swap(string &a, string &b)  //交换两个字符串 
{
    string t; 
    t = a; 
    a = b; 
    b = t; 
}
bool compare(string a, string b) //判断a是否小于b 
{
    if (a.size() < b.size()) return true;  //当a的位数比b小时，a比b小 
    if (a.size() > b.size()) return false; //当a的位数比b大时，a比b大
    for (int i = 0; i < a.size(); ++i)     //剩余情况就是a的位数与b相同 
    {
        if (a[i] > b[i]) return false;     //逐位比较 
        if (b[i] > a[i]) return true; 
    }
    return false; //最后当a与b的各个位的数字都相同时，a等于b 
}
int main()
{
    cin >> s1;           //读入不解释 
    cin >> s2; 
    if (compare(s1, s2)) //如果s1小于s2，就输出符号，并交换它们 
    {
        swap(s1, s2);  
        putchar('-'); 
    }
    len1 = s1.size(); 
    len2 = s2.size(); 
    for (int i = 0; i < len1; ++i) a[len1 - i] = s1[i] - '0'; 
    for (int i = 0; i < len2; ++i) b[len2 - i] = s2[i] - '0'; 
    //将字符转化为数字 
    for (int i = 1; i <= len1; ++i) //从低位算到高位，模拟竖式的运算过程 
    {
        a[i] -= b[i];               //直接用a储存结果：a[i]=a[i]-b[i] 
        if (a[i] < 0)               //如果不够减（减完是负数） 
        {                           
            a[i + 1]--;             //就向高位借一 
            a[i] += 10; 
        }
    }
    while (a[len1] == 0 && len1 > 1) len1--; //去除前导零
    //注意不能把单个零给去掉 
    for (int i = len1; i >= 1; --i)          //从高位到低位输出
      printf("%d", a[i]); 
    return 0; 
}