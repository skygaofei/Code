m=int(input())
n=int(input())
left=0
right=1
while right**m<=n:
    left=right;right=right*2
while left+1<right :
    mid=(left+right)//2
    if mid**m<=n :
        left=mid
    else:
        right=mid
if left**m<=n :
    print(left)
else:
    print(right)