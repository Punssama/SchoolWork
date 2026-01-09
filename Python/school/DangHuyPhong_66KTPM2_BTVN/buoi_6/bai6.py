import math

a = int(input("nhap vao a: "))
b = int(input("nhap vao b: "))

gcd = math.gcd(a, b)

findBigger = max(a, b)
rs = []
for i in range(1, gcd + 1):
    if a % i == 0 and b % i == 0:
        rs.append(i)

print(rs)
