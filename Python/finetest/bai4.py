import math as m

n = int(input("N = "))

rs = 0
sqrt_N = int(m.sqrt(n))
for i in range(1, sqrt_N + 1):
    if n % i == 0:
        rs += i
        if i != n // i:
            rs += n // i

print(f"Tong cac uoc so cua {n} la", rs)
