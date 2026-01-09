def fibo(n):
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
    return a


n = int(input("Nhap so n: "))
l = []

for i in range(1, n + 1):
    if fibo(i) < n:
        l.append(fibo(i))
print(l)
