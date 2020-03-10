// luogu-judger-enable-o2
// 生日.cpp: 定义控制台应用程序的入口点。
//
#include<iostream>
#include<string>
using namespace std;
struct student
{
    string name;
    int y, m, d;
    int num;
}stu[110];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> stu[i].name >> stu[i].y >> stu[i].m >> stu[i].d;
        stu[i].num = i;
    }
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            if (stu[i].y > stu[j].y)
                swap(stu[i], stu[j]);
            else if (stu[i].y == stu[j].y)
            {
                if (stu[i].m > stu[j].m)
                    swap(stu[i], stu[j]);
                else if (stu[i].m ==stu[j].m)
                {
                    if (stu[i].d > stu[j].d)
                        swap(stu[i], stu[j]);
                    else if (stu[i].d == stu[j].d)
                    {
                        if(stu[i].num<stu[j].num)
                            swap(stu[i], stu[j]);
                    }
                }
            }
        }
    for (int i = 1; i <= n; i++)
        cout << stu[i].name << endl;
    return 0;
}

