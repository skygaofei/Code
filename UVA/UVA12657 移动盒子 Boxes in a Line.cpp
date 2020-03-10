#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
struct lst
{
	lst *prev, *next;
	int val;
	lst(int value = 0) :prev(0), next(0), val(value) {}
};
lst *tmp;
lst* arr[100005];
int cnt;
void init()
{
	tmp = new lst;
	tmp->prev = tmp;
	tmp->next = tmp;
}
lst* insert(lst *it, int val)
{
	lst *it2 = new lst(val);
	it2->next = it->next;
	it->next->prev = it2;
	it2->prev = it;
	it->next = it2;
	cnt++;
	return arr[val] = it2;
}
lst* erase(lst *it)
{
	lst *res = it->next;
	it->next->prev = it->prev;
	it->prev->next = it->next;
	arr[it->val] = 0;
	delete it;
	cnt--;
	return res;
}
int k;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, m, k = 0;
	long long ans = 0;
	bool reff = false;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++)
			insert(tmp, n - i + 1);
		while (m--)
		{
			int x, y, z;
			cin >> x;
			if (x == 1)
			{
				cin >> y >> z;
				erase(arr[y]);
				if (reff)
					insert(arr[z], y);
				else
					insert(arr[z]->prev, y);
			}
			else if (x == 2)
			{
				cin >> y >> z;
				erase(arr[y]);
				if (reff)
					insert(arr[z]->prev, y);
				else
					insert(arr[z], y);
			}
			else if (x == 3)
			{
				cin >> y >> z;
				arr[y]->val = z;
				arr[z]->val = y;
				swap(arr[y], arr[z]);
			}
			else
				reff = !reff;
		}
		ans = 0;
		int s = 1;
		if (reff)
			for (lst *it = tmp->prev; it != tmp; it = it->prev, s++)
			{
				if (s % 2)
					ans += it->val;
			}
		else
			for (lst *it = tmp->next; it != tmp; it = it->next, s++)
				if (s % 2)
					ans += it->val;
		cout << "Case " << ++k << ": " << ans << endl;
		reff = false;
		while (cnt)
			erase(tmp->next);
	}
	return 0;
}