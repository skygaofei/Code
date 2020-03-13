#include<bits/stdc++.h>
using namespace std;
int sj[100000][10]; 
int main()
{
	int n,i1,i2,i3,i4,i5,i6,i7,i8,i9,i10,s=0;
	cin>>n;
	for(i1=1;i1<=3;i1++)
		for(i2=1;i2<=3;i2++)
			for(i3=1;i3<=3;i3++)
				for(i4=1;i4<=3;i4++)
					for(i5=1;i5<=3;i5++)
						for(i6=1;i6<=3;i6++)
							for(i7=1;i7<=3;i7++)
								for(i8=1;i8<=3;i8++)
									for(i9=1;i9<=3;i9++)
										for(i10=1;i10<=3;i10++)
										{
											if(i1+i2+i3+i4+i5+i6+i7+i8+i9+i10==n)
											{
												s++;
												sj[s-1][0]=i1;
												sj[s-1][1]=i2;
												sj[s-1][2]=i3;
												sj[s-1][3]=i4;
												sj[s-1][4]=i5;
												sj[s-1][5]=i6;
												sj[s-1][6]=i7;
												sj[s-1][7]=i8;
												sj[s-1][8]=i9;
												sj[s-1][9]=i10;
											}
										} 
	cout<<s<<endl; 
	for(i1=0;i1<s;i1++)
	{
		for(i2=0;i2<10;i2++)
			cout<<sj[i1][i2]<<' ';
		cout<<endl;
	}
		
	return 0;
}
