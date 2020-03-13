//
//  main.cpp
//  显示数字
//
//  Created by 高飞 on 2018/3/24.
//  Copyright © 2018年 高飞. All rights reserved.
//

#include<iostream>
#include<string>
#define outl for(int i=1;i<=k;i++) cout<<'-';
#define outb for(int i=1;i<=k;i++) cout<<' ';
using namespace std;
int k;
struct number
{
    bool a, bl, br, c, dl, dr, e;
}num[10];
void clean()
{
    num[1].br = true;
    num[1].dr = true;
    num[2].a = true;
    num[2].br = true;
    num[2].c = true;
    num[2].dl = true;
    num[2].e = true;
    num[3].a = true;
    num[3].br = true;
    num[3].c = true;
    num[3].dr = true;
    num[3].e = true;
    num[4].bl = true;
    num[4].br = true;
    num[4].c = true;
    num[4].dr = true;
    num[5].a = true;
    num[5].bl = true;
    num[5].c = true;
    num[5].dr = true;
    num[5].e = true;
    num[6].a = true;
    num[6].bl = true;
    num[6].c = true;
    num[6].dr = true;
    num[6].dl = true;
    num[6].e = true;
    num[7].a = true;
    num[7].br = true;
    num[7].dr = true;
    num[8].a = true;
    num[8].br = true;
    num[8].bl = true;
    num[8].c = true;
    num[8].dr = true;
    num[8].dl = true;
    num[8].e = true;
    num[9].a = true;
    num[9].bl = true;
    num[9].br = true;
    num[9].c = true;
    num[9].dr = true;
    num[9].e = true;
    num[0].a = true;
    num[0].br = true;
    num[0].bl = true;
    num[0].dr = true;
    num[0].dl = true;
    num[0].e=true;
}
int main()
{
    clean();
    string n;
    cin >> k;
    cin >> n;
    for (int i = 0; i < n.length(); i++)
    {
        if (num[n[i] - '0'].a)
        {
            cout << ' ';
            outl
            cout << ' ';
        }
        else
        {
            cout << "  ";
            outb
        }
        if(i!=n.length()-1)
            cout<<' ';
    }
    cout << endl;
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i < n.length(); i++)
        {
            if (num[int(n[i] - '0')].bl)
            {
                cout << "|";
                outb
                if (num[int(n[i] - '0')].br&&i!=n.length()-1)
                    cout << '|'<<' ';
                else if(num[int(n[i] - '0')].br)
                    cout<<'|';
                else if(i!=n.length()-1)
                    cout<<' '<<' ';
                else
                    cout<<' ';
            }
            else if (num[int(n[i] - '0')].br&&i!=n.length()-1)
            {
                cout << ' ';
                outb
                cout << '|'<<' ';
            }
            else if(num[int(n[i] - '0')].br)
            {
                cout<<' ';
                outb
                cout<<'|';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n.length(); i++)
    {
        if (num[n[i] - '0'].c)
        {
            cout << ' ';
            outl
            cout << ' ';
        }
        else
        {
            cout << "  ";
            outb
        }
        if(i!=n.length()-1)
            cout<<' ';
    }
    cout << endl;
    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i < n.length(); i++)
        {
            if (num[int(n[i] - '0')].dl)
            {
                cout << "|";
                outb
                if (num[int(n[i] - '0')].dr&&i!=n.length()-1)
                    cout << '|'<<' ';
                else if(num[int(n[i] - '0')].dr)
                    cout<<'|';
                else if(i!=n.length()-1)
                    cout<<' '<<' ';
                else
                    cout<<' ';
            }
            else if (num[int(n[i] - '0')].dr&&i!=n.length()-1)
            {
                cout << ' ';
                outb
                cout << '|'<<' ';
            }
            else if(num[int(n[i] - '0')].dr)
            {
                cout<<' ';
                outb
                cout<<'|';
            }
        }
        cout << endl;
    }
    for (int i = 0; i < n.length(); i++)
    {
        if (num[n[i] - '0'].e)
        {
            cout << ' ';
            outl
            cout << ' ';
        }
        else
        {
            cout << "  ";
            outb
        }
        if(i!=n.length()-1)
            cout<<' ';
    }
    return 0;
}
