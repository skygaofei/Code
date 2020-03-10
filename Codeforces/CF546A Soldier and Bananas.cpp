#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,k,w;
int main() {
	ios::sync_with_stdio(false);
	cin >> k >> n >> w;
	int ans = 0;
	ans = (1 + w)*w / 2;
	cout << max(ans*k - n, 0);
	return 0;
}