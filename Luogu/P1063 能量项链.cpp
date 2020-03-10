// 能量项链.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#define maxn 200
using namespace std;
int dp[2 * maxn + 5][2 * maxn + 5], n, energy[maxn + 5], ans = 0;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &energy[i]);
		energy[n + i] = energy[i];
	}
	for (int i = 2; i < n + 2; i++) {
		for (int j = 1; j + i < 2 * n + 2; j++) {
			int r = j + i - 1;
			for (int k = j + 1; k + 2 <= j + i; k++) {
				dp[j][r] = max(dp[j][r], dp[j][k] + dp[k][r] + energy[j] * energy[k] * energy[r]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][n + i]);
	}
	printf("%d", ans);
	return 0;
}
