import sys
import math

n = int(input("Nhap N duong: "))

rs = 0
fact = 1
for i in range(1, n + 1):
    fact *= i
    rs += fact
print(f"F({n}) =", rs)
