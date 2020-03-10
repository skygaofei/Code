n=int(input())
tmp=input().split()
s=int(tmp[0])
t=int(tmp[1])
num=[]
ans=0
for i in range(0,n):
	x=input().split()
	num.append((int(x[0]),int(x[1])))
num.sort(key=lambda x:x[0]*x[1])
for i in range(0,n):
	if(s//(num[i])[1]>ans):
		ans=s//(num[i])[1]
	s*=(num[i])[0]
print(ans)