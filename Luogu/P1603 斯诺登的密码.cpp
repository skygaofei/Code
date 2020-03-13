#include<bits/stdc++.h>
using namespace std;
string num[30]= {"zero","one",
                 "two","three",
                 "four","five",
                 "six","seven",
                 "eight","nine",
                 "ten","eleven",
                 "twelve","thirteen",
                 "fourteen","fifteen",
                 "sixteen","seventeen",
                 "eighteen","nineteen",
                 "twenty","a",
                 "both","another",
                 "first","second","third"
                },s;
int nu[30]= {0,1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
long long ans[10],k;
bool flag;
int main()
{
	for(int i=1; i<=6; i++) {
		cin>>s;
		for(int j=1; j<=26; j++) {
			if(s==num[j]) {
				k++;
				ans[k]=nu[j];
				break;
			}
		}
	}
	sort(ans+1,ans+k+1);
	for(int i=1; i<=k; i++) {
		if(flag)
			printf("%.2d",ans[i]);
		else {
			if(ans[i]) {
				cout<<ans[i];
				flag=true;
			}
		}
	}
	if(flag==0)
		cout<<0;
	return 0;
}