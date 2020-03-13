// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int l, n, m;
int a[50010];
bool jd(int s)
{
    bool flag = true;
    int k = 1, p = 0, k1 = 2;
    while (k <= n+2 && k1 <= n+2)
    {
        if (k == n+2)
        {
            flag = false;
            break;
        }
        if (k1 == n+2 && a[k1] - a[k] < s)
        {
            flag = false;
            break;
        }
        else if (a[k1] - a[k] >= s)
        {
            k = k1;
            k1 = k + 1;
        }
        else
        {
            p++;
            k1++;
        }
    }
    if (p <= m&&flag)
        return true;
    else
        return false;
}
int main()
{
    cin >> l >> n >> m;
    if (n == 0 || m == 0)
    {
        cout << l;
        return 0;
    }
    a[1] = 1;
    a[n + 2] = l;
    for (int i = 2; i <= n+1; i++)
        cin >> a[i];
    int le, r, mid;
    le = 1;
    r = l;
    while (le < r-1)
    {
        mid = (le + r) / 2;
        if (jd(mid))
            le = mid;
        else
            r = mid;
    }
    cout << le;
    return 0;
}
