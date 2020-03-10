n = int(input())
a = 1
b = 2
c = 0
if n==0:
    print(0)
    exit(0)
if n==1:
    print(1);
    exit(0);
for i in range(n-2):
    c = a+b
    a = b
    b = c
print(b)