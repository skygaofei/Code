a,b = map(int,input().split())
c = abs(a - b)
a = 1
b = 1
for i in range(1, c + 1):
    p = (a + b)
    a = b
    b = p
print(a)
