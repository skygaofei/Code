#include<iostream>
using namespace std;
int main()
{
	unsigned long long num;
	cin >> num;
	unsigned long long num1, num2;
	num1 = num & 0x0000ffff;
	num2 = num & 0xffff0000;
	cout << ((num1 << 16) | (num2 >> 16));
	return 0;
}